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
  $view->name = 'api_public_notices';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'API: Public Notices';
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
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'notices';
  $handler->display->display_options['style_options']['top_child_object'] = 'notice';
  $handler->display->display_options['style_options']['plaintext_output'] = 0;
  $handler->display->display_options['style_options']['remove_newlines'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
  /* Field: Content: Contact Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_email']['type'] = 'text_plain';
  /* Field: Content: Phone Number */
  $handler->display->display_options['fields']['field_phone_number']['id'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['table'] = 'field_data_field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['field'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['label'] = '';
  $handler->display->display_options['fields']['field_phone_number']['element_type'] = '0';
  $handler->display->display_options['fields']['field_phone_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone_number']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_phone_number']['element_default_classes'] = FALSE;
  /* Field: Content: Point of Contact */
  $handler->display->display_options['fields']['field_event_contact']['id'] = 'field_event_contact';
  $handler->display->display_options['fields']['field_event_contact']['table'] = 'field_data_field_event_contact';
  $handler->display->display_options['fields']['field_event_contact']['field'] = 'field_event_contact';
  $handler->display->display_options['fields']['field_event_contact']['label'] = '';
  $handler->display->display_options['fields']['field_event_contact']['element_type'] = '0';
  $handler->display->display_options['fields']['field_event_contact']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_contact']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_event_contact']['element_default_classes'] = FALSE;
  /* Field: Field: Contact */
  $handler->display->display_options['fields']['field_contact']['id'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['table'] = 'field_data_field_contact';
  $handler->display->display_options['fields']['field_contact']['field'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['label'] = '';
  $handler->display->display_options['fields']['field_contact']['element_type'] = '0';
  $handler->display->display_options['fields']['field_contact']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_contact']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_contact']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Intro Text */
  $handler->display->display_options['fields']['field_intro_text']['id'] = 'field_intro_text';
  $handler->display->display_options['fields']['field_intro_text']['table'] = 'field_data_field_intro_text';
  $handler->display->display_options['fields']['field_intro_text']['field'] = 'field_intro_text';
  $handler->display->display_options['fields']['field_intro_text']['label'] = '';
  $handler->display->display_options['fields']['field_intro_text']['element_type'] = '0';
  $handler->display->display_options['fields']['field_intro_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_intro_text']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_intro_text']['element_default_classes'] = FALSE;
  /* Field: Field: Downloads */
  $handler->display->display_options['fields']['field_links']['id'] = 'field_links';
  $handler->display->display_options['fields']['field_links']['table'] = 'field_data_field_links';
  $handler->display->display_options['fields']['field_links']['field'] = 'field_links';
  $handler->display->display_options['fields']['field_links']['label'] = '';
  $handler->display->display_options['fields']['field_links']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_links']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_links']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_links']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_links']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_links']['field_api_classes'] = TRUE;
  /* Field: Field: Drawer */
  $handler->display->display_options['fields']['field_drawer']['id'] = 'field_drawer';
  $handler->display->display_options['fields']['field_drawer']['table'] = 'field_data_field_drawer';
  $handler->display->display_options['fields']['field_drawer']['field'] = 'field_drawer';
  $handler->display->display_options['fields']['field_drawer']['label'] = '';
  $handler->display->display_options['fields']['field_drawer']['alter']['text'] = '\\n';
  $handler->display->display_options['fields']['field_drawer']['element_type'] = '0';
  $handler->display->display_options['fields']['field_drawer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_drawer']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_drawer']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_drawer']['settings'] = array(
    'view_mode' => 'token',
  );
  $handler->display->display_options['fields']['field_drawer']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_drawer']['field_api_classes'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Cancelled */
  $handler->display->display_options['fields']['field_cancelled']['id'] = 'field_cancelled';
  $handler->display->display_options['fields']['field_cancelled']['table'] = 'field_data_field_cancelled';
  $handler->display->display_options['fields']['field_cancelled']['field'] = 'field_cancelled';
  $handler->display->display_options['fields']['field_cancelled']['label'] = '';
  $handler->display->display_options['fields']['field_cancelled']['element_type'] = '0';
  $handler->display->display_options['fields']['field_cancelled']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cancelled']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_cancelled']['element_default_classes'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_public_notice_date']['id'] = 'field_public_notice_date';
  $handler->display->display_options['fields']['field_public_notice_date']['table'] = 'field_data_field_public_notice_date';
  $handler->display->display_options['fields']['field_public_notice_date']['field'] = 'field_public_notice_date';
  $handler->display->display_options['fields']['field_public_notice_date']['label'] = '';
  $handler->display->display_options['fields']['field_public_notice_date']['alter']['text'] = '{
  "start_date": [field_public_notice_date-value],
  "end_date": [field_public_notice_date-value2],
}';
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
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['element_type'] = '0';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_address']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_address']['field_api_classes'] = TRUE;
  /* Field: Field: Extra Info */
  $handler->display->display_options['fields']['field_extra_info']['id'] = 'field_extra_info';
  $handler->display->display_options['fields']['field_extra_info']['table'] = 'field_data_field_extra_info';
  $handler->display->display_options['fields']['field_extra_info']['field'] = 'field_extra_info';
  $handler->display->display_options['fields']['field_extra_info']['label'] = '';
  $handler->display->display_options['fields']['field_extra_info']['element_type'] = '0';
  $handler->display->display_options['fields']['field_extra_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_extra_info']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_extra_info']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_extra_info']['field_api_classes'] = TRUE;
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
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'id';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'id';
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
  $export['api_public_notices'] = $view;

  return $export;
}
