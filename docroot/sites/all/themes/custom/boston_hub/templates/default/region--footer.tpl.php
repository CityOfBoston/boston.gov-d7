<?php
/**
 * @file
 * Returns the HTML for the footer region.
 *
 * Complete documentation for this file is available online.
 *
 * @see https://drupal.org/node/1728140
 */
?>
<?php if ($content): ?>
  <footer class="footer <?php print $classes; ?>">
    <div class="container">
      <?php print $content; ?>
      <span class="footer-feature">
        Mayor Martin J. Walsh
      </span>
    </div>
  </footer>
<?php endif; ?>
