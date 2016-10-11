<?php
/**
 * @file
 * Contains DepartmentProfileFixtureMigration class.
 */

/**
 * Class DepartmentProfileFixtureMigration.
 */
class DepartmentProfileFixtureMigration extends NodeBaseMigration {

  /**
   * Constructor for department profile fixture migration.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = 'Migration class for department profile fixtures.';

    $this->addFieldMapping('title', 'title')
      ->xpath('title');
    $this->addFieldMapping('body', 'body')
      ->xpath('body');
    $this->addFieldMapping('uid', 'author')
      ->xpath('author')
      ->sourceMigration('UserFixtures')
      ->defaultValue(1);
    $this->addFieldMapping('field_icon', 'icon')
      ->xpath('icon');
    $this->addFieldMapping('field_icon:source_dir')
      ->defaultValue($this->mediaDirectory);
    $this->addFieldMapping('field_phone_number', 'phone')
      ->xpath('phone');
    $this->addFieldMapping('field_email', 'email')
      ->xpath('email');
    $this->addFieldMapping('field_address')
      ->defaultValue('US');
    $this->addFieldMapping('field_address:thoroughfare', 'address')
      ->xpath('address');
    $this->addFieldMapping('field_address:locality', 'city')
      ->xpath('city');
    $this->addFieldMapping('field_address:administrative_area', 'state')
      ->xpath('state');
    $this->addFieldMapping('field_address:postal_code', 'zip')
      ->xpath('zip');
  }

  /**
   * Get the node migration's type/bundle.
   *
   * @return string
   *   The machine name of the node type/bundle.
   */
  protected function getNodeType() {
    return 'department_profile';
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
      'author' => t('Author'),
      'title' => t('Title'),
      'body' => t('Body'),
      'icon' => t('Department Icon'),
      'phone' => t('Phone Number'),
      'email' => t('Email'),
      'address' => t('Address'),
      'city' => t('City'),
      'state' => t('State'),
      'zip' => t('Zip Code'),
    );
  }

}
