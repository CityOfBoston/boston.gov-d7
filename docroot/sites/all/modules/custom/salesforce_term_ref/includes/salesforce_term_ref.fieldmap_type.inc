<?php

/**
 * @file
 * This files adds the 'Term Reference' fieldmap type.
 */

/**
 * Implements hook_salesforce_mapping_fieldmap_type().
 */
function salesforce_term_ref_salesforce_mapping_fieldmap_type() {
  $types = array(
    'term_ref' => array(
      'label' => t('Term Reference'),
      'field_type' => 'select',
      'description' => t('Select a Drupal taxonomy reference field in order to map incoming terms.'),
      'options_callback' => 'salesforce_mapping_related_entity_fieldmap_options',
      'push_value_callback' => 'salesforce_mapping_related_entity_fieldmap_push_value',
      'pull_value_callback' => 'salesforce_mapping_related_entity_fieldmap_pull_value',
    ),
  );
  return $types;
}
