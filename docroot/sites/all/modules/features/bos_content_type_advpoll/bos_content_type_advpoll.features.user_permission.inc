<?php
/**
 * @file
 * bos_content_type_advpoll.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bos_content_type_advpoll_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'vote on polls'.
  $permissions['vote on polls'] = array(
    'name' => 'vote on polls',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'advpoll',
  );

  return $permissions;
}
