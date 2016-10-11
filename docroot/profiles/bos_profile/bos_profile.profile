<?php
/**
 * @file
 * Hooks and code file for Boston.gov installation profile.
 */

/**
 * Implements hook_install_tasks().
 */
function bos_profile_install_tasks() {
  return array(
    'set_theme' => array(
      'display' => FALSE,
      'function' => '_bos_profile_set_theme',
    ),
  );
}


/**
 * Callback for set_theme install task.
 *
 * Enable and set the default theme to boston_public. Enable boston theme. Disable bartik.
 *
 * @see bos_profile_install_tasks
 */
function _bos_profile_set_theme() {
  $enable = array(
    'theme_default' => 'boston_public',
    'admin_theme' => 'boston_admin',
    'boston',
  );
  theme_enable($enable);
  variable_set('theme_default', 'boston_public');
  variable_set('admin_theme', 'boston_admin');
  foreach ($enable as $var => $theme) {
    if (!is_numeric($var)) {
      variable_set($var, $theme);
    }
  }
  theme_disable(array('bartik'));
}
