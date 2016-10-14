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
<div class="b b--g b--fw">
  <div class="b-c">
  	<div class="sh">
	    <?php print render($content['field_component_title']); ?>
	    <?php if (isset($content['field_contact'])): ?>
	      <?php print render($content['field_contact']); ?>
	    <?php endif; ?>
    </div>
    <div class="g">
      <?php if (isset($content['field_transactions'])): ?>
        <?php print render($content['field_transactions']); ?>
      <?php endif; ?>
    </div>
  </div>
</div>
