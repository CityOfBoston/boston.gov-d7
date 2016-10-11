<?php

/**
 * @file - Contians a commen set of core Acquia drush commands that provide
 * helpful functionality for most Drupal installations.
 *
 * Troubleshooting - If these drush commands are not firing when executed,
 * be sure it is included in your /sites/all/drush/ directory and run
 * `drush cc drush` so that Drush is aware of the file.
 */

/**
 * Implementation of hook_drush_command().
 */
function acquia_drush_command() {
  
  // Rebuild node access permissions for all nodes in the site.
  $items['acquia-rebuild-node-access'] = array(
    'description' => "Rebuild node access.",
    'examples' => array(
      'drush acquia-rebuild-node-access',
    ),
    'callback' => 'drush_acquia_rebuild_node_access',
  );

  // Will read permissions.settings.php file and rebuild all permissions
  // based on the values contained within that file.
  $items['acquia-reset-permissions'] = array(
    'description' => "Reset user permissions based on the mappings found in acquia_permissions_map().",
    'examples' => array(
      'drush acquia-reset-permissions',
    ),
    'callback' => 'drush_acquia_reset_permissions',
  );

  // This is the debug version of reset permissions that will throw errors for
  // any individual permission that cannot be set.
  $items['debug-acquia-reset-permissions'] = array(
    'description' => "Debug version of Reset user permissions based on the mappings found in acquia_permissions_map().",
    'examples' => array(
      'drush debug_acquia-reset-permissions',
    ),
    'callback' => 'drush_debug_acquia_reset_permissions',
  );

  // Used to generate an array that will be pasted into permissions.settings.php
  // and contains all of the roles and their permissions on the site.
  $items['acquia-generate-permissions-string'] = array(
    'description' => "Generate a string that can be used to replace the array acquia_permissions_map().",
    'examples' => array(
      'drush acquia-generate-permissions-string',
    ),
    'callback' => 'drush_acquia_generate_permissions_string',
  );

  // A custom updb function.
  $items['acquia-updb'] = array(
    'description' => "A copy of `drush updb` without a cache clear.",
    'callback' => 'drush_acquia_updb',
  );

  // Quick helper function that disables usual remote modules not required for
  // local opporation and sets local file systems to defaults, etc. Great command
  // when you sync you local DB from a remote DB.
  $items['acquia-reset-local'] = array(
    'description' => "Resets values for local development after a production or staging sync",
    'callback' => 'drush_acquia_reset_local',
  );

  return $items;
}

/**
 * Drush callback that resets all permissions with the roles and permissions
 * found in permissions.settings.php (assuming it is available on the site)
 *
 * @see acquia_permissions_map() in permissions.settings.php
 */
function drush_acquia_reset_permissions() {
  // Throw error if acquia_permissions_map() has not yet been configured.
  if (!function_exists("acquia_permissions_map")) {
    drush_print("Error! Have you run acquia-generate-permissions-string and added the values to acquia_permissions_map() in permissions.settings.php?");
    exit;
  }

  drush_print(dt('THIS ACTION IS DESTRUCTIVE TO EXISTING PERMISSIONS SETTINGS.'));
  if (!drush_confirm(dt('Are you sure you want to reset user permissions?'))) {
    return;
  }

  // Only administrators can create accounts (registration happens outside of
  // Drupal).
  variable_set('user_register', USER_REGISTER_ADMINISTRATORS_ONLY);
  $permissions_map = acquia_permissions_map();

  // Attempt to load each role in the permissions map so that we can create any
  // new roles, if needed.
  foreach ($permissions_map as $role_name => $permissions) {
    $role = user_role_load_by_name($role_name);
    if (!$role || empty($role->rid)) {
      $role = new stdClass();
      $role->name = $role_name;
      user_role_save($role);
    }

    foreach ($permissions as $key => $permission){
      // Account for taxonomy permissions referencing a VID.
      if ( strpos($permission, 'edit terms in ') !== FALSE || strpos($permission, 'delete terms in ') !== FALSE) {
        preg_match("/(?<=\040)([^\s]+?)$/", trim($permission), $machine_id);
        $machine_name = $machine_id[0];
        if ($voc = taxonomy_vocabulary_machine_name_load($machine_name)) {
          $permissions_map[$role_name][$key] = str_replace($machine_name, $voc->vid, $permission);
        }
      }
    }
  }

  // Loops through roles and save permissions based on configuration in
  // acquia_permissions_map().
  $roles = user_roles();
  foreach ($roles as $rid => $role_name) {
    if (strtolower($role_name) == 'administrator') {
      // Grant all permissions to the administrator role.
      user_role_grant_permissions($rid, array_keys(module_invoke_all('permission')));
      // Set this as the administrator role.
      variable_set('user_admin_role', $rid);
    }
    else {
      // Clear existing and re-grant new permissions.
      db_delete('role_permission')->condition('rid', $rid)->execute();
      user_role_grant_permissions($rid, $permissions_map[$role_name]);
    }
    drush_print(dt('Reset @role permissions', array('@role' => $role_name)));
  }
}

