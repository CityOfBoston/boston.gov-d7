<?php
/**
 * @file
 * Drush command for tools and apps API.
 */

/**
 * Implements hook_drush_command().
 */
function hub_tools_and_apps_api_drush_command() {

  $items['hub-tools-user-update'] = array(
    'description' => 'Update users from the DrupalQueue of pending application access rights.',
    'aliases' => array('htu'),
    'options' => array(
      'count' => 'The number of API queue objects to process. One object is processed by default.',
      'all' => 'Process all API queue objects.',
    ),
    'examples' => array(
      'drush htu --all' => 'Process all queued API updates.',
      'drush htu --count=3' => 'Process 3 queues API updates.',
      'drush htu' => 'Process 1 queued API update.',
    ),
  );

  return $items;
}

/**
 * Drush command for running through application API user queue objects.
 */
function drush_hub_tools_and_apps_api_hub_tools_user_update() {
  $count = drush_get_option('count', 1);
  $process_all = drush_get_option('all', FALSE);
  if ($process_all !== FALSE) {
    $count = db_query("SELECT COUNT(*) FROM queue WHERE name = 'hub_tools_and_apps_queue'")->fetchField();
  }
  for ($i = 0; $i < $count; $i++) {
    _hub_tools_and_apps_api_update_users_from_queue();
  }
}
