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

 $url = $content['field_source_url'][0]['#markup'];
 $async = $content['field_sticky'][0]['#markup'] == '1';
?>
<?php if (isset($url)) { ?>
  <script src="<?php print($url); ?>" <?php print(($async ? 'async' : '')) ?>></script>
<?php } ?>

<?php if ($url === '//genius.codes') { ?>
  <style>
    genius-referent {
      color: inherit !important;
    }

    genius-pre-annotation-prompt-inner {
      line-height: 1;
    }
  </style>
<?php } ?>
