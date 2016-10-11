<?php
/**
 * @file
 * Template for modal block.
 */
?>
<div class="<?php print $classes; ?> modal-overlay modal-overlay-<?php print render($block->delta); ?>
"<?php print $attributes; ?> id="<?php print $block_html_id; ?>">
  <div class="container feedback-container">
    <div class="hidden-scroll">
    <div class="content">
      <?php print render($title_prefix); ?>
      <button class="close-button" title="Close"></button>
      <?php if ($title): ?>
        <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <div class="modal-body">
        <?php print $content; ?>
      </div><!-- end .modal-body -->
    </div><!-- end .content -->
    </div><!-- end .hidden-scroll -->
  </div><!-- end .container -->
</div><!-- end .modal-overlay -->
