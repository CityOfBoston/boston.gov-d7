<?php
/**
 * @file
 * Returns the HTML for a transaction page.
 *
 * Complete documentation for this file is available online.
 *
 * @see https://drupal.org/node/1728164
 */
hide($content['comments']);
hide($content['links']);
?>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix desktop-100"<?php print $attributes; ?>>

  <div class="department-info-wrapper desktop-100">
    <div class="column mobile-100 desktop-66-left">
      <h1 class="title"><?php print $title; ?></h1>
      <?php if (isset($content['field_intro_text'])): ?>
        <?php print render($content['field_intro_text']); ?>
      <?php endif; ?>
      <?php if (isset($content['field_embed_list'])): ?>
        <?php print render($content['field_embed_list']); ?>
      <?php endif; ?>
    </div>
    <div class="column mobile-100 desktop-33-right">
      <div class="contact-info">
        <?php if (isset($content['field_contact'])): ?>
          <div>Still have questions? Contact:</div>
          <?php print render($content['field_contact']); ?>
        <?php endif; ?>
      </div>
      <div class="pdf-link">
        <?php if((isset($content['field_link']))): ?>
          <?php print render($content['field_link']); ?>
        <?php endif; ?>
      </div>
      <?php if (isset($content['field_sidebar_components'])): ?>
        <div class="list-item">
          <?php print render($content['field_sidebar_components']); ?>
        </div>
      <?php endif; ?>
    </div>
    <div class="clearfix"></div>
  </div>
  <?php if (isset($content['field_components'])): ?>
    <div class="department-components desktop-100" <?php print $content_attributes; ?>>
      <?php print render($content['field_components']); ?>
    </div>
  <?php endif; ?>
</article>


