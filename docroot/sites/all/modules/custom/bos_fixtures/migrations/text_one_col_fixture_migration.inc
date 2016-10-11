<?php
/**
 * @file
 * Contains TextOneColFixtureMigration class.
 */

/**
 * Class TextOneColFixtureMigration.
 */
class TextOneColFixtureMigration extends ParagraphsBaseMigration {

  /**
   * Class constructor.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = t('Migration for Text One Column paragraphs.');
    $default_format = $this->getDefaultFormat();

    $this->addFieldMapping('field_middle_column', 'middle_column')
      ->xpath('middle_column');
    $this->addFieldMapping('field_middle_column:format')
      ->defaultValue($default_format);
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
      'middle_column' => t('Middle Column'),
    );
  }

  /**
   * Get the name of the paragraph field that this migration maps to.
   *
   * @return string
   *   Returns the name of the paragraph field.
   */
  protected function getFieldName() {
    return 'field_text_blocks';
  }

  /**
   * Get the paragraph migration's type/bundle.
   *
   * @return string
   *   The machine name of the paragraph type/bundle.
   */
  protected function getParagraphType() {
    return 'text_one_column';
  }

}
