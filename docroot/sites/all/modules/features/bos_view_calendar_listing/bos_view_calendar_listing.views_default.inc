<?php
/**
 * @file
 * bos_view_calendar_listing.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bos_view_calendar_listing_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'calendar';
  $view->description = 'Calendar displays for Boston.gov.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Calendar';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'filtered_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'field_event_dates_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
        'datepicker_options' => '',
      ),
    ),
    'field_event_dates_value2' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
        'datepicker_options' => '',
      ),
    ),
    'title' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_event_type_target_id' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_multiple_neighborhoods_target_id' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_related_departments_target_id' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'prev';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'next';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_event_dates',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: date grouping */
  $handler->display->display_options['fields']['field_event_dates']['id'] = 'field_event_dates';
  $handler->display->display_options['fields']['field_event_dates']['table'] = 'field_data_field_event_dates';
  $handler->display->display_options['fields']['field_event_dates']['field'] = 'field_event_dates';
  $handler->display->display_options['fields']['field_event_dates']['ui_name'] = 'date grouping';
  $handler->display->display_options['fields']['field_event_dates']['label'] = '';
  $handler->display->display_options['fields']['field_event_dates']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_dates']['element_type'] = '0';
  $handler->display->display_options['fields']['field_event_dates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_dates']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_event_dates']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_event_dates']['settings'] = array(
    'format_type' => 'normal_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_event_dates']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_event_dates']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_event_dates']['field_api_classes'] = TRUE;
  /* Field: Content: Rendered Content */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'calendar_listing';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: Content: Related departments */
  $handler->display->display_options['fields']['field_related_departments']['id'] = 'field_related_departments';
  $handler->display->display_options['fields']['field_related_departments']['table'] = 'field_data_field_related_departments';
  $handler->display->display_options['fields']['field_related_departments']['field'] = 'field_related_departments';
  $handler->display->display_options['fields']['field_related_departments']['label'] = '';
  $handler->display->display_options['fields']['field_related_departments']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_related_departments']['element_type'] = '0';
  $handler->display->display_options['fields']['field_related_departments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_departments']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_related_departments']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_related_departments']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_related_departments']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_related_departments']['field_api_classes'] = TRUE;
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Event Dates -  start date (field_event_dates) */
  $handler->display->display_options['filters']['field_event_dates_value']['id'] = 'field_event_dates_value';
  $handler->display->display_options['filters']['field_event_dates_value']['table'] = 'field_data_field_event_dates';
  $handler->display->display_options['filters']['field_event_dates_value']['field'] = 'field_event_dates_value';
  $handler->display->display_options['filters']['field_event_dates_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_dates_value']['group'] = 1;
  $handler->display->display_options['filters']['field_event_dates_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_dates_value']['expose']['operator_id'] = 'field_event_dates_value_op';
  $handler->display->display_options['filters']['field_event_dates_value']['expose']['label'] = 'Event Start';
  $handler->display->display_options['filters']['field_event_dates_value']['expose']['operator'] = 'field_event_dates_value_op';
  $handler->display->display_options['filters']['field_event_dates_value']['expose']['identifier'] = 'field_event_dates_value';
  $handler->display->display_options['filters']['field_event_dates_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['field_event_dates_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_event_dates_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_event_dates_value']['year_range'] = '-0:+10';
  /* Filter criterion: Content: Event Dates - end date (field_event_dates:value2) */
  $handler->display->display_options['filters']['field_event_dates_value2']['id'] = 'field_event_dates_value2';
  $handler->display->display_options['filters']['field_event_dates_value2']['table'] = 'field_data_field_event_dates';
  $handler->display->display_options['filters']['field_event_dates_value2']['field'] = 'field_event_dates_value2';
  $handler->display->display_options['filters']['field_event_dates_value2']['operator'] = '<=';
  $handler->display->display_options['filters']['field_event_dates_value2']['group'] = 1;
  $handler->display->display_options['filters']['field_event_dates_value2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_dates_value2']['expose']['operator_id'] = 'field_event_dates_value2_op';
  $handler->display->display_options['filters']['field_event_dates_value2']['expose']['label'] = 'End Date';
  $handler->display->display_options['filters']['field_event_dates_value2']['expose']['operator'] = 'field_event_dates_value2_op';
  $handler->display->display_options['filters']['field_event_dates_value2']['expose']['identifier'] = 'field_event_dates_value2';
  $handler->display->display_options['filters']['field_event_dates_value2']['expose']['remember_roles'] = array(
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
    56 => 0,
  );
  $handler->display->display_options['filters']['field_event_dates_value2']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_event_dates_value2']['default_date'] = 'now +3 months';
  $handler->display->display_options['filters']['field_event_dates_value2']['year_range'] = '-0:+10';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: Event Type (field_event_type) */
  $handler->display->display_options['filters']['field_event_type_target_id']['id'] = 'field_event_type_target_id';
  $handler->display->display_options['filters']['field_event_type_target_id']['table'] = 'field_data_field_event_type';
  $handler->display->display_options['filters']['field_event_type_target_id']['field'] = 'field_event_type_target_id';
  $handler->display->display_options['filters']['field_event_type_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_event_type_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_type_target_id']['expose']['operator_id'] = 'field_event_type_target_id_op';
  $handler->display->display_options['filters']['field_event_type_target_id']['expose']['label'] = 'Event Type';
  $handler->display->display_options['filters']['field_event_type_target_id']['expose']['operator'] = 'field_event_type_target_id_op';
  $handler->display->display_options['filters']['field_event_type_target_id']['expose']['identifier'] = 'field_event_type_target_id';
  $handler->display->display_options['filters']['field_event_type_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_event_type_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    16 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
  );
  /* Filter criterion: Content: Related Neighborhoods (field_multiple_neighborhoods) */
  $handler->display->display_options['filters']['field_multiple_neighborhoods_target_id']['id'] = 'field_multiple_neighborhoods_target_id';
  $handler->display->display_options['filters']['field_multiple_neighborhoods_target_id']['table'] = 'field_data_field_multiple_neighborhoods';
  $handler->display->display_options['filters']['field_multiple_neighborhoods_target_id']['field'] = 'field_multiple_neighborhoods_target_id';
  $handler->display->display_options['filters']['field_multiple_neighborhoods_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_multiple_neighborhoods_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_multiple_neighborhoods_target_id']['expose']['operator_id'] = 'field_multiple_neighborhoods_target_id_op';
  $handler->display->display_options['filters']['field_multiple_neighborhoods_target_id']['expose']['operator'] = 'field_multiple_neighborhoods_target_id_op';
  $handler->display->display_options['filters']['field_multiple_neighborhoods_target_id']['expose']['identifier'] = 'field_multiple_neighborhoods_target_id';
  $handler->display->display_options['filters']['field_multiple_neighborhoods_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_multiple_neighborhoods_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    16 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
  );
  /* Filter criterion: Content: Event not sponsored by the City (field_city_sponsored) */
  $handler->display->display_options['filters']['field_city_sponsored_value']['id'] = 'field_city_sponsored_value';
  $handler->display->display_options['filters']['field_city_sponsored_value']['table'] = 'field_data_field_city_sponsored';
  $handler->display->display_options['filters']['field_city_sponsored_value']['field'] = 'field_city_sponsored_value';
  $handler->display->display_options['filters']['field_city_sponsored_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_city_sponsored_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_city_sponsored_value']['group'] = 1;
  /* Filter criterion: Content: Related departments (field_related_departments) */
  $handler->display->display_options['filters']['field_related_departments_target_id']['id'] = 'field_related_departments_target_id';
  $handler->display->display_options['filters']['field_related_departments_target_id']['table'] = 'field_data_field_related_departments';
  $handler->display->display_options['filters']['field_related_departments_target_id']['field'] = 'field_related_departments_target_id';
  $handler->display->display_options['filters']['field_related_departments_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_related_departments_target_id']['expose']['operator_id'] = 'field_related_departments_target_id_op';
  $handler->display->display_options['filters']['field_related_departments_target_id']['expose']['operator'] = 'field_related_departments_target_id_op';
  $handler->display->display_options['filters']['field_related_departments_target_id']['expose']['identifier'] = 'field_related_departments_target_id';
  $handler->display->display_options['filters']['field_related_departments_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_related_departments_target_id']['expose']['remember_roles'] = array(
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
    56 => 0,
  );

  /* Display: Listing */
  $handler = $view->new_display('page', 'Listing', 'listing');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h2 class="m-t000">No Events Found</h2>
<div class="intro-text supporting-text">Thomas Paine noted "These are the times that try men\'s souls." Well this is a time to try another search</div>
<form accept-charset="UTF-8" action="/search" method="get" class="sf sf--md">
    <input name="utf8" type="hidden" value="✓">
    <input name="facet[]" type="hidden" value="event">
    <div class="sf-i">
        <input type="text" name="query" id="q" placeholder="Search…" class="sf-i-f" autocomplete="off">
        <button class="sf-i-b">Search</button>
    </div>
</form>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['path'] = 'view-page/calendar';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'date_ical';
  $handler->display->display_options['style_options']['cal_name'] = 'City of Boston Events';
  $handler->display->display_options['style_options']['unescape_punctuation'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'date_ical_fields';
  $handler->display->display_options['row_options']['date_field'] = 'field_event_dates';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['description_field'] = 'body';
  $handler->display->display_options['row_options']['location_field'] = 'field_address';
  $handler->display->display_options['row_options']['additional_settings'] = array(
    'skip_blank_dates' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: date grouping */
  $handler->display->display_options['fields']['field_event_dates']['id'] = 'field_event_dates';
  $handler->display->display_options['fields']['field_event_dates']['table'] = 'field_data_field_event_dates';
  $handler->display->display_options['fields']['field_event_dates']['field'] = 'field_event_dates';
  $handler->display->display_options['fields']['field_event_dates']['ui_name'] = 'date grouping';
  $handler->display->display_options['fields']['field_event_dates']['label'] = '';
  $handler->display->display_options['fields']['field_event_dates']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_dates']['element_type'] = '0';
  $handler->display->display_options['fields']['field_event_dates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_dates']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_event_dates']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_event_dates']['settings'] = array(
    'format_type' => 'normal_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_event_dates']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_event_dates']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_event_dates']['field_api_classes'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['alter']['text'] = '[field_address-thoroughfare]
[field_address-locality] [field_address-dependent_locality] [field_address-postal_code]';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_address']['field_api_classes'] = TRUE;
  $handler->display->display_options['path'] = 'events.ical';
  $export['calendar'] = $view;

  return $export;
}
