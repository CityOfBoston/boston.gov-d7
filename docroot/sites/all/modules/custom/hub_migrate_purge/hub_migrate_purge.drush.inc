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
      'description' => 'Check remote source for orphaned records (removed) and disable them locally',
      'arguments' => array(
        'migration-name' => 'Name of the migration to check',
      ),
      'required-arguments' => 1,
      'options' => array(
        'dry-run' => 'Do not alter, just report the records',
        'delete-accounts' => 'Delete the purged accounts'
      ),
    ),
  );
}

/**
 * Callback for hub-migrate-purge command.
 */
function drush_hub_migrate_purge($migration_name) {

  $migration_names = explode(',', $migration_name);
  foreach ($migration_names as $migration_name) {

    // https://www.drupal.org/node/1416672
    /** @var Migration $migration */
    $migration = Migration::getInstance(drupal_strtolower($migration_name));
    if (!$migration) {
      drush_set_error('No migration found: ' . $migration_name);
      return;
    }

    // Determine if the user passed the "dry-run" flag.
    $dry_run = drush_get_option('dry-run');
    // Determine if the user passed the "delete-accounts" flag.
    $verb = "disable";
    if($delete_accounts = drush_get_option('delete-accounts')) {
      $verb = "delete";
    }

    drush_log('Starting migration purge for ' . $migration_name, 'ok');
    if ($dry_run) {
      drush_log('** Notice: using --dry-run, some errors ignored, nothing will be committed', 'ok');
    }

    if ($migration->getStatus() != MigrationBase::STATUS_IDLE) {
      drush_set_error('Migration not idle, waiting to finish. Status is: ' . $migration->getStatus());
      if (!$dry_run) {
        return;
      }
    }

    // Get the source to destination ID mapping from database.
    $rows = db_select('migrate_map_' . $migration->getMachineName(), 'm')
      ->fields('m', array('sourceid1', 'destid1'))
      ->isNotNull('destid1')
      ->execute()
      ->fetchAllKeyed(0, 1);

    // Count how many mapped IDs we have.
    $count = count($rows);
    $threshold_map = 10000;
    $threshold_feed = 15000;
    if ($count < $threshold_map) {
      // fail safe, dont want to alter records based on incomplete file.
      drush_set_error('Found '. $count . ' records in map file - less than threshold of ' . $threshold_map .' so aborting. Purge not performed.');
      if (!$dry_run) {
        return;
      }
    }

    // Grab latest migrate_log record from the DB
    $q = db_select('hub.migrate_log', 'log')
      ->fields('log', array('numprocessed'))
      ->condition('machine_name', 'User', '=')
      ->condition('process_type', '1', '=')
      ->where('DATE(from_unixtime(starttime/1000)) = CURDATE()')
      ->orderBy('starttime', 'DESC');
    $q->addExpression('from_unixtime(starttime/1000)', 'start');
    $q->addExpression('from_unixtime(endtime/1000)', 'end');
    $q->addExpression('(endtime - starttime) / 1000 / 60', 'duration');
    $q->range(0,1);
    $rows2 = $q->execute()->fetchAll();

    if (empty($rows2)) {
      // only run if a migration has been started today.
      drush_set_error('Migration has not yet been run today.');
      if (!$dry_run) {
        return;
      }
    }

    if (empty($rows2[0]->end)) {
      // only run if a migration has already ended today.
      drush_set_error('Migration has not yet finished for today.');
      if (!$dry_run) {
        return;
      }
    }

    // Get the source object.
    $source = $migration->getSource();
    // Get the URL where we're getting the JSON.
    $urls = $source->getSourceUrls();

    if ($urls[0]) {
      // Get the JSON from the URL.
      $request = drupal_http_request($urls[0]);
      if(!isset($request)) {
        // Quit if can't connect to URL (will happen outside the boston network).
        drush_set_error('Can\'t access source URL.');
        return;
      }

      if (!empty($request->data)) {
          // Turn the JSON into an array that we can manipulate.
          $json_response = drupal_json_decode($request->data);
          if (empty($json_response)) {
            drush_set_error('Bad JSON data retrieved from source.');
            return;
          }
          // Get the relevant employee data from the array.
          $employee_data = $json_response['Y_HCM_PORTALDIR_DOC']['EE_GET_DATA'];
      }

      if(empty($employee_data)) {
        // Quit if can't connect to URL (will happen outside the boston network).
        drush_set_error('No data retrieved from source.');
        return;
      }

      if (count($employee_data) < $threshold_feed) {
        // fail safe, dont want to alter records based on incomplete file.
        drush_set_error('Found '. count($employee_data) . ' records in feed - less than threshold of ' . $threshold_feed .' so aborting. Purge not performed.');
        if (!$dry_run) {
          return;
        }
      }
    }
    else {
      // Quit if can't find any URLs.
      drush_set_error('Can\'t find a source URL.');
      return;
    }
    foreach ($employee_data as $id => $data) {
      // Create a new array of all current source IDs from URL.
      $json_source_ids[] = $data['EMPLID'];
    }

    $uids = array();
    $pids = array();
    $delete_src = array();
    foreach ($rows as $db_source_id => $drupal_id) {
      // If the mapped ID from the db is not still in the source.
      if (!in_array($db_source_id, $json_source_ids)) {
        // Add the ID to an array.
        $delete_src[] = $db_source_id;
        if ($migration_name == 'User') {
          // Add the corresponding User ID to an array.
          $uids[] = $drupal_id;
        }
        if ($migration_name == 'Profile') {
          // Add the corresponding Profile ID to an array.
          $pids[] = $drupal_id;
        }
      }
    }
    // Send notices to terminal to give information about orphan records.
    if (count($delete_src) == 0) {
      drush_log('There are no source IDs to remove from map.', 'ok');
    }
    elseif (count($delete_src) < 25) {
      // If there are only a few IDs, specify which ones are being removed.
      drush_log('Preparing to remove the following source IDs from map: ' . implode(",", $delete_src), 'ok');
    }
    else {
      // If there are a lot of IDs just tell user how many will be removed.
      drush_log('Preparing to remove ' . count($delete_src) . ' source IDs from map.', 'ok');
    }
    if ($migration_name == 'User') {
      if (count($uids) == 0) {
        drush_log('There are no Users to ' . $verb . '.', 'ok');
      }
      elseif (count($uids) < 100) {
        // If there are only a few Users, specify which ones are being deleted.
        drush_log('Preparing to ' . $verb . ' the following users: ' . implode(",", $uids), 'ok');
      }
      else {
        // If there are a lot of Users, just specify how many are being deleted.
        drush_log('Preparing to ' . $verb . ' ' . count($uids) . ' Users.', 'ok');
      }
    }
    if ($migration_name == 'Profile') {
      if (count($pids) == 0) {
        drush_log('There are no Profiles to delete.', 'ok');
      }
      elseif (count($pids) < 100) {
        // If there are only a few Profiles, specify which ones to delete.
        drush_log('Preparing to delete the following Profiles: ' . implode(",", $pids), 'ok');
      }
      elseif (!$delete_accounts) {
        // If we are not deleting accounts.
        drush_log('The --delete-accounts flag is not swet, so profile records are not altered.', 'ok');
      }
      else {
        // If there are lots of Profiles, just specify how many to delete.
        drush_log('Preparing to delete ' . count($pids) . ' Profiles.', 'ok');
      }
    }
    // Check if the user actually wants us to alter anything from the db.
    if (!$dry_run) {

      // Delete/disable the users specified.
      if ($uids) {
        $action = 'user_cancel_block';
        if ($delete_accounts) {
          $action = "user_cancel_reassign";
        }
        foreach ($uids as $uid) {
          user_cancel(
            array(
              'user_cancel_notify' => FALSE,
              'user_cancel_method' => $action,
            ),
            $uid,
            $action
          );
          // The user cancellation process needs to be run in a batch.
          // https://drupal.stackexchange.com/questions/204394/cannot-disable-user-programmatically-with-user-cancel
          $batch = &batch_get();
          $batch['progressive'] = FALSE;
          batch_process();
        }
        drush_log('Users have been ' . $verb . 'd.', 'ok');
      }

      // Delete the profiles specified if flag set.
      if ($delete_accounts && $pids) {
        profile2_delete_multiple($pids);
        drush_log('Profiles have been deleted.', 'ok');
      }
      // finally,
      foreach ($delete_src as $id) {
        // Delete the IDs from the map table for this migration.
        $migration->getMap()->delete(array($id));
        drush_log('Map records have been deleted.', 'ok');
      }
      // Notify the user that the deletion has completed.
      drush_log('Updates complete!', 'ok');
    }
    else {
      // If dry-run, tell the user that no action was performed.
      drush_log('Skipping... dry run.', 'ok');
    }

  }
}
