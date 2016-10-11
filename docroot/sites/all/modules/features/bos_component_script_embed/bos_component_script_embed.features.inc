<?php
/**
 * @file
 * bos_component_script_embed.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_script_embed_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_script_embed_paragraphs_info() {
  $items = array(
    'script_embed' => array(
      'name' => 'Script Embed',
      'bundle' => 'script_embed',
      'locked' => '1',
    ),
  );
  return $items;
}
