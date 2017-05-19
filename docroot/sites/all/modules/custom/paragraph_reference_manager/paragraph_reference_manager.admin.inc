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
      // Select only the fields that are paragraph reference.
      if ($type == 'paragraphs') {
        //$entity_ref_fields .= " $name <br />";
        $entity_ref[$name][] = $bundle;
      }
    }
  }
  foreach ($entity_ref as $field => $content_types) {
    //echo 'field is ' . $field . '<br />';
    //echo 'content type is ' . $content_types . '<br /><br />';
    $form_field_key = 'paragraph_reference_manager' . $field;
    $form[$form_field_key] = array(
      '#type' => 'fieldset',
      '#title' => $field,//t(),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    foreach ($content_types as $content_type) {
      $form[$form_field_key][$content_type] = array(
        '#type' => 'checkbox',
        '#title' => $content_type,
        '#default_value' => 0,
      );
    }
  }
  //return $entity_ref_fields;
  return system_settings_form($form);
}
