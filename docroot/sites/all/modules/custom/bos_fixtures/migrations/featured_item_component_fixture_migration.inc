<?php
/**
 * @file
 * Contains FeaturedItemComponentFixtureMigration class.
 */

/**
 * Class FeaturedItemComponentFixtureMigration.
 */
class FeaturedItemComponentFixtureMigration extends ParagraphsBaseMigration {

  /**
   * Class constructor.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $this->description = t('Migration for featured item components.');

    $this->addFieldMapping('field_featured_item', 'reference')
      ->xpath('reference')
      ->sourceMigration($arguments['field_migrations']['field_featured_item']);
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
      'reference' => t('Referenced Content'),
    );
  }

  /**
   * Get the name of the paragraph field that this migration maps to.
   *
   * @return string
   *   Returns the name of the paragraph field.
   */
  protected function getFieldName() {
    return 'field_header_component';
  }

  /**
   * Get the paragraph migration's type/bundle.
   *
   * @return string
   *   The machine name of the paragraph type/bundle.
   */
  protected function getParagraphType() {
    return 'featured_item';
  }

}
