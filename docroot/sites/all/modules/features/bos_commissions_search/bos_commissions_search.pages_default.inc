<?php
/**
 * @file
 * bos_commissions_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function bos_commissions_search_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'commissions_search';
  $page->task = 'page';
  $page->admin_title = 'Commissions Search';
  $page->admin_description = '';
  $page->path = 'commissions-search';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_commissions_search__panel';
  $handler->task = 'page';
  $handler->subtask = 'commissions_search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Commissions Search',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Boards and Commissions';
  $display->uuid = '65c46975-3334-4d00-b9fe-d897aa6f9518';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_commissions_search__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-431b4e3c-54c3-4d7f-be5f-ad1777200fd2';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Commissions Search Body',
    'title' => '',
    'body' => '<p>Boards and Commissions are an important part of Boston&rsquo;s government. Each board or commission has a specific purpose and works with internal departments, city councilors, and the public to serve the City. <a href="/departments/311/city-boston-government">Learn more about how Boston&rsquo;s government works.</a> &nbsp;</p><p>Each board or commission has a specific number of members. Members go through an application process to ensure they have the expertise and passion for serving.&nbsp;</p><p>Serving on a board or commission is one of the most impactful ways Bostonians can become active in their community. <a href="departments/diversity/how-serve-board-or-commission">Read our guide</a> if you are interested in applying.&nbsp;</p><p>Search below to find information about the board(s) or commission(s) you are interested in and those with open seats.</p>',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '431b4e3c-54c3-4d7f-be5f-ad1777200fd2';
  $display->content['new-431b4e3c-54c3-4d7f-be5f-ad1777200fd2'] = $pane;
  $display->panels['center'][0] = 'new-431b4e3c-54c3-4d7f-be5f-ad1777200fd2';
  $pane = new stdClass();
  $pane->pid = 'new-26fb34ef-a2c4-4fe7-b085-ae4e9c4d3e4d';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Commissions Search Component',
    'title' => '',
    'body' => '<link href="https://apps.boston.gov/commissions-search/static/css/main.css" rel="stylesheet" type="text/css" /><noscript>You need to enable JavaScript to run this app.</noscript><div id="root">&nbsp;<script type="text/javascript" src="https://apps.boston.gov/commissions-search/static/js/main.js"></script></div>',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '26fb34ef-a2c4-4fe7-b085-ae4e9c4d3e4d';
  $display->content['new-26fb34ef-a2c4-4fe7-b085-ae4e9c4d3e4d'] = $pane;
  $display->panels['center'][1] = 'new-26fb34ef-a2c4-4fe7-b085-ae4e9c4d3e4d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-431b4e3c-54c3-4d7f-be5f-ad1777200fd2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['commissions_search'] = $page;

  return $pages;

}
