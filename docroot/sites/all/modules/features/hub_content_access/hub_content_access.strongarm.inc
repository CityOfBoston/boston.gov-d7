<?php
/**
 * @file
 * hub_content_access.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hub_content_access_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_article';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'per_node' => 1,
  );
  $export['content_access_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_department_profile';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'per_node' => 1,
  );
  $export['content_access_department_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_event';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'per_node' => 1,
  );
  $export['content_access_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_how_to';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'per_node' => 1,
  );
  $export['content_access_how_to'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_landing_page';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'per_node' => 1,
  );
  $export['content_access_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_listing_page';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'per_node' => 1,
  );
  $export['content_access_listing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_post';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'per_node' => 1,
  );
  $export['content_access_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_script_page';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'per_node' => 1,
  );
  $export['content_access_script_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_tabbed_content';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'per_node' => 1,
  );
  $export['content_access_tabbed_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_topic_page';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 5,
    ),
    'per_node' => 1,
  );
  $export['content_access_topic_page'] = $strongarm;

  return $export;
}
