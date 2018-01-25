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
 $field_title = $content['field_title'][0]['#markup'];
?>
<?php if (isset($link_icon["classes"]["icon"])) { ?>
  <a href="<?php print $external_link_path; ?>" class="<?php print $link_icon["classes"]["container"]; ?>" target="_blank">
    <span<?php print((isset($link_icon["classes"]["icon"]) ? ' class="' . $link_icon["classes"]["icon"] . '"' : '')); ?>><img src="<?php print $link_icon["image"] ?>" class="lwi-i" alt="" /></span>
    <span<?php print((isset($link_icon["classes"]["text"]) ? ' class="' . $link_icon["classes"]["text"] . '"' : '')); ?>><?php print ((!empty($field_title) ? $field_title : $external_link_title)); ?></span>
  </a>
<?php } else { ?>
  <div class="link-wrapper"<?php print $content_attributes; ?>>
    <?php print render($content); ?>
  </div>
<?php } ?>
