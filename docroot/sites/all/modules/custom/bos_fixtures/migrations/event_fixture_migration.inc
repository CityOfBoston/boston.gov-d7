<?php
/**
 * @file
 * Contains EventFixtureMigration class.
 */

/**
 * Class EventFixtureMigration.
 */
class EventFixtureMigration extends NodeBaseMigration {
  /**
   * Constructor for event fixture migration.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = 'Migration class for fixture Event pages.';

    $this->addFieldMapping('title', 'title')
      ->xpath('title');
    $this->addFieldMapping('uid', 'author')
      ->xpath('author')
      ->sourceMigration($arguments['field_migrations']['uid'])
      ->defaultValue(1);
    $this->addFieldMapping('field_address')
      ->defaultValue('US');
    $this->addFieldMapping('field_address:thoroughfare', 'address')
      ->xpath('address');
    $this->addFieldMapping('field_phone_number', 'phone')
      ->xpath('phone');
    $this->addFieldMapping('field_cost', 'cost')
      ->xpath('cost');
    $this->addFieldMapping('field_address:locality', 'city')
      ->xpath('city');
    $this->addFieldMapping('field_address:administrative_area', 'state')
      ->xpath('state');
    $this->addFieldMapping('field_address:postal_code', 'zip')
      ->xpath('zip');
    $this->addFieldMapping('field_description', 'description')
      ->callbacks('trim')
      ->xpath('description');
    $this->addFieldMapping('field_event_contact', 'event_contact')
      ->xpath('event_contact');
    $this->addFieldMapping('field_event_dates', 'from_date')
      ->xpath('dates/from');
    $this->addFieldMapping('field_event_dates:to', 'to_date')
      ->xpath('dates/to');
    $this->addFieldMapping('field_event_dates:rrule', 'repeat_rule')
      ->xpath('dates/repeat');
    $this->addFieldMapping('field_details_link', 'details_url')
      ->xpath('details/url');
    $this->addFieldMapping('field_details_link:title', 'details_title')
      ->xpath('details/title');
    $this->addFieldMapping('field_thumbnail', 'image')
      ->xpath('image');
    $this->addFieldMapping('field_thumbnail:source_dir')
      ->defaultValue($this->mediaDirectory);
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
      'event_contact' => t('Contact'),
      'address' => t('Address'),
      'phone' => t('Phone Number'),
      'cost' => t('Cost'),
      'city' => t('City'),
      'state' => t('State'),
      'zip' => t('Zip Code'),
      'from_date' => t('Event Start Date'),
      'to_date' => t('Event End Date'),
      'repeat_rule' => t('Repeat Rule'),
      'details_url' => t('Details Link'),
      'details_title' => t('Details Link Title'),
      'image' => t('Event Image'),
    );
  }

  /**
   * Get the node migration's type/bundle.
   *
   * @return string
   *   The machine name of the node type/bundle.
   */
  protected function getNodeType() {
    return 'event';
  }

}
