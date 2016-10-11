<?php
/**
 * @file
 * Administration form code.
 */

/**
 * Create a form for the admin to set up the header area of the profile page.
 */
function _hub_profile2_main_admin($form, &$form_state) {

  if (variable_get('hub_profile_header_text')) {
    $header_format = variable_get('hub_profile_header_text')['format'];
  }
  else {
    $header_format = 'filtered_html';
  }

  $form['hub_profile_header_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Header Text'),
    '#rows' => 5,
    '#default_value' => variable_get('hub_profile_header_text', array('value' => 'Header Text for user profile.'))['value'],
    '#required' => FALSE,
    '#format' => $header_format,
  );

  $form['hub_profile_header_payroll_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Payroll Link'),
    '#rows' => 5,
    '#default_value' => variable_get('hub_profile_header_payroll_link', '/payroll'),
    '#required' => FALSE,
  );
  $form['hub_profile_header_leave_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Leave Link'),
    '#rows' => 5,
    '#default_value' => variable_get('hub_profile_header_leave_link', '/leave'),
    '#required' => FALSE,
  );
  $form['hub_profile_header_benefits_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Benefits Link'),
    '#rows' => 5,
    '#default_value' => variable_get('hub_profile_header_benefits_link', '/benefits'),
    '#required' => FALSE,
  );
  $form['hub_profile_change_password_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Change Password URL'),
    '#rows' => 5,
    '#default_value' => variable_get('hub_profile_change_password_url', ''),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}
