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
$title = $content['field_how_to_title'][0]['#markup'];
$title_id = drupal_clean_css_identifier(drupal_html_class($title));
?>

<div class="tab-p tab-p-<?php print $how_to_tabs_count ?>" id="<?php print $title_id; ?>_content" <?php print $content_attributes; ?>>
  <?php if (isset($content['field_how_to_steps'])): ?>
    <?php print render($content['field_how_to_steps']); ?>
  <?php endif; ?>
  <?php if (isset($content['field_keep_in_mind'])): ?>
    <?php print render($content['field_keep_in_mind']); ?>
  <?php endif; ?>
</div>
