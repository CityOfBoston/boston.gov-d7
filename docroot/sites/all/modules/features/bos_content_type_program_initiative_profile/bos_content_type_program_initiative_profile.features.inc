<?php
/**
 * @file
 * bos_content_type_program_initiative_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_content_type_program_initiative_profile_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function bos_content_type_program_initiative_profile_node_info() {
  $items = array(
    'program_initiative_profile' => array(
      'name' => t('Program Initiative Profile'),
      'base' => 'node_content',
      'description' => t('A content type for creating programs and/or initiatives.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
