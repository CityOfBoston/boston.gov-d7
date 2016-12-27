<?php
/**
 * @file
 * bos_keyboard_shortcuts.default_keyboard_shortcut_bindings.inc
 */

/**
 * Implements hook_default_keyboard_shortcut_bindings().
 */
function bos_keyboard_shortcuts_default_keyboard_shortcut_bindings() {
  $export = array();

  $keyboard_shortcut_binding = new stdClass();
  $keyboard_shortcut_binding->disabled = FALSE; /* Edit this to true to make a default keyboard_shortcut_binding disabled initially */
  $keyboard_shortcut_binding->api_version = 1;
  $keyboard_shortcut_binding->admin_title = 'Go to Details & Forms';
  $keyboard_shortcut_binding->name = 'go_to_details_forms';
  $keyboard_shortcut_binding->shortcut = 'h+l';
  $keyboard_shortcut_binding->shortcut_type = 'url_action';
  $keyboard_shortcut_binding->shortcut_action_data = array(
    'goto_url' => '/details-and-forms',
  );
  $keyboard_shortcut_binding->shortcut_roles = 'a:11:{i:5;s:1:"5";i:4;s:1:"4";i:1;i:0;i:2;i:0;i:3;i:0;i:6;i:0;i:11;i:0;i:16;i:0;i:21;i:0;i:26;i:0;i:31;i:0;}';
  $export['go_to_details_forms'] = $keyboard_shortcut_binding;

  $keyboard_shortcut_binding = new stdClass();
  $keyboard_shortcut_binding->disabled = FALSE; /* Edit this to true to make a default keyboard_shortcut_binding disabled initially */
  $keyboard_shortcut_binding->api_version = 1;
  $keyboard_shortcut_binding->admin_title = 'Go to Employee Directory';
  $keyboard_shortcut_binding->name = 'go_to_employee_directory';
  $keyboard_shortcut_binding->shortcut = 'h+d';
  $keyboard_shortcut_binding->shortcut_type = 'url_action';
  $keyboard_shortcut_binding->shortcut_action_data = array(
    'goto_url' => '/employee-directory',
  );
  $keyboard_shortcut_binding->shortcut_roles = 'a:11:{i:5;s:1:"5";i:4;s:1:"4";i:1;i:0;i:2;i:0;i:3;i:0;i:6;i:0;i:11;i:0;i:16;i:0;i:21;i:0;i:26;i:0;i:31;i:0;}';
  $export['go_to_employee_directory'] = $keyboard_shortcut_binding;

  $keyboard_shortcut_binding = new stdClass();
  $keyboard_shortcut_binding->disabled = FALSE; /* Edit this to true to make a default keyboard_shortcut_binding disabled initially */
  $keyboard_shortcut_binding->api_version = 1;
  $keyboard_shortcut_binding->admin_title = 'Go to Feature Form';
  $keyboard_shortcut_binding->name = 'go_to_feature_form';
  $keyboard_shortcut_binding->shortcut = 'h+q';
  $keyboard_shortcut_binding->shortcut_type = 'url_action';
  $keyboard_shortcut_binding->shortcut_action_data = array(
    'goto_url' => '/need-something-else',
  );
  $keyboard_shortcut_binding->shortcut_roles = 'a:11:{i:5;s:1:"5";i:4;s:1:"4";i:1;i:0;i:2;i:0;i:3;i:0;i:6;i:0;i:11;i:0;i:16;i:0;i:21;i:0;i:26;i:0;i:31;i:0;}';
  $export['go_to_feature_form'] = $keyboard_shortcut_binding;

  $keyboard_shortcut_binding = new stdClass();
  $keyboard_shortcut_binding->disabled = FALSE; /* Edit this to true to make a default keyboard_shortcut_binding disabled initially */
  $keyboard_shortcut_binding->api_version = 1;
  $keyboard_shortcut_binding->admin_title = 'Go to Homepage';
  $keyboard_shortcut_binding->name = 'go_to_home';
  $keyboard_shortcut_binding->shortcut = 'h+f';
  $keyboard_shortcut_binding->shortcut_type = 'url_action';
  $keyboard_shortcut_binding->shortcut_action_data = array(
    'goto_url' => '/',
  );
  $keyboard_shortcut_binding->shortcut_roles = 'a:11:{i:5;s:1:"5";i:4;s:1:"4";i:1;i:0;i:2;i:0;i:3;i:0;i:6;i:0;i:11;i:0;i:16;i:0;i:21;i:0;i:26;i:0;i:31;i:0;}';
  $export['go_to_home'] = $keyboard_shortcut_binding;

  $keyboard_shortcut_binding = new stdClass();
  $keyboard_shortcut_binding->disabled = FALSE; /* Edit this to true to make a default keyboard_shortcut_binding disabled initially */
  $keyboard_shortcut_binding->api_version = 1;
  $keyboard_shortcut_binding->admin_title = 'Go to Shortcut Details';
  $keyboard_shortcut_binding->name = 'go_to_shortcut_details';
  $keyboard_shortcut_binding->shortcut = '?';
  $keyboard_shortcut_binding->shortcut_type = 'url_action';
  $keyboard_shortcut_binding->shortcut_action_data = array(
    'goto_url' => '/shortcuts',
  );
  $keyboard_shortcut_binding->shortcut_roles = 'a:11:{i:5;s:1:"5";i:4;s:1:"4";i:1;i:0;i:2;i:0;i:3;i:0;i:6;i:0;i:11;i:0;i:16;i:0;i:21;i:0;i:26;i:0;i:31;i:0;}';
  $export['go_to_shortcut_details'] = $keyboard_shortcut_binding;

  $keyboard_shortcut_binding = new stdClass();
  $keyboard_shortcut_binding->disabled = FALSE; /* Edit this to true to make a default keyboard_shortcut_binding disabled initially */
  $keyboard_shortcut_binding->api_version = 1;
  $keyboard_shortcut_binding->admin_title = 'Go to Tools';
  $keyboard_shortcut_binding->name = 'go_to_tools';
  $keyboard_shortcut_binding->shortcut = 'h+t';
  $keyboard_shortcut_binding->shortcut_type = 'url_action';
  $keyboard_shortcut_binding->shortcut_action_data = array(
    'goto_url' => '/tools',
  );
  $keyboard_shortcut_binding->shortcut_roles = 'a:11:{i:5;s:1:"5";i:4;s:1:"4";i:1;i:0;i:2;i:0;i:3;i:0;i:6;i:0;i:11;i:0;i:16;i:0;i:21;i:0;i:26;i:0;i:31;i:0;}';
  $export['go_to_tools'] = $keyboard_shortcut_binding;

  return $export;
}
