<?php
/**
 * @file
 * bos_view_api_public_notices.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bos_view_api_public_notices_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'api_public_notice';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'API: Public Notice';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_public_notice_date']['id'] = 'field_public_notice_date';
  $handler->display->display_options['fields']['field_public_notice_date']['table'] = 'field_data_field_public_notice_date';
  $handler->display->display_options['fields']['field_public_notice_date']['field'] = 'field_public_notice_date';
  $handler->display->display_options['fields']['field_public_notice_date']['label'] = 'event_date';
  $handler->display->display_options['fields']['field_public_notice_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_public_notice_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_public_notice_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Is there public testimony? */
  $handler->display->display_options['fields']['field_is_there_public_testimony']['id'] = 'field_is_there_public_testimony';
  $handler->display->display_options['fields']['field_is_there_public_testimony']['table'] = 'field_data_field_is_there_public_testimony';
  $handler->display->display_options['fields']['field_is_there_public_testimony']['field'] = 'field_is_there_public_testimony';
  $handler->display->display_options['fields']['field_is_there_public_testimony']['label'] = 'is_testimony';
  $handler->display->display_options['fields']['field_is_there_public_testimony']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_is_there_public_testimony']['element_default_classes'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'id';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'posted';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'boston_featured';
  /* Field: Content: Time public testimony begins */
  $handler->display->display_options['fields']['field_time']['id'] = 'field_time';
  $handler->display->display_options['fields']['field_time']['table'] = 'field_data_field_time';
  $handler->display->display_options['fields']['field_time']['field'] = 'field_time';
  $handler->display->display_options['fields']['field_time']['label'] = 'testimony_time';
  $handler->display->display_options['fields']['field_time']['element_type'] = '0';
  $handler->display->display_options['fields']['field_time']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_time']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_time']['settings'] = array(
    'format_type' => 'calendar_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_time']['field_api_classes'] = TRUE;
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Field: Drawer */
  $handler->display->display_options['fields']['field_drawer']['id'] = 'field_drawer';
  $handler->display->display_options['fields']['field_drawer']['table'] = 'field_data_field_drawer';
  $handler->display->display_options['fields']['field_drawer']['field'] = 'field_drawer';
  $handler->display->display_options['fields']['field_drawer']['label'] = '';
  $handler->display->display_options['fields']['field_drawer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_drawer']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_drawer']['settings'] = array(
    'view_mode' => 'token',
  );
  $handler->display->display_options['fields']['field_drawer']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'public_notice' => 'public_notice',
  );

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['path'] = 'public-notices';
  $export['api_public_notice'] = $view;

  return $export;
}