/**
 * Drush callback that resets all permissions with the roles and permissions
 * found in permissions.settings.php (assuming it is available on the site)
 *
 * @see acquia_permissions_map() in permissions.settings.php
 */
function drush_debug_acquia_reset_permissions() {
  // Throw error if acquia_permissions_map() has not yet been configured.
  if (!function_exists("acquia_permissions_map")) {
    drush_print("Error! Have you run acquia-generate-permissions-string and added the values to acquia_permissions_map() in permissions.settings.php?");
    exit;
  }

  drush_print(dt('THIS ACTION IS DESTRUCTIVE TO EXISTING PERMISSIONS SETTINGS.'));
  if (!drush_confirm(dt('Are you sure you want to reset user permissions?'))) {
    return;
  }

  // Only administrators can create accounts (registration happens outside of
  // Drupal).
  variable_set('user_register', USER_REGISTER_ADMINISTRATORS_ONLY);
  $permissions_map = acquia_permissions_map();

  // Attempt to load each role in the permissions map so that we can create any
  // new roles, if needed.
  foreach ($permissions_map as $role_name => $permissions) {
    $role = user_role_load_by_name($role_name);
    if (!$role || empty($role->rid)) {
      $role = new stdClass();
      $role->name = $role_name;
      user_role_save($role);
    }

    foreach ($permissions as $key => $permission){
      // Account for taxonomy permissions referencing a VID.
      if ( strpos($permission, 'edit terms in ') !== FALSE || strpos($permission, 'delete terms in ') !== FALSE) {
        preg_match("/(?<=\040)([^\s]+?)$/", trim($permission), $machine_id);
        $machine_name = $machine_id[0];
        if ($voc = taxonomy_vocabulary_machine_name_load($machine_name)) {
          $permissions_map[$role_name][$key] = str_replace($machine_name, $voc->vid, $permission);
        }
      }
    }
  }

  // Loops through roles and save permissions based on configuration in
  // acquia_permissions_map().
  $roles = user_roles();
  foreach ($roles as $rid => $role_name) {
    if (strtolower($role_name) == 'administrator') {
      // Grant all permissions to the administrator role.
      user_role_grant_permissions($rid, array_keys(module_invoke_all('permission')));
      // Set this as the administrator role.
      variable_set('user_admin_role', $rid);
    }
    else {

        // Clear existing and re-grant new permissions.
        db_delete('role_permission')->condition('rid', $rid)->execute();
        foreach ($permissions_map[$role_name] as $perm) {
          //user_role_grant_permissions($rid, $permissions_map[$role_name]);
          try {
          user_role_grant_permissions($rid, array($perm));
          } catch (Exception $e){
            drush_print(dt('-- ERROR -- Could not grant role permission for role ' . $role_name . ' for :' . $perm));
          }
        }

    }
    drush_print(dt('Reset @role permissions', array('@role' => $role_name)));
  }
}

