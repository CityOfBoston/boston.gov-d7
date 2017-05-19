<?php

/**
 * @file
 * Admin callback for Paragraph Reference Manager.
 */

/**
 * Build the settings for managing references.
 */
function paragraph_reference_manager_admin() {
  // Get list of all content types.
  $bundle_info = field_info_bundles('node');
  foreach ($bundle_info as $bundle => $value) {
    // Get all the fields for the current content type.
    $fields_info = field_info_instances('node', $bundle);
    foreach ($fields_info as $field_name => $field_info) {
      $type = $field_info['widget']['type'];
      $name = $field_name;
      $label = $field_info['label'];
      // Select only the fields that are paragraph reference.
      if ($type == 'paragraphs_embed') {
        // Create array with information needed to create form.
        $entity_ref_fields[$name]['bundle'][] = $bundle;
        $entity_ref_fields[$name]['label'] = $label;
      }
    }
  }
  if (!isset($entity_ref_fields)) {
    // Set a default message if no paragraph reference fields are found.
    drupal_set_message('There are no paragraph reference fields on any of your content types.', 'warning');
    return;
  }
  foreach ($entity_ref_fields as $field_name => $field_info) {
    $form_field_key = 'paragraph_reference_manager' . $field_name;
    // Group options by paragraph reference field.
    $form[$form_field_key] = array(
      '#type' => 'fieldset',
      '#title' => $field_info['label'] . " ($field_name)",
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    foreach ($field_info['bundle'] as $content_type) {
      // Create checkbox for each content type in group.
      $form[$form_field_key][$content_type] = array(
        '#type' => 'checkbox',
        '#title' => $bundle_info[$content_type]['label'] . " ($content_type)",
        '#default_value' => 0,
      );
    }
  }
  return system_settings_form($form);
}
