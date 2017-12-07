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

<div class="b b--fw">
  <div id="vid_<?php print $id; ?>" class="vid" style="background-image: url(<?php print render($content['field_image']) ?>)" data-vid-id="<?php print trim(render($content['field_extra_info'])) ?>" data-vid-channel="<?php print trim(render($content['field_is_channel'])) ?>">
    <div class="vid-c">
      <div class="vid-ci">
        <div class="b-c">
          <div class="vid-t"><?php print render($content['field_component_title']) ?></div>
          <?php if (isset($content['field_contact'])) : ?>
            <div class="vid-st m-t300">Credit: <?php print_r($field_contact[0]['entity']->name) ?></div>
          <?php endif; ?>
          <div class="vid-ic m-t300">
            <button class="vid-cta">
              <img src="<?php print $asset_url ?>/images/global/icons/play.svg" alt="Play Video" height="97" width="97" class="vid-cta-i" />
            </button>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
