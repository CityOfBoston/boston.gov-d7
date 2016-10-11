<?php
/**
 * @file
 * Contains ListingPageFixtureMigration class.
 */

/**
 * Class ListingPageFixtureMigration.
 */
class ListingPageFixtureMigration extends NodeBaseMigration {
  /**
   * Constructor for event fixture migration.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = 'Migration class for listing page fixtures.';

    $this->addFieldMapping('title', 'title')
      ->xpath('title');
    $this->addFieldMapping('uid', 'author')
      ->xpath('author')
      ->sourceMigration($arguments['field_migrations']['uid'])
      ->defaultValue(1);
    $this->addFieldMapping('field_header_component', 'header_component')
      ->xpath('header_component')
      ->sourceMigration($arguments['field_migrations']['field_header_component']);
    $this->addFieldMapping('field_intro_image', 'intro_image')
      ->xpath('intro_image');
    $this->addFieldMapping('field_intro_image:source_dir')
      ->defaultValue($this->mediaDirectory);
    $this->addFieldMapping('field_components', 'components')
      ->xpath('components')
      ->sourceMigration($arguments['field_migrations']['field_components'])
      ->separator(',');
  }

  /**
   * Specify what fields are available to the XML mapping.
   *
   * @return array
   *   The fields that this XML migration contains.
   */
  protected function getFields() {
    return array(
      'id' => t('ID'),
      'author' => t('Author'),
      'title' => t('Title'),
      'intro_image' => t('Intro Image'),
      'header_component' => t('Header Component'),
      'components' => t('Components'),
    );
  }

  /**
   * Get the node migration's type/bundle.
   *
   * @return string
   *   The machine name of the node type/bundle.
   */
  protected function getNodeType() {
    return 'listing_page';
  }

}
