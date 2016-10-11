<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php

?>
  <div class="<?php print $classes; ?> clearfix applications-grid-of-links"<?php print $attributes; ?>>

  <?php foreach ($rows as $id => $row): ?>
    <div class="<?php print $classes; ?> clearfix tablet-2-col desktop-3-col field-grid-links"<?php print $attributes; ?>>
      <div class="content"<?php print $content_attributes; ?>>
        <div class="grid-link">
        <?php print $row; ?>
      </div>
    </div>
      </div>
  <?php endforeach; ?>
</div>
