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
 * Implements hook_views_pre_view().
 */
function bos_core_views_pre_view(&$view) {
  $parent_node = node_load(trim($view->override_path, 'node\/'));
  $view->parent_node = $parent_node;
  if ($view->name == 'upcoming_events') {
    switch ($parent_node->type) {
      case 'place_profile':
        $view->set_display('block_3');
        break;

      case 'person_profile':
        $view->set_display('block_4');
        break;

      case 'department_profile':
        $view->set_display('block_2');
        break;

      case 'program_initiative_profile':
        $view->set_display('block_5');
        break;
    }
  }

  if ($view->name == 'news_announcements') {
    switch ($parent_node->type) {
      case 'place_profile':
        $view->set_display('places');
        break;

      case 'person_profile':
        $view->set_display('people');
        break;

      case 'department_profile':
        $view->set_display('departments');
        break;

      case 'program_initiative_profile':
        $view->set_display('programs');
        break;
    }
  }
}
