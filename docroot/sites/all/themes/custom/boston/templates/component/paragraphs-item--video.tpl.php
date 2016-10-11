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

<div class="<?php print $classes; ?>">
  <?php if (isset($content['field_short_title'])) : ?>
    <?php print render($content['field_short_title']); ?>
  <?php endif; ?>
  <div id="plyr__<?php print $id; ?>" data-video-id="<?php print trim(render($content['field_extra_info'])); ?>" class="plyr">
    <div id="plyr__<?php print $id; ?>">
      <?php print render($content['field_image']) ?>
      <div id="plyr__vid--<?php print $id; ?>" class="plyr__video"></div>
      <div class="plyr__overlay"></div>
      <div class="plyr__meta">
        <h2 class="section-header plyr__title"><?php print render($content['field_title']) ?></h2>
        <div class="plyr__credit"><?php print render($content['field_photo_credit']) ?></div>
        <div class="plyr__play"><img src="/<?php print drupal_get_path('theme', $GLOBALS['theme']); ?>/dist/img/icon-play.svg" alt="Play <?php print render($content['field_title']) ?>" /></div>
      </div>
    </div>
  </div>
</div>

<script>
  var vids = vids || {};
  vids['<?php print $id; ?>'] = {
    button: document.getElementById("plyr__<?php print $id; ?>")
  }

  vids['<?php print $id; ?>'].button.addEventListener('click', function() {
    vids['<?php print $id; ?>'].video = new YT.Player('plyr__vid--<?php print $id; ?>', {
      videoId: vids['<?php print $id; ?>'].button.getAttribute('data-video-id'),
      height: "100%",
      width: "100%",
      events: {
        'onReady': function(event) {
          event.target.playVideo();
        }
      }
    });

    vids['<?php print $id; ?>'].button.classList.toggle("plyr--isPlaying");
  });
</script>
