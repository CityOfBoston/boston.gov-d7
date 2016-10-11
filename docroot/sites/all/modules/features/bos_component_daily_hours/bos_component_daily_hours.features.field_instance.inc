<?php
/**
 * @file
 * bos_component_daily_hours.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_daily_hours_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-daily_hours-field_daily_hours'.
  $field_instances['paragraphs_item-daily_hours-field_daily_hours'] = array(
    'bundle' => 'daily_hours',
    'default_value' => array(
      0 => array(
        'starthours' => 900,
        'endhours' => 1700,
        'day' => 1,
        'daydelta' => 0,
      ),
      1 => array(
        'day' => 2,
        'daydelta' => 0,
        'endhours' => 1700,
        'starthours' => 900,
      ),
      2 => array(
        'day' => 3,
        'daydelta' => 0,
        'endhours' => 1700,
        'starthours' => 900,
      ),
      3 => array(
        'day' => 4,
        'daydelta' => 0,
        'endhours' => 1700,
        'starthours' => 900,
      ),
      4 => array(
        'day' => 5,
        'daydelta' => 0,
        'endhours' => 1700,
        'starthours' => 900,
      ),
    ),
    'deleted' => 0,
    'description' => 'Add daily open hours.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'office_hours',
        'settings' => array(
          'closedformat' => 'Closed',
          'compress' => 0,
          'current_status' => array(
            'closed_text' => 'Currently closed',
            'open_text' => 'Currently open!',
            'position' => 'hide',
          ),
          'date_first_day' => 0,
          'daysformat' => 'long',
          'grouped' => 0,
          'hoursformat' => 1,
          'separator_day_hours' => ': ',
          'separator_days' => '<br />',
          'separator_grouped_days' => ' - ',
          'separator_hours_hours' => '-',
          'separator_more_hours' => ', ',
          'showclosed' => 'open',
          'timezone_field' => '',
        ),
        'type' => 'office_hours',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_daily_hours',
    'label' => 'Daily Hours',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'office_hours',
      'settings' => array(),
      'type' => 'office_hours',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-daily_hours-field_hours_icon'.
  $field_instances['paragraphs_item-daily_hours-field_hours_icon'] = array(
    'bundle' => 'daily_hours',
    'default_value' => array(
      0 => array(
        'value' => 'icon-time',
      ),
    ),
    'deleted' => 0,
    'description' => 'Add an hours icon to display next the open hours.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_hours_icon',
    'label' => 'Hours Icon',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-daily_hours-field_title'.
  $field_instances['paragraphs_item-daily_hours-field_title'] = array(
    'bundle' => 'daily_hours',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add a label to the open hours.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_title',
    'label' => 'Label',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a label to the open hours.');
  t('Add an hours icon to display next the open hours.');
  t('Add daily open hours.');
  t('Daily Hours');
  t('Hours Icon');
  t('Label');

  return $field_instances;
}
