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

<a href="<?php print $card_url; ?>" <?php if ($isLightbox): ?> data-lity<?php endif; ?> class="cd g--4 g--4--sl m-t500"<?php if (!empty($card_attr)): print $card_attr; endif ?>>
  <div class="cd-ic" style="background-image: url(<?php print render($content['field_thumbnail']); ?>)"></div>
  <div class="cd-c">
    <div class="cd-t"><?php print render($content['field_title']); ?></div>
    <?php if (isset($content['field_subheader'])): ?>
      <div class="cd-st t--upper t--subtitle"><?php print render($content['field_subheader']); ?></div>
    <?php endif; ?>
    <div class="cd-d"><?php print render($content['field_short_description']); ?></div>
  </div>
</a>