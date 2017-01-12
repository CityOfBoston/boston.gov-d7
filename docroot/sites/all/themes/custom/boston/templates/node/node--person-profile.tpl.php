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
<article class="<?php print $classes; ?> clearfix node-<?php print $node->nid; ?>"<?php print $attributes; ?>>
  <div class="person-profile-info-wrapper desktop-100 clearfix">
    <div class="column mobile-100 desktop-66-right">
      <h1 class="person-profile-display-name">
        <?php print $title; ?>
      </h1>
      <?php if (isset($content['field_position_title'])): ?>
        <div class="person-profile-position-title">
          <?php print render($content['field_position_title']); ?>
        </div>
      <?php endif; ?>
      <?php if (isset($content['field_description'])): ?>
        <div class="person-profile-bio squiggle-border-top">
          <?php print render($content['field_description']); ?>
        </div>
      <?php endif; ?>
    </div>
    <div class="column mobile-100 desktop-33-left sidebar">
      <?php if (isset($content['field_person_photo'])): ?>
        <div class="list-item person-profile-photo">
          <?php print render($content['field_person_photo']); ?>
        </div>
      <?php endif; ?>
      <?php if (isset($content['field_phone_number'])): ?>
        <div class="list-item">
          <?php print render($content['field_phone_number']); ?>
        </div>
      <?php endif; ?>
      <?php if (isset($content['field_email'])): ?>
        <div class="list-item">
          <?php print render($content['field_email']); ?>
        </div>
      <?php endif; ?>
      <?php if (isset($content['field_address'])): ?>
        <div class="list-item">
          <?php print render($content['field_address']); ?>
        </div>
      <?php endif; ?>
      <?php if (isset($content['field_year_elected'])): ?>
        <div class="list-item ">
          <?php print render($content['field_year_elected']); ?>
        </div>
      <?php endif; ?>
      <?php if (isset($content['field_political_party'])): ?>
        <div class="list-item">
          <?php print render($content['field_political_party']); ?>
        </div>
      <?php endif; ?>
      <?php if (isset($content['field_sidebar_components'])): ?>
        <?php print render($content['field_sidebar_components']); ?>
      <?php endif; ?>
    </div>
  </div>
  <?php if (isset($content['field_components'])): ?>
    <div class="person-profile-components desktop-100" <?php print $content_attributes; ?>>
      <?php print render($content['field_components']); ?>
    </div>
  <?php endif; ?>
</article>
