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
        <li class="ft-ll-i"><a href="https://www.boston.gov/mayor" class="ft-ll-a lnk--white">Mayor Martin J. Walsh</a></li>
      </ul>
      <?php print $content; ?>
    </div>
  </footer>
<?php endif; ?>
