<?php
/**
 * @file
 * Contains HeaderTextComponentFixtureMigration class.
 */

/**
 * Class HeaderTextComponentFixtureMigration.
 */
class HeaderTextComponentFixtureMigration extends ParagraphsBaseMigration {

  /**
   * Class constructor.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = t('Migration for header text components.');

    $this->addFieldMapping('field_contact', 'contact')
      ->xpath('contact')
      ->sourceMigration($arguments['field_migrations']['field_contact']);
    $this->addFieldMapping('field_intro_text', 'text')
      ->xpath('text');
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
      'contact' => t('Contact Reference'),
      'text' => t('Introductory Text'),
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
    return 'header_text';
  }

}
