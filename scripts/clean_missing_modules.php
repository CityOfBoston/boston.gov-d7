<?php
/**
 * @file
 * Script for cleaning out missing modules.
 */

// These are special modules that have their own patches already.
// This will help eliminate some of the brute force of this module.
$special = array(
  'adminimal_theme' => 'https://www.drupal.org/node/2763581',
  'content' => 'https://www.drupal.org/node/2763555',
  'field_collection_table' => 'https://www.drupal.org/node/2764331',
);

// Grab all the modules in the system table.
$query = db_query("SELECT filename, type, name FROM system;");
$modules = array();

// Go through the query and check to see if the module exists in the directory.
foreach ($query->fetchAll() as $record) {
  // Grab the checker.
  $check = drupal_get_filename($record->type, $record->name, $record->filename, FALSE);

  // If drupal_get_filename returns null = we got problems.
  if (is_null($check) && $record->name != 'default' && !array_key_exists($record->name, $special)) {
    // Go ahead and set the row if all is well.
    $modules[] = $record->name;
  }
}

// Delete if there is no modules.
if (count($modules) > 0) {
  db_delete('system')
    ->condition('name', $modules, 'IN')
    ->execute();
}
