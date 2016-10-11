<?php
/**
 * @file
 * Contains DocumentFixtureMigration class.
 */

/**
 * Class DocumentFixtureMigration.
 */
class DocumentFixtureMigration extends ParagraphsBaseMigration {

  /**
   * Class constructor.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = t('Migration for document links.');

    $this->addFieldMapping('field_title', 'title')
      ->xpath('title');
    $this->addFieldMapping('field_document', 'file')
      ->xpath('file');
    $this->addFieldMapping('field_document:source_dir')
      ->defaultValue($this->mediaDirectory);
  }

  /**
   * Get the name of the paragraph field that this migration maps to.
   *
   * @return string
   *   Returns the name of the paragraph field.
   */
  protected function getFieldName() {
    return 'field_link';
  }

  /**
   * Specify what fields are available to the XML mapping.
   *
   * @return array
   *   The fields that this XML migration contains.
   */
  protected function getFields() {
    return $arguments['fields'] = array(
      'id' => t('ID'),
      'title' => t('Document Title'),
      'file' => t('Document File'),
    );
  }

  /**
   * Get the paragraph migration's type/bundle.
   *
   * @return string
   *   The machine name of the paragraph type/bundle.
   */
  protected function getParagraphType() {
    return 'document';
  }

}
