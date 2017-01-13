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
