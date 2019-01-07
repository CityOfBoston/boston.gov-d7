<?php
/**
 * @file Install file for bos_rst module
 */

/**
 * Implements hook_uninstall().
 */
function bos_rest_uninstall() {

  variable_del('cityscore_token');
  variable_del('cityscore_ip_whitelist');

}

/**
 * Gives administrator role permissions to key objects.
 */
function bos_rest_update_7001() {
  // Give administrator permissions to the admin page.
  $permissions[] = 'administer bos_rest';
  // Give administrator permissions to the taxonomy pages.
  $tax = taxonomy_vocabulary_machine_name_load('cityscore_metrics');
  if (!empty($tax)) {
    $permissions[] = 'delete terms in ' . $tax->vid;
    $permissions[] = 'edit terms in ' . $tax->vid;
  }

  $roles = array_flip(user_roles());
  $admin_rid = $roles['administrator'];
  user_role_grant_permissions($admin_rid, $permissions);
}

/**
 * Creates a default cityscore token.
 */
function bos_rest_update_7002() {
  // Creates a default cityscore  token.
  if (!variable_get('cityscore_token', FALSE)) {
    variable_set('cityscore_token', '9juHD7Y8oZpN2-erChlUQQ');
  }
}
