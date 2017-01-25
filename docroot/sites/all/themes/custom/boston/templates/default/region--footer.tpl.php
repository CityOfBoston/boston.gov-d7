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
  <footer class="ft">
    <div class="ft-c">
      <ul class="ft-ll ft-ll--r">
        <li class="ft-ll-i"><a href="http://www.cityofboston.gov/311/" class="ft-ll-a lnk--yellow"><span class="ft-ll-311">BOS:311</span><span class="tablet--hidden"> - </span>Report an issue</a></li>
      </ul>
      <?php print $content; ?>
    </div>
  </footer>
<?php endif; ?>
