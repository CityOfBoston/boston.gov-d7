/**
 * @file
 * Map Functionality.
 *
 * Provides map functionality for the site.
 */

(function ($) {
  Drupal.behaviors.exampleModule = {
    attach: function (context, settings) {

      // Set ESRI Feed title, url, and color info.
      var feeds = Drupal.settings.feeds;
      // Set Custom Pins title, desc, latitude and longitude info.
      var points = Drupal.settings.points;
      // Set Map Options (0 = Static, 1 = Zoom).
      var mapOptions = Drupal.settings.options;
      // Set Basemap URL.
      var basemapUrl = Drupal.settings.basemap;
      // Set Latitude to component value if it exists, if not set to ESRI Lat, if nothing exists set hardcoded value.
      var latitude = Drupal.settings.componentLat ? Drupal.settings.componentLat : Drupal.settings.esriLat ? Drupal.settings.esriLat : 42.357004;
      // Set Longitude to component value if it exists, if not set to ESRI Lat, if nothing exists set hardcoded value.
      var longitude = Drupal.settings.componentLong ? Drupal.settings.componentLong : Drupal.settings.esriLong ? Drupal.settings.esriLong : -71.062309;
      // Set Zoom to component value if it exists, if not set to ESRI Lat, if nothing exists set hardcoded value.
      var zoom = Drupal.settings.componentZoom ? Drupal.settings.componentZoom : Drupal.settings.esriZoom ? Drupal.settings.esriZoom : 14;
      //var cluster = Drupal.settings.esriCluster;

      // Apply default coordinates and zoom level.
      var map = L.map('map', {zoomControl: false}).setView([latitude, longitude], zoom);
      // Add zoom control to bottom right.
      L.control.zoom({
        position:'bottomright'
      }).addTo(map);

      if (mapOptions === '0') {
        // Disable map zoom when using scroll.
        map.scrollWheelZoom.disable();
      }

      // Add custom pins created in Map component.
      points.forEach(function(point) {
        var customPin = L.marker([point.lat, point.long]).addTo(map);
        customPin.bindPopup(
          '<a class="title" href="' + point.url + '" target="_blank">' +
            '<b>' +
              point.name +
            '</b>' +
          '</a>' +
          '<p class="times">' +
            point.desc +
          '</p>'
        );
      });

      // Add mapbox basemap.
      L.tileLayer(basemapUrl).addTo(map);
      // Set the legend position.
      var legend = L.control({position: 'topleft'});
      var div = L.DomUtil.create('div', 'info legend');
      // Add layer for ESRI feed(s) and add item for legend.
      feeds.forEach(function(feed) {
        var layerObj;
        var baseObj;
        // Check if pins should be clustered.
        if (feed.cluster == 1) {
          baseObj = L.esri.Cluster;
        } else {
          baseObj = L.esri;
        }
        layerObj = baseObj.featureLayer({
          url: feed.url,
          // Set line style.
          style: {
            "color": feed.color,
            "weight": 3
          }
        }).addTo(map);
        // Create popups for pin markers
        layerObj.bindPopup(function (layer) {
          return L.Util.template(feed.popup, layer.feature.properties);
        });
        // Add item to legend.
        div.innerHTML +='<i style="background:' + feed.color + '"></i> ' + (feed.title + '<br>');
      });
      // Add "div" variable created in loop to legend.
      legend.onAdd = function (map) { return div; };
      // Add legend to map.
      legend.addTo(map);

    }
  };
}(jQuery));
