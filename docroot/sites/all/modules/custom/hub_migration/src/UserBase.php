<?php
/**
 * @file
 * JsonSource.
 */

namespace Drupal\hub_migration;

/**
 * Class JsonSource.
 *
 * @package Drupal\hub_migration
 */
abstract class UserBase extends \Migration {

  protected $sourceFields;

  /**
   * JsonSource constructor.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // If we are not in a drupal environment, lets use a cached version
    // of the feed data. The file should be in the data folder, and it
    // should be named hub_feed.json.
    if (variable_get('hub_feed_cache', FALSE)) {
      $json_file = drupal_get_path('module', 'hub_migration') . "/data/hub_feed.json";
      if (file_exists($json_file)) {
        $data_source_path = $json_file;
      }
      else {
        throw new \Exception("The json file containing the cached feed data does not exist at {$json_file}.");
      }
    }
    elseif (!empty($file = $this->group->getArguments()['source_file'])) {
      if (file_exists($file)) {
        $data_source_path = $file;
      }
    }
    // We are in an Acquia environment, the feed credentials should be set.
    elseif ($basic_auth = variable_get('hub_feed_basic_auth', FALSE)) {
      $data_source_path = "{$basic_auth}";
    }
    // If non of the right conditions are set, default to using our local dummy
    // json file.
    else {
      $data_source_path = DRUPAL_ROOT . "/" . drupal_get_path('module', "hub_migration") . "/data/149000.json";
    }

    $this->sourceFields = array(
      // Employee ID.
      "EMPLID" => "",

      // Title.
      "TITLE" => "",

      // Name.
      "FIRST_NAME" => "",
      "LAST_NAME" => "",
      "MIDDLE_NAME" => "",

      // Home Address.
      "HOME_ADDRESS1" => "",
      "HOME_ADDRESS2" => "",
      "HOME_CITY" => "",
      "HOME_STATE" => "",
      "HOME_POSTAL" => "",

      // Mailing Address.
      "MAIL_ADDRESS1" => "",
      "MAIL_ADDRESS2" => "",
      "MAIL_CITY" => "",
      "MAIL_STATE" => "",
      "MAIL_POSTAL" => "",

      // Phone numbers.
      "HOME_PHONE" => "",
      "WORK_PHONE" => "",
      "CELL_PHONE" => "",

      // Emails.
      "WORK_EMAIL" => "",
      "HOME_EMAIL" => "",

      // Is a manager?
      "MSS" => "",

      // Employee's manager info.
      "REPORTS_TO_EMPLID" => "",
      "REPORTS_TO_NAME" => "",

      // Department info.
      "DEPTID" => "",
      "DEPARTMENT" => "",

      // Others.
      "ESS" => "",
      "EMPL_RCD" => "",
      "FLOOR" => "",
      "LOCATION" => "",
      "LOCATION_NAME" => "",
      "LOCATION_ADDRESS" => "",
      "ROOM_NBR" => "",
    );

    $options = array(
      'reader_class' => "Drupal\\hub_migration\\JsonReader",
      'track_changes' => TRUE,
    );
    $this->setSource(new JsonSource($data_source_path, 'EMPLID', $this->sourceFields, $options));
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    if ($tid = $this->departmentExist($row->DEPTID)) {
      $row->contact = $tid;
    }
  }

  /**
   * Add a field and all its subfields to the Unmigrated Destinations.
   */
  protected function doNotMigrateFieldOrSubs($field_name) {
    $dest = $this->getDestination();
    foreach ($dest->fields() as $machine_name => $description) {
      if (substr_count($machine_name, $field_name) > 0) {
        $dont_migrate_fields[] = $machine_name;
      }
    }
    $this->addUnmigratedDestinations($dont_migrate_fields);
  }

  /**
   * Check whether a department with the given legacy id exists.
   */
  protected function departmentExist($department_id) {

    $cache = &drupal_static(__FUNCTION__, array());

    if (isset($cache[$department_id])) {
      return $cache[$department_id];
    }

    $query = new \EntityFieldQuery();
    $query->entityCondition('entity_type', 'taxonomy_term');
    $query->fieldCondition('field_department_legacy_id', 'value', $department_id);
    $results = $query->execute();

    if (!empty($results)) {
      foreach ($results['taxonomy_term'] as $index => $info) {
        $cache[$department_id] = $info->tid;
        return $info->tid;
      }
    }
    else {
      return FALSE;
    }
  }

}
