<?php
/**
 * @file
 * Contains FixtureMigrationXml. Base class for all fixture migrations.
 */

/**
 * Class FixtureMigrationXml.
 */
abstract class FixtureMigrationXml extends XMLMigration {

  protected $dataDirectory;
  protected $mediaDirectory;

  /**
   * Specify what fields are available to the XML mapping.
   *
   * @return array
   *   The fields that this XML migration contains.
   */
  abstract protected function getFields();

  /**
   * Initialize the class.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->dependencies = isset($arguments['dependencies']) ? $arguments['dependencies'] : array();
    $this->dataDirectory = DRUPAL_ROOT . '/' . drupal_get_path('module', 'bos_fixtures') . '/data/' . $arguments['group_name'] . '/fixtures';
    $this->mediaDirectory = DRUPAL_ROOT . '/' . drupal_get_path('module', 'bos_fixtures') . '/data/' . $arguments['group_name'] . '/files';
    $this->team = array(
      new MigrateTeamMember('Les Peabody', 'lpeabody@wearegenuine.com', t('PHP Developer')),
    );
    // Set the migration source.
    $this->source = new MigrateSourceXML(
      $this->dataDirectory . '/' . $arguments['data_file'],
      $arguments['item_xpath'],
      'id',
      $this->getFields(),
      array(
        'track_changes' => 1,
      )
    );

    // Create a migration map. All fixture migrations will use the field 'id'
    // as it's unique identifier.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      $arguments['schema']
    );
  }

  /**
   * Gets the default text format.
   *
   * If the migration group defines the format, use that, otherwise defualt to
   * filtered_html.
   *
   * @return string
   *   The default format to be used for text fields.
   */
  public function getDefaultFormat() {
    $arguments = $this->getGroup()->getArguments();
    if (isset($arguments['default_format'])) {
      return $arguments['default_format'];
    }
    return 'filtered_html';
  }

}