/**
 * Drush callback that generates an array of all roles and permissions to be copied
 * and pasted in permissions.settings.php, specifically, in acquia_permissions_map() function.
 *
 * @example - drush acquia_generate_permissions_string | pbcopy
 */
function drush_acquia_generate_permissions_string() {
  $lines = array();

  $roles = user_roles();
  foreach ($roles as $rid => $role_name) {
    if (strtolower($role_name) == 'administrator') {
      unset($roles[$rid]);
    }
  }

  // Load the current site permissions
  $permissions = user_role_permissions($roles);

  // Load all permission modules (used in user.module and checked here first)
  $modules = user_permission_get_modules();

  $lines[] = "  return array(";
  foreach ($permissions as $rid => $values) {
    $role_name = $roles[$rid];
    // Add the role name as a comment.
    $lines[] = "    // " . ucfirst($role_name) . " role permissions.";
    $lines[] = "    '$role_name' => array(";
    foreach ($values as $permission => $enabled) {
      if (!empty($modules[$permission])) {
        // Account for taxonomy permissions referencing a VID.
        if ( strpos($permission, 'edit terms in ') !== FALSE || strpos($permission, 'delete terms in ') !== FALSE) {
          preg_match("/(?<=\040)([^\s]+?)$/", trim($permission), $voc_id);
          $vid = $voc_id[0];
          if (is_numeric($vid)) {
            if (function_exists('taxonomy_vocabulary_load')) {
              $voc = taxonomy_vocabulary_load($vid);
              $permission = str_replace($vid, $voc->machine_name, $permission);
            }
          }
        }
        $lines[] = "      '$permission',";
      }
    }
    $lines[] = "    ),";
  }
  $lines[] = "  );";

  $output = implode("\n", $lines);
  drush_print($output);
}


/**
 * Drush callback that rebuilds node access for all nodes in the site.
 */
function drush_acquia_rebuild_node_access() {
  $start = time();
  $row = 0;
  $max_nid = db_query("SELECT MAX(nid) FROM {node}")->fetchField();
  $current_nid = 0;
  $chunk_size = drush_get_option('chunk-size', 100);

  drush_print(dt('Rebuilding content access permissions'));

  while ($current_nid <= $max_nid) {
    $query = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('n.nid', $current_nid, '>')
      ->orderBy('n.nid')
      ->range(0, $chunk_size);
    $nids = $query->execute()->fetchCol();
    $nodes = node_load_multiple($nids, array(), TRUE);

    foreach ($nodes as $nid => $node) {
      if (!empty($node)) {
        node_access_acquire_grants($node);
      }
      $current_nid = $nid;

      // Log progress
      $row++;
      if ($row %1000 == 0) {
        drush_print('.', 0, NULL, FALSE);
      }
    }

    if ($current_nid == $max_nid) {
      break;
    }
  }

  $end = time();
  $throughput = round($row / ($end - $start));

  // Clear line.
  drush_print();
  // Output metrics.
  drush_print("Throughput: $throughput / sec");

}

/**
 * Drush callback for running the custom version of drush updb.
 */
function drush_acquia_updb() {
  if (drush_get_context('DRUSH_SIMULATE')) {
    drush_log(dt('updatedb command does not support --simulate option.'), 'ok');
    return TRUE;
  }

  drush_include_engine('drupal', 'update', drush_drupal_major_version());
  if (update_main() === FALSE) {
    return FALSE;
  }

  drush_log(dt('Finished performing updates.'), 'ok');
}

/**
 * Drush Callback
 * Used for when your local environment is synced from production or staging.
 * It disables modules you don't need locally and sets caching and compression values
 * to those consistent with dev mode.
 */
function drush_acquia_reset_local() {
  // Disable any modules that are usually used and not required for local functionality
  module_disable(array(
    'cdn', 'memcache'
  ));

  // Set Variables
  variable_set('file_temporary_path', '/tmp');
  variable_set('cache', 0);
  variable_set('block_cache', 0);
  variable_set('page_compression', 0);
  variable_set('preprocess_css', 0);
  variable_set('preprocess_css', 0);

  drush_print("Your local is ready to go! =)");
}
