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
    foreach ($fields_info as $field_name => $value) {
      $field_info = field_info_field($field_name);
      $type = $field_info['type'];
      $name = $field_info['field_name'];
      $label = $value['label'];
      // Select only the fields that are paragraph reference.
      if ($type == 'paragraphs') {
        // Create array with information needed to create form.
        $entity_ref[$name]['bundle'][] = $bundle;
        $entity_ref[$name]['label'] = $label;
      }
    }
  }
  foreach ($entity_ref as $field => $field_info) {
    $form_field_key = 'paragraph_reference_manager' . $field;
    $form[$form_field_key] = array(
      '#type' => 'fieldset',
      '#title' => $field_info['label'] . " ($field)",//t(),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    foreach ($field_info['bundle'] as $content_type) {
      $form[$form_field_key][$content_type] = array(
        '#type' => 'checkbox',
        '#title' => $bundle_info[$content_type]['label'] . " ($content_type)",
        '#default_value' => 0,
      );
    }
  }
  return system_settings_form($form);
}
