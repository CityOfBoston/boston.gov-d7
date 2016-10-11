<?php
/**
 * @file
 * bos_view_upcoming_events_feed.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bos_view_upcoming_events_feed_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'upcoming_events_feed';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Upcoming Events Feed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Upcoming Events Feed';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'events';
  $handler->display->display_options['style_options']['top_child_object'] = 'event';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
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
  /* Field: Content: Intro Image */
  $handler->display->display_options['fields']['field_intro_image']['id'] = 'field_intro_image';
  $handler->display->display_options['fields']['field_intro_image']['table'] = 'field_data_field_intro_image';
  $handler->display->display_options['fields']['field_intro_image']['field'] = 'field_intro_image';
  $handler->display->display_options['fields']['field_intro_image']['label'] = '';
  $handler->display->display_options['fields']['field_intro_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_intro_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_intro_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_intro_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_intro_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_intro_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_intro_image']['settings'] = array(
    'url_type' => '0',
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_intro_image']['field_api_classes'] = TRUE;
  /* Field: Field: Intro Text */
  $handler->display->display_options['fields']['field_intro_text']['id'] = 'field_intro_text';
  $handler->display->display_options['fields']['field_intro_text']['table'] = 'field_data_field_intro_text';
  $handler->display->display_options['fields']['field_intro_text']['field'] = 'field_intro_text';
  $handler->display->display_options['fields']['field_intro_text']['label'] = '';
  $handler->display->display_options['fields']['field_intro_text']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_intro_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_intro_text']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_intro_text']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_intro_text']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Event Date */
  $handler->display->display_options['fields']['field_event_dates']['id'] = 'field_event_dates';
  $handler->display->display_options['fields']['field_event_dates']['table'] = 'field_data_field_event_dates';
  $handler->display->display_options['fields']['field_event_dates']['field'] = 'field_event_dates';
  $handler->display->display_options['fields']['field_event_dates']['ui_name'] = 'Event Date';
  $handler->display->display_options['fields']['field_event_dates']['label'] = '';
  $handler->display->display_options['fields']['field_event_dates']['alter']['text'] = '[field_event_dates-value]';
  $handler->display->display_options['fields']['field_event_dates']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_event_dates']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_event_dates']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_event_dates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_dates']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_event_dates']['settings'] = array(
    'format_type' => 'boston_short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_event_dates']['delta_offset'] = '0';
  /* Field: Content: Details Link */
  $handler->display->display_options['fields']['field_details_link']['id'] = 'field_details_link';
  $handler->display->display_options['fields']['field_details_link']['table'] = 'field_data_field_details_link';
  $handler->display->display_options['fields']['field_details_link']['field'] = 'field_details_link';
  $handler->display->display_options['fields']['field_details_link']['label'] = '';
  $handler->display->display_options['fields']['field_details_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_details_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_details_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_details_link']['type'] = 'link_url';
  /* Field: Content: Event Dates */
  $handler->display->display_options['fields']['field_event_dates_1']['id'] = 'field_event_dates_1';
  $handler->display->display_options['fields']['field_event_dates_1']['table'] = 'field_data_field_event_dates';
  $handler->display->display_options['fields']['field_event_dates_1']['field'] = 'field_event_dates';
  $handler->display->display_options['fields']['field_event_dates_1']['label'] = '';
  $handler->display->display_options['fields']['field_event_dates_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_dates_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_event_dates_1']['settings'] = array(
    'format_type' => 'calendar_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_event_dates_1']['delta_offset'] = '0';
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address']['alter']['text'] = '[field_address-thoroughfare]
[field_address-premise]';
  $handler->display->display_options['fields']['field_address']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Sort criterion: Content: Event Dates -  start date (field_event_dates) */
  $handler->display->display_options['sorts']['field_event_dates_value']['id'] = 'field_event_dates_value';
  $handler->display->display_options['sorts']['field_event_dates_value']['table'] = 'field_data_field_event_dates';
  $handler->display->display_options['sorts']['field_event_dates_value']['field'] = 'field_event_dates_value';
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
    'event' => 'event',
  );
  /* Filter criterion: Content: Event Dates -  start date (field_event_dates) */
  $handler->display->display_options['filters']['field_event_dates_value']['id'] = 'field_event_dates_value';
  $handler->display->display_options['filters']['field_event_dates_value']['table'] = 'field_data_field_event_dates';
  $handler->display->display_options['filters']['field_event_dates_value']['field'] = 'field_event_dates_value';
  $handler->display->display_options['filters']['field_event_dates_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_event_dates_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_event_dates_value']['default_date'] = 'now';

  /* Display: Upcoming Events Feed */
  $handler = $view->new_display('page', 'Upcoming Events Feed', 'page');
  $handler->display->display_options['path'] = 'api/v1/upcoming-events';
  $export['upcoming_events_feed'] = $view;

  return $export;
}
