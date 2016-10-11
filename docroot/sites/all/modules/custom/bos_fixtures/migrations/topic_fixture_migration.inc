<?php
/**
 * @file
 * Contains TopicFixtureMigration class.
 */

/**
 * Class TopicFixtureMigration.
 */
class TopicFixtureMigration extends NodeBaseMigration {

  /**
   * Constructor for topic fixture migration.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = 'Migration class for Topic page fixtures.';

    $this->addFieldMapping('title', 'title')
      ->xpath('title');
    $this->addFieldMapping('uid', 'author')
      ->xpath('author')
      ->sourceMigration($arguments['field_migrations']['uid'])
      ->defaultValue(1);
    $this->addFieldMapping('field_intro_image', 'intro_image')
      ->xpath('intro_image');
    $this->addFieldMapping('field_intro_image:source_dir')
      ->defaultValue($this->mediaDirectory);
    $this->addFieldMapping('field_intro_text', 'intro_text')
      ->xpath('intro_text');
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
      'intro_image' => t('Intro Image'),
      'intro_text' => t('Intro Text'),
    );
  }

  /**
   * Get the node migration's type/bundle.
   *
   * @return string
   *   The machine name of the node type/bundle.
   */
  protected function getNodeType() {
    return 'topic_page';
  }

}
