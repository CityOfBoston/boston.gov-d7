<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="g p-b500">
  <?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
  <?php endforeach; ?>
</div>
