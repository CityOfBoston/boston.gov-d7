<?php
/**
 * @file
 * Contains ProgramInitiativeFixtureMigration class.
 */

/**
 * Class ProgramInitiativeFixtureMigration.
 */
class ProgramInitiativeFixtureMigration extends NodeBaseMigration {

  /**
   * Constructor for place profile fixture migration.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = 'Migration class for program initiative fixtures.';
    $default_format = $this->getDefaultFormat();

    $this->addFieldMapping('title', 'title')
      ->xpath('title');
    $this->addFieldMapping('field_published_date', 'publish_date')
      ->xpath('publish_date');
    $this->addFieldMapping('field_updated_date', 'updated_date')
      ->xpath('updated_date');
    $this->addFieldMapping('body', 'body')
      ->xpath('body')
      ->callbacks('trim');
    $this->addFieldMapping('body:format')
      ->defaultValue($default_format);
    $this->addFieldMapping('field_intro_text', 'intro_text')
      ->xpath('intro_text')
      ->callbacks('trim');
    $this->addFieldMapping('field_intro_text:format')
      ->defaultValue($default_format);
    $this->addFieldMapping('uid', 'author')
      ->xpath('author')
      ->sourceMigration($arguments['field_migrations']['uid'])
      ->defaultValue(1);
    $this->addFieldMapping('field_intro_image', 'intro_image')
      ->xpath('intro_image');
    $this->addFieldMapping('field_intro_image:source_dir')
      ->defaultValue($this->mediaDirectory);
    $this->addFieldMapping('field_program_logo', 'logo')
      ->xpath('logo');
    $this->addFieldMapping('field_program_logo:source_dir')
      ->defaultValue($this->mediaDirectory);
    $this->addFieldMapping('field_contacts', 'contacts')
      ->xpath('contacts')
      ->separator(',')
      ->sourceMigration($arguments['field_migrations']['field_contacts']);
    $this->addFieldMapping('field_sidebar_components', 'sidebar_items')
      ->xpath('sidebar_items')
      ->separator(',')
      ->sourceMigration($arguments['field_migrations']['field_sidebar_components']);
    $this->addFieldMapping('field_program_type', 'program_type')
      ->xpath('program_type')
      ->sourceMigration($arguments['field_migrations']['field_program_type']);
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
      'publish_date' => t('Published Date'),
      'updated_date' => t('Updated Date'),
      'title' => t('Title'),
      'body' => t('Body'),
      'contacts' => t('Contact'),
      'sidebar_items' => t('Sidebar Items'),
      'intro_image' => t('Intro Image'),
      'logo' => t('Logo'),
      'intro_text' => t('Intro Text'),
      'program_type' => t('Program Type'),
    );
  }

  /**
   * Get the node migration's type/bundle.
   *
   * @return string
   *   The machine name of the node type/bundle.
   */
  protected function getNodeType() {
    return 'program_initiative_profile';
  }

}
