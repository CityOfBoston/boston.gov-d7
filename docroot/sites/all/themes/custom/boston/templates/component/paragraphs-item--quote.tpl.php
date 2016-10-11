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
<div class="quote">
  <div class="quote-text">
    "<?php print render($content['field_quote']); ?>"
  </div>
  <div class="quote-details">
    <div class="quote-photo">
      <?php print $field_default_person_photo ?>
    </div>
    <div class="quote-person-details">
      <div class="quote-name">
        <?php print strtoupper(render($content['field_first_name'])); ?>
        <?php $lastname = substr(strtoupper(render($content['field_last_name'])), 3, 1); ?>
        <?php print $lastname; ?>.
      </div>
      <div class="quote-location">
        <?php print render($content['field_single_neighborhood']); ?>
      </div>
    </div>
  </div>
</div>