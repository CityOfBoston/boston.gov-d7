<?php
/**
 * @file
 * bos_view_blank_layouts.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bos_view_blank_layouts_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'blank_layouts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Blank Layouts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Filter criterion: Content: Published Date (field_published_date) */
  $handler->display->display_options['filters']['field_published_date_value']['id'] = 'field_published_date_value';
  $handler->display->display_options['filters']['field_published_date_value']['table'] = 'field_data_field_published_date';
  $handler->display->display_options['filters']['field_published_date_value']['field'] = 'field_published_date_value';

  /* Display: Search */
  $handler = $view->new_display('page', 'Search', 'page_1');
  $handler->display->display_options['display_description'] = 'The layout container for search results';
  $handler->display->display_options['path'] = 'api/v1/layouts/search';

  /* Display: Generic */
  $handler = $view->new_display('page', 'Generic', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Generic';
  $handler->display->display_options['path'] = 'api/v1/layouts/generic';

  /* Display: App */
  $handler = $view->new_display('page', 'App', 'page_3');
  $handler->display->display_options['path'] = 'api/v1/layouts/app';
  $export['blank_layouts'] = $view;

  return $export;
}
