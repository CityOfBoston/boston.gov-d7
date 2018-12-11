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
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'menu';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_previous_day' => 'field_previous_day',
    'field_previous_week' => 'field_previous_week',
    'field_previous_month' => 'field_previous_month',
    'field_previous_quarter' => 'field_previous_quarter',
    'php' => 'php',
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
    'field_previous_week' => array(
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
    'php' => array(
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
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<script>
jQuery(\'table.views-table\').append(\'<thead><tr class="cs__table-header"><th>Topic</th><th class="cs__table--centered">Day</th><th class="cs__table--centered">Week</th><th class="cs__table--centered">Month</th><th class="cs__table--centered">QTR</th></tr></thead>\');
</script>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_previous_day']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_previous_week']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_previous_month']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_previous_quarter']['exclude'] = TRUE;
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
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
$getName = $data->taxonomy_term_data_name; 
$getDay = $data->field_field_previous_day[0][\'raw\'][\'value\'];
$getWeek = $data->field_field_previous_week[0][\'raw\'][\'value\'];
$getMonth = $data->field_field_previous_month[0][\'raw\'][\'value\'];
$getQuarter = $data->field_field_previous_quarter[0][\'raw\'][\'value\'];

$getDay = (is_null($getDay) ? \'-\' : number_format($getDay, 2) );
$getWeek = (is_null($getWeek) ? \'-\' : number_format($getWeek, 2) );
$getMonth = (is_null($getMonth) ? \'-\' : number_format($getMonth, 2) );
$getQuarter = (is_null($getQuarter) ? \'-\' : number_format($getQuarter, 2) );

$gdLT1 = ($getDay < 1 && $getDay !== \'-\' ? \'cs__low \' : \'\');
$gwLT1 = ($getWeek < 1 && $getWeek !== \'-\' ? \'cs__low \' : \'\');
$gmLT1 = ($getMonth < 1 && $getMonth !== \'-\' ? \'cs__low \' : \'\');
$gqLT1 = ($getQuarter < 1 && $getQuarter !== \'-\' ? \'cs__low \' : \'\');

print \'<tr class="cs__table-row">\';
print \'<td>\'.$getName.\'</td>\';
print \'<td class="\'.$gdLT1.\'cs__table--centered">\'.$getDay.\'</td>\';
print \'<td class="\'.$gwLT1.\'cs__table--centered">\'.$getWeek.\'</td>\';
print \'<td class="\'.$gmLT1.\'cs__table--centered">\'.$getMonth.\'</td>\';
print \'<td class="\'.$gqLT1.\'cs__table--centered">\'.$getQuarter.\'</td>\';
print \'</tr>\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: weight (field_cs_weight) */
  $handler->display->display_options['sorts']['field_cs_weight_value']['id'] = 'field_cs_weight_value';
  $handler->display->display_options['sorts']['field_cs_weight_value']['table'] = 'field_data_field_cs_weight';
  $handler->display->display_options['sorts']['field_cs_weight_value']['field'] = 'field_cs_weight_value';
  $handler->display->display_options['path'] = 'rest/cityscore/html-table';

  /* Display: JSON Output */
  $handler = $view->new_display('page', 'JSON Output', 'json_cs_output');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = '';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 0;
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
  /* Field: Taxonomy term: Previous Quarter */
  $handler->display->display_options['fields']['field_previous_quarter']['id'] = 'field_previous_quarter';
  $handler->display->display_options['fields']['field_previous_quarter']['table'] = 'field_data_field_previous_quarter';
  $handler->display->display_options['fields']['field_previous_quarter']['field'] = 'field_previous_quarter';
  $handler->display->display_options['fields']['field_previous_quarter']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_previous_quarter']['label'] = 'quarter';
  $handler->display->display_options['fields']['field_previous_quarter']['element_default_classes'] = FALSE;
  /* Field: Taxonomy term: Table Timestamp */
  $handler->display->display_options['fields']['field_table_timestamp']['id'] = 'field_table_timestamp';
  $handler->display->display_options['fields']['field_table_timestamp']['table'] = 'field_data_field_table_timestamp';
  $handler->display->display_options['fields']['field_table_timestamp']['field'] = 'field_table_timestamp';
  $handler->display->display_options['fields']['field_table_timestamp']['group_type'] = 'max';
  $handler->display->display_options['fields']['field_table_timestamp']['label'] = 'date_posted';
  $handler->display->display_options['fields']['field_table_timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_table_timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_table_timestamp']['alter']['text'] = '<?php print \'test\'?>';
  $handler->display->display_options['fields']['field_table_timestamp']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_table_timestamp']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_table_timestamp']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'date_posted';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print date("m/d/Y", $data->field_data_field_table_timestamp_field_table_timestamp_value); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'cityscore/totals/latest.json';
  $export['cityscore'] = $view;

  return $export;
}
