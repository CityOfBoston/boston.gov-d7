<?php
/**
 * @file
 * Migrate configuration.
 */

/**
 * Implements hook_migrate_api().
 */
function hub_migration_migrate_api() {
  return array(
    'api' => 2,
    'groups' => array(
      'hub-user' => array(
        'title' => 'Hub User',
        'source_file' => variable_get('hub_migration_file', FALSE),
      ),
    ),
    'migrations' => array(
      'User' => array(
        'class_name' => 'Drupal\\hub_migration\\User',
        'description' => 'Users Migration',
        'group_name' => 'hub-user',
      ),
      'Profile' => array(
        'class_name' => 'Drupal\\hub_migration\\Profile',
        'description' => 'Profiles Migration',
        'group_name' => 'hub-user',
      ),
    ),
  );
}
