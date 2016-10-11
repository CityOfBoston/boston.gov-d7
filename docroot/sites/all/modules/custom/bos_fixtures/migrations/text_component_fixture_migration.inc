<?php
/**
 * @file
 * Contains TextComponentFixtureMigration class.
 */

/**
 * Class TextComponentFixtureMigration.
 */
class TextComponentFixtureMigration extends ParagraphsBaseMigration {

  /**
   * Class constructor.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = t('Migration for Text components.');

    $this->addFieldMapping('field_component_title', 'title')
      ->xpath('title');
    $this->addFieldMapping('field_hide_title_bar', 'hide_title')
      ->xpath('hide_title');
    $this->addFieldMapping('field_short_title', 'short_title')
      ->xpath('short_title');
    $this->addFieldMapping('field_contact', 'contact')
      ->xpath('contact')
      ->sourceMigration($arguments['field_migrations']['field_contact']);
    $this->addFieldMapping('field_background_image', 'background_image')
      ->xpath('background_image');
    $this->addFieldMapping('field_text_blocks', 'text_blocks')
      ->xpath('text_blocks')
      ->sourceMigration($arguments['field_migrations']['field_text_blocks'])
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
      'title' => t('Component Title'),
      'short_title' => t('Component Short Title'),
      'contact' => t('Contact'),
      'hide_title' => t('Hide Title Bar'),
      'text_blocks' => t('Text Blocks'),
    );
  }

  /**
   * Get the name of the paragraph field that this migration maps to.
   *
   * @return string
   *   Returns the name of the paragraph field.
   */
  protected function getFieldName() {
    return 'field_components';
  }

  /**
   * Get the paragraph migration's type/bundle.
   *
   * @return string
   *   The machine name of the paragraph type/bundle.
   */
  protected function getParagraphType() {
    return 'text';
  }

}
