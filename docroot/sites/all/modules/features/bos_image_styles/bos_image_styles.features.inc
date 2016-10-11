<?php
/**
 * @file
 * bos_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function bos_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: featured_item_thumbnail.
  $styles['featured_item_thumbnail'] = array(
    'label' => 'Featured Item Thumbnail (625px)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 625,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: grid_card_image.
  $styles['grid_card_image'] = array(
    'label' => 'Grid Card Image',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 720,
          'height' => 300,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: med-large_square_360x360.
  $styles['med-large_square_360x360'] = array(
    'label' => 'Med-Large Square (360x360)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 360,
          'height' => 360,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: med_small_square__200x200_.
  $styles['med_small_square__200x200_'] = array(
    'label' => 'Med Small Square (200x200)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: medium_square.
  $styles['medium_square'] = array(
    'label' => 'Medium Square (220x220)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 220,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: news-item-thumb.
  $styles['news-item-thumb'] = array(
    'label' => 'news-item-thumb',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 725,
          'height' => 725,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rep_wide_2000x700custom_boston_desktop_1x.
  $styles['rep_wide_2000x700custom_boston_desktop_1x'] = array(
    'label' => 'rep_wide_2000x700custom_boston_desktop_1x',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1439,
          'height' => 700,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rep_wide_2000x700custom_boston_desktop_2x.
  $styles['rep_wide_2000x700custom_boston_desktop_2x'] = array(
    'label' => 'rep_wide_2000x700custom_boston_desktop_2x',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2878,
          'height' => 1400,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rep_wide_2000x700custom_boston_mobile_1x.
  $styles['rep_wide_2000x700custom_boston_mobile_1x'] = array(
    'label' => 'rep_wide_2000x700custom_boston_mobile_1x',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 370,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rep_wide_2000x700custom_boston_mobile_2x.
  $styles['rep_wide_2000x700custom_boston_mobile_2x'] = array(
    'label' => 'rep_wide_2000x700custom_boston_mobile_2x',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 960,
          'height' => 740,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rep_wide_2000x700custom_boston_tablet_1x.
  $styles['rep_wide_2000x700custom_boston_tablet_1x'] = array(
    'label' => 'rep_wide_2000x700custom_boston_tablet_1x',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 768,
          'height' => 530,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rep_wide_2000x700custom_boston_tablet_2x.
  $styles['rep_wide_2000x700custom_boston_tablet_2x'] = array(
    'label' => 'rep_wide_2000x700custom_boston_tablet_2x',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2878,
          'height' => 1400,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rep_wide_2000x700custom_boston_wide_1x.
  $styles['rep_wide_2000x700custom_boston_wide_1x'] = array(
    'label' => 'rep_wide_2000x700custom_boston_wide_1x',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2000,
          'height' => 700,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_wide_2000x460custom_boston_desktop_1x.
  $styles['resp_wide_2000x460custom_boston_desktop_1x'] = array(
    'label' => 'resp_wide_2000x460custom_boston_desktop_1x',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1439,
          'height' => 460,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_wide_2000x460custom_boston_desktop_2x.
  $styles['resp_wide_2000x460custom_boston_desktop_2x'] = array(
    'label' => 'resp_wide_2000x460custom_boston_desktop_2x',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2878,
          'height' => 920,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_wide_2000x460custom_boston_mobile_1x.
  $styles['resp_wide_2000x460custom_boston_mobile_1x'] = array(
    'label' => 'resp_wide_2000x460custom_boston_mobile_1x',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 270,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_wide_2000x460custom_boston_mobile_2x.
  $styles['resp_wide_2000x460custom_boston_mobile_2x'] = array(
    'label' => 'resp_wide_2000x460custom_boston_mobile_2x',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 960,
          'height' => 540,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_wide_2000x460custom_boston_tablet_1x.
  $styles['resp_wide_2000x460custom_boston_tablet_1x'] = array(
    'label' => 'resp_wide_2000x460custom_boston_tablet_1x',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 768,
          'height' => 400,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_wide_2000x460custom_boston_tablet_2x.
  $styles['resp_wide_2000x460custom_boston_tablet_2x'] = array(
    'label' => 'resp_wide_2000x460custom_boston_tablet_2x',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1536,
          'height' => 800,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_wide_2000x460custom_boston_wide_1x.
  $styles['resp_wide_2000x460custom_boston_wide_1x'] = array(
    'label' => 'resp_wide_2000x460custom_boston_wide_1x',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2000,
          'height' => 460,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_wide_2000x800custom_boston_desktop_1x.
  $styles['resp_wide_2000x800custom_boston_desktop_1x'] = array(
    'label' => 'resp_wide_2000x800custom_boston_desktop_1x',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1439,
          'height' => 800,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_wide_2000x800custom_boston_desktop_2x.
  $styles['resp_wide_2000x800custom_boston_desktop_2x'] = array(
    'label' => 'resp_wide_2000x800custom_boston_desktop_2x',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2878,
          'height' => 1600,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_wide_2000x800custom_boston_mobile_1x.
  $styles['resp_wide_2000x800custom_boston_mobile_1x'] = array(
    'label' => 'resp_wide_2000x800custom_boston_mobile_1x',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 250,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_wide_2000x800custom_boston_mobile_2x.
  $styles['resp_wide_2000x800custom_boston_mobile_2x'] = array(
    'label' => 'resp_wide_2000x800custom_boston_mobile_2x',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 960,
          'height' => 500,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_wide_2000x800custom_boston_tablet_1x.
  $styles['resp_wide_2000x800custom_boston_tablet_1x'] = array(
    'label' => 'resp_wide_2000x800custom_boston_tablet_1x',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 767,
          'height' => 420,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_wide_2000x800custom_boston_tablet_2x.
  $styles['resp_wide_2000x800custom_boston_tablet_2x'] = array(
    'label' => 'resp_wide_2000x800custom_boston_tablet_2x',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1534,
          'height' => 840,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_wide_2000x800custom_boston_wide_1x.
  $styles['resp_wide_2000x800custom_boston_wide_1x'] = array(
    'label' => 'resp_wide_2000x800custom_boston_wide_1x',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2000,
          'height' => 800,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: topic_header_image.
  $styles['topic_header_image'] = array(
    'label' => 'Topic Header Image',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 2000,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 2000,
          'height' => 460,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: topic_thumbnail.
  $styles['topic_thumbnail'] = array(
    'label' => 'Topic Thumbnail',
    'effects' => array(
      2 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 500,
          'height' => 500,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: wide_2000x460.
  $styles['wide_2000x460'] = array(
    'label' => 'wide_2000x460',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2000,
          'height' => 460,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: wide_2000x700.
  $styles['wide_2000x700'] = array(
    'label' => 'wide_2000x700',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2000,
          'height' => 700,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: wide_2000x800.
  $styles['wide_2000x800'] = array(
    'label' => 'wide_2000x800',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2000,
          'height' => 800,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
