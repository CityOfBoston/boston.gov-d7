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
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
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
  /* Field: Content: Time public testimony begins */
  $handler->display->display_options['fields']['field_time']['id'] = 'field_time';
  $handler->display->display_options['fields']['field_time']['table'] = 'field_data_field_time';
  $handler->display->display_options['fields']['field_time']['field'] = 'field_time';
  $handler->display->display_options['fields']['field_time']['label'] = 'testimony_time';
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Field: Location - Full name */
  $handler->display->display_options['fields']['field_address_name_line']['id'] = 'field_address_name_line';
  $handler->display->display_options['fields']['field_address_name_line']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_name_line']['field'] = 'field_address_name_line';
  $handler->display->display_options['fields']['field_address_name_line']['label'] = 'location_name';
  $handler->display->display_options['fields']['field_address_name_line']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_name_line']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_name_line']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_name_line']['element_default_classes'] = FALSE;
  /* Field: Field: Location - Premise (i.e. Apartment / Suite number) */
  $handler->display->display_options['fields']['field_address_premise']['id'] = 'field_address_premise';
  $handler->display->display_options['fields']['field_address_premise']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_premise']['field'] = 'field_address_premise';
  $handler->display->display_options['fields']['field_address_premise']['label'] = 'location_room';
  $handler->display->display_options['fields']['field_address_premise']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_premise']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_premise']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_premise']['element_default_classes'] = FALSE;
  /* Field: Field: Location - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_address_thoroughfare']['id'] = 'field_address_thoroughfare';
  $handler->display->display_options['fields']['field_address_thoroughfare']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_thoroughfare']['field'] = 'field_address_thoroughfare';
  $handler->display->display_options['fields']['field_address_thoroughfare']['label'] = 'location_street';
  $handler->display->display_options['fields']['field_address_thoroughfare']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address_thoroughfare']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_thoroughfare']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address_thoroughfare']['element_default_classes'] = FALSE;
  /* Field: Content: Canceled */
  $handler->display->display_options['fields']['field_cancelled']['id'] = 'field_cancelled';
  $handler->display->display_options['fields']['field_cancelled']['table'] = 'field_data_field_cancelled';
  $handler->display->display_options['fields']['field_cancelled']['field'] = 'field_cancelled';
  $handler->display->display_options['fields']['field_cancelled']['label'] = 'canceled';
  $handler->display->display_options['fields']['field_cancelled']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cancelled']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cancelled']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_cancelled']['settings'] = array(
    'data_element_key' => '',
    'skip_safe' => 0,
    'skip_empty_values' => 0,
  );
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_public_notice_date']['id'] = 'field_public_notice_date';
  $handler->display->display_options['fields']['field_public_notice_date']['table'] = 'field_data_field_public_notice_date';
  $handler->display->display_options['fields']['field_public_notice_date']['field'] = 'field_public_notice_date';
  $handler->display->display_options['fields']['field_public_notice_date']['label'] = 'notice_date';
  $handler->display->display_options['fields']['field_public_notice_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_public_notice_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_public_notice_date']['settings'] = array(
    'format_type' => 'normal_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_public_notice_date_1']['id'] = 'field_public_notice_date_1';
  $handler->display->display_options['fields']['field_public_notice_date_1']['table'] = 'field_data_field_public_notice_date';
  $handler->display->display_options['fields']['field_public_notice_date_1']['field'] = 'field_public_notice_date';
  $handler->display->display_options['fields']['field_public_notice_date_1']['label'] = 'notice_time';
  $handler->display->display_options['fields']['field_public_notice_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_public_notice_date_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_public_notice_date_1']['settings'] = array(
    'format_type' => 'calendar_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Field: Drawer */
  $handler->display->display_options['fields']['field_drawer']['id'] = 'field_drawer';
  $handler->display->display_options['fields']['field_drawer']['table'] = 'field_data_field_drawer';
  $handler->display->display_options['fields']['field_drawer']['field'] = 'field_drawer';
  $handler->display->display_options['fields']['field_drawer']['label'] = '';
  $handler->display->display_options['fields']['field_drawer']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_drawer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_drawer']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_drawer']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_drawer']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Node: Published at */
  $handler->display->display_options['fields']['published_at']['id'] = 'published_at';
  $handler->display->display_options['fields']['published_at']['table'] = 'publication_date';
  $handler->display->display_options['fields']['published_at']['field'] = 'published_at';
  $handler->display->display_options['fields']['published_at']['label'] = 'posted';
  $handler->display->display_options['fields']['published_at']['date_format'] = 'short';
  $handler->display->display_options['fields']['published_at']['second_date_format'] = 'boston_featured';
  /* Sort criterion: Content: Date -  start date (field_public_notice_date) */
  $handler->display->display_options['sorts']['field_public_notice_date_value']['id'] = 'field_public_notice_date_value';
  $handler->display->display_options['sorts']['field_public_notice_date_value']['table'] = 'field_data_field_public_notice_date';
  $handler->display->display_options['sorts']['field_public_notice_date_value']['field'] = 'field_public_notice_date_value';
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
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'id';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    16 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
    51 => 0,
  );
  /* Filter criterion: Content: Date -  start date (field_public_notice_date) */
  $handler->display->display_options['filters']['field_public_notice_date_value']['id'] = 'field_public_notice_date_value';
  $handler->display->display_options['filters']['field_public_notice_date_value']['table'] = 'field_data_field_public_notice_date';
  $handler->display->display_options['filters']['field_public_notice_date_value']['field'] = 'field_public_notice_date_value';
  $handler->display->display_options['filters']['field_public_notice_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_public_notice_date_value']['default_date'] = '-3 hours';

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['path'] = 'public-notices';
  $export['api_public_notice'] = $view;

  return $export;
}
