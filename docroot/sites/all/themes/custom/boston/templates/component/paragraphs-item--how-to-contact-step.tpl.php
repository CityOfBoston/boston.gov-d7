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
    <div class="step-line"></div>
    <div class="step-label-wrapper">
      <div class="step-label">Step</div>
      <div class="step-number"><?php print $how_to_step_count; ?></div>
    </div>
    <div class="content step-content"<?php print $content_attributes; ?>>
    <?php if (isset($content['field_title'])): ?>
      <h2 class="header-border-bottom"><?php print render($content['field_title']); ?></h2>
    <?php endif; ?>
    <?php if (isset($content['field_step_details'])): ?>
      <?php print render($content['field_step_details']); ?>
    <?php endif; ?>
    <?php if (isset($content['field_address'])): ?>
      <div class="list-item">
        <?php print render($content['field_address']); ?>
      </div>
    <?php endif; ?>
    <?php if (isset($content['field_operation_hours'])): ?>
      <?php print render($content['field_operation_hours']); ?>
    <?php endif; ?>
  </div>
</div>
