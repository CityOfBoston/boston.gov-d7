<?php
/**
 * @file
 * bos_dates.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_dates_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fe_date_custom_date_formats().
 */
function bos_dates_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['F j, Y'] = 'F j, Y';
  $custom_date_formats['M j'] = 'M j';
  $custom_date_formats['g:ia'] = 'g:ia';
  $custom_date_formats['l, F j'] = 'l, F j';
  $custom_date_formats['m-Y'] = 'm-Y';
  $custom_date_formats['n/j/y'] = 'n/j/y';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function bos_dates_date_format_types() {
  $format_types = array();
  // Exported date format type: boston_featured
  $format_types['boston_featured'] = 'Boston Featured';
  // Exported date format type: boston_short
  $format_types['boston_short'] = 'Boston Short';
  // Exported date format type: calendar_time
  $format_types['calendar_time'] = 'Calendar Time';
  // Exported date format type: file_directory_storage_date
  $format_types['file_directory_storage_date'] = 'File Directory Storage Date';
  // Exported date format type: normal_date
  $format_types['normal_date'] = 'Normal Date';
  // Exported date format type: status
  $format_types['status'] = 'Status';
  return $format_types;
}
