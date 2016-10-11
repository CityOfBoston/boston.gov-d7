<?php
/**
 * @file
 * Contains LandingFixtureMigration class.
 */

/**
 * Class LandingFixtureMigration.
 */
class LandingFixtureMigration extends NodeBaseMigration {
  /**
   * Constructor for landing fixture migration.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = 'Migration class for landing page fixtures.';

    $this->addFieldMapping('title', 'title')
      ->xpath('title');
    $this->addFieldMapping('uid', 'author')
      ->xpath('author')
      ->sourceMigration($arguments['field_migrations']['uid'])
      ->defaultValue(1);
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
      'id' => t('User ID'),
      'author' => t('Author'),
      'title' => t('Title'),
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
    return 'landing_page';
  }

}
