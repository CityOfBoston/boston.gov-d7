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

 $id = uniqid();
?>
<div class="dr"<?php print $attributes; ?>>
  <input type="checkbox" id="dr-<?php print $id; ?>" class="dr-tr a11y--h">
  <label for="dr-<?php print $id; ?>" class="dr-h">
    <div class="dr-ic"><svg xmlns="http://www.w3.org/2000/svg" viewBox="-2 8.5 18 25"><path class="dr-i" d="M16 21L.5 33.2c-.6.5-1.5.4-2.2-.2-.5-.6-.4-1.6.2-2l12.6-10-12.6-10c-.6-.5-.7-1.5-.2-2s1.5-.7 2.2-.2L16 21z"/></svg></div>
    <div class="dr-t"><?php print render($content['field_title']); ?></div>
    <?php if (isset($content['field_short_description'])): ?>
      <div class="dr-st"><?php print render($content['field_short_description']); ?></div>
    <?php endif; ?>
  </label>
  <div class="dr-c">
    <?php print render($content['field_text_blocks']); ?>
  </div>
</div>
