/**
 * @file
 * Map Functionality.
 *
 * Provides map functionality for the site.
 */

(function ($) {
  Drupal.behaviors.exampleModule = {
    attach: function (context, settings) {

      alert(Drupal.settings.esri);
      var map = L.map('map', {zoomControl: false}).setView([42.357004, -71.062309], 14);
      //add zoom control to top right
      L.control.zoom({
        position:'bottomright'
      }).addTo(map);

      // find user location
      map.locate({setView: true, maxZoom: 18});
      function onLocationFound(e) {
        var radius = e.accuracy / 2;
        var user_loc = L.marker(e.latlng).addTo(map).bindPopup('<p class="title">You are here.</p>').openPopup();
        var radius_circle = L.circle(e.latlng, radius, {color:'#091F2F',opacity:1,fillOpacity:0.2}).addTo(map);
      }
      map.on('locationfound', onLocationFound);
      // add mapbox basemap
      L.tileLayer('https://api.mapbox.com/styles/v1/cityofboston/cj1hyqwt2001s2so0hjacals3/tiles/256/{z}/{x}/{y}?access_token=pk.eyJ1IjoiY2l0eW9mYm9zdG9uIiwiYSI6ImNqMTd1dDdqZTA1c2UyeHFzNGhrN2g0bHYifQ.SZ8J0aXwDHt4sCmZ9rQO2A').addTo(map);
      // add food trucks layer
      var food_trucks = L.esri.Cluster.featureLayer({
        url: 'https://services.arcgis.com/sFnw0xNflSi8J0uh/arcgis/rest/services/food_trucks_schedule/FeatureServer/0',
      }).addTo(map);
      food_trucks.bindPopup(function (layer) {
        return L.Util.template('<a class="title" href={Link} target="_blank"><b>{Truck}</b></a><p class="times">{Time}: {Hours}<br>Day: {Day}<br><br>{Title}</p><p class="content">{Loc}<br><br>Managed by: {Management}</p>', layer.feature.properties);
      });

    }
  };
}(jQuery));
