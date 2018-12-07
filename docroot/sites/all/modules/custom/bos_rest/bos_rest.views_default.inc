<?php
/**
 * @file
 * bos_rest.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bos_rest_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cityscore';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Cityscore';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'hsfghbsfgh';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = '';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['content_type'] = 'text/json';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 1;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Sort criterion: Taxonomy term: Previous Day (field_previous_day) */
  $handler->display->display_options['sorts']['field_previous_day_value']['id'] = 'field_previous_day_value';
  $handler->display->display_options['sorts']['field_previous_day_value']['table'] = 'field_data_field_previous_day';
  $handler->display->display_options['sorts']['field_previous_day_value']['field'] = 'field_previous_day_value';
  /* Sort criterion: Taxonomy term: Previous Month (field_previous_month) */
  $handler->display->display_options['sorts']['field_previous_month_value']['id'] = 'field_previous_month_value';
  $handler->display->display_options['sorts']['field_previous_month_value']['table'] = 'field_data_field_previous_month';
  $handler->display->display_options['sorts']['field_previous_month_value']['field'] = 'field_previous_month_value';
  /* Sort criterion: Taxonomy term: Previous Quarter (field_previous_quarter) */
  $handler->display->display_options['sorts']['field_previous_quarter_value']['id'] = 'field_previous_quarter_value';
  $handler->display->display_options['sorts']['field_previous_quarter_value']['table'] = 'field_data_field_previous_quarter';
  $handler->display->display_options['sorts']['field_previous_quarter_value']['field'] = 'field_previous_quarter_value';
  /* Sort criterion: Taxonomy term: Previous Week (field_previous_week) */
  $handler->display->display_options['sorts']['field_previous_week_value']['id'] = 'field_previous_week_value';
  $handler->display->display_options['sorts']['field_previous_week_value']['table'] = 'field_data_field_previous_week';
  $handler->display->display_options['sorts']['field_previous_week_value']['field'] = 'field_previous_week_value';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'cityscore_metrics' => 'cityscore_metrics',
  );

  /* Display: Cityscore */
  $handler = $view->new_display('page', 'Cityscore', 'html_cs_table');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'HTML Output';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'menu';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'cs__table-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_previous_day' => 'field_previous_day',
    'field_previous_month' => 'field_previous_month',
    'field_previous_quarter' => 'field_previous_quarter',
    'field_previous_week' => 'field_previous_week',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_previous_day' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_previous_month' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_previous_quarter' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_previous_week' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<table class="cs__table">
  <thead>
    <tr class="cs__table-header">
      <th>Topic</th>
      <th class="cs__table--centered">Day</th>
      <th class="cs__table--centered">Week</th>
      <th class="cs__table--centered">Month</th>
      <th class="cs__table--centered">QTR</th>
    </tr>
  </thead>
  </table>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<td>[name]</td>';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: Taxonomy term: Previous Day */
  $handler->display->display_options['fields']['field_previous_day']['id'] = 'field_previous_day';
  $handler->display->display_options['fields']['field_previous_day']['table'] = 'field_data_field_previous_day';
  $handler->display->display_options['fields']['field_previous_day']['field'] = 'field_previous_day';
  $handler->display->display_options['fields']['field_previous_day']['label'] = '';
  $handler->display->display_options['fields']['field_previous_day']['alter']['text'] = '[field_previous_day] * 1000';
  $handler->display->display_options['fields']['field_previous_day']['element_type'] = '0';
  $handler->display->display_options['fields']['field_previous_day']['element_class'] = 'cs__table--centered';
  $handler->display->display_options['fields']['field_previous_day']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_previous_day']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_previous_day']['empty'] = '-';
  $handler->display->display_options['fields']['field_previous_day']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_previous_day']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Taxonomy term: Previous Week */
  $handler->display->display_options['fields']['field_previous_week']['id'] = 'field_previous_week';
  $handler->display->display_options['fields']['field_previous_week']['table'] = 'field_data_field_previous_week';
  $handler->display->display_options['fields']['field_previous_week']['field'] = 'field_previous_week';
  $handler->display->display_options['fields']['field_previous_week']['label'] = '';
  $handler->display->display_options['fields']['field_previous_week']['alter']['text'] = '<td class="cs__table--centered">[field_previous_week]</td>';
  $handler->display->display_options['fields']['field_previous_week']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_previous_week']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_previous_week']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_previous_week']['element_wrapper_class'] = 'cs__table--centered';
  $handler->display->display_options['fields']['field_previous_week']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_previous_week']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Taxonomy term: Previous Month */
  $handler->display->display_options['fields']['field_previous_month']['id'] = 'field_previous_month';
  $handler->display->display_options['fields']['field_previous_month']['table'] = 'field_data_field_previous_month';
  $handler->display->display_options['fields']['field_previous_month']['field'] = 'field_previous_month';
  $handler->display->display_options['fields']['field_previous_month']['label'] = '';
  $handler->display->display_options['fields']['field_previous_month']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_previous_month']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_previous_month']['element_wrapper_class'] = ' cs__table--centered';
  $handler->display->display_options['fields']['field_previous_month']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_previous_month']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Taxonomy term: Previous Quarter */
  $handler->display->display_options['fields']['field_previous_quarter']['id'] = 'field_previous_quarter';
  $handler->display->display_options['fields']['field_previous_quarter']['table'] = 'field_data_field_previous_quarter';
  $handler->display->display_options['fields']['field_previous_quarter']['field'] = 'field_previous_quarter';
  $handler->display->display_options['fields']['field_previous_quarter']['label'] = '';
  $handler->display->display_options['fields']['field_previous_quarter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_previous_quarter']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_previous_quarter']['element_wrapper_class'] = 'cs__table--centered';
  $handler->display->display_options['fields']['field_previous_quarter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_previous_quarter']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['path'] = 'rest/cityscore/html-table';

  /* Display: JSON Output */
  $handler = $view->new_display('page', 'JSON Output', 'json_cs_output');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = '';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 0;
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
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Previous Day */
  $handler->display->display_options['fields']['field_previous_day']['id'] = 'field_previous_day';
  $handler->display->display_options['fields']['field_previous_day']['table'] = 'field_data_field_previous_day';
  $handler->display->display_options['fields']['field_previous_day']['field'] = 'field_previous_day';
  $handler->display->display_options['fields']['field_previous_day']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_previous_day']['label'] = 'day';
  $handler->display->display_options['fields']['field_previous_day']['alter']['text'] = '"day":[field_previous_day], ';
  $handler->display->display_options['fields']['field_previous_day']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_previous_day']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Taxonomy term: Previous Week */
  $handler->display->display_options['fields']['field_previous_week']['id'] = 'field_previous_week';
  $handler->display->display_options['fields']['field_previous_week']['table'] = 'field_data_field_previous_week';
  $handler->display->display_options['fields']['field_previous_week']['field'] = 'field_previous_week';
  $handler->display->display_options['fields']['field_previous_week']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_previous_week']['label'] = 'week';
  $handler->display->display_options['fields']['field_previous_week']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_previous_week']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Taxonomy term: Previous Month */
  $handler->display->display_options['fields']['field_previous_month']['id'] = 'field_previous_month';
  $handler->display->display_options['fields']['field_previous_month']['table'] = 'field_data_field_previous_month';
  $handler->display->display_options['fields']['field_previous_month']['field'] = 'field_previous_month';
  $handler->display->display_options['fields']['field_previous_month']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_previous_month']['label'] = 'month';
  $handler->display->display_options['fields']['field_previous_month']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_previous_month']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_previous_month']['type'] = 'text_default';
  /* Field: Taxonomy term: Previous Quarter */
  $handler->display->display_options['fields']['field_previous_quarter']['id'] = 'field_previous_quarter';
  $handler->display->display_options['fields']['field_previous_quarter']['table'] = 'field_data_field_previous_quarter';
  $handler->display->display_options['fields']['field_previous_quarter']['field'] = 'field_previous_quarter';
  $handler->display->display_options['fields']['field_previous_quarter']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_previous_quarter']['label'] = 'quarter';
  $handler->display->display_options['fields']['field_previous_quarter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_previous_quarter']['type'] = 'text_default';
  /* Field: Taxonomy term: Table Timestamp */
  $handler->display->display_options['fields']['field_table_timestamp']['id'] = 'field_table_timestamp';
  $handler->display->display_options['fields']['field_table_timestamp']['table'] = 'field_data_field_table_timestamp';
  $handler->display->display_options['fields']['field_table_timestamp']['field'] = 'field_table_timestamp';
  $handler->display->display_options['fields']['field_table_timestamp']['group_type'] = 'max';
  $handler->display->display_options['fields']['field_table_timestamp']['label'] = 'date_posted';
  $handler->display->display_options['fields']['field_table_timestamp']['alter']['text'] = '<?php print \'test\'?>';
  $handler->display->display_options['fields']['field_table_timestamp']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_table_timestamp']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_table_timestamp']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'rest/cityscore/totals';
  $export['cityscore'] = $view;

  return $export;
}
