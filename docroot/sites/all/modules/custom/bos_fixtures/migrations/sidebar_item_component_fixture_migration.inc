<?php
/**
 * @file
 * Contains SidebarItemComponentFixtureMigration class.
 */

/**
 * Class SidebarItemComponentFixtureMigration.
 */
class SidebarItemComponentFixtureMigration extends ParagraphsBaseMigration {

  /**
   * Class constructor.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = t('Migration for sidebar item components.');
    $default_format = $this->getDefaultFormat();

    $this->addFieldMapping('field_title', 'title')
      ->xpath('title');
    $this->addFieldMapping('field_sidebar_text', 'text')
      ->xpath('text');
    $this->addFieldMapping('field_sidebar_text:format')
      ->defaultValue($default_format);
  }

  /**
   * Get the name of the paragraph field that this migration maps to.
   *
   * @return string
   *   Returns the name of the paragraph field.
   */
  protected function getFieldName() {
    return 'field_sidebar_components';
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
      'title' => t('Sidebar Title'),
      'text' => t('Sidebar Text'),
    );
  }

  /**
   * Get the paragraph migration's type/bundle.
   *
   * @return string
   *   The machine name of the paragraph type/bundle.
   */
  protected function getParagraphType() {
    return 'sidebar_item';
  }

}
