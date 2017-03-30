<?php
/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content)
 *   to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div id="sa-a" class="b b--<?php print $block_theme; ?> b--fw"<?php print $attributes; ?> data-excludes="<?php print implode(',', $excluded_nodes) ?>">
  <div class="b-c b-c--xsmv fyi--<?php print $block_theme; ?>">
    <div class="fyi-c">
      <?php if (!empty($icon)): ?><div class="fyi-i fyi-i--<?php print $block_theme; ?>"><?php print render($icon) ?></div><?php endif; ?>
      <div class="fyi-t fyi-t--<?php print $block_theme; ?>"><?php print render($content['title_field']); ?></div>
      <div class="fyi-s fyi-s--<?php print $block_theme; ?>">/</div>
      <div class="fyi-d fyi-d--<?php print $block_theme; ?>"><?php print render($content['field_extra_info']); ?></div>
      <?php print render($content['field_link']); ?>
    </div>
  </div>
</div>
