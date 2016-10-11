<?php
/**
 * @file
 * Hooks and code file for Boston.gov installation profile.
 */

/**
 * Implements hook_install_tasks().
 */
function hub_profile_install_tasks() {
  return array(
    'set_theme' => array(
      'display' => FALSE,
      'function' => '_hub_profile_set_theme',
    ),
  );
}

/**
 * Callback for set_theme install task.
 *
 * Enable and set the default theme to boston. Disable bartik. Ensure
 * seven is the default theme.
 *
 * @see hub_profile_install_tasks
 */
function _hub_profile_set_theme() {
  $enable = array(
    'theme_default' => 'boston_hub',
    'admin_theme' => 'boston_admin',
    'boston',
  );
  theme_enable($enable);
  variable_set('theme_default', 'boston_hub');
  variable_set('admin_theme', 'boston_admin');
  theme_disable(array('bartik'));
}
