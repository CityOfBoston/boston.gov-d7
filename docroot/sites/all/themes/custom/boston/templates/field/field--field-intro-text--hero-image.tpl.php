<?php
/**
 * @file
 * Default implementation of field intro text.
 */
?>

<?php if (isset($short_title)) { ?>
  <a name="<?php print $short_title_link; ?>"
     data-text="<?php print $short_title ?>" class="subnav-anchor"></a>
<?php } ?>
<div class="hro-i"><?php print render($items); ?></div>
