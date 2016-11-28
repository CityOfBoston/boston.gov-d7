<?php
/**
 * @file
 * boston_metrolist_affordable_housing_listing.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function boston_metrolist_affordable_housing_listing_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'metrolist_unit_contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Metrolist Unit Contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Metrolist Unit Contacts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_muc_contact_ref' => 'field_muc_contact_ref',
    'field_muc_project_unit_ref' => 'field_muc_project_unit_ref',
    'field_mpu_street_name' => 'field_mpu_street_name',
    'field_mpu_street_number' => 'field_mpu_street_number',
    'field_mpu_zipcode' => 'field_mpu_zipcode',
    'field_mpu_neighborhood' => 'field_mpu_neighborhood',
    'field_mc_property_phone' => 'field_mc_property_phone',
    'field_mc_property_email' => 'field_mc_property_email',
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
    'field_muc_contact_ref' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_muc_project_unit_ref' => array(
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
    'field_mpu_street_number' => array(
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
    'field_mc_property_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mc_property_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_muc_project_unit_ref_target_id']['id'] = 'field_muc_project_unit_ref_target_id';
  $handler->display->display_options['relationships']['field_muc_project_unit_ref_target_id']['table'] = 'field_data_field_muc_project_unit_ref';
  $handler->display->display_options['relationships']['field_muc_project_unit_ref_target_id']['field'] = 'field_muc_project_unit_ref_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_muc_contact_ref_target_id']['id'] = 'field_muc_contact_ref_target_id';
  $handler->display->display_options['relationships']['field_muc_contact_ref_target_id']['table'] = 'field_data_field_muc_contact_ref';
  $handler->display->display_options['relationships']['field_muc_contact_ref_target_id']['field'] = 'field_muc_contact_ref_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Contact Reference */
  $handler->display->display_options['fields']['field_muc_contact_ref']['id'] = 'field_muc_contact_ref';
  $handler->display->display_options['fields']['field_muc_contact_ref']['table'] = 'field_data_field_muc_contact_ref';
  $handler->display->display_options['fields']['field_muc_contact_ref']['field'] = 'field_muc_contact_ref';
  $handler->display->display_options['fields']['field_muc_contact_ref']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_muc_contact_ref']['element_type'] = '0';
  $handler->display->display_options['fields']['field_muc_contact_ref']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_muc_contact_ref']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_muc_contact_ref']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_muc_contact_ref']['field_api_classes'] = TRUE;
  /* Field: Content: Project Unit Reference */
  $handler->display->display_options['fields']['field_muc_project_unit_ref']['id'] = 'field_muc_project_unit_ref';
  $handler->display->display_options['fields']['field_muc_project_unit_ref']['table'] = 'field_data_field_muc_project_unit_ref';
  $handler->display->display_options['fields']['field_muc_project_unit_ref']['field'] = 'field_muc_project_unit_ref';
  $handler->display->display_options['fields']['field_muc_project_unit_ref']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_muc_project_unit_ref']['element_type'] = '0';
  $handler->display->display_options['fields']['field_muc_project_unit_ref']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_muc_project_unit_ref']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_muc_project_unit_ref']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_muc_project_unit_ref']['field_api_classes'] = TRUE;
  /* Field: Content: Street Name */
  $handler->display->display_options['fields']['field_mpu_street_name']['id'] = 'field_mpu_street_name';
  $handler->display->display_options['fields']['field_mpu_street_name']['table'] = 'field_data_field_mpu_street_name';
  $handler->display->display_options['fields']['field_mpu_street_name']['field'] = 'field_mpu_street_name';
  $handler->display->display_options['fields']['field_mpu_street_name']['relationship'] = 'field_muc_project_unit_ref_target_id';
  $handler->display->display_options['fields']['field_mpu_street_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mpu_street_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_street_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_street_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mpu_street_name']['field_api_classes'] = TRUE;
  /* Field: Content: Street # */
  $handler->display->display_options['fields']['field_mpu_street_number']['id'] = 'field_mpu_street_number';
  $handler->display->display_options['fields']['field_mpu_street_number']['table'] = 'field_data_field_mpu_street_number';
  $handler->display->display_options['fields']['field_mpu_street_number']['field'] = 'field_mpu_street_number';
  $handler->display->display_options['fields']['field_mpu_street_number']['relationship'] = 'field_muc_project_unit_ref_target_id';
  $handler->display->display_options['fields']['field_mpu_street_number']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mpu_street_number']['alter']['text'] = '[field_mpu_street_number] [field_mpu_street_name]';
  $handler->display->display_options['fields']['field_mpu_street_number']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_street_number']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_street_number']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mpu_street_number']['field_api_classes'] = TRUE;
  /* Field: Content: Zipcode */
  $handler->display->display_options['fields']['field_mpu_zipcode']['id'] = 'field_mpu_zipcode';
  $handler->display->display_options['fields']['field_mpu_zipcode']['table'] = 'field_data_field_mpu_zipcode';
  $handler->display->display_options['fields']['field_mpu_zipcode']['field'] = 'field_mpu_zipcode';
  $handler->display->display_options['fields']['field_mpu_zipcode']['relationship'] = 'field_muc_project_unit_ref_target_id';
  $handler->display->display_options['fields']['field_mpu_zipcode']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_zipcode']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_zipcode']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mpu_zipcode']['field_api_classes'] = TRUE;
  /* Field: Content: Neighborhood */
  $handler->display->display_options['fields']['field_mpu_neighborhood']['id'] = 'field_mpu_neighborhood';
  $handler->display->display_options['fields']['field_mpu_neighborhood']['table'] = 'field_data_field_mpu_neighborhood';
  $handler->display->display_options['fields']['field_mpu_neighborhood']['field'] = 'field_mpu_neighborhood';
  $handler->display->display_options['fields']['field_mpu_neighborhood']['relationship'] = 'field_muc_project_unit_ref_target_id';
  $handler->display->display_options['fields']['field_mpu_neighborhood']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_neighborhood']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mpu_neighborhood']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mpu_neighborhood']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_mpu_neighborhood']['field_api_classes'] = TRUE;
  /* Field: Content: Property Phone */
  $handler->display->display_options['fields']['field_mc_property_phone']['id'] = 'field_mc_property_phone';
  $handler->display->display_options['fields']['field_mc_property_phone']['table'] = 'field_data_field_mc_property_phone';
  $handler->display->display_options['fields']['field_mc_property_phone']['field'] = 'field_mc_property_phone';
  $handler->display->display_options['fields']['field_mc_property_phone']['relationship'] = 'field_muc_contact_ref_target_id';
  $handler->display->display_options['fields']['field_mc_property_phone']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mc_property_phone']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mc_property_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mc_property_phone']['field_api_classes'] = TRUE;
  /* Field: Content: Property Email */
  $handler->display->display_options['fields']['field_mc_property_email']['id'] = 'field_mc_property_email';
  $handler->display->display_options['fields']['field_mc_property_email']['table'] = 'field_data_field_mc_property_email';
  $handler->display->display_options['fields']['field_mc_property_email']['field'] = 'field_mc_property_email';
  $handler->display->display_options['fields']['field_mc_property_email']['relationship'] = 'field_muc_contact_ref_target_id';
  $handler->display->display_options['fields']['field_mc_property_email']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mc_property_email']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_mc_property_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mc_property_email']['field_api_classes'] = TRUE;
  /* Field: Content: Unit Type */
  $handler->display->display_options['fields']['field_mpu_unit_type']['id'] = 'field_mpu_unit_type';
  $handler->display->display_options['fields']['field_mpu_unit_type']['table'] = 'field_data_field_mpu_unit_type';
  $handler->display->display_options['fields']['field_mpu_unit_type']['field'] = 'field_mpu_unit_type';
  $handler->display->display_options['fields']['field_mpu_unit_type']['relationship'] = 'field_muc_project_unit_ref_target_id';
  $handler->display->display_options['fields']['field_mpu_unit_type']['element_type'] = '0';
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
    'metrolist_unit_contact' => 'metrolist_unit_contact',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Project Unit Reference (field_muc_project_unit_ref) */
  $handler->display->display_options['filters']['field_muc_project_unit_ref_target_id']['id'] = 'field_muc_project_unit_ref_target_id';
  $handler->display->display_options['filters']['field_muc_project_unit_ref_target_id']['table'] = 'field_data_field_muc_project_unit_ref';
  $handler->display->display_options['filters']['field_muc_project_unit_ref_target_id']['field'] = 'field_muc_project_unit_ref_target_id';
  $handler->display->display_options['filters']['field_muc_project_unit_ref_target_id']['operator'] = '!=';
  $handler->display->display_options['filters']['field_muc_project_unit_ref_target_id']['group'] = 1;
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
    'field_mpu_street_name' => 'field_mpu_street_name',
    'field_mpu_street_number' => 'field_mpu_street_number',
    'field_mpu_zipcode' => 'field_mpu_zipcode',
    'field_mc_property_phone' => 'field_mc_property_phone',
    'field_mc_property_email' => 'field_mc_property_email',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'field_muc_project_unit_ref_target_id';
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Neighborhood';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
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
  $handler->display->display_options['filters']['field_mpu_unit_type_value_1']['relationship'] = 'field_muc_project_unit_ref_target_id';
  $handler->display->display_options['filters']['field_mpu_unit_type_value_1']['value'] = 'Rental Unit Group (R)';
  $handler->display->display_options['filters']['field_mpu_unit_type_value_1']['group'] = 2;
  /* Filter criterion: Content: Unit Type (field_mpu_unit_type) */
  $handler->display->display_options['filters']['field_mpu_unit_type_value']['id'] = 'field_mpu_unit_type_value';
  $handler->display->display_options['filters']['field_mpu_unit_type_value']['table'] = 'field_data_field_mpu_unit_type';
  $handler->display->display_options['filters']['field_mpu_unit_type_value']['field'] = 'field_mpu_unit_type_value';
  $handler->display->display_options['filters']['field_mpu_unit_type_value']['relationship'] = 'field_muc_project_unit_ref_target_id';
  $handler->display->display_options['filters']['field_mpu_unit_type_value']['value'] = 'External Monitoring';
  $handler->display->display_options['filters']['field_mpu_unit_type_value']['group'] = 2;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'metrolist-unit-contacts';
  $export['metrolist_unit_contacts'] = $view;

  return $export;
}
