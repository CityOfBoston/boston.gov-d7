<?php
/**
 * @file
 * Returns the HTML for Panels Everywhere's messages pane.
 *
 * Complete documentation for this file is available online.
 *
 * @see https://drupal.org/node/2052511
 */
?>

<?php print $messages; ?>
<?php print render($tabs); ?>
<?php print $help; ?>

<?php if ($action_links): ?>
  <ul class="action-links"><?php print render($action_links); ?></ul>
<?php endif; ?>
