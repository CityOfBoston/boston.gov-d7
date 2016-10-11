<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h2 class="listing-group-title"><?php print $title; ?></h2>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
	<?php if ($classes_array[$id]) : ?><div class="<?php print $classes_array[$id]; ?>"><?php endif; ?>
	  <?php print $row; ?>
	<?php if ($classes_array[$id]) : ?></div><?php endif; ?>
<?php endforeach; ?>
