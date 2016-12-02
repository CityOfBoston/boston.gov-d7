<?php
/**
 * @file
 * bos_metrolist.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bos_metrolist_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'metrolist_project_units';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Metrolist Project Units';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Metrolist';
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
        'bef_select_all_none' => FALSE,
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
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_mpu_street_number' => 'field_mpu_street_number',
    'field_mpu_street_name' => 'field_mpu_street_name',
    'field_mpu_zipcode' => 'field_mpu_zipcode',
    'field_mpu_neighborhood' => 'field_mpu_neighborhood',
    'field_mpu_property_phone' => 'field_mpu_property_phone',
    'field_mpu_property_email' => 'field_mpu_property_email',
    'field_mpu_unit_type' => 'field_mpu_unit_type',
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
    'field_mpu_street_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mpu_street_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mpu_zipcode' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mpu_neighborhood' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mpu_property_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mpu_property_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mpu_unit_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Unit Name';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Street # */
  $handler->display->display_options['fields']['field_mpu_street_number']['id'] = 'field_mpu_street_number';
  $handler->display->display_options['fields']['field_mpu_street_number']['table'] = 'field_data_field_mpu_street_number';
  $handler->display->display_options['fields']['field_mpu_street_number']['field'] = 'field_mpu_street_number';
  $handler->display->display_options['fields']['field_mpu_street_number']['label'] = '';
  $handler->display->display_options['fields']['field_mpu_street_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mpu_street_number']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_street_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mpu_street_number']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_street_number']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mpu_street_number']['field_api_classes'] = TRUE;
  /* Field: Content: Street Name */
  $handler->display->display_options['fields']['field_mpu_street_name']['id'] = 'field_mpu_street_name';
  $handler->display->display_options['fields']['field_mpu_street_name']['table'] = 'field_data_field_mpu_street_name';
  $handler->display->display_options['fields']['field_mpu_street_name']['field'] = 'field_mpu_street_name';
  $handler->display->display_options['fields']['field_mpu_street_name']['label'] = 'Address';
  $handler->display->display_options['fields']['field_mpu_street_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mpu_street_name']['alter']['text'] = '[field_mpu_street_number] [field_mpu_street_name]';
  $handler->display->display_options['fields']['field_mpu_street_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_street_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_street_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mpu_street_name']['field_api_classes'] = TRUE;
  /* Field: Content: Zipcode */
  $handler->display->display_options['fields']['field_mpu_zipcode']['id'] = 'field_mpu_zipcode';
  $handler->display->display_options['fields']['field_mpu_zipcode']['table'] = 'field_data_field_mpu_zipcode';
  $handler->display->display_options['fields']['field_mpu_zipcode']['field'] = 'field_mpu_zipcode';
  $handler->display->display_options['fields']['field_mpu_zipcode']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_zipcode']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mpu_zipcode']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_zipcode']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mpu_zipcode']['field_api_classes'] = TRUE;
  /* Field: Content: Neighborhood */
  $handler->display->display_options['fields']['field_mpu_neighborhood']['id'] = 'field_mpu_neighborhood';
  $handler->display->display_options['fields']['field_mpu_neighborhood']['table'] = 'field_data_field_mpu_neighborhood';
  $handler->display->display_options['fields']['field_mpu_neighborhood']['field'] = 'field_mpu_neighborhood';
  $handler->display->display_options['fields']['field_mpu_neighborhood']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_neighborhood']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_neighborhood']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mpu_neighborhood']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_mpu_neighborhood']['field_api_classes'] = TRUE;
  /* Field: Content: Property Phone */
  $handler->display->display_options['fields']['field_mpu_property_phone']['id'] = 'field_mpu_property_phone';
  $handler->display->display_options['fields']['field_mpu_property_phone']['table'] = 'field_data_field_mpu_property_phone';
  $handler->display->display_options['fields']['field_mpu_property_phone']['field'] = 'field_mpu_property_phone';
  /* Field: Content: Property Email */
  $handler->display->display_options['fields']['field_mpu_property_email']['id'] = 'field_mpu_property_email';
  $handler->display->display_options['fields']['field_mpu_property_email']['table'] = 'field_data_field_mpu_property_email';
  $handler->display->display_options['fields']['field_mpu_property_email']['field'] = 'field_mpu_property_email';
  $handler->display->display_options['fields']['field_mpu_property_email']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_property_email']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_property_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mpu_property_email']['field_api_classes'] = TRUE;
  /* Field: Content: Unit Type */
  $handler->display->display_options['fields']['field_mpu_unit_type']['id'] = 'field_mpu_unit_type';
  $handler->display->display_options['fields']['field_mpu_unit_type']['table'] = 'field_data_field_mpu_unit_type';
  $handler->display->display_options['fields']['field_mpu_unit_type']['field'] = 'field_mpu_unit_type';
  $handler->display->display_options['fields']['field_mpu_unit_type']['label'] = '';
  $handler->display->display_options['fields']['field_mpu_unit_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mpu_unit_type']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_unit_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mpu_unit_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_unit_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mpu_unit_type']['field_api_classes'] = TRUE;
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
    'metrolist_project_unit' => 'metrolist_project_unit',
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
    'title' => 'title',
    'field_mpu_street_number' => 'field_mpu_street_number',
    'field_mpu_street_name' => 'field_mpu_street_name',
    'field_mpu_zipcode' => 'field_mpu_zipcode',
    'field_mpu_property_phone' => 'field_mpu_property_phone',
    'field_mpu_property_email' => 'field_mpu_property_email',
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
  /* Filter criterion: Content: Unit Type (field_mpu_unit_type) */
  $handler->display->display_options['filters']['field_mpu_unit_type_value_1']['id'] = 'field_mpu_unit_type_value_1';
  $handler->display->display_options['filters']['field_mpu_unit_type_value_1']['table'] = 'field_data_field_mpu_unit_type';
  $handler->display->display_options['filters']['field_mpu_unit_type_value_1']['field'] = 'field_mpu_unit_type_value';
  $handler->display->display_options['filters']['field_mpu_unit_type_value_1']['value'] = 'External Monitoring';
  $handler->display->display_options['filters']['field_mpu_unit_type_value_1']['group'] = 2;
  /* Filter criterion: Content: Unit Type (field_mpu_unit_type) */
  $handler->display->display_options['filters']['field_mpu_unit_type_value']['id'] = 'field_mpu_unit_type_value';
  $handler->display->display_options['filters']['field_mpu_unit_type_value']['table'] = 'field_data_field_mpu_unit_type';
  $handler->display->display_options['filters']['field_mpu_unit_type_value']['field'] = 'field_mpu_unit_type_value';
  $handler->display->display_options['filters']['field_mpu_unit_type_value']['value'] = 'Rental Unit Group (R)';
  $handler->display->display_options['filters']['field_mpu_unit_type_value']['group'] = 2;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'metrolist-project-units';
  $export['metrolist_project_units'] = $view;

  return $export;
}
