<?php
/**
 * @file
 * Contains UserFixturesMigration class.
 */

/**
 * Class UserFixtureMigration.
 */
class UserFixtureMigration extends UserBaseMigration {

  /**
   * Constructor for user fixture migration.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = 'Migration class for user fixtures.';

    $this->addFieldMapping('name', 'name')
      ->xpath('name');
    $this->addFieldMapping('mail', 'mail')
      ->xpath('mail');
    $this->addFieldMapping('pass', 'pass')
      ->xpath('pass');
    $this->addFieldMapping('status')
      ->defaultValue(1);
    $this->addFieldMapping('roles', 'roles')
      ->xpath('roles')
      ->defaultValue(DRUPAL_AUTHENTICATED_RID)
      ->separator(',')
      ->callbacks(array($this, 'convertRoleId'));
  }

  /**
   * Specify what fields are available to the XML mapping.
   *
   * @return array
   *   The fields that this XML migration contains.
   */
  protected function getFields() {
    return array(
      'id' => t('User ID'),
      'name' => t('Username'),
      'pass' => t('Password'),
      'mail' => t('Email'),
      'roles' => t('User Roles'),
    );
  }


  /**
   * Convert role labels to role ids.
   *
   * @param array $roles
   *   Array of role labels.
   *
   * @return array
   *   Array of role ids.
   */
  public function convertRoleId($roles) {
    foreach ($roles as $index => &$role) {
      $role = user_role_load_by_name($role);
      $role = $role->rid;
    }
    return $roles;
  }

}
