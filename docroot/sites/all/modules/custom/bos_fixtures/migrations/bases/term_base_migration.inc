<?php
/**
 * @file
 * Contains TermBaseMigration class.
 */

/**
 * Class TermBaseMigration.
 */
abstract class TermBaseMigration extends FixtureMigrationXml {

  /**
   * Get the term migration's type/bundle.
   *
   * @return string
   *   The machine name of the term type/bundle.
   */
  abstract protected function getTermType();

  /**
   * Class constructor.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    $arguments['schema'] = MigrateDestinationTerm::getKeySchema();
    parent::__construct($arguments);
    $this->destination = new MigrateDestinationTerm($this->getTermType());
  }

}
