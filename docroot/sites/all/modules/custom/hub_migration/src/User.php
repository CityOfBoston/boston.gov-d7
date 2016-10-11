<?php
/**
 * @file
 * JsonSource.
 */

namespace Drupal\hub_migration;

/**
 * Class User.
 *
 * @package Drupal\hub_migration
 */
class User extends UserBase {

  /**
   * The rid of the Manager role.
   *
   * @var integer $managerId
   */
  private $managerId;

  /**
   * User constructor.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->managerId = user_role_load_by_name('Manager')->rid;

    $this->setDestination(new \MigrateDestinationUser());
    $source_key = array(
      'EMPLID' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
        'description' => t('Employee ID'),
      ),
    );
    $this->setMap(new \MigrateSQLMap($this->machineName, $source_key,
      \MigrateDestinationUser::getKeySchema()));

    $this->addFieldMapping('name', 'EMPLID');
    $this->addFieldMapping('mail', 'WORK_EMAIL');
    $this->addFieldMapping('status')->defaultValue("1");

    $this->addSimpleMappings(array('role_names'));

    $dont_migrate_fields = array(
      'pass',
      'created',
      'access',
      'login',
      'picture',
      'signature',
      'signature_format',
      'timezone',
      'language',
      'theme',
      'init',
      'data',
      'is_new',
      'path',
      // We use the display name for the alias, an we do not have that data yet.
      'pathauto',
      'roles',
    );

    $this->addUnmigratedDestinations($dont_migrate_fields);

    // Don't migrate anything to the metatag fields.
    $this->doNotMigrateFieldOrSubs('metatag');

    $source_fields = $this->sourceFields;
    unset($source_fields['EMPLID']);
    unset($source_fields['WORK_EMAIL']);

    $this->addUnmigratedSources(array_keys($source_fields));
  }

  /**
   * {@inheritdoc}
   */
  public function prepare($user, $row) {
    if ($user->is_new === FALSE) {
      $user_exists = user_load($user->uid);
      $user->roles = $user_exists->roles;
    }
    if ($row->MSS == 'Y') {
      $user->roles[$this->managerId] = 'Manager';
    }
    else {
      unset($user->roles[$this->managerId]);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function complete($entity, $row) {
    $module = 'simplesamlphp_auth';
    user_set_authmaps($entity, array("authname_$module" => $entity->name));
  }

  /**
   * {@inheritdoc}
   */
  public function preRollback() {
    parent::preRollback();
  }

}
