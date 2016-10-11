<?php
/**
 * @file
 * Contains UserBaseMigration class.
 */

/**
 * Class UserBaseMigration.
 */
abstract class UserBaseMigration extends FixtureMigrationXml {

  /**
   * Constructor method for class.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments) {
    $arguments['schema'] = MigrateDestinationUser::getKeySchema();
    parent::__construct($arguments);
    $user_options = array(
      'language' => 'en',
    );
    $this->destination = new MigrateDestinationUser($user_options);
  }

}
