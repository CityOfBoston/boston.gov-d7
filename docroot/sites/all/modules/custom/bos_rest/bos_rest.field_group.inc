<?php
/**
 * @file
 * bos_rest.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_rest_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metrics|taxonomy_term|cityscore_metrics|default';
  $field_group->group_name = 'group_metrics';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'cityscore_metrics';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metrics',
    'weight' => '2',
    'children' => array(
      0 => 'field_previous_month',
      1 => 'field_previous_quarter',
      2 => 'field_day',
      3 => 'field_previous_day',
      4 => 'field_previous_week',
      5 => 'field_calc_timestamp',
      6 => 'field_table_timestamp',
      7 => 'field_cs_weight',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-metrics field-group-fieldset',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Metrics');

  return $field_groups;
}
