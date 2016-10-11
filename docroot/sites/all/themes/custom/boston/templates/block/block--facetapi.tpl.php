<?php
/**
 * @file
 * Template for modal block.
 */
?>
<div class="<?php print $classes; ?>" <?php print $attributes; ?> id="<?php print $block_html_id; ?>">
  <div class="content">
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
        <h3 <?php print $title_attributes; ?>><?php print $title; ?></h3>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php print $content; ?>
  </div><!-- end .content -->
</div>
