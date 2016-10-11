<?php
/**
 * @file
 * Administration forms.
 */

/**
 * Create a form for the admin to set up the header area of the profile page.
 */
function _hub_settings_apache_solr_admin($form, &$form_state) {

  if (variable_get('hub_settings_apache_solr_no_results_suggestions')) {
    $no_results_format = variable_get('hub_settings_apache_solr_no_results_suggestions')['format'];
  }
  else {
    $no_results_format = 'filtered_html';
  }

  $no_results_default = hub_settings_apache_solr_no_results_suggestions_text();

  $form['hub_settings_apache_solr_no_results_suggestions'] = array(
    '#type' => 'text_format',
    '#title' => t('Header Text'),
    '#rows' => 8,
    '#default_value' => variable_get('hub_settings_apache_solr_no_results_suggestions', array('value' => $no_results_default))['value'],
    '#required' => FALSE,
    '#format' => $no_results_format,
  );

  return system_settings_form($form);
}

/**
 * Return the default noResults text for a apachesolr search.
 *
 * @return string
 *   Apache suggestion text after no results come back.
 */
function hub_settings_apache_solr_no_results_suggestions_text() {
  $no_results_default = "<h4>Suggestions</h4>";
  $no_results_default .= "<ul>";
  $no_results_default .= "<li>Make sure all words are spelled correctly.</li>";
  $no_results_default .= "<li>Try different keywords.</li>";
  $no_results_default .= "<li>Try more general keywords</li>";
  $no_results_default .= "<li>Try fewer keywords</li>";
  $no_results_default .= "</ul>";

  return $no_results_default;
}
