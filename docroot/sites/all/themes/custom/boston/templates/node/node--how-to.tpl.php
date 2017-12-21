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

<input id="tabMenuCTRL" type="checkbox" name="tab-menu-ctrl" class="tab-menu-ctrl" aria-hidden="true">

<?php if (isset($content['field_intro_image'])) { ?>
  <?php print render($content['field_intro_image']); ?>
<?php } ?>

<?php
$ctrlCount = 0;
foreach($content['field_how_to_tabs'] as $key => $array){
  if (is_int($key)) {
    foreach ($array['entity']['paragraphs_item'] as $pid => $item) {
      if (is_int($pid)) {
        $title_text = $item['field_how_to_title'][0]['#markup'];
        $title_id = drupal_clean_css_identifier(drupal_html_class($title_text));
        $checked = $ctrlCount == 0 ? 'checked' : '';

        print "<input id=\"tabCTRL$ctrlCount\" type=\"radio\" name=\"tab-ctrl\" class=\"tab-ctrl tab-ctrl-$ctrlCount\" data-href=\"#$title_id\" $checked aria-hidden=\"true\">";
        $ctrlCount++;
      }
    }
  }
}
?>

<div class="hro <?php if (isset($content['field_intro_image'])) { ?>hro--t<?php } else { ?>hro--d<?php } ?> hro--wh b--fw">
  <div class="hro-c b-c">
    <h1 class="hro-t"><?php print $title; ?></h1>
    <?php if (isset($content['body'])): ?>
      <div class="hro-st hro-st--l"><?php print render($content['body']); ?></div>
    <?php endif; ?>
  </div>
  <ul class="tab">
    <?php
    $count = 0;
    foreach($content['field_how_to_tabs'] as $key => $array){
      if (is_int($key)) {
        if ($ctrlCount > 1) {
          foreach ($array['entity']['paragraphs_item'] as $pid => $item) {
            if (is_int($pid)) {
              $title = $item['field_how_to_title'][0]['#markup'];
              $title_id = drupal_clean_css_identifier(drupal_html_class($title));
              print "<li class=\"tab-li tab-li-$count\">";
              print "<label for=\"tabMenuCTRL\" class=\"tab-li-m\" aria-hidden=\"true\">$title</label>";
              print "<label for=\"tabCTRL$count\" data-href=\"#$title_id\" class=\"tab-li-a tab-li-a-$count\">$title</label>";
              print "</li>";
              $count++;
            }
          }
        }
      }
    }
    ?>
    <li class="tab-li tab-li-close">
      <label for="tabMenuCTRL" class="tab-li-a tab-li-a--c" aria-hidden="true">Close</label>
    </li>
  </ul>
</div>

<article class="<?php print $classes; ?> clearfix node-<?php print $node->nid; ?> tab-pc p-t500"<?php print $attributes; ?>>
  <?php if (isset($content['field_updated_date'])): ?>
    <div class="brc-lu">
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
        <div class="list-item-wrapper">
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
