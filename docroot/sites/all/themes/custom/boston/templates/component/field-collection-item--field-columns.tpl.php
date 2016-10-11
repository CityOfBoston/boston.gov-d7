<?php
/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items.
 *   Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="<?php print $classes; ?> clearfix column-wrapper"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <?php if (isset($content['field_image'])): ?>
      <div class="field-three-col-image">
        <?php print render($content['field_image']); ?>
      </div>
    <?php endif; ?>
    <div class="field-three-col-title">
      <?php print render($content['field_column_title']); ?>
    </div>
    <div class="field-three-col-description">
      <?php print render($content['field_column_description']); ?>
    </div>
    <?php if (isset($content['field_link'])): ?>
      <div class="field-three-col-link">
        <?php print render($content['field_link']); ?>
      </div>
    <?php endif; ?>
  </div>
</div>
