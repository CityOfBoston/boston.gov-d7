<?php
/**
 * @file
 * Contains PlaceProfileFixtureMigration class.
 */

/**
 * Class PlaceProfileFixtureMigration.
 */
class PlaceProfileFixtureMigration extends NodeBaseMigration {

  /**
   * Constructor for place profile fixture migration.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = 'Migration class for place profile fixtures.';

    $this->addFieldMapping('title', 'title')
      ->xpath('title');
    $this->addFieldMapping('body', 'body')
      ->xpath('body')
      ->callbacks('trim');
    $this->addFieldMapping('field_intro_text', 'intro_text')
      ->xpath('intro_text')
      ->callbacks('trim');
    $this->addFieldMapping('uid', 'author')
      ->xpath('author')
      ->sourceMigration($arguments['field_migrations']['uid'])
      ->defaultValue(1);
    $this->addFieldMapping('field_intro_image', 'intro_image')
      ->xpath('intro_image');
    $this->addFieldMapping('field_intro_image:source_dir')
      ->defaultValue($this->mediaDirectory);
    $this->addFieldMapping('field_contact', 'contact')
      ->xpath('contact')
      ->sourceMigration($arguments['field_migrations']['field_contact']);
    $this->addFieldMapping('field_place_type', 'place_type')
      ->xpath('place_type')
      ->sourceMigration($arguments['field_migrations']['field_place_type']);
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
      'contact' => t('Contact'),
      'intro_image' => t('Intro Image'),
      'intro_text' => t('Intro Text'),
      'place_type' => t('Place Type'),
    );
  }

  /**
   * Get the node migration's type/bundle.
   *
   * @return string
   *   The machine name of the node type/bundle.
   */
  protected function getNodeType() {
    return 'place_profile';
  }

}
