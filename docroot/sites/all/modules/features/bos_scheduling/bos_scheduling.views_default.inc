<?php
/**
 * @file
 * bos_scheduling.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bos_scheduling_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'boston_scheduling';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'Boston Scheduling';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Boston Scheduling';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access workbench';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Content Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'nid';
  $handler->display->display_options['fields']['type']['label'] = 'Type of Content';
  /* Field: Field: Contact */
  $handler->display->display_options['fields']['field_contact']['id'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['table'] = 'field_data_field_contact';
  $handler->display->display_options['fields']['field_contact']['field'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_contact']['label'] = 'Department';
  $handler->display->display_options['fields']['field_contact']['element_type'] = '0';
  $handler->display->display_options['fields']['field_contact']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_contact']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_contact']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_contact']['field_api_classes'] = TRUE;
  /* Field: Workbench Scheduler: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = 'Scheduled Publish Time';
  $handler->display->display_options['fields']['date']['date_format'] = 'short';
  $handler->display->display_options['fields']['date']['second_date_format'] = 'boston_featured';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'nid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'change' => 'change',
    'article' => 'article',
    'department_profile' => 'department_profile',
    'emergency_alert' => 'emergency_alert',
    'how_to' => 'how_to',
    'landing_page' => 'landing_page',
    'listing_page' => 'listing_page',
    'person_profile' => 'person_profile',
    'place_profile' => 'place_profile',
    'procurement_advertisement' => 'procurement_advertisement',
    'program_initiative_profile' => 'program_initiative_profile',
    'public_notice' => 'public_notice',
    'script_page' => 'script_page',
    'site_alert' => 'site_alert',
    'status_item' => 'status_item',
    'tabbed_content' => 'tabbed_content',
    'topic_page' => 'topic_page',
    'transaction' => 'transaction',
    'metrolist_affordable_housing' => 'metrolist_affordable_housing',
    'advpoll' => 'advpoll',
  );
  /* Filter criterion: Workbench Scheduler: Completed */
  $handler->display->display_options['filters']['completed']['id'] = 'completed';
  $handler->display->display_options['filters']['completed']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['filters']['completed']['field'] = 'completed';
  $handler->display->display_options['filters']['completed']['value'] = '0';
  /* Filter criterion: Workbench Scheduler: Schedule Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'workbench_scheduler_schedules';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['value'] = array(
    'schedule' => 'schedule',
  );
  /* Filter criterion: Workbench Scheduler: Active */
  $handler->display->display_options['filters']['is_active']['id'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['filters']['is_active']['field'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['value'] = '1';

  /* Display: All: Publish */
  $handler = $view->new_display('page', 'All: Publish', 'page');
  $handler->display->display_options['path'] = 'admin/workbench/schedule/all-publish';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'All: Publish';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Scheduled Content';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: All: Unpublish */
  $handler = $view->new_display('page', 'All: Unpublish', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Content Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'nid';
  $handler->display->display_options['fields']['type']['label'] = 'Type of Content';
  /* Field: Field: Contact */
  $handler->display->display_options['fields']['field_contact']['id'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['table'] = 'field_data_field_contact';
  $handler->display->display_options['fields']['field_contact']['field'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_contact']['label'] = 'Department';
  $handler->display->display_options['fields']['field_contact']['element_type'] = '0';
  $handler->display->display_options['fields']['field_contact']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_contact']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_contact']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_contact']['field_api_classes'] = TRUE;
  /* Field: Workbench Scheduler: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = 'Scheduled Unpublish Time';
  $handler->display->display_options['fields']['date']['date_format'] = 'short';
  $handler->display->display_options['fields']['date']['second_date_format'] = 'boston_featured';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'nid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'change' => 'change',
    'article' => 'article',
    'department_profile' => 'department_profile',
    'emergency_alert' => 'emergency_alert',
    'how_to' => 'how_to',
    'landing_page' => 'landing_page',
    'listing_page' => 'listing_page',
    'person_profile' => 'person_profile',
    'place_profile' => 'place_profile',
    'procurement_advertisement' => 'procurement_advertisement',
    'program_initiative_profile' => 'program_initiative_profile',
    'public_notice' => 'public_notice',
    'script_page' => 'script_page',
    'site_alert' => 'site_alert',
    'status_item' => 'status_item',
    'tabbed_content' => 'tabbed_content',
    'topic_page' => 'topic_page',
    'transaction' => 'transaction',
    'metrolist_affordable_housing' => 'metrolist_affordable_housing',
    'advpoll' => 'advpoll',
  );
  /* Filter criterion: Workbench Scheduler: Completed */
  $handler->display->display_options['filters']['completed']['id'] = 'completed';
  $handler->display->display_options['filters']['completed']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['filters']['completed']['field'] = 'completed';
  $handler->display->display_options['filters']['completed']['value'] = '0';
  /* Filter criterion: Workbench Scheduler: Schedule Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'workbench_scheduler_schedules';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['value'] = array(
    'unpublish' => 'unpublish',
  );
  /* Filter criterion: Workbench Scheduler: Active */
  $handler->display->display_options['filters']['is_active']['id'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['filters']['is_active']['field'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['value'] = '1';
  $handler->display->display_options['path'] = 'admin/workbench/schedule/all-unpublish';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'All: Unpublish';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Scheduled Content';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['boston_scheduling'] = $view;

  $view = new view();
  $view->name = 'boston_scheduling_event';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'Boston Scheduling: Event';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Boston Scheduling: Event';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access workbench';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Content Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'nid';
  $handler->display->display_options['fields']['type']['label'] = 'Type of Content';
  /* Field: Field: Contacts */
  $handler->display->display_options['fields']['field_contacts']['id'] = 'field_contacts';
  $handler->display->display_options['fields']['field_contacts']['table'] = 'field_data_field_contacts';
  $handler->display->display_options['fields']['field_contacts']['field'] = 'field_contacts';
  $handler->display->display_options['fields']['field_contacts']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_contacts']['label'] = 'Departments';
  $handler->display->display_options['fields']['field_contacts']['element_type'] = '0';
  $handler->display->display_options['fields']['field_contacts']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_contacts']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_contacts']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_contacts']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_contacts']['field_api_classes'] = TRUE;
  /* Field: Workbench Scheduler: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = 'Scheduled Publish Time';
  $handler->display->display_options['fields']['date']['date_format'] = 'short';
  $handler->display->display_options['fields']['date']['second_date_format'] = 'boston_featured';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'nid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Workbench Scheduler: Completed */
  $handler->display->display_options['filters']['completed']['id'] = 'completed';
  $handler->display->display_options['filters']['completed']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['filters']['completed']['field'] = 'completed';
  $handler->display->display_options['filters']['completed']['value'] = '0';
  /* Filter criterion: Workbench Scheduler: Schedule Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'workbench_scheduler_schedules';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['value'] = array(
    'schedule' => 'schedule',
  );
  /* Filter criterion: Workbench Scheduler: Active */
  $handler->display->display_options['filters']['is_active']['id'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['filters']['is_active']['field'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['value'] = '1';

  /* Display: Event: Publish */
  $handler = $view->new_display('page', 'Event: Publish', 'page');
  $handler->display->display_options['path'] = 'admin/workbench/schedule/event-publish';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Event: Publish';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Scheduled Content';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Event: Unpublish */
  $handler = $view->new_display('page', 'Event: Unpublish', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Content Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'nid';
  $handler->display->display_options['fields']['type']['label'] = 'Type of Content';
  /* Field: Field: Contacts */
  $handler->display->display_options['fields']['field_contacts_1']['id'] = 'field_contacts_1';
  $handler->display->display_options['fields']['field_contacts_1']['table'] = 'field_data_field_contacts';
  $handler->display->display_options['fields']['field_contacts_1']['field'] = 'field_contacts';
  $handler->display->display_options['fields']['field_contacts_1']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_contacts_1']['label'] = 'Departments';
  $handler->display->display_options['fields']['field_contacts_1']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_contacts_1']['delta_offset'] = '0';
  /* Field: Workbench Scheduler: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = 'Scheduled Unpublish Time';
  $handler->display->display_options['fields']['date']['date_format'] = 'short';
  $handler->display->display_options['fields']['date']['second_date_format'] = 'boston_featured';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'nid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Workbench Scheduler: Completed */
  $handler->display->display_options['filters']['completed']['id'] = 'completed';
  $handler->display->display_options['filters']['completed']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['filters']['completed']['field'] = 'completed';
  $handler->display->display_options['filters']['completed']['value'] = '0';
  /* Filter criterion: Workbench Scheduler: Schedule Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'workbench_scheduler_schedules';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['value'] = array(
    'unpublish' => 'unpublish',
  );
  /* Filter criterion: Workbench Scheduler: Active */
  $handler->display->display_options['filters']['is_active']['id'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['filters']['is_active']['field'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['value'] = '1';
  $handler->display->display_options['path'] = 'admin/workbench/schedule/event-unpublish';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Event: Unpublish';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Scheduled Content';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['boston_scheduling_event'] = $view;

  $view = new view();
  $view->name = 'boston_scheduling_post';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'Boston Scheduling: Post';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Boston Scheduling: Post';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access workbench';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Content Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'nid';
  $handler->display->display_options['fields']['type']['label'] = 'Type of Content';
  /* Field: Field: Contact */
  $handler->display->display_options['fields']['field_contact']['id'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['table'] = 'field_data_field_contact';
  $handler->display->display_options['fields']['field_contact']['field'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_contact']['label'] = 'Department';
  $handler->display->display_options['fields']['field_contact']['element_type'] = '0';
  $handler->display->display_options['fields']['field_contact']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_contact']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_contact']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_contact']['field_api_classes'] = TRUE;
  /* Field: Workbench Scheduler: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = 'Scheduled Publish Time';
  $handler->display->display_options['fields']['date']['date_format'] = 'short';
  $handler->display->display_options['fields']['date']['second_date_format'] = 'boston_featured';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'nid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'post' => 'post',
  );
  /* Filter criterion: Workbench Scheduler: Completed */
  $handler->display->display_options['filters']['completed']['id'] = 'completed';
  $handler->display->display_options['filters']['completed']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['filters']['completed']['field'] = 'completed';
  $handler->display->display_options['filters']['completed']['value'] = '0';
  /* Filter criterion: Workbench Scheduler: Schedule Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'workbench_scheduler_schedules';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['value'] = array(
    'schedule' => 'schedule',
  );
  /* Filter criterion: Workbench Scheduler: Active */
  $handler->display->display_options['filters']['is_active']['id'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['filters']['is_active']['field'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['value'] = '1';

  /* Display: Post: Publish */
  $handler = $view->new_display('page', 'Post: Publish', 'page');
  $handler->display->display_options['path'] = 'admin/workbench/schedule/post-publish';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Post: Publish';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Scheduled Content';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Post: Unpublish */
  $handler = $view->new_display('page', 'Post: Unpublish', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Content Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'nid';
  $handler->display->display_options['fields']['type']['label'] = 'Type of Content';
  /* Field: Field: Contact */
  $handler->display->display_options['fields']['field_contact']['id'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['table'] = 'field_data_field_contact';
  $handler->display->display_options['fields']['field_contact']['field'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_contact']['label'] = 'Department';
  $handler->display->display_options['fields']['field_contact']['element_type'] = '0';
  $handler->display->display_options['fields']['field_contact']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_contact']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_contact']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_contact']['field_api_classes'] = TRUE;
  /* Field: Workbench Scheduler: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = 'Scheduled Unpublish Time';
  $handler->display->display_options['fields']['date']['date_format'] = 'short';
  $handler->display->display_options['fields']['date']['second_date_format'] = 'boston_featured';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'nid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'post' => 'post',
  );
  /* Filter criterion: Workbench Scheduler: Completed */
  $handler->display->display_options['filters']['completed']['id'] = 'completed';
  $handler->display->display_options['filters']['completed']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['filters']['completed']['field'] = 'completed';
  $handler->display->display_options['filters']['completed']['value'] = '0';
  /* Filter criterion: Workbench Scheduler: Schedule Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'workbench_scheduler_schedules';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['value'] = array(
    'unpublish' => 'unpublish',
  );
  /* Filter criterion: Workbench Scheduler: Active */
  $handler->display->display_options['filters']['is_active']['id'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['table'] = 'workbench_scheduler_nodes';
  $handler->display->display_options['filters']['is_active']['field'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['value'] = '1';
  $handler->display->display_options['path'] = 'admin/workbench/schedule/post-unpublish';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Post: Unpublish';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Scheduled Content';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['boston_scheduling_post'] = $view;

  return $export;
}
