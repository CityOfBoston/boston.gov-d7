<?php
/**
 * @file
 * Profile migration code.
 */

namespace Drupal\hub_migration;

/**
 * Class Profile.
 *
 * @package Drupal\hub_migration
 */
class Profile extends UserBase {

  /**
   * Profile constructor.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addHardDependencies(array('User'));

    $this->setDestination(new \MigrateDestinationProfile2('main'));
    $source_key = array(
      'EMPLID' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
        'description' => t('Employee ID'),
      ),
    );
    $this->setMap(new \MigrateSQLMap($this->machineName, $source_key,
      \MigrateDestinationProfile2::getKeySchema()));

    // User.
    $this->addFieldMapping('uid', 'employee_id');
    $this->addFieldMapping('revision_uid', 'employee_id');

    // Manager.
    $this->addFieldMapping('field_manager', 'manager_id');

    // Name.
    $this->addFieldMapping('field_display_name', 'name');
    $this->addFieldMapping('field_first_name', 'FIRST_NAME');
    $this->addFieldMapping('field_last_name', 'LAST_NAME');

    // Position.
    $this->addFieldMapping('field_position_title', 'TITLE');

    // Emails.
    $this->addFieldMapping('field_work_email', 'WORK_EMAIL');

    // Phone Numbers.
    $this->addFieldMapping('field_work_phone_number', 'WORK_PHONE');

    // Addresses.
    $addresses = array(
      'mailing' => 'MAIL',
    );

    foreach ($addresses as $src => $dest) {
      $this->addFieldMapping("field_{$src}_address")->defaultValue('US');
      $this->addFieldMapping("field_{$src}_address:thoroughfare", "{$dest}_ADDRESS1");
      $this->addFieldMapping("field_{$src}_address:premise", "{$dest}_ADDRESS2");
      $this->addFieldMapping("field_{$src}_address:locality", "{$dest}_CITY");
      $this->addFieldMapping("field_{$src}_address:administrative_area", "{$dest}_STATE");
      $this->addFieldMapping("field_{$src}_address:postal_code", "{$dest}_POSTAL");
    }

    $this->addFieldMapping('field_office_location')->defaultValue('US');
    $this->addFieldMapping('field_office_location:thoroughfare', 'LOCATION_ADDRESS');
    $this->addFieldMapping('field_office_location:premise', 'LOCATION_ADDRESS2');
    $this->addFieldMapping('field_office_location:locality', 'LOCATION_CITY');
    $this->addFieldMapping('field_office_location:administrative_area', 'LOCATION_STATE');
    $this->addFieldMapping('field_office_location:postal_code', 'LOCATION_POSTAL');

    // The contact property is dynamically acquired in prepareRow().
    $this->addFieldMapping('field_contact', 'contact');

    // DNM.
    $dont_migrate_fields = array(
      'field_linked_in',
      'field_twitter',
      'language',
      'path',
      'pathauto',
      'field_phone_number',
      'field_cell_phone_number',
      'field_home_address',
    );

    $dont_migrate_address_subs = array(
      'sub_administrative_area',
      'dependent_locality',
      'sub_premise',
      'organisation_name',
      'name_line',
      'first_name',
      'last_name',
      'data',
    );

    foreach ($addresses as $src => $dest) {
      foreach ($dont_migrate_address_subs as $sub) {
        $dont_migrate_fields[] = "field_{$src}_address:{$sub}";
      }
    }

    $this->doNotMigrateFieldOrSubs('field_user_picture');

    $this->addUnmigratedDestinations($dont_migrate_fields);

    $dont_migrate_sources = array(
      // Used to set roles in the User migration, not needed here.
      'MSS',
      // Used dynamically in prepareRow().
      'REPORTS_TO_EMPLID',
      'DEPTID',
      'DEPARTMENT',
      // We map managers by employee id, do not need the name.
      'REPORTS_TO_NAME',
    );
    $this->addUnmigratedSources($dont_migrate_sources);
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $row->name = $row->FIRST_NAME . " " . $row->LAST_NAME;

    $row->employee_id = $this->handleSourceMigration(array('User'), $row->EMPLID);
    $row->manager_id = $this->handleSourceMigration(array('User'), $row->REPORTS_TO_EMPLID);
  }

  /**
   * {@inheritdoc}
   */
  public function complete($entity, $row) {
    pathauto_user_update_alias(user_load($entity->uid), 'update');
  }

}
