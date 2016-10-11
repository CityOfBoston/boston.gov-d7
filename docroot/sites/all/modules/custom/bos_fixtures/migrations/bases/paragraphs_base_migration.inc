<?php
/**
 * @file
 * Contains ParagraphsBaseMigration class.
 */

/**
 * Class ParagraphsBaseMigration.
 */
abstract class ParagraphsBaseMigration extends FixtureMigrationXml {

  /**
   * Get the name of the paragraph field that this migration maps to.
   *
   * @return string
   *   Returns the name of the paragraph field.
   */
  abstract protected function getFieldName();

  /**
   * Get the paragraph migration's type/bundle.
   *
   * @return string
   *   The machine name of the paragraph type/bundle.
   */
  abstract protected function getParagraphType();

  /**
   * Class constructor.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    $arguments['schema'] = MigrateDestinationParagraphsItem::getKeySchema();
    parent::__construct($arguments);
    $this->paragraph_options = MigrateDestinationParagraphsItem::options('en', 'filtered_html');
    $this->paragraph_options['field_name'] = $this->getFieldName();

    // Set a destination.
    $this->destination = new MigrateDestinationParagraphsItem(
      $this->getParagraphType(),
      $this->paragraph_options
    );
  }

}
