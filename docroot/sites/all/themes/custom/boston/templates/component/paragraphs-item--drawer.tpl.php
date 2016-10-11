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
<div class="dr"<?php print $attributes; ?>>
  <div class="dr__header">
    <div class="dr__buffer">
      <div class="dr__title"><?php print render($content['field_title']); ?></div>
      <?php if (isset($content['field_short_description'])): ?>
        <div class="dr__subtitle"><?php print render($content['field_short_description']); ?></div>
      <?php endif; ?>
    </div>
    <?php print file_get_contents(drupal_get_path('theme', $GLOBALS['theme']) . '/dist/img/subnav-toggle.svg') ?>
  </div>
  <div class="dr__content">
    <?php print render($content['field_text_blocks']); ?>
  </div>
</div>
