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
<article class="cdp m-t500 g--1 g--3--sl"<?php print $attributes; ?>>
  <a href="<?php print $node_url; ?>" class="cdp-l d-b p-a300">
    <?php print render($content['field_person_photo']); ?>
    <div>
      <div class="cdp-t t--sans t--upper"><?php print $title; ?></div>
      <?php if (isset($content['field_position_title'])): ?>
        <div class="cdp-st t--subinfo t--g300"><?php print render($content['field_position_title']); ?></div>
      <?php endif; ?>
    </div>
  </a>
  <?php if (isset($content['field_preferred_contact'])) : ?>
    <?php if(!empty($content['field_preferred_contact']['#items'][0]['value'])) : ?>
      <?php if ($content['field_preferred_contact']['#items'][0]['value'] == 'phone'): ?>
        <?php if (isset($content['field_phone_number'])): ?>
          <?php print render($content['field_phone_number']); ?>
        <?php endif; ?>
      <?php endif; ?>
      <?php if ($content['field_preferred_contact']['#items'][0]['value'] == 'email'): ?>
        <?php if (isset($content['field_email'])): ?>
          <?php print render($content['field_email']); ?>
        <?php endif; ?>
      <?php endif; ?>
    <?php endif; ?>
  <?php endif; ?>
</article>
