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
?>

<?php if (!empty($content['field_map_inline']) && $content['field_map_inline']['#items'][0]['value'] == 1) { ?>
<div class="b b--w b--fw">
  <div class="b-c">
    <div class="sh">
      <?php print render($content['field_component_title']) ?>
    </div>

    <cob-map
      config="<?php print render($content['field_map_config_json']); ?>"
      style="height: 500px; max-height: calc(100vh - 120px);"
      class="m-v500"
    </cob-map>
  </div>
</div>

<?php } else { ?>

<cob-map
  id="<?php print $map_id; ?>"
  config="<?php print render($content['field_map_config_json']); ?>"
  modal>
</cob-map>

<div class="b b--fw">
  <div class="ph ph--wc">
    <a href="#<?php print $map_id; ?>">
      <div class="ph-p ph-p--<?php print $photo_id; ?>">
        <?php print render($content['field_image']); ?>
      </div>
    </a>

    <div class="ph-c p-a600">
      <div class="m-b200">
        <?php print render($content['field_component_title']); ?>
      </div>
      <?php if (isset($content['field_extra_info'])): ?>
        <div class="t--info m-b200"><?php print render($content['field_extra_info']); ?></div>
      <?php endif; ?>
      <a class="btn" href="#<?php print $map_id; ?>">
        Show Map
      </a>
    </div>
  </div>
</div>

<?php } ?>
