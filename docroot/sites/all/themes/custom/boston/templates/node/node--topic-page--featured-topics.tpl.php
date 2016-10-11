<?php
/**
 * @file
 * Returns the HTML for a Topic node displayed via Featured Guides view mode.
 *
 * Complete documentation for this file is available online.
 *
 * @see https://drupal.org/node/1728164
 */
?>
<a href="<?php print url("node/{$node->nid}"); ?>">
<article class="<?php print $classes; ?> clearfix node-<?php print $node->nid; ?>"<?php print $attributes; ?>>
  <div class="color-background-layer <?php if (empty($content['field_thumbnail'])): ?>transparent<?php endif; ?>">
    <div class="float-left-xl badge"></div>
    <div class="float-left-xl title-block">
      <div class="label">Guide:</div>
      <h2><?php print $title; ?></h2>
    </div>
    <?php print render($content['links']); ?>
  </div>
</article>
</a>
