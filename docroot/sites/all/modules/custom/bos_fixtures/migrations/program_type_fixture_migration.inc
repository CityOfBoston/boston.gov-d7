<?php
/**
 * @file
 * Contains ProgramTypeFixtureMigration class.
 */

/**
 * Class ProgramTypeFixtureMigration.
 */
class ProgramTypeFixtureMigration extends TermBaseMigration {

  /**
   * Class constructor.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = 'Migration for program type fixtures.';

    $this->addFieldMapping('name', 'name')
      ->xpath('name');
    $this->addFieldMapping('description', 'description')
      ->xpath('description')
      ->callbacks('trim');
  }

  /**
   * Specify what fields are available to the XML mapping.
   *
   * @return array
   *   The fields that this XML migration contains.
   */
  protected function getFields() {
    return array(
      'id' => t('Program Type ID'),
      'name' => t('Program Type Name'),
      'description' => t('Program Type Description'),
    );
  }

  /**
   * Get the term migration's type/bundle.
   *
   * @return string
   *   The machine name of the term type/bundle.
   */
  protected function getTermType() {
    return 'program_type';
  }

}
