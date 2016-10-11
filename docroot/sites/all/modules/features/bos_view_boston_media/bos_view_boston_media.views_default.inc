<?php
/**
 * @file
 * bos_view_boston_media.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bos_view_boston_media_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'boston_media_browser_tabs';
  $view->description = 'Default view for the media browser library tab.';
  $view->tag = 'media, default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Boston Media Browser Tabs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view files';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_tags'] = array(
    0 => 'media_browser',
  );
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'media_browser';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No files available.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: File: Upload date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  $handler->display->display_options['sorts']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['timestamp']['expose']['label'] = 'Upload date';
  /* Sort criterion: SUM(File Usage: Use count) */
  $handler->display->display_options['sorts']['count']['id'] = 'count';
  $handler->display->display_options['sorts']['count']['table'] = 'file_usage';
  $handler->display->display_options['sorts']['count']['field'] = 'count';
  $handler->display->display_options['sorts']['count']['group_type'] = 'sum';
  $handler->display->display_options['sorts']['count']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['count']['expose']['label'] = 'Use count';
  /* Filter criterion: File: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'file_managed';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: File: Name */
  $handler->display->display_options['filters']['filename']['id'] = 'filename';
  $handler->display->display_options['filters']['filename']['table'] = 'file_managed';
  $handler->display->display_options['filters']['filename']['field'] = 'filename';
  $handler->display->display_options['filters']['filename']['operator'] = 'contains';
  $handler->display->display_options['filters']['filename']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filename']['expose']['operator_id'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['label'] = 'File name';
  $handler->display->display_options['filters']['filename']['expose']['operator'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';

  /* Display: Boston Media */
  $handler = $view->new_display('media_browser', 'Boston Media', 'boston_media');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Boston Media';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Boston Icons */
  $handler = $view->new_display('media_browser', 'Boston Icons', 'icons');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: File: Name */
  $handler->display->display_options['sorts']['filename']['id'] = 'filename';
  $handler->display->display_options['sorts']['filename']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['filename']['field'] = 'filename';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: File: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'file_managed';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: File: Icon Category (field_icon_category) */
  $handler->display->display_options['filters']['field_icon_category_tid']['id'] = 'field_icon_category_tid';
  $handler->display->display_options['filters']['field_icon_category_tid']['table'] = 'field_data_field_icon_category';
  $handler->display->display_options['filters']['field_icon_category_tid']['field'] = 'field_icon_category_tid';
  $handler->display->display_options['filters']['field_icon_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_icon_category_tid']['expose']['operator_id'] = 'field_icon_category_tid_op';
  $handler->display->display_options['filters']['field_icon_category_tid']['expose']['label'] = 'Icon Category';
  $handler->display->display_options['filters']['field_icon_category_tid']['expose']['operator'] = 'field_icon_category_tid_op';
  $handler->display->display_options['filters']['field_icon_category_tid']['expose']['identifier'] = 'field_icon_category_tid';
  $handler->display->display_options['filters']['field_icon_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_icon_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    16 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    42 => 0,
  );
  $handler->display->display_options['filters']['field_icon_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_icon_category_tid']['vocabulary'] = 'icons';
  /* Filter criterion: File: Icon Category (field_icon_category) */
  $handler->display->display_options['filters']['field_icon_category_tid_1']['id'] = 'field_icon_category_tid_1';
  $handler->display->display_options['filters']['field_icon_category_tid_1']['table'] = 'field_data_field_icon_category';
  $handler->display->display_options['filters']['field_icon_category_tid_1']['field'] = 'field_icon_category_tid';
  $handler->display->display_options['filters']['field_icon_category_tid_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_icon_category_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_icon_category_tid_1']['vocabulary'] = 'icons';
  $export['boston_media_browser_tabs'] = $view;

  return $export;
}
