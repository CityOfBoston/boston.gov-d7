<?php

/**
 * @file
 * Template for mini grid links.
 */
?>

<?php foreach ($items as $delta => $item): ?>
  <div><?php print render($item); ?></div>
<?php endforeach; ?>
