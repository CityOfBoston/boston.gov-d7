<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 *
 * @see https://drupal.org/node/1728164
 */
?>

<article class="<?php print $classes; ?> clearfix node-<?php print $node->nid; ?> desktop-4-col tablet-3-col mobile-1-col"<?php print $attributes; ?>>
  <div class="topic-wrapper">
    <a href="<?php print $node_url; ?>">
      <div class="topic-highlight-area">
        <?php print render($content); ?>
        <div class="topic-details">
          <div class="grid-of-topics-label">
            Guide:
          </div>
          <div class="topic-listing-title">
            <?php print $title; ?>
          </div>
        </div>
      </div>
    </a>
  </div>
</article>
