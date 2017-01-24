<?php
/**
 * @file
 * hub_keyboard_shortcuts.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hub_keyboard_shortcuts_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access keyboard shortcuts'.
  $permissions['access keyboard shortcuts'] = array(
    'name' => 'access keyboard shortcuts',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'keyboard_shortcut',
  );

  // Exported permission: 'administer keyboard shortcuts'.
  $permissions['administer keyboard shortcuts'] = array(
    'name' => 'administer keyboard shortcuts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'keyboard_shortcut',
  );

  return $permissions;
}
