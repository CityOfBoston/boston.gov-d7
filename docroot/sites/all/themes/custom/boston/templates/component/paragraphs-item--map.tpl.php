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
?>
<div class="b b--fw">
  <div class="mp">
    <div class="mp-ec">
      <button class="mp-e md-cb">Exit</button>
    </div>
    <div class="mp-h">
      <?php if ($show_title): ?>
        <div class="mp-h-i p-a400 p-a500--xl">
          <div class="sh m-b300">
            <div class="sh--title"><?php print render($content['field_component_title']); ?></div>
          </div>
          <div class="mp-st m-b300"><?php print render($content['field_extra_info']); ?></div>
          <button class="mp-v btn btn--100 btn--200--m btn--300--l">View Map</button>
        </div>
      <?php endif; ?>
    </div>
    <?php print render($content['map_canvas']) ?>
  </div>
  <script>
    var mapData = mapData || {};
    mapData['<?php print $content['map_id']; ?>'] = '<?php print render($content["map_object"]) ?>';
  </script>
</div>
