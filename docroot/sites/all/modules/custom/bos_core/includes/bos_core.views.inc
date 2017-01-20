<?php
/**
 * @file
 * Include file for views hooks.
 */

/**
 * Implements hook_views_plugins().
 */
function bos_core_views_plugins() {
  return array(
    'argument validator' => array(
      'first_page' => array(
        'title' => t('First page of results'),
        'handler' => 'bos_core_plugin_argument_validate_first_page',
        'path' => drupal_get_path('module', 'bos_core') . '/includes',
      ),
    ),
  );
}

/**
 * Implements hook_views_query_alter().
 */
function bos_core_views_query_alter(&$view, &$query) {
  if ($view->name == 'upcoming_events') {
    $query->orderby = array(
      array(
        'field' => 'CASE WHEN 
          field_data_field_public_notice_date.field_public_notice_date_value THEN
          field_data_field_public_notice_date.field_public_notice_date_value  ELSE
          field_data_field_event_dates.field_event_dates_value END',
        'direction' => 'ASC',
      )
    );
  }
}
