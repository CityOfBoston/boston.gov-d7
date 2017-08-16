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
<div class="<?php print $classes; ?> fullwidth"<?php print $attributes; ?>>
  <div class="content container"<?php print $content_attributes; ?>>
  	  <div class="sh">
        <?php if (isset($content['field_component_title'])): ?>
          <?php print render($content['field_component_title']); ?>
        <?php endif; ?>
        <?php if (isset($content['field_short_title'])): ?>
          <?php print render($content['field_short_title']); ?>
        <?php endif; ?>
        <?php if (isset($content['field_contact'])): ?>
          <?php print render($content['field_contact']); ?>
        <?php endif; ?>
      </div>
     <div>
       <?php print render($content['field_featured_item']); ?>
     </div>
     <div class="grid-wrapper clearfix">
      <?php print render($content['field_list']); ?>
    </div>
    <?php if (isset($call_to_action)): ?>
      <?php print render($call_to_action); ?>
    <?php endif; ?>
  </div>
</div>
