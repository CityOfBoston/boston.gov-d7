<?php
/**
 * @file
 * Contains theme helper functions leveraged on Boston.gov site.
 */

/**
 * Helper function to unset the title on a page template.
 *
 * Useful for where you need to render the page title at a deeper level in the
 * rendering process, like within a node wrapper. Additionally, the hero image
 * overlay should be unset here as it is tightly coupled with unsetting the
 * title.
 *
 * @param array $variables
 *   Page variables.
 */
function _boston_unset_page_title(&$variables) {
  $hero_classes = array();
  $node_custom_page_templates = array(
    'person_profile',
    'program_initiative_profile',
    'place_profile',
    'procurement_advertisement',
    'public_notice',
    'event',
    'post',
    'script_page',
  );

  // If a listing page has a header text component, run these functions.
  if (isset($variables['node']) && ($variables['node']->type == 'listing_page')) {

    // If there IS a hero image and there IS a header component that IS NOT
    // a featured item, REMOVE default title and blue overlay.
    if (_boston_check_header_component($variables['node'], 'text')) {
      array_push($node_custom_page_templates, 'listing_page');
      $hero_classes[] = 'hero-image-wrapper--no-overlay';
    }

    // If there IS a hero image and there IS a header component that IS
    // a featured item, REMOVE title but DO NOT remove blue overlay.
    if (_boston_check_header_component($variables['node'], 'featured')) {
      array_push($node_custom_page_templates, 'listing_page');
    }

    // If there is NO hero image but there IS a header component that IS NOT
    // a featured item,REMOVE title (ignore blue overlay because no image).
    $check_image = FALSE;
    if (_boston_check_header_component($variables['node'], 'text', $check_image)) {
      array_push($node_custom_page_templates, 'listing_page');
    }

    // If there IS a hero image but NO header component of any type,
    // REMOVE TITLE but DO NOT remove blue overlay.
    if (!empty($variables['node']->field_intro_image) && empty($variables['node']->field_header_component)) {
      array_push($node_custom_page_templates, 'listing_page');
    }

  }

  if (isset($variables['node']) && in_array($variables['node']->type, $node_custom_page_templates)) {
    unset($variables['title']);
    // If we're unsetting the title on a node, then we don't want to place an
    // overlay on the hero image if it has one.
    // Unless it is a listing page whose overlay handling is handled above.
    if ($variables['node']->type !== 'listing_page') {
      $hero_classes[] = 'hero-image-wrapper--no-overlay';
    }
  }

  // Additionally, if a node in the $no-overlay array has no intro image
  // set on it, then it will display a default image which should not have
  // an overlay. Logic for adding the default image is handled elsewhere.
  $no_overlay = array(
    'how_to',
    'tabbed_content',
  );

  if (isset($variables['node']) && in_array($variables['node']->type, $no_overlay) && empty($variables['node']->field_intro_image)) {
    $hero_classes[] = 'hero-image-wrapper--no-overlay';
  }

  // Implode hero classes and set the variable.
  $variables['hero_classes'] = implode(' ', $hero_classes);
}

/**
 * Unset theme wrappers where needed.
 *
 * Typically this will be used to unset theme wrappers on fields where Fences
 * hasn't completely removed field formatting.
 *
 * @param array $variables
 *   Node variables.
 */
function _boston_unset_node_wrappers(&$variables) {
  if ($variables['view_mode'] == 'full') {
    $field_no_wrappers = array(
      'field_operation_hours',
      'field_sidebar_components',
    );
    foreach ($field_no_wrappers as $field) {
      if (isset($variables['content'][$field])) {
        unset($variables['content'][$field]['#theme_wrappers']);
      }
    }
  }
}

/**
 * Set the with_image_title variable if there is an image for this listing page.
 *
 * @param array $variables
 *   Node variables.
 */
function _boston_listing_page_title(&$variables) {
  // If there is a hero image and there is.
  if (!empty($variables['node']->field_intro_image) &&
        (empty($variables['node']->field_header_component) ||
        _boston_check_header_component($variables['node'], 'featured'))) {
    $variables['with_image_title'] = $variables['node']->title;
  }
}

/**
 * Checks what type of header component exists and returns a boolean.
 */
function _boston_check_header_component($node, $check_component = 'text', $check_image = TRUE) {
  $return_val = FALSE;
  if (!empty($node->field_header_component)) {
    $header = $node->field_header_component;
    $entity_array = entity_load('paragraphs_item', array($header[$node->language][0]['value']));
    if (!empty($entity_array)) {
      $entity = array_pop($entity_array);
      $featured_item = field_get_items('paragraphs_item', $entity, 'field_featured_item');
      if ($check_component == 'text' && empty($featured_item)) {
        $return_val = TRUE;
      }
      if ($check_component == 'featured' && !empty($featured_item)) {
        $return_val = TRUE;
      }
    }
  }
  if ($check_image) {
    // If there is no image return false.
    if (empty($node->field_intro_image)) {
      $return_val = FALSE;
    }
  }
  else {
    // If there is an image, return false.
    if (!empty($node->field_intro_image)) {
      $return_val = FALSE;
    }
  }
  return $return_val;
}
