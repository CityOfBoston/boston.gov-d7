<?php
/**
 * @file
 * Contains InternalLinkFixtureMigration class.
 */

/**
 * Class InternalLinkFixtureMigration.
 */
class InternalLinkFixtureMigration extends ParagraphsBaseMigration {

  /**
   * Class constructor.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = t('Migration for internal links.');

    $this->addFieldMapping('field_title', 'title')
      ->xpath('title');
    $this->addFieldMapping('field_internal_link', 'link')
      ->xpath('link')
      ->sourceMigration($arguments['field_migrations']['field_internal_link']);
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
      'title' => t('Link Title'),
      'link' => t('Internal Link'),
    );
  }

  /**
   * Get the paragraph migration's type/bundle.
   *
   * @return string
   *   The machine name of the paragraph type/bundle.
   */
  protected function getParagraphType() {
    return 'internal_link';
  }

}
