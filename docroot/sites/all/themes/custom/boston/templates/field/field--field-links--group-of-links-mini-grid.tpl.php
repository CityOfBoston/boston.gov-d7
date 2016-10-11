<?php

/**
 * @file
 * Template for mini grid links.
 */
?>

<?php foreach ($items as $delta => $item): ?>
  <div class="field-grid-links clearfix desktop-3-col clearfix tablet-2-col">
    <div class="grid-link">
      <?php print render($item); ?>
    </div>
  </div>
<?php endforeach; ?>
