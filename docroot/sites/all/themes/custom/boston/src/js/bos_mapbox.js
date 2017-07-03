/**
 * @file
 * Map Functionality.
 *
 * Provides map functionality for the site.
 */

(function ($) {
  Drupal.behaviors.exampleModule = {
    attach: function (context, settings) {

      // Get array of map objects from Drupal.
      var maps = Drupal.settings.maps;
      for (i = 0; i < maps.length; i++) {
        // Set the Map ID used to create a unique canvas for each map.
        var mapID = maps[i].mapID;
        // Set ESRI Feed title, url, and color info.
        var feeds = maps[i].feeds;
        // Set Custom Pins title, desc, latitude and longitude info.
        var points = maps[i].points;
        // Set Map Options (0 = Static, 1 = Zoom).
        var mapOptions = maps[i].options;
        // Set Basemap URL.
        var basemapUrl = maps[i].basemap;
        // Set Latitude to component value if it exists, if not set to ESRI Lat, if nothing exists set hardcoded value.
        var latitude = maps[i].componentLat ? maps[i].componentLat : maps[i].esriLat ? maps[i].esriLat : 42.357004;
        // Set Longitude to component value if it exists, if not set to ESRI Lat, if nothing exists set hardcoded value.
        var longitude = maps[i].componentLong ? maps[i].componentLong : maps[i].esriLong ? maps[i].esriLong : -71.062309;
        // Set Zoom to component value if it exists, if not set to ESRI Lat, if nothing exists set hardcoded value.
        var zoom = maps[i].componentZoom ? maps[i].componentZoom : maps[i].esriZoom ? maps[i].esriZoom : 14;

        // Apply default coordinates and zoom level.
        var map = L.map(mapID, {zoomControl: false}).setView([latitude, longitude], zoom);
        // Add zoom control to bottom right.
        L.control.zoom({
          position:'bottomright'
        }).addTo(map);

        // Add custom pins created in Map component.
        for (j = 0; j < points.length; j++) {
          var customPin = L.marker([points[j].lat, points[j].long]).addTo(map);
          customPin.bindPopup(
            '<a class="title" href="' + points[j].url + '" target="_blank">' +
              '<b>' +
                points[j].name +
              '</b>' +
            '</a>' +
            '<p class="times">' +
              points[j].desc +
            '</p>'
          );
        }

        // Add mapbox basemap.
        L.tileLayer(basemapUrl).addTo(map);

        // Set the legend position.
        var legend = L.control({position: 'topleft'});
        var div = L.DomUtil.create('div', 'info legend');

        // Add layer for ESRI feed(s) and add item for legend.
        for (k = 0; k < feeds.length; k++) {
          // Check if pins should be clustered.
          baseObj = (feeds[k].cluster == 1) ? L.esri.Cluster : L.esri;
          layerObj = baseObj.featureLayer({
            url: feeds[k].url,
            style: {
              "color": feeds[k].color,
              "weight": 3
            }
          }).addTo(map);
          // Create popups for pin markers
          layerObj.bindPopup(createPopup(feeds[k].popup));
          // Add item to legend.
          div.innerHTML += '<i style="background:' + feeds[k].color + '"></i> ' + feeds[k].title + '<br>';
        }

        // Add "div" variable created in loop to legend.
        legend.onAdd = createLegend(div);
        // Add legend to map.
        legend.addTo(map);

      }

      function createPopup (p) {
        return function (layer) { return L.Util.template(p, layer.feature.properties); };
      }

      function createLegend(d) {
        return function (map) { return d; };
      }

      /*
        if (mapOptions === '0') {
          // Disable map zoom when using scroll.
          map.scrollWheelZoom.disable();
        } else {
          // Disable map zoom when using scroll.
          map.scrollWheelZoom.disable();
          var buttonHTML = L.DomUtil.create('div', 'info legend');
          interactiveMode.onAdd = function (map) { return buttonHTML; };
          interactiveMode.addTo(map);
        }
      }
      $('.map-zoom').click(function() {
        if ($(this).text() == 'Interactive Map') {
          // Re-enable zoom when user clicks button.
          map.scrollWheelZoom.enable();
          // Adjust the button text.
          $(this).text('X');
        } else {
          // Disable zoom when user clicks button.
          map.scrollWheelZoom.disable();
        }
      });
      */

    }
  };
}(jQuery));
