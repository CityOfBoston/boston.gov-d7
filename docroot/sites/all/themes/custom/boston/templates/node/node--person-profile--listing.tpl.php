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
<article class="<?php print $classes; ?> node-<?php print $node->nid; ?>"<?php print $attributes; ?>>
  <div class="person-profile-listing-info-wrapper">
    <div class="column">
      <a href="<?php print $node_url; ?>">
        <div class="person-highlight-area">
          <?php if (isset($content['field_person_photo'])): ?>
            <div class="detail-list-item person-profile-photo-list">
              <?php print render($content['field_person_photo']); ?>
            </div>
          <?php endif; ?>
          <div class="person-text-data">
            <div class="person-name-and-title">
              <div class="person-profile-display-name">
                <?php print $title; ?>
              </div>
              <?php if (isset($content['field_position_title'])): ?>
                <div class="person-profile-position-title-list ">
                  <?php print render($content['field_position_title']); ?>
                </div>
              <?php endif; ?>
            </div>
          </div>
        </div>
      </a>
      <?php if (isset($content['field_preferred_contact'])) : ?>
        <div class="person-preferred-contact">
          <?php if(!empty($content['field_preferred_contact']['#items'][0]['value'])) : ?>
            <?php if ($content['field_preferred_contact']['#items'][0]['value'] == 'phone'): ?>
              <?php if (isset($content['field_phone_number'])): ?>
                <div class="detail-list-item person-profile-phone-number">
                  <div class="field-content">
                    <?php print render($content['field_phone_number']); ?>
                  </div>
                </div>
              <?php endif; ?>
            <?php endif; ?>
            <?php if ($content['field_preferred_contact']['#items'][0]['value'] == 'email'): ?>
              <?php if (isset($content['field_email'])): ?>
                <div class="detail-list-item person-profile-email">
                  <div class="field-content">
                    <?php print render($content['field_email']); ?>
                  </div>
                </div>
              <?php endif; ?>
            <?php endif; ?>
          <?php endif; ?>
        </div>
      <?php endif; ?>
</article>
