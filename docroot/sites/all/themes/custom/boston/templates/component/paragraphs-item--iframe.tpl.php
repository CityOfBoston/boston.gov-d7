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

$field_source_url = $content['field_source_url'][0]["#markup"];
$iframe_id = uniqid();
?>

<?php if (!$iframe_height) { ?>
  <script>
    jQuery(document).ready(function () {
      iFrameResize(null, '#iframe-<?php print $iframe_id ?>');
    });
  </script>
<?php } ?>

<div class="<?php print $classes; ?>">
  <div class="content" <?php print $content_attributes; ?>>
    <div class="sh">
      <?php print render($content['field_component_title']); ?>
      <?php print render($content['field_contact']); ?>
    </div>
  </div>
  <iframe src="<?php print $field_source_url ?>" border="0" class="iframe-component" id="iframe-<?php print $iframe_id ?>"<?php if ($iframe_height) { ?> style="height: <?php echo $iframe_height; ?><?php } ?>"></iframe>
</div>
