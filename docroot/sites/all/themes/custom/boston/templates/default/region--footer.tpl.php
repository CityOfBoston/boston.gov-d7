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
  <footer class="footer <?php print $classes; ?>" data-swiftype-index="false">
    <div class="container">
      <a class="icon-311-link" href="http://www.cityofboston.gov/311/" target="_blank">
        <span class="icon-311-reportbos">BOS-311 - </span><span class="icon-311-report">Report an issue</span>
        <div class="icon-311">
          <span class="icon-311-bos">BOS:</span>
          <span class="icon-311-number">311</span>
        </div>
      </a>
      <?php print $content; ?>
    </div>
  </footer>
<?php endif; ?>
