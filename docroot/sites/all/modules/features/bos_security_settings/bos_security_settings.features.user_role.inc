<?php
/**
 * @file
 * bos_security_settings.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function bos_security_settings_user_default_roles() {
  $roles = array();

  // Exported role: authenticated user.
  $roles['authenticated user'] = array(
    'name' => 'authenticated user',
    'weight' => 1,
  );

  return $roles;
}
