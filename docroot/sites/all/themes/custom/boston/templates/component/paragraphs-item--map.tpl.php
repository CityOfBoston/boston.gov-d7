<?php

/**
 * @file
 * Default theme implementation for a single paragraph item.
 *
 * Available variables:
 * - $content: An array of content items. Use render($content) to print them
 *   all, or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity
 *   - entity-paragraphs-item
 *   - paragraphs-item-{bundle}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened into
 *   a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */

 $show_title = $content['field_map_options']['#items'][0]['value'] === '1';

 if (!$show_title) {
   $show_title = !empty($content['field_hide_title_bar']) && !$content['field_hide_title_bar']['#items'][0]['value'];
 }
?>
<div class="b b--fw">
  <div class="content"<?php print $content_attributes; ?>>
    <div class="mp">
      <?php if ($show_title): ?>
        <div class="mp-h">
          <div class="mp-h-i">
            <div class="mp-t"><?php print render($content['field_component_title']); ?></div>
            <div class="mp-st"><?php print render($content['field_extra_info']); ?></div>
            <button class="btn">View Map</button>
          </div>
        </div>
      <?php endif; ?>
      <?php print render($content['map_canvas']) ?>
    </div>
  </div>
</div>

<script>
document.addEventListener("DOMContentLoaded", function(event) {

  // Get array of map objects from Drupal.
  var mapJSON = '<?php print render($content["map_object"]) ?>';
  // Convert JSON into javascript object.
  var mapObj = JSON.parse(mapJSON);

  // Set the Map ID used to create a unique canvas for each map.
  var mapID = mapObj.mapID;
  // Set ESRI Feed title, url, and color info.
  var feeds = mapObj.feeds;
  // Set Custom Pins title, desc, latitude and longitude info.
  var points = mapObj.points;
  // Set Map Options (0 = Static, 1 = Zoom).
  var mapOptions = mapObj.options;
  // Set Basemap URL.
  var basemapUrl = mapObj.basemap;
  // Set Latitude to component value if it exists, if not set to ESRI Lat, if nothing exists set hardcoded value.
  var latitude = mapObj.componentLat ? mapObj.componentLat : mapObj.esriLat ? mapObj.esriLat : 42.357004;
  // Set Longitude to component value if it exists, if not set to ESRI Lat, if nothing exists set hardcoded value.
  var longitude = mapObj.componentLong ? mapObj.componentLong : mapObj.esriLong ? mapObj.esriLong : -71.062309;
  // Set Zoom to component value if it exists, if not set to ESRI Lat, if nothing exists set hardcoded value.
  var zoom = mapObj.componentZoom ? mapObj.componentZoom : mapObj.esriZoom ? mapObj.esriZoom : 14;

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

  function createPopup (p) {
    return function (layer) { return L.Util.template(p, layer.feature.properties); };
  }

  function createLegend(d) {
    return function (map) { return d; };
  }

});
</script>


<style>
.co {position: relative; z-index: 1000;}
body { margin:0; padding:0; }
.map { position: absolute; top:0; bottom:0; right:0; left:0; z-index:0; }
.leaflet-popup {
  width: 250px;
  height: auto;
}
.leaflet-popup-content .title {
  font-size: 22px;
  font-family: 'Montserrat', sans-serif;
  font-weight: bold;
}
.leaflet-popup-content .times {
  font-size: 16px;
  font-family: 'Lora', serif;
  font-style: italic;
}
.leaflet-popup-content .content {
  font-size: 14px;
  font-family: 'Lora', serif;
  font-style: italic;
}
.leaflet-popup-content p {
  font-size: 14px;
  font-family: 'Lora', serif;
  margin: 0px;
}
a[href=""] {
  color: #000000;
  text-decoration: none;
  cursor: default;
}

.queries {
  position: static;
  top: 25px;
  left: 25px;
  background: white;
  z-index: 1000;
  /*border-radius: 10px;
  box-shadow: 5px 5px 5px #888888;*/
}
@media screen and (min-width: 980px) {
  .queries {
    position: absolute;
    padding: .5em;
  }
}
.query {
  padding: .5em;
  box-shadow: none;
}
label {
  font-size: 22px;
  font-family: "Montserrat", Arial, sans-serif;
  font-weight: bold;
}
.query select {
  font-family: 'Lora', serif;
  font-size: 18px;
  font-style: italic;
}
/* style leaflet marker clusters */
.marker-cluster-small {
  background-color: rgba(40, 139, 228, 0.6);
}
.marker-cluster-small div {
  background-color: rgba(40, 139, 228, 0.6);
}
.marker-cluster-medium {
  background-color: rgba(40, 139, 228, 0.6);
}
.marker-cluster-medium div {
  background-color: rgba(40, 139, 228, 0.6);
}
.marker-cluster-large {
  background-color: rgba(40, 139, 228, 0.6);
}
.marker-cluster-large div {
  background-color: rgba(40, 139, 228, 0.6);
}
.marker-cluster div {
  width: 30px;
  height: 30px;
  margin-left: 5px;
  margin-top: 5px;
  text-align: center;
  border-radius: 15px;
  font-family: 'Montserrat', sans-serif;
  font-weight: 500;
  font-size: : 12px;
  color: white;
}
/* Style Legend */
.legend {
  line-height: 18px;
  color: #555;
  background-color: rgba(255, 250, 250, 1);
  border: 3px;
  outline-color: white;
  border-radius: 5px;
  padding: 6px 8px;
  font-size: 14px;
}
.legend i {
  width: 18px;
  height: 18px;
  float: left;
  margin-right: 8px;
  opacity: 0.7;
}
</style>
