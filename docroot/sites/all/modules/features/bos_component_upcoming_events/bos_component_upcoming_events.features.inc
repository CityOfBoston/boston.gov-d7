<?php
/**
 * @file
 * bos_component_upcoming_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_upcoming_events_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_upcoming_events_paragraphs_info() {
  $items = array(
    'upcoming_events' => array(
      'name' => 'Upcoming Events',
      'bundle' => 'upcoming_events',
      'locked' => '1',
    ),
  );
  return $items;
}
