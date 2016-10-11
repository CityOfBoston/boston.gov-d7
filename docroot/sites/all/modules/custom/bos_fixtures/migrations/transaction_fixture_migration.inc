<?php
/**
 * @file
 * Contains TransactionFixtureMigration class.
 */

/**
 * Class TransactionFixtureMigration.
 */
class TransactionFixtureMigration extends NodeBaseMigration {
  /**
   * Constructor for person profile fixture migration.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = 'Migration class for Transaction content type fixtures.';

    $this->addFieldMapping('title', 'title')
      ->xpath('title');
    $this->addFieldMapping('uid', 'author')
      ->xpath('author')
      ->sourceMigration($arguments['field_migrations']['uid'])
      ->defaultValue(1);
    $this->addFieldMapping('field_description', 'description')
      ->xpath('description');
    $this->addFieldMapping('field_sticky', 'sticky')
      ->xpath('sticky');
    $this->addFieldMapping('field_link', 'link')
      ->xpath('link')
      ->sourceMigration($arguments['field_migrations']['field_link']);
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
      'description' => t('Description'),
      'link' => t('Transaction Link'),
      'sticky' => t('Sticky'),
    );
  }

  /**
   * Get the node migration's type/bundle.
   *
   * @return string
   *   The machine name of the node type/bundle.
   */
  protected function getNodeType() {
    return 'transaction';
  }

}
