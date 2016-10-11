<?php
/**
 * @file
 * Field implementation for calendar listing view mode.
 */
?>
<?php foreach ($items as $item): ?>
  <div class="list-item">
    <?php print render($item); ?>
  </div>
<?php endforeach; ?>
