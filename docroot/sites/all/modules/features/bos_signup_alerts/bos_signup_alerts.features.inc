<?php
/**
 * @file
 * bos_signup_alerts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_signup_alerts_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_signup_alerts_paragraphs_info() {
  $items = array(
    'bos_signup_emergency_alerts' => array(
      'name' => 'Signup Emergency Alerts',
      'bundle' => 'bos_signup_emergency_alerts',
      'locked' => '1',
    ),
  );
  return $items;
}
