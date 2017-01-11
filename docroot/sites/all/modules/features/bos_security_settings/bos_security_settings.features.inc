<?php
/**
 * @file
 * bos_security_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_security_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_password_policy_features_default_policy().
 */
function bos_security_settings_password_policy_features_default_policy() {
  return array(
    'Boston Authenticated Users' => array(
      'name' => 'Boston Authenticated Users',
      'description' => '',
      'enabled' => 1,
      'policy' => array(
        'character_types' => 3,
        'delay' => 2,
        'history' => 5,
        'length' => 8,
      ),
      'created' => 1450737105,
      'expiration' => 0,
      'weight' => 0,
      'roles' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
}
