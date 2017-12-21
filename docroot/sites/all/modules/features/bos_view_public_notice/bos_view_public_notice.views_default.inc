<?php
/**
 * @file
 * bos_view_public_notice.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bos_view_public_notice_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'public_notice';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Public Notice';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Landing Page';
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
    'title' => array(
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
    'field_contact_target_id' => array(
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
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'listing';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h2>No Public Notices Found</h2>
<div class="intro-text supporting-text">Thomas Paine noted "These are the times that try men\'s souls." Well this is a time to try another search.</div>
<form accept-charset="UTF-8" action="/search" method="get" class="sf sf--md">
    <input name="utf8" type="hidden" value="✓">
    <input name="facet[]" type="hidden" value="public_notice">
    <div class="sf-i">
        <input type="text" name="query" id="q" placeholder="Search…" class="sf-i-f" autocomplete="off">
        <button class="sf-i-b">Search</button>
    </div>
</form>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
  /* Filter criterion: Content: Date -  start date (field_public_notice_date) */
  $handler->display->display_options['filters']['field_public_notice_date_value']['id'] = 'field_public_notice_date_value';
  $handler->display->display_options['filters']['field_public_notice_date_value']['table'] = 'field_data_field_public_notice_date';
  $handler->display->display_options['filters']['field_public_notice_date_value']['field'] = 'field_public_notice_date_value';
  $handler->display->display_options['filters']['field_public_notice_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_public_notice_date_value']['default_date'] = '+1 hours';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search Public Notices';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Field: Contact (field_contact) */
  $handler->display->display_options['filters']['field_contact_target_id']['id'] = 'field_contact_target_id';
  $handler->display->display_options['filters']['field_contact_target_id']['table'] = 'field_data_field_contact';
  $handler->display->display_options['filters']['field_contact_target_id']['field'] = 'field_contact_target_id';
  $handler->display->display_options['filters']['field_contact_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_contact_target_id']['expose']['operator_id'] = 'field_contact_target_id_op';
  $handler->display->display_options['filters']['field_contact_target_id']['expose']['label'] = 'Contact (field_contact)';
  $handler->display->display_options['filters']['field_contact_target_id']['expose']['operator'] = 'field_contact_target_id_op';
  $handler->display->display_options['filters']['field_contact_target_id']['expose']['identifier'] = 'field_contact_target_id';
  $handler->display->display_options['filters']['field_contact_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_contact_target_id']['expose']['remember_roles'] = array(
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

  /* Display: Landing */
  $handler = $view->new_display('page', 'Landing', 'landing');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h2>No Public Notices Found</h2>
<div class="intro-text supporting-text">Thomas Paine noted "These are the times that try men\'s souls." Well this is a time to try another search.</div>
<form accept-charset="UTF-8" action="/search" method="get" class="sf sf--md">
    <input name="utf8" type="hidden" value="✓">
    <input name="facet[]" type="hidden" value="public_notice">
    <div class="sf-i">
        <input type="text" name="query" id="q" placeholder="Search…" class="sf-i-f" autocomplete="off">
        <button class="sf-i-b">Search</button>
    </div>
</form>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
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
    'public_notice' => 'public_notice',
  );
  /* Filter criterion: Content: Date -  start date (field_public_notice_date) */
  $handler->display->display_options['filters']['field_public_notice_date_value']['id'] = 'field_public_notice_date_value';
  $handler->display->display_options['filters']['field_public_notice_date_value']['table'] = 'field_data_field_public_notice_date';
  $handler->display->display_options['filters']['field_public_notice_date_value']['field'] = 'field_public_notice_date_value';
  $handler->display->display_options['filters']['field_public_notice_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_public_notice_date_value']['default_date'] = '-3 hours';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search Public Notices';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Field: Contact (field_contact) */
  $handler->display->display_options['filters']['field_contact_target_id']['id'] = 'field_contact_target_id';
  $handler->display->display_options['filters']['field_contact_target_id']['table'] = 'field_data_field_contact';
  $handler->display->display_options['filters']['field_contact_target_id']['field'] = 'field_contact_target_id';
  $handler->display->display_options['filters']['field_contact_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_contact_target_id']['expose']['operator_id'] = 'field_contact_target_id_op';
  $handler->display->display_options['filters']['field_contact_target_id']['expose']['label'] = 'Filter by Department';
  $handler->display->display_options['filters']['field_contact_target_id']['expose']['operator'] = 'field_contact_target_id_op';
  $handler->display->display_options['filters']['field_contact_target_id']['expose']['identifier'] = 'field_contact_target_id';
  $handler->display->display_options['filters']['field_contact_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_contact_target_id']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'views/public-notice';

  /* Display: Archive */
  $handler = $view->new_display('page', 'Archive', 'archive');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_public_notice_date) */
  $handler->display->display_options['sorts']['field_public_notice_date_value']['id'] = 'field_public_notice_date_value';
  $handler->display->display_options['sorts']['field_public_notice_date_value']['table'] = 'field_data_field_public_notice_date';
  $handler->display->display_options['sorts']['field_public_notice_date_value']['field'] = 'field_public_notice_date_value';
  $handler->display->display_options['sorts']['field_public_notice_date_value']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'views/public-notices/archive';
  $export['public_notice'] = $view;

  return $export;
}
