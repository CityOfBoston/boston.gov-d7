<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="grid-wrapper">
    <?php foreach ($rows as $id => $row): ?>
      <div class="status-item-wrapper desktop-5-col tablet-3-col mobile-1-col">
      <?php print $row; ?>
      </div>
    <?php endforeach; ?>
</div>
