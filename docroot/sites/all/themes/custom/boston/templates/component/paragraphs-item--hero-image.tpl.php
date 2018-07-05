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
<style>
  .hro {
    background-image: url(<?php print $small_image ?>);
  }

  @media screen and (min-width: 768px) {
    .hro {
      background-image: url(<?php print $medium_image ?>);
    }
  }

  @media screen and (min-width: 1024px) {
    .hro {
      background-image: url(<?php print $large_image ?>);
    }
  }

  @media screen and (min-width: 1200px) {
    .hro {
      background-image: url(<?php print $xlarge_image ?>);
    }
  }
</style>

<div class="b b--fw">
  <div class="hro hro--t">
    <div class="hro-c">
      <?php if (isset($content['field_intro_text'])): ?>
        <?php print render($content['field_intro_text']); ?>
      <?php endif; ?>
      <h1 class="hro-t hro-t--l m-t000"><?php print render($content['field_header']); ?></h1>
      <?php if (isset($content['field_subheader'])): ?>
        <div class="hro-st hro-st--l hro-st--w"><?php print render($content['field_subheader']); ?></div>
      <?php endif; ?>
      <?php if (isset($content['field_grid_link'])): ?>
        <div class="hro-lnk"><?php print render($content['field_grid_link']); ?></div>
      <?php endif; ?>
    </div>
    <?php if (!isset($content['field_grid_link'])): ?>
      <div class="the-b the-b--c">
        <img src="<?php print $asset_url ?>/images/b-light.svg" alt="City of Boston" class="the-b-i">
      </div>
    <?php endif; ?>
  </div>
</div>
