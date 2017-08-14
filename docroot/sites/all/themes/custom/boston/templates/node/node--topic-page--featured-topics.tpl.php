<?php
/**
 * @file
 * Returns the HTML for a Topic node displayed via Featured Guides view mode.
 *
 * Complete documentation for this file is available online.
 *
 * @see https://drupal.org/node/1728164
 */

 $guide_themes = array(
   'ob',
   'cb',
   'r',
   'cb',
   'cb',
   'r',
   'cb',
   'ob',
   'ob',
   'cb',
   'r',
   'cb',
   'cb',
   'r',
   'cb',
   'ob',
 );

 if (!isset($GLOBALS["featured_guide_count"])) {
   $GLOBALS["featured_guide_count"] = 0;
 } else {
   $GLOBALS["featured_guide_count"]++;
 }

 $guide_index = $GLOBALS["featured_guide_count"] + 1;
 $guide_theme = $guide_themes[$GLOBALS["featured_guide_count"]];

?>
<a href="<?php print url("node/{$node->nid}"); ?>" class="cdfg cdfg--<?php print $guide_theme ?>" style="background-image: url(<?php print render($content['field_thumbnail']); ?>)">
  <div class="cdfg-c">
    <div class="cdfg-i"><span><?php print $guide_index ?></span></div>
    <div class="cdfg-ic">
      <div class="cdfg-d">Guide:</div>
      <div class="cdfg-t"><?php print $title; ?></div>
    </div>
  </div>
</a>
