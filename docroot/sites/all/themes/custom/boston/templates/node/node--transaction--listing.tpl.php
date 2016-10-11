<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 *
 * @see https://drupal.org/node/1728164
 */
?>

<article class="<?php print $classes; ?> clearfix desktop-1-col"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>

    <div class="list-link tablet-25-left">
      <?php print render($content['field_link']); ?>
    </div>

    <div class="list-description tablet-75-right">
      <?php  print render($content['field_description']); ?>
    </div>

  </div>
</article>
