<?php
/**
 * @file
 * bos_view_upcoming_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bos_view_upcoming_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'upcoming_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Upcoming Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No post content related to this department is available at this time.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_contact_target_id']['id'] = 'field_contact_target_id';
  $handler->display->display_options['relationships']['field_contact_target_id']['table'] = 'field_data_field_contact';
  $handler->display->display_options['relationships']['field_contact_target_id']['field'] = 'field_contact_target_id';
  $handler->display->display_options['relationships']['field_contact_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_department_profile_target_id']['id'] = 'field_department_profile_target_id';
  $handler->display->display_options['relationships']['field_department_profile_target_id']['table'] = 'field_data_field_department_profile';
  $handler->display->display_options['relationships']['field_department_profile_target_id']['field'] = 'field_department_profile_target_id';
  $handler->display->display_options['relationships']['field_department_profile_target_id']['relationship'] = 'field_contact_target_id';
  $handler->display->display_options['relationships']['field_department_profile_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_place_target_id']['id'] = 'field_place_target_id';
  $handler->display->display_options['relationships']['field_place_target_id']['table'] = 'field_data_field_place';
  $handler->display->display_options['relationships']['field_place_target_id']['field'] = 'field_place_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Event Dates */
  $handler->display->display_options['fields']['field_event_dates']['id'] = 'field_event_dates';
  $handler->display->display_options['fields']['field_event_dates']['table'] = 'field_data_field_event_dates';
  $handler->display->display_options['fields']['field_event_dates']['field'] = 'field_event_dates';
  $handler->display->display_options['fields']['field_event_dates']['label'] = '';
  $handler->display->display_options['fields']['field_event_dates']['element_type'] = '0';
  $handler->display->display_options['fields']['field_event_dates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_dates']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_event_dates']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_event_dates']['settings'] = array(
    'format_type' => 'boston_featured',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_event_dates']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_event_dates']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_event_dates']['field_api_classes'] = TRUE;
  /* Field: Content: Intro Image */
  $handler->display->display_options['fields']['field_intro_image']['id'] = 'field_intro_image';
  $handler->display->display_options['fields']['field_intro_image']['table'] = 'field_data_field_intro_image';
  $handler->display->display_options['fields']['field_intro_image']['field'] = 'field_intro_image';
  $handler->display->display_options['fields']['field_intro_image']['label'] = '';
  $handler->display->display_options['fields']['field_intro_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_intro_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_intro_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_intro_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_intro_image']['empty'] = 'default';
  $handler->display->display_options['fields']['field_intro_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_intro_image']['settings'] = array(
    'image_style' => 'topic_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_intro_image']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_intro_image']['field_api_classes'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Field: Thumbnail */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_type'] = '0';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_thumbnail']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'med-large_square_360x360',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_thumbnail']['field_api_classes'] = TRUE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_public_notice_date']['id'] = 'field_public_notice_date';
  $handler->display->display_options['fields']['field_public_notice_date']['table'] = 'field_data_field_public_notice_date';
  $handler->display->display_options['fields']['field_public_notice_date']['field'] = 'field_public_notice_date';
  $handler->display->display_options['fields']['field_public_notice_date']['label'] = '';
  $handler->display->display_options['fields']['field_public_notice_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_public_notice_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_public_notice_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_public_notice_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_public_notice_date']['settings'] = array(
    'format_type' => 'boston_featured',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_public_notice_date']['field_api_classes'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_featured_item_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_public_notice_date) */
  $handler->display->display_options['sorts']['field_public_notice_date_value']['id'] = 'field_public_notice_date_value';
  $handler->display->display_options['sorts']['field_public_notice_date_value']['table'] = 'field_data_field_public_notice_date';
  $handler->display->display_options['sorts']['field_public_notice_date_value']['field'] = 'field_public_notice_date_value';
  /* Sort criterion: Content: Event Dates -  start date (field_event_dates) */
  $handler->display->display_options['sorts']['field_event_dates_value']['id'] = 'field_event_dates_value';
  $handler->display->display_options['sorts']['field_event_dates_value']['table'] = 'field_data_field_event_dates';
  $handler->display->display_options['sorts']['field_event_dates_value']['field'] = 'field_event_dates_value';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'public_notice' => 'public_notice',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Date -  start date (field_public_notice_date) */
  $handler->display->display_options['filters']['field_public_notice_date_value']['id'] = 'field_public_notice_date_value';
  $handler->display->display_options['filters']['field_public_notice_date_value']['table'] = 'field_data_field_public_notice_date';
  $handler->display->display_options['filters']['field_public_notice_date_value']['field'] = 'field_public_notice_date_value';
  $handler->display->display_options['filters']['field_public_notice_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_public_notice_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_public_notice_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_public_notice_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_public_notice_date_value']['default_date'] = '-3 hours';
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['views_exclude_previous']['id'] = 'views_exclude_previous';
  $handler->display->display_options['filters']['views_exclude_previous']['table'] = 'node';
  $handler->display->display_options['filters']['views_exclude_previous']['field'] = 'views_exclude_previous';
  $handler->display->display_options['filters']['views_exclude_previous']['value'] = array(
    'node_view' => 'node_view',
  );
  $handler->display->display_options['filters']['views_exclude_previous']['group'] = 1;
  /* Filter criterion: Content: Event Dates -  start date (field_event_dates) */
  $handler->display->display_options['filters']['field_event_dates_value']['id'] = 'field_event_dates_value';
  $handler->display->display_options['filters']['field_event_dates_value']['table'] = 'field_data_field_event_dates';
  $handler->display->display_options['filters']['field_event_dates_value']['field'] = 'field_event_dates_value';
  $handler->display->display_options['filters']['field_event_dates_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_dates_value']['group'] = 2;
  $handler->display->display_options['filters']['field_event_dates_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_event_dates_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_event_dates_value']['default_date'] = '-3 hours';
  /* Filter criterion: Content: Event not sponsored by the City (field_city_sponsored) */
  $handler->display->display_options['filters']['field_city_sponsored_value']['id'] = 'field_city_sponsored_value';
  $handler->display->display_options['filters']['field_city_sponsored_value']['table'] = 'field_data_field_city_sponsored';
  $handler->display->display_options['filters']['field_city_sponsored_value']['field'] = 'field_city_sponsored_value';
  $handler->display->display_options['filters']['field_city_sponsored_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_city_sponsored_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'field_featured_item_target_id';
  $handler->display->display_options['filters']['nid']['operator'] = 'empty';

  /* Display: Upcoming Events */
  $handler = $view->new_display('block', 'Upcoming Events', 'most_recent');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['display_description'] = 'The events in the near future.';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no upcoming events available at this time.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_featured_item_paragraphs_item_1']['id'] = 'reverse_field_featured_item_paragraphs_item_1';
  $handler->display->display_options['relationships']['reverse_field_featured_item_paragraphs_item_1']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_featured_item_paragraphs_item_1']['field'] = 'reverse_field_featured_item_paragraphs_item';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_featured_item_target_id']['id'] = 'field_featured_item_target_id';
  $handler->display->display_options['relationships']['field_featured_item_target_id']['table'] = 'field_data_field_featured_item';
  $handler->display->display_options['relationships']['field_featured_item_target_id']['field'] = 'field_featured_item_target_id';
  $handler->display->display_options['relationships']['field_featured_item_target_id']['relationship'] = 'reverse_field_featured_item_paragraphs_item_1';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Event Dates -  start date (field_event_dates) */
  $handler->display->display_options['sorts']['field_event_dates_value']['id'] = 'field_event_dates_value';
  $handler->display->display_options['sorts']['field_event_dates_value']['table'] = 'field_data_field_event_dates';
  $handler->display->display_options['sorts']['field_event_dates_value']['field'] = 'field_event_dates_value';
  /* Sort criterion: Content: Date -  start date (field_public_notice_date) */
  $handler->display->display_options['sorts']['field_public_notice_date_value']['id'] = 'field_public_notice_date_value';
  $handler->display->display_options['sorts']['field_public_notice_date_value']['table'] = 'field_data_field_public_notice_date';
  $handler->display->display_options['sorts']['field_public_notice_date_value']['field'] = 'field_public_notice_date_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $export['upcoming_events'] = $view;

  return $export;
}
