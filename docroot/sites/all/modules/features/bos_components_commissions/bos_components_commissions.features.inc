<?php
/**
 * @file
 * bos_components_commissions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_components_commissions_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_components_commissions_paragraphs_info() {
  $items = array(
    'commission_contact_info' => array(
      'name' => 'Commission Contact Info',
      'bundle' => 'commission_contact_info',
      'locked' => '1',
    ),
    'commission_members' => array(
      'name' => 'Commission Members',
      'bundle' => 'commission_members',
      'locked' => '1',
    ),
    'commission_summary' => array(
      'name' => 'Commission Summary',
      'bundle' => 'commission_summary',
      'locked' => '1',
    ),
  );
  return $items;
}
