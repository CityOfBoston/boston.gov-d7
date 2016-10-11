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

<article class="<?php print $classes; ?> clearfix node-<?php print $node->nid; ?> desktop-3-col tablet-2-col mobile-1-col"<?php print $attributes; ?>>
  <div class="topic-wrapper">
    <div class="topic-highlight-area">
      <a href="<?php print $node_url; ?>" class="item-link" title="Go to <?php print $title; ?>"><?php print $title; ?></a>
      <div class="image-wrapper">
        <?php print render($content['field_intro_image']); ?>
      </div>
      <div class="topic-details">
        <div class="grid-of-topics-label">
          Guide:
        </div>
        <div class="topic-listing-title">
          <?php print $title; ?>
        </div>
      </div>
    </div>
    <div class="topic-link-area">
      <ul class="topics-links">
        <?php foreach($nav_links as $nav_link): ?>
          <li><?php print $nav_link; ?></li>
        <?php endforeach; ?>
        <?php if ($num_components) : ?>
          <li><a href="<?php print $node_url; ?>"> SEE <?php print $num_components; ?> MORE </a></li>
        <?php endif; ?>
      </ul>
    </div>
  </div>
</article>
