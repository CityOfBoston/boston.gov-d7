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
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="content" <?php print $content_attributes; ?>>
    <div class="sh">
      <?php print render($content['field_component_title']); ?>
      <?php if (isset($content['field_short_title'])) : ?>
        <?php print render($content['field_short_title']); ?>
      <?php endif; ?>
      <?php if (isset($content['field_contact'])): ?>
        <?php print render($content['field_contact']); ?>
      <?php endif; ?>
    </div>

    <div class="links-grid-left-rail mobile-100 tablet-100 <?php print (!$left_region_is_empty) ? "desktop-25-left" : "";?>">
      <div class="links-grid-field-subheader">
        <?php print render($content['field_subheader']); ?>
      </div>
      <div class="links-grid-field-description">
        <?php print render($content['field_description']); ?>
      </div>
      <?php if (!empty($call_to_action)): ?>
        <?php print $call_to_action;?>
      <?php endif; ?>
    </div>

    <div class="links-grid-field-grid-links mobile-100 tablet <?php print (!$left_region_is_empty) ? "desktop-75-right" : "desktop-100";?>">
      <?php print render($content['field_grid_links']); ?>
    </div>
  </div>
</div>
