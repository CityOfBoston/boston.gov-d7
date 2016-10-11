<?php
/**
 * @file
 * bos_component_featured_topics.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_featured_topics_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-featured_topics-field_topics'.
  $field_instances['paragraphs_item-featured_topics-field_topics'] = array(
    'bundle' => 'featured_topics',
    'default_value' => array(
      0 => array(
        'target_id' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Control + Click to select multiple (CMD+Click on a Mac)',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 1,
          'view_mode' => 'featured_topics',
        ),
        'type' => 'entityreference_entity_view',
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
    'field_name' => 'field_topics',
    'label' => 'Guides',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'entityreference_autocreate' => 0,
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Control + Click to select multiple (CMD+Click on a Mac)');
  t('Guides');

  return $field_instances;
}
