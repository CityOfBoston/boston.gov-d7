<?php
/**
 * @file
 * Output of links field for user action (appear in dropdown).
 */
?>

<div class="featured select-list-links">
  <select id="select-links" class="dropdown chosen-disable">
    <?php foreach ($items as $delta => $item): ?>
      <?php print render($item); ?>
    <?php endforeach; ?>
  </select>
</div>
