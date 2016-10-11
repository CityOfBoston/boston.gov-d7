<?php
/**
 * @file
 * Contains ExternalLinkFixtureMigration class.
 */

/**
 * Class ExternalLinkFixtureMigration.
 */
class ExternalLinkFixtureMigration extends ParagraphsBaseMigration {

  /**
   * Class constructor.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = t('Migration for external links.');

    $this->addFieldMapping('field_external_link', 'link_href')
      ->xpath('link_href');
    $this->addFieldMapping('field_external_link:title', 'title')
      ->xpath('link_title');
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
      'link_title' => t('Link Title'),
      'link_href' => t('Link Destination'),
    );
  }

  /**
   * Get the paragraph migration's type/bundle.
   *
   * @return string
   *   The machine name of the paragraph type/bundle.
   */
  protected function getParagraphType() {
    return 'external_link';
  }

}
