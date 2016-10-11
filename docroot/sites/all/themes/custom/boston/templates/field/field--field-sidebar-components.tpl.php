<?php
/**
 * @file
 * Default implementation for field_sidebar_components field render.
 */
?>
<?php foreach ($items as $item): ?>
  <div class="list-item">
    <?php print render($item); ?>
  </div>
<?php endforeach; ?>
