<?php
/**
 * @file
 * bos_api_public_notice.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_api_public_notice_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cors_domains';
  $strongarm->value = array(
    'api/v1/*' => '<mirror>,localhost',
  );
  $export['cors_domains'] = $strongarm;

  return $export;
}
