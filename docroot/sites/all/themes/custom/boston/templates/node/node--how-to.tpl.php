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

<div class="title-wrapper">
  <div class="title-inner-wrapper">
    <h1 class="title-with-hero"><?php print $title; ?></h1>
    <div class="title-body supporting-text">
      <?php if (isset($content['body'])): ?>
        <?php print render($content['body']); ?>
      <?php endif; ?>
    </div>
  </div>
</div>
<ul class="how-to-tabs tabs content-section-tabs">
  <?php
  foreach($content['field_how_to_tabs'] as $key => $array){
    if (is_int($key)) {
      foreach ($array['entity']['paragraphs_item'] as $pid => $item) {
        if (is_int($pid)) {
          $title = $item['field_how_to_title'][0]['#markup'];
          $title_id = drupal_clean_css_identifier(drupal_html_class($title));
          print "<li data-tab=\"$title_id\" class=\"tabs__tab\"><a href=\"#$title_id\" class=\"tabs__tab-link\">$title</a></li>";
        }
      }
    }
  }
  ?>
</ul>
<article class="<?php print $classes; ?> clearfix node-<?php print $node->nid; ?>"<?php print $attributes; ?>>
  <?php if (isset($content['field_updated_date'])): ?>
    <div class="breadcrumb-last-updated">
      Last updated:<?php print render($content['field_updated_date']); ?>
    </div>
  <?php endif; ?>
    <div class="tabbed-info-wrapper desktop-100">
      <div class="column mobile-100 desktop-66-left">
        <?php if (isset($content['field_how_to_tabs'])): ?>
          <?php print render($content['field_how_to_tabs']); ?>
        <?php endif; ?>
      </div><!-- end .desktop-66-left -->
      <div class="column mobile-100 desktop-33-right">
        <?php if (isset($content['field_payment_info'])): ?>
        <div class="list-item">
          <?php print render($content['field_payment_info']); ?>
        </div>
        <?php endif; ?>
        <?php if (isset($content['field_links'])): ?>
        <div class="list-item">
          <?php print render($content['field_links']); ?>
        </div>
        <?php endif; ?>
        <?php if (isset($content['field_need_to_know'])): ?>
        <div class="list-item">
          <?php print render($content['field_need_to_know']); ?>
        </div>
        <?php endif; ?>
        <?php if (isset($content['field_contact'])): ?>
        <div class="contact-info">
          <?php print render($content['field_contact']); ?>
        </div>
        <?php endif; ?>
        <?php if (isset($content['field_sidebar_components'])): ?>
        <div class="list-item">
          <?php print render($content['field_sidebar_components']); ?>
        </div>
        <?php endif; ?>
      </div><!-- end .desktop-33-right -->
      <div class="clearfix"></div>
    </div><!-- end .tabbed-info-wrapper -->
    <?php if (isset($content['field_components'])): ?>
      <div class="tab-components desktop-100" <?php print $content_attributes; ?>>
        <?php print render($content['field_components']); ?>
      </div>
    <?php endif; ?>
</article>
