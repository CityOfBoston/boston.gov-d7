<?php
/**
 * @file
 * bos_metrolist_affordable_housing.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bos_metrolist_affordable_housing_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'metrolist_affordable_housing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Metrolist Affordable Housing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Metrolist Affordable Housing';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'combine' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_mah_lottery_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_mah_address' => 'field_mah_address',
    'field_mah_zipcode' => 'field_mah_zipcode',
    'field_mah_neighborhood' => 'field_mah_neighborhood',
    'field_mah_phone' => 'field_mah_phone',
    'field_mah_email' => 'field_mah_email',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mah_address' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mah_zipcode' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mah_neighborhood' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mah_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mah_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no Lottery listings at this time. Please check back here for updates.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Property Address */
  $handler->display->display_options['fields']['field_mah_address']['id'] = 'field_mah_address';
  $handler->display->display_options['fields']['field_mah_address']['table'] = 'field_data_field_mah_address';
  $handler->display->display_options['fields']['field_mah_address']['field'] = 'field_mah_address';
  $handler->display->display_options['fields']['field_mah_address']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_address']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_address']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_address']['field_api_classes'] = TRUE;
  /* Field: Content: Zipcode */
  $handler->display->display_options['fields']['field_mah_zipcode']['id'] = 'field_mah_zipcode';
  $handler->display->display_options['fields']['field_mah_zipcode']['table'] = 'field_data_field_mah_zipcode';
  $handler->display->display_options['fields']['field_mah_zipcode']['field'] = 'field_mah_zipcode';
  $handler->display->display_options['fields']['field_mah_zipcode']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_zipcode']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_zipcode']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_zipcode']['field_api_classes'] = TRUE;
  /* Field: Content: Outer Location */
  $handler->display->display_options['fields']['field_mah_outer_location']['id'] = 'field_mah_outer_location';
  $handler->display->display_options['fields']['field_mah_outer_location']['table'] = 'field_data_field_mah_outer_location';
  $handler->display->display_options['fields']['field_mah_outer_location']['field'] = 'field_mah_outer_location';
  $handler->display->display_options['fields']['field_mah_outer_location']['label'] = '';
  $handler->display->display_options['fields']['field_mah_outer_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mah_outer_location']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_outer_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mah_outer_location']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_outer_location']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_outer_location']['field_api_classes'] = TRUE;
  /* Field: Content: Neighborhood */
  $handler->display->display_options['fields']['field_mah_neighborhood']['id'] = 'field_mah_neighborhood';
  $handler->display->display_options['fields']['field_mah_neighborhood']['table'] = 'field_data_field_mah_neighborhood';
  $handler->display->display_options['fields']['field_mah_neighborhood']['field'] = 'field_mah_neighborhood';
  $handler->display->display_options['fields']['field_mah_neighborhood']['label'] = 'Location';
  $handler->display->display_options['fields']['field_mah_neighborhood']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mah_neighborhood']['alter']['path'] = 'neighborhood/[field_mah_neighborhood]';
  $handler->display->display_options['fields']['field_mah_neighborhood']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_mah_neighborhood']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_neighborhood']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_neighborhood']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_neighborhood']['empty'] = '[field_mah_outer_location]';
  $handler->display->display_options['fields']['field_mah_neighborhood']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_mah_neighborhood']['field_api_classes'] = TRUE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_mah_phone']['id'] = 'field_mah_phone';
  $handler->display->display_options['fields']['field_mah_phone']['table'] = 'field_data_field_mah_phone';
  $handler->display->display_options['fields']['field_mah_phone']['field'] = 'field_mah_phone';
  $handler->display->display_options['fields']['field_mah_phone']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_phone']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_phone']['field_api_classes'] = TRUE;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_mah_email']['id'] = 'field_mah_email';
  $handler->display->display_options['fields']['field_mah_email']['table'] = 'field_data_field_mah_email';
  $handler->display->display_options['fields']['field_mah_email']['field'] = 'field_mah_email';
  $handler->display->display_options['fields']['field_mah_email']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mah_email']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_email']['field_api_classes'] = TRUE;
  /* Sort criterion: Content: Property Address (field_mah_address) */
  $handler->display->display_options['sorts']['field_mah_address_value']['id'] = 'field_mah_address_value';
  $handler->display->display_options['sorts']['field_mah_address_value']['table'] = 'field_data_field_mah_address';
  $handler->display->display_options['sorts']['field_mah_address_value']['field'] = 'field_mah_address_value';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'metrolist_affordable_housing' => 'metrolist_affordable_housing',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_mah_address' => 'field_mah_address',
    'field_mah_zipcode' => 'field_mah_zipcode',
    'field_mah_outer_location' => 'field_mah_outer_location',
    'field_mah_neighborhood' => 'field_mah_neighborhood',
    'field_mah_phone' => 'field_mah_phone',
    'field_mah_email' => 'field_mah_email',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'neighborhoods';
  /* Filter criterion: Content: Property Address (field_mah_address) */
  $handler->display->display_options['filters']['field_mah_address_value']['id'] = 'field_mah_address_value';
  $handler->display->display_options['filters']['field_mah_address_value']['table'] = 'field_data_field_mah_address';
  $handler->display->display_options['filters']['field_mah_address_value']['field'] = 'field_mah_address_value';
  $handler->display->display_options['filters']['field_mah_address_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_mah_address_value']['group'] = 1;
  /* Filter criterion: Content: Zipcode (field_mah_zipcode) */
  $handler->display->display_options['filters']['field_mah_zipcode_value']['id'] = 'field_mah_zipcode_value';
  $handler->display->display_options['filters']['field_mah_zipcode_value']['table'] = 'field_data_field_mah_zipcode';
  $handler->display->display_options['filters']['field_mah_zipcode_value']['field'] = 'field_mah_zipcode_value';
  $handler->display->display_options['filters']['field_mah_zipcode_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_mah_zipcode_value']['group'] = 1;
  /* Filter criterion: Content: Phone (field_mah_phone) */
  $handler->display->display_options['filters']['field_mah_phone_value']['id'] = 'field_mah_phone_value';
  $handler->display->display_options['filters']['field_mah_phone_value']['table'] = 'field_data_field_mah_phone';
  $handler->display->display_options['filters']['field_mah_phone_value']['field'] = 'field_mah_phone_value';
  $handler->display->display_options['filters']['field_mah_phone_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_mah_phone_value']['group'] = 2;
  /* Filter criterion: Content: Email (field_mah_email) */
  $handler->display->display_options['filters']['field_mah_email_value']['id'] = 'field_mah_email_value';
  $handler->display->display_options['filters']['field_mah_email_value']['table'] = 'field_data_field_mah_email';
  $handler->display->display_options['filters']['field_mah_email_value']['field'] = 'field_mah_email_value';
  $handler->display->display_options['filters']['field_mah_email_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_mah_email_value']['group'] = 2;
  /* Filter criterion: Content: Publish to Metrolist (field_mah_publish_to_metrolist) */
  $handler->display->display_options['filters']['field_mah_publish_to_metrolist_value']['id'] = 'field_mah_publish_to_metrolist_value';
  $handler->display->display_options['filters']['field_mah_publish_to_metrolist_value']['table'] = 'field_data_field_mah_publish_to_metrolist';
  $handler->display->display_options['filters']['field_mah_publish_to_metrolist_value']['field'] = 'field_mah_publish_to_metrolist_value';
  $handler->display->display_options['filters']['field_mah_publish_to_metrolist_value']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'metrolist-affordable-housing';

  /* Display: Page - Lottery */
  $handler = $view->new_display('page', 'Page - Lottery', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_mah_address' => 'field_mah_address',
    'field_mah_zipcode' => 'field_mah_zipcode',
    'field_mah_outer_location' => 'field_mah_outer_location',
    'field_mah_neighborhood' => 'field_mah_neighborhood',
    'field_mah_lottery_type' => 'field_mah_lottery_type',
    'nothing' => 'nothing',
    'field_mah_contact' => 'field_mah_contact',
    'field_mah_phone' => 'field_mah_phone',
    'field_mah_email' => 'field_mah_email',
    'nothing_1' => 'nothing_1',
    'field_mah_lottery_deadline' => 'field_mah_lottery_deadline',
    'field_mah_lottery_url' => 'field_mah_lottery_url',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mah_address' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mah_zipcode' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mah_outer_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mah_neighborhood' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mah_lottery_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mah_contact' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mah_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mah_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mah_lottery_deadline' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mah_lottery_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Property Address */
  $handler->display->display_options['fields']['field_mah_address']['id'] = 'field_mah_address';
  $handler->display->display_options['fields']['field_mah_address']['table'] = 'field_data_field_mah_address';
  $handler->display->display_options['fields']['field_mah_address']['field'] = 'field_mah_address';
  $handler->display->display_options['fields']['field_mah_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mah_address']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_address']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_address']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_address']['field_api_classes'] = TRUE;
  /* Field: Content: Zipcode */
  $handler->display->display_options['fields']['field_mah_zipcode']['id'] = 'field_mah_zipcode';
  $handler->display->display_options['fields']['field_mah_zipcode']['table'] = 'field_data_field_mah_zipcode';
  $handler->display->display_options['fields']['field_mah_zipcode']['field'] = 'field_mah_zipcode';
  $handler->display->display_options['fields']['field_mah_zipcode']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mah_zipcode']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_zipcode']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_zipcode']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_zipcode']['field_api_classes'] = TRUE;
  /* Field: Content: Outer Location */
  $handler->display->display_options['fields']['field_mah_outer_location']['id'] = 'field_mah_outer_location';
  $handler->display->display_options['fields']['field_mah_outer_location']['table'] = 'field_data_field_mah_outer_location';
  $handler->display->display_options['fields']['field_mah_outer_location']['field'] = 'field_mah_outer_location';
  $handler->display->display_options['fields']['field_mah_outer_location']['label'] = '';
  $handler->display->display_options['fields']['field_mah_outer_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mah_outer_location']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_outer_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mah_outer_location']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_outer_location']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_outer_location']['field_api_classes'] = TRUE;
  /* Field: Content: Neighborhood */
  $handler->display->display_options['fields']['field_mah_neighborhood']['id'] = 'field_mah_neighborhood';
  $handler->display->display_options['fields']['field_mah_neighborhood']['table'] = 'field_data_field_mah_neighborhood';
  $handler->display->display_options['fields']['field_mah_neighborhood']['field'] = 'field_mah_neighborhood';
  $handler->display->display_options['fields']['field_mah_neighborhood']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mah_neighborhood']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mah_neighborhood']['alter']['path'] = 'neighborhood/[field_mah_neighborhood]';
  $handler->display->display_options['fields']['field_mah_neighborhood']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_mah_neighborhood']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_neighborhood']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_neighborhood']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_neighborhood']['empty'] = '[field_mah_outer_location]';
  $handler->display->display_options['fields']['field_mah_neighborhood']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_mah_neighborhood']['field_api_classes'] = TRUE;
  /* Field: Content: Lottery Type */
  $handler->display->display_options['fields']['field_mah_lottery_type']['id'] = 'field_mah_lottery_type';
  $handler->display->display_options['fields']['field_mah_lottery_type']['table'] = 'field_data_field_mah_lottery_type';
  $handler->display->display_options['fields']['field_mah_lottery_type']['field'] = 'field_mah_lottery_type';
  $handler->display->display_options['fields']['field_mah_lottery_type']['label'] = 'Type';
  $handler->display->display_options['fields']['field_mah_lottery_type']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_lottery_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_lottery_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_lottery_type']['field_api_classes'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Property Address';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title] [field_mah_address] [field_mah_neighborhood] [field_mah_zipcode]';
  /* Field: Content: Household Income Limits (AMI) */
  $handler->display->display_options['fields']['field_mah_household_income_limit']['id'] = 'field_mah_household_income_limit';
  $handler->display->display_options['fields']['field_mah_household_income_limit']['table'] = 'field_data_field_mah_household_income_limit';
  $handler->display->display_options['fields']['field_mah_household_income_limit']['field'] = 'field_mah_household_income_limit';
  $handler->display->display_options['fields']['field_mah_household_income_limit']['label'] = 'Household Income Limits ​(AMI%)';
  $handler->display->display_options['fields']['field_mah_household_income_limit']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_household_income_limit']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_household_income_limit']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_household_income_limit']['field_api_classes'] = TRUE;
  /* Field: Content: Property Manager Contact */
  $handler->display->display_options['fields']['field_mah_contact']['id'] = 'field_mah_contact';
  $handler->display->display_options['fields']['field_mah_contact']['table'] = 'field_data_field_mah_contact';
  $handler->display->display_options['fields']['field_mah_contact']['field'] = 'field_mah_contact';
  $handler->display->display_options['fields']['field_mah_contact']['label'] = '';
  $handler->display->display_options['fields']['field_mah_contact']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mah_contact']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_contact']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mah_contact']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_contact']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_contact']['field_api_classes'] = TRUE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_mah_phone']['id'] = 'field_mah_phone';
  $handler->display->display_options['fields']['field_mah_phone']['table'] = 'field_data_field_mah_phone';
  $handler->display->display_options['fields']['field_mah_phone']['field'] = 'field_mah_phone';
  $handler->display->display_options['fields']['field_mah_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mah_phone']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_phone']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_phone']['field_api_classes'] = TRUE;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_mah_email']['id'] = 'field_mah_email';
  $handler->display->display_options['fields']['field_mah_email']['table'] = 'field_data_field_mah_email';
  $handler->display->display_options['fields']['field_mah_email']['field'] = 'field_mah_email';
  $handler->display->display_options['fields']['field_mah_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mah_email']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mah_email']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_email']['field_api_classes'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Contact';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_mah_contact] [field_mah_phone] [field_mah_email]';
  /* Field: Content: Lottery Application Deadline */
  $handler->display->display_options['fields']['field_mah_lottery_deadline']['id'] = 'field_mah_lottery_deadline';
  $handler->display->display_options['fields']['field_mah_lottery_deadline']['table'] = 'field_data_field_mah_lottery_deadline';
  $handler->display->display_options['fields']['field_mah_lottery_deadline']['field'] = 'field_mah_lottery_deadline';
  $handler->display->display_options['fields']['field_mah_lottery_deadline']['label'] = 'Application Deadline';
  $handler->display->display_options['fields']['field_mah_lottery_deadline']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_lottery_deadline']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_lottery_deadline']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_lottery_deadline']['empty'] = 'Open Enrollment';
  $handler->display->display_options['fields']['field_mah_lottery_deadline']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_mah_lottery_deadline']['field_api_classes'] = TRUE;
  /* Field: Content: Lottery URL */
  $handler->display->display_options['fields']['field_mah_lottery_url']['id'] = 'field_mah_lottery_url';
  $handler->display->display_options['fields']['field_mah_lottery_url']['table'] = 'field_data_field_mah_lottery_url';
  $handler->display->display_options['fields']['field_mah_lottery_url']['field'] = 'field_mah_lottery_url';
  $handler->display->display_options['fields']['field_mah_lottery_url']['label'] = 'Listing Information';
  $handler->display->display_options['fields']['field_mah_lottery_url']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mah_lottery_url']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mah_lottery_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mah_lottery_url']['empty'] = 'Reach out to Contact';
  $handler->display->display_options['fields']['field_mah_lottery_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_mah_lottery_url']['field_api_classes'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'metrolist_affordable_housing' => 'metrolist_affordable_housing',
  );
  /* Filter criterion: Content: Property Address (field_mah_address) */
  $handler->display->display_options['filters']['field_mah_address_value']['id'] = 'field_mah_address_value';
  $handler->display->display_options['filters']['field_mah_address_value']['table'] = 'field_data_field_mah_address';
  $handler->display->display_options['filters']['field_mah_address_value']['field'] = 'field_mah_address_value';
  $handler->display->display_options['filters']['field_mah_address_value']['operator'] = '!=';
  /* Filter criterion: Content: Zipcode (field_mah_zipcode) */
  $handler->display->display_options['filters']['field_mah_zipcode_value']['id'] = 'field_mah_zipcode_value';
  $handler->display->display_options['filters']['field_mah_zipcode_value']['table'] = 'field_data_field_mah_zipcode';
  $handler->display->display_options['filters']['field_mah_zipcode_value']['field'] = 'field_mah_zipcode_value';
  $handler->display->display_options['filters']['field_mah_zipcode_value']['operator'] = '!=';
  /* Filter criterion: Content: Lottery (field_mah_lottery_indicator) */
  $handler->display->display_options['filters']['field_mah_lottery_indicator_value']['id'] = 'field_mah_lottery_indicator_value';
  $handler->display->display_options['filters']['field_mah_lottery_indicator_value']['table'] = 'field_data_field_mah_lottery_indicator';
  $handler->display->display_options['filters']['field_mah_lottery_indicator_value']['field'] = 'field_mah_lottery_indicator_value';
  $handler->display->display_options['filters']['field_mah_lottery_indicator_value']['value'] = 'Yes';
  /* Filter criterion: Content: Not Active (field_mah_not_active) */
  $handler->display->display_options['filters']['field_mah_not_active_value']['id'] = 'field_mah_not_active_value';
  $handler->display->display_options['filters']['field_mah_not_active_value']['table'] = 'field_data_field_mah_not_active';
  $handler->display->display_options['filters']['field_mah_not_active_value']['field'] = 'field_mah_not_active_value';
  $handler->display->display_options['filters']['field_mah_not_active_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_mah_not_active_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Publish to Metrolist (field_mah_publish_to_metrolist) */
  $handler->display->display_options['filters']['field_mah_publish_to_metrolist_value']['id'] = 'field_mah_publish_to_metrolist_value';
  $handler->display->display_options['filters']['field_mah_publish_to_metrolist_value']['table'] = 'field_data_field_mah_publish_to_metrolist';
  $handler->display->display_options['filters']['field_mah_publish_to_metrolist_value']['field'] = 'field_mah_publish_to_metrolist_value';
  $handler->display->display_options['filters']['field_mah_publish_to_metrolist_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'metrolist-affordable-housing-lottery';
  $export['metrolist_affordable_housing'] = $view;

  return $export;
}
