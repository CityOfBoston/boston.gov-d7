<?php
/**
 * @file
 * hub_settings_apache_solr_local_dev.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hub_settings_apache_solr_local_dev_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_attachments_extract_using';
  $strongarm->value = 'tika';
  $export['apachesolr_attachments_extract_using'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_attachments_tika_jar';
  $strongarm->value = 'tika-app-1.11.jar';
  $export['apachesolr_attachments_tika_jar'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_attachments_tika_path';
  $strongarm->value = '/usr/local/Cellar/tika/1.11/libexec';
  $export['apachesolr_attachments_tika_path'] = $strongarm;

  return $export;
}
