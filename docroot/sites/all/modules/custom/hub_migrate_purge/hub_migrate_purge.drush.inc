<?php

/**
 * @file
 * Deletes "Orphan" records (record in destination but removed from source).
 */

/**
 * Implements hook_drush_command().
 *
 * Adds drush command: hub-migrate-purge.
 */
function hub_migrate_purge_drush_command() {
  return array(
    'hub-migrate-purge' => array(
      'description' => 'Check remote source for orphaned records (removed) and remove them locally',
      'arguments' => array(
        'migration-name' => 'Name of the migration to check',
      ),
      'required-arguments' => 1,
      'options' => array(
        'dry-run' => 'Do not delete, just report the records',
      ),
    ),
  );
}

/**
 * Callback for hub-migrate-purge command.
 */
function drush_hub_migrate_purge($migration_name) {

  // https://www.drupal.org/node/1416672
  /** @var Migration $migration */
  $migration = Migration::getInstance(drupal_strtolower($migration_name));
  if (!$migration) {
    drush_set_error('No migration found:' . $migration_name);
    return;
  }
  if ($migration->getStatus() != MigrationBase::STATUS_IDLE) {
    drush_set_error('Migration not idle, waiting to finish. Status is: ' . $migration->getStatus());
    return;
  }
  // Get the source to destination ID mapping from database.
  $rows = db_select('migrate_map_' . $migration->getMachineName(), 'm')
    ->fields('m', array('sourceid1', 'destid1'))
    ->isNotNull('destid1')
    ->execute()
    ->fetchAllKeyed(0, 1);
  // Count how many mapped IDs we have.
  $count = count($rows);
  // Determine if the user passed the "dry-run" flag.
  $dry_run = drush_get_option('dry-run');

  // Get the source object.
  $source = $migration->getSource();
  // Get the URL where we're getting the JSON.
  $urls = $source->getSourceUrls();
  if ($urls[0]) {
    // Get the JSON from the URL.
    $request = drupal_http_request($urls[0]);
    // Turn the JSON into an array that we can manipulate.
    $json_response = drupal_json_decode($request->data);
    // Get the relevant employee data from the array.
    $employee_data = $json_response['Y_HCM_PORTALDIR_DOC']['EE_GET_DATA'];
  }
  else {
    // Quit if can't connect to URL (will happen outside the boston network).
    drush_set_error('Can\'t access source URL.');
    return;
  }
  foreach ($employee_data as $id => $data) {
    // Create a new array of all current source IDs from URL.
    $source_ids[] = $data['EMPLID'];
  }

  $delete_nids = array();
  $delete_src = array();
  foreach ($rows as $db_id => $nid) {
    // If the mapped ID from the db is not still in the source.
    if (!in_array($db_id, $source_ids)) {
      // Add the ID to an array.
      $delete_src[] = $db_id;
      // Add the corresponding node ID to an array.
      $delete_nids[] = $nid;
    }
  }
  // Send notices to terminal to give the user information about orphan records.
  if (count($delete_src) < 25) {
    // If there are only a few IDs, specify which ones are being removed.
    drush_set_error('Preparing to remove the following source IDs from map: ' . implode(",", $delete_src));
  }
  else {
    // If there are a lot of IDs just tell user how many will be removed.
    drush_set_error('Preparing to remove ' . count($delete_src) . ' source IDs from map.');
  }
  if (count($delete_nids) < 25) {
    // If there are only a few nodes, specify which ones are being deleted.
    drush_set_error('Preparing to delete the following Nodes: ' . implode(",", $delete_nids));
  }
  else {
    // If there are a lot of nodes, just tell user how many are being deleted.
    drush_set_error('Preparing to delete ' . count($delete_nids) . ' Nodes.');
  }
  // Check if the user actually wants us to delete anything from the db.
  if (!$dry_run) {
    // Delete the nodes specified.
    node_delete_multiple($delete_nids);
    foreach ($delete_src as $id) {
      // Delete the IDs from the map table for this migration.
      $migration->getMap()->delete(array($id));
    }
    // Notify the user that the deletion has completed.
    drush_set_error('Deleted!');
  }
  else {
    // If dry-run, tell the user that no action was performed.
    drush_set_error('Skipping... dry run.');
  }
}
