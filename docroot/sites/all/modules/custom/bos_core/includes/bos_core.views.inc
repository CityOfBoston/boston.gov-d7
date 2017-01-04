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
 * Implements hook_views_query_alter();
 */
function bos_core_views_query_alter(&$view, &$query) {
  if ($view->name == 'upcoming_events') {
    $parent_node = node_load(trim($view->override_path, 'node\/'));
    if ($parent_node->type == 'person_profile') {
      $view->set_items_per_page(2);
    } else if ($parent_node->type == 'place_profile') {
      $query->where[0]['conditions'][0]['field'] = 'node_field_data_field_related_content.nid != :node_nid';  
      $view->set_items_per_page(5);
    } else {
    $view->set_items_per_page(3);
    $view->parent_content_type = $parent_node->type;;
    $view->fun_query_time = $query->where;
    }
  }
}
