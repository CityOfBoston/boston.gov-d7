<?php
/**
 * @file
 * bos_view_landing_public_notice.features.inc
 */

/**
 * Implements hook_views_api().
 */
function bos_view_landing_public_notice_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_preprocess_views_exposed_form().
 */
function bos_view_landing_public_notice_preprocess_views_exposed_form(&$vars) {
  if ($vars['form']['#id'] == 'views-exposed-form-public-notice-landing-page') {
    $vars['widget_groups'] = array(
      'search by title' => array(),
      'filter by department' => array(),
    );

    foreach ($vars['widgets'] as $id => $widget) {
      switch ($id) {
        case 'filter-title':
          $vars['widget_groups']['search by title'][$id] = $widget;
          break;

        case 'filter-field_contact_target_id':
          $vars['widget_groups']['filter by department'][$id] = $widget;
          break;
      }
    }
  }
}
