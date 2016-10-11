<?php
/**
 * @file
 * Contains PersonProfileFixtureMigration class.
 */

/**
 * Class PersonProfileFixtureMigration.
 */
class PersonProfileFixtureMigration extends NodeBaseMigration {
  /**
   * Constructor for person profile fixture migration.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = 'Migration class for Person Profile page fixtures.';

    $this->addFieldMapping('title', 'title')
      ->xpath('title');
    $this->addFieldMapping('field_last_name', 'last_name')
      ->xpath('last_name');
    $this->addFieldMapping('uid', 'author')
      ->xpath('author')
      ->sourceMigration($arguments['field_migrations']['uid'])
      ->defaultValue(1);
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
      'last_name' => t('Last Name'),
      'address' => t('Address'),
      'city' => t('City'),
      'state' => t('State'),
      'zip' => t('Zip Code'),
    );
  }

  /**
   * Get the node migration's type/bundle.
   *
   * @return string
   *   The machine name of the node type/bundle.
   */
  protected function getNodeType() {
    return 'person_profile';
  }

}
