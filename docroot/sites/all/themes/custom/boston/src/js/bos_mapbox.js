/**
 * @file
 * Map Functionality.
 *
 * Provides map functionality for the site.
 */

(function ($) {
  Drupal.behaviors.exampleModule = {
    attach: function (context, settings) {

      var map = L.map('map', {zoomControl: false}).setView([42.357004, -71.062309], 14);
      //add zoom control to top right
      L.control.zoom({
            position:'bottomright'
      }).addTo(map);

      // find user location
      map.locate({setView: true, maxZoom: 18});
      function onLocationFound(e) {
        var radius = e.accuracy / 2;
      /*var user_loc_icon = L.icon({
        iconUrl: 'http://www.clker.com/cliparts/n/T/g/C/Z/k/google-maps-icon-red-md.png',
        iconSize: [24, 38]
      })*/
      var user_loc = L.marker(e.latlng).addTo(map)
        .bindPopup('<p class="title">You are here.</p>').openPopup();
      var radius_circle = L.circle(e.latlng, radius, {color:'#091F2F',opacity:1,fillOpacity:0.2}).addTo(map);
      }
      map.on('locationfound', onLocationFound);
      // add mapbox basemap
      L.tileLayer('https://api.mapbox.com/styles/v1/cityofboston/cj1hyqwt2001s2so0hjacals3/tiles/256/{z}/{x}/{y}?access_token=pk.eyJ1IjoiY2l0eW9mYm9zdG9uIiwiYSI6ImNqMTd1dDdqZTA1c2UyeHFzNGhrN2g0bHYifQ.SZ8J0aXwDHt4sCmZ9rQO2A').addTo(map);
      // add food trucks layer
      /*var icon = L.icon({
        iconUrl: 'https://www.portlandchronicle.com/wp-content/uploads/leaflet-maps-marker-icons/bluemapicon.png',
        iconSize: [24, 38]
      })*/
      var food_trucks = L.esri.Cluster.featureLayer({
        url: 'https://services.arcgis.com/sFnw0xNflSi8J0uh/arcgis/rest/services/food_trucks_schedule/FeatureServer/0',
          /*pointToLayer: function (geojson, latlng) {
          return L.marker(latlng, {
            icon: icon
          });
          },*/
      }).addTo(map);
      food_trucks.bindPopup(function (layer) {
        return L.Util.template('<a class="title" href={Link} target="_blank"><b>{Truck}</b></a><p class="times">{Time}: {Hours}<br>Day: {Day}<br><br>{Title}</p><p class="content">{Loc}<br><br>Managed by: {Management}</p>', layer.feature.properties);
      });
      // add day, time of day, and truck filters
      // get day of week as a string
      function DayOfWeekAsString(dayIndex) {
        return ["Sunday", "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"][dayIndex];
      }
      // get current day of week and make the default selection
      var d = new Date();
      var n = d.getDay(); 
      var temp = DayOfWeekAsString(n);
      var day = document.getElementById('day');
      var days = ["Sunday", "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"];
      day.selectedIndex = days.indexOf(temp);
      day.addEventListener('change', function(){
        food_trucks.setWhere(day.value + " AND " + time.value + " AND " + truck.value);
      });
      // build time of day filter
      // get current time of day as string value
      function GetTimeIndex(time) {
        if (time >= '07:00:00' && time <= '10:30:00') {
          return "Breakfast";
        } else if (time <= '15:00:00')  {
          return "Lunch";
        } else if (time <= '20:00:00') {
          return "Dinner";
        } else {
          return "Any";
        }}
      // get current time of day
      var t = GetTimeIndex(d.toTimeString().replace(/.*(\d{2}:\d{2}:\d{2}).*/, "$1"));
      console.log(d.toTimeString().replace(/.*(\d{2}:\d{2}:\d{2}).*/, "$1"));
      console.log(t);
      var time = document.getElementById('time');
      var times = ["Any", "Breakfast", "Lunch", "Dinner"];
      time.selectedIndex = times.indexOf(t);
      time.addEventListener('change', function(){
        food_trucks.setWhere(day.value + " AND " + time.value + " AND " + truck.value);
      });
      // build trucks fitler
      // query trucks layer to get unique names of trucks
      var trucksQuery = L.esri.query({
        url: "https://services.arcgis.com/sFnw0xNflSi8J0uh/arcgis/rest/services/food_trucks_schedule/FeatureServer/0"
      })
        .where("1=1")
        .returnGeometry(false)
        .fields(['Truck']);
      trucksQuery.params.returnDistinctValues = true;
      // run query and build options list from it
      trucksQuery.run(function (err, res, raw) {
        for (i=1; i<res.features.length; i++) {
          var option = document.createElement("option");
          option.text = res.features[i].properties.Truck;
          option.value = "Truck = '" + res.features[i].properties.Truck + "'";
          var select = document.getElementById("truck");
          select.appendChild(option);
        }
      });
      truck.addEventListener('change', function(){
        food_trucks.setWhere(day.value + " AND " + time.value + " AND " + truck.value);
      });
      // once all food trucks have loaded adjust display to the default selection
      food_trucks.once('load', function(){
        food_trucks.setWhere(day.value + " AND " + time.value + " AND " + truck.value);
      });

    }
  };
}(jQuery));
