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
    <?php if (isset($content['field_intro_text'])): ?>
      <div class="title-body supporting-text">
          <?php print render($content['field_intro_text']); ?>
      </div>
    <?php endif; ?>
  </div>
</div>
<ul class="tabs content-section-tabs">
  <?php
  if (!empty($content['field_tabbed_content'])) {
    foreach($content['field_tabbed_content'] as $key => $array){
      if (is_int($key)) {
        foreach ($array['entity']['paragraphs_item'] as $pid => $item) {
          if (is_int($pid)) {
            $title = $item['field_component_title'][0]['#markup'];
            $title_id = drupal_clean_css_identifier(drupal_html_class($title));
            print "<li data-tab=\"$title_id\" class=\"tabs__tab\"><a href=\"#$title_id\" class=\"tabs__tab-link\">$title</a></li>";
          }
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
      <?php if (isset($content['field_tabbed_content'])): ?>
        <?php print render($content['field_tabbed_content']); ?>
      <?php endif; ?>
    </div><!-- end .tabbed-info-wrapper -->
    <?php if (isset($content['field_components'])): ?>
      <div class="tab-components desktop-100" <?php print $content_attributes; ?>>
        <?php print render($content['field_components']); ?>
      </div>
    <?php endif; ?>
</article>
