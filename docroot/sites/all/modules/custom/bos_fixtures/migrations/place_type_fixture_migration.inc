<?php
/**
 * @file
 * Contains PlaceTypeFixtureMigration class.
 */

/**
 * Class PlaceTypeFixtureMigration.
 */
class PlaceTypeFixtureMigration extends TermBaseMigration {

  /**
   * Class constructor.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = 'Migration for place type fixtures.';

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
      'id' => t('Place Type ID'),
      'name' => t('Place Type Name'),
      'description' => t('Place Type Description'),
    );
  }

  /**
   * Get the term migration's type/bundle.
   *
   * @return string
   *   The machine name of the term type/bundle.
   */
  protected function getTermType() {
    return 'place_type';
  }

}
