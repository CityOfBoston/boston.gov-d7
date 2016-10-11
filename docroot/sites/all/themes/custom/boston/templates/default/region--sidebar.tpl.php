<?php
/**
 * @file
 * Returns HTML for a sidebar region.
 *
 * Complete documentation for this file is available online.
 *
 * @see https://drupal.org/node/1728118
 */
?>
<?php if ($content): ?>
  <section class="<?php print $classes; ?>">
    <?php print $content; ?>
  </section>
<?php endif; ?>
