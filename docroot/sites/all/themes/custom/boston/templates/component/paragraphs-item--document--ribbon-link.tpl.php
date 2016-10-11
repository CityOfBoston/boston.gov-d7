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

<div class="link-wrapper download-link">
  <div class="link-item ribbon">
    <a href="<?php print $document_link; ?>" title="Download <?php print $document_filename; ?>" target="_blank">
    <?php if (!empty($content['field_title'])): ?>
    <?php print render($content['field_title']); ?>
    <?php else: ?>
      <?php print $document_filename; ?>
    <?php endif; ?>
  </a>
  </div>
  <?php if (!empty($content['field_title'])): ?>
    <?php print render($content['field_title']); ?>
  <?php else: ?>
    <?php print $document_filename; ?>
  <?php endif; ?>
  <div class="link-icon-ribbon"></div>
</div>
