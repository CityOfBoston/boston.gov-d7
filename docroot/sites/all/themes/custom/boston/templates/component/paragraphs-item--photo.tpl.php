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

// Hide this now to print later.
hide($content['group_photo_details']);
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <?php print render($content); ?>
    <?php if (isset($content['group_photo_details']['field_component_title'])||isset($content['group_photo_details']['field_photo_caption'])||isset($content['group_photo_details']['field_photo_credit'])||isset($content['group_photo_details']['field_link'])): ?>
    <div class="photo-details">
      <?php if (isset($content['group_photo_details']['field_component_title'])): ?>
        <?php print render($content['group_photo_details']['field_component_title']); ?>
      <?php endif; ?>
      <?php if (isset($content['group_photo_details']['field_photo_caption'])): ?>
        <div class="photo-caption-wrapper">
          <?php print render($content['group_photo_details']['field_photo_caption']); ?>
        </div>
      <?php endif; ?>
      <?php if (isset($content['group_photo_details']['field_photo_credit'])): ?>
        <div class="photo-credit-wrapper">
          <?php print render($content['group_photo_details']['field_photo_credit']); ?>
        </div>
      <?php endif; ?>
      <?php if (isset($content['group_photo_details']['field_link'])): ?>
        <div class="call-to-action">
          <?php print render($content['group_photo_details']['field_link']); ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
  </div>
</div>
