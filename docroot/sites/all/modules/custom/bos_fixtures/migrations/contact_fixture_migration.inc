<?php
/**
 * @file
 * Contains ContactFixtureMigration class.
 */

/**
 * Class ContactFixtureMigration.
 */
class ContactFixtureMigration extends TermBaseMigration {

  /**
   * Class constructor.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = 'Migration for contact fixtures.';

    $this->addFieldMapping('name', 'name')
      ->xpath('name');
    $this->addFieldMapping('description', 'description')
      ->xpath('description')
      ->callbacks('trim');
    $this->addFieldMapping('field_department_profile', 'department_profile')
      ->xpath('department_profile')
      ->sourceMigration($arguments['field_migrations']['field_department_profile']);
  }

  /**
   * Specify what fields are available to the XML mapping.
   *
   * @return array
   *   The fields that this XML migration contains.
   */
  protected function getFields() {
    return array(
      'id' => t('Contact ID'),
      'name' => t('Contact Name'),
      'description' => t('Contact Description'),
      'department_profile' => t('Associated Department'),
    );
  }

  /**
   * Get the term migration's type/bundle.
   *
   * @return string
   *   The machine name of the term type/bundle.
   */
  protected function getTermType() {
    return 'contact';
  }

}
