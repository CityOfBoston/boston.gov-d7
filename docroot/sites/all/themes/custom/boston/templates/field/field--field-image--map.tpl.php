<?php
/**
 * @file
 * Copied from the image template for use as the maps background.
 */
 $image_uri = $items[0]['#item']['uri'];
 $xlarge_image = image_style_url('rep_wide_2000x700custom_boston_desktop_2x', $image_uri);
 $large_image = image_style_url('rep_wide_2000x700custom_boston_desktop_1x', $image_uri);
 $medium_image = image_style_url('rep_wide_2000x700custom_boston_tablet_2x', $image_uri);
 $small_image = image_style_url('rep_wide_2000x700custom_boston_mobile_2x', $image_uri);
?>

<style>
  @media screen and (max-width: 767px) {
    .ph-p--<?php print $photo_id; ?> {
      background-image: url(<?php print $small_image ?>);
    }
  }

  @media screen and (min-width: 768px) {
    .ph-p--<?php print $photo_id; ?> {
      background-image: url(<?php print $medium_image ?>);
    }
  }

  @media screen and (min-width: 1024px) {
    .ph-p--<?php print $photo_id; ?> {
      background-image: url(<?php print $large_image ?>);
    }
  }

  @media screen and (min-width: 1200px) {
    .ph-p--<?php print $photo_id; ?> {
      background-image: url(<?php print $xlarge_image ?>);
    }
  }
</style>
