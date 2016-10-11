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

<?php if(!empty($content['field_link'])): ?>
  <div class="status-item linked <?php print $classes; ?>"<?php print $attributes; ?>>
<?php else: ?>
  <div class="status-item <?php print $classes; ?>"<?php print $attributes; ?>>
<?php endif; ?>
  <div class="status-icon-wrapper">
    <?php print $icon; ?>
  <?php if ($use_alert): ?>
    <svg class="alert" width="28px" height="28px" viewBox="-1187 1989 24 24" version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
      <title>Alert</title>
      <desc>A red exclamation point in a cirlce.</desc>
      <circle class="svg-stroke-hover" stroke="#FB4D42" stroke-width="3" fill="#FFFFFF" fill-rule="evenodd" cx="-1175" cy="2001" r="10.5"></circle>
      <path d="M-1175,2008.2 C-1175.4,2008.2 -1175.8,2008.1 -1176.1,2007.8 C-1176.4,2007.5 -1176.5,2007.2 -1176.5,2006.8 C-1176.5,2006.4 -1176.4,2006 -1176.1,2005.8 C-1175.8,2005.5 -1175.5,2005.4 -1175,2005.4 C-1174.6,2005.4 -1174.2,2005.5 -1174,2005.8 C-1173.8,2006.1 -1173.6,2006.4 -1173.6,2006.8 C-1173.6,2007.2 -1173.7,2007.6 -1174,2007.8 C-1174.3,2008 -1174.6,2008.2 -1175,2008.2 L-1175,2008.2 Z M-1176.4,1993.8 L-1173.6,1993.8 L-1173.6,1996.4 L-1174.2,2003.6 L-1175.8,2003.6 L-1176.4,1996.4 L-1176.4,1993.8 L-1176.4,1993.8 Z" class="svg-fill-hover" stroke="none" fill="#FB4D42" fill-rule="evenodd"></path>
    </svg>
  <?php endif; ?>
  </div>
  <div class="status-text-wrapper">
  <h3 class="status-message-title"><?php print render($content['field_title']); ?></h3>
  <div class="status-message-body"><?php print render($content['field_message']); ?></div>
  </div>
  <?php if(isset($content['field_link'])): ?>
    <?php print render($content['field_link']); ?>
  <?php endif; ?>
</div>
