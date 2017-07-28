<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any.
 *
 * @ingroup views_templates
 */
?>
<div>
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <div class="g">
    <div class="g--4 m-b500">
      <?php if ($exposed): ?>
        <?php print $exposed; ?>
      <?php endif; ?>
    </div>

    <div class="g--8">
      <div class="p-b700">
        <?php if ($attachment_before): ?>
          <?php print $attachment_before; ?>
        <?php endif; ?>
        <?php if ($rows): ?>
          <?php print $rows; ?>
        <?php elseif ($empty): ?>
          <?php print $empty; ?>
        <?php endif; ?>
        <?php if ($pager): ?>
          <?php print $pager; ?>
        <?php endif; ?>
        <?php if ($attachment_after): ?>
          <?php print $attachment_after; ?>
        <?php endif; ?>
        <?php if ($more): ?>
          <?php print $more; ?>
        <?php endif; ?>
      </div>
    </div>
  </div>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>
