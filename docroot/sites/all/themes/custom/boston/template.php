<?php
/**
 * @file
 * Contains functions to alter Drupal's markup for the STARTERKIT theme.
 */

include_once 'includes/boston.helpers.inc';
include_once 'includes/boston.theme.inc';

/**
 * Implements hook_theme().
 */
function boston_theme() {
  return array(
    'page_contacts' => array(
      'variables' => array(
        'title' => NULL,
        'short_title' => NULL,
        'contacts' => NULL,
      ),
      'template' => 'templates/snippets/page-contacts',
    ),
    'detail_item' => array(
      'variables' => array(
        'label' => NULL,
        'body' => NULL,
        'image' => NULL,
        'classes' => array(
          'detail' => '',
          'icon' => '',
          'label' => '',
          'body' => '',
        ),
      ),
      'template' => 'templates/snippets/detail-item',
    ),
    'grid_card' => array(
      'variables' => array(
        'title' => NULL,
        'link' => NULL,
        'subtitle' => NULL,
        'image' => NULL,
        'description' => NULL,
        'classes' => '',
      ),
      'template' => 'templates/snippets/grid-card',
    ),
    'user_login' => array(
      'render element' => 'form',
      'template' => 'templates/snippets/user_login',
    ),
    'alert_js' => array(
      'template' => 'templates/snippets/alert-js',
    ),
    'logo' => array(
      'template' => 'templates/snippets/logo',
    ),
    'burger' => array(
      'template' => 'templates/snippets/burger',
    ),
    'seal' => array(
      'template' => 'templates/snippets/seal',
    ),
    'search' => array(
      'template' => 'templates/snippets/search',
    ),
    'secondary_nav' => array(
      'template' => 'templates/snippets/secondary-nav',
    ),
    'profile_address' => array(
      'variables' => array(
        'address' => NULL,
        'address_type' => NULL,
      ),
      'template' => 'templates/snippets/profile-address',
    ),
  );
}

/**
 * Override or insert variables for the breadcrumb theme function.
 *
 * @param array $variables
 *   An array of variables to pass to the theme function.
 * @param string $hook
 *   The name of the theme hook being called ("breadcrumb" in this case).
 *
 * @see boston_breadcrumb()
 */
function boston_preprocess_breadcrumb(array &$variables, $hook) {
  // Define variables for the breadcrumb-related theme settings. This is done
  // here so that sub-themes can dynamically change the settings under
  // particular conditions in a preprocess function of their own.
  $variables['display_breadcrumb'] = check_plain(theme_get_setting('boston_breadcrumb'));
  $variables['display_breadcrumb'] = ($variables['display_breadcrumb'] == 'yes' || $variables['display_breadcrumb'] == 'admin' && arg(0) == 'admin') ? TRUE : FALSE;
  $variables['breadcrumb_separator'] = filter_xss_admin(theme_get_setting('boston_breadcrumb_separator'));
  $variables['display_trailing_separator'] = theme_get_setting('boston_breadcrumb_trailing') ? TRUE : FALSE;

  // Optionally get rid of the homepage link.
  if (!theme_get_setting('boston_breadcrumb_home')) {
    array_shift($variables['breadcrumb']);
  }

  // Add the title of the page to the end of the breadcrumb list.
  if (!empty($variables['breadcrumb']) && theme_get_setting('boston_breadcrumb_title')) {
    $item = menu_get_item();
    if (!empty($item['tab_parent'])) {
      // If we are on a non-default tab, use the tab's title.
      $variables['breadcrumb'][] = check_plain($item['title']);
    }
    else {
      $variables['breadcrumb'][] = drupal_get_title();
    }
    // Turn off the trailing separator.
    $variables['display_trailing_separator'] = FALSE;
  }

  // Provide a navigational heading to give context for breadcrumb links to
  // screen-reader users.
  if (empty($variables['title'])) {
    $variables['title'] = t('You are here');
  }
}

/**
 * Override or insert variables into the html template.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered. This is usually "html", but can
 *   also be "maintenance_page" since boston_preprocess_maintenance_page() calls
 *   this function to have consistent variables.
 */
function boston_preprocess_html(array &$variables, $hook) {
  // A variable to define the cache buster
  $buster = variable_get('css_js_query_string', '0');
  $variables['cache_buster'] = $buster;

  if (isset($_GET['response_type']) && $_GET['response_type'] == 'embed') {
    $variables['theme_hook_suggestions'][] = 'html__embed';
  }

  // A variable to define the asset url
  $variables['asset_url'] = variable_get('asset_url', 'https://patterns.boston.gov');
  $variables['asset_name'] = $GLOBALS['theme'] == 'boston_hub' ? 'hub' : 'public';
  $variables['google_tag_manager_id'] = variable_get('google_tag_manager_id', FALSE);

  // Adds variable to connect to contact form
  $variables['contact_url'] = variable_get('contact_url', 'https://www.boston.gov');

  // Add variables and paths needed for HTML5 and responsive support.
  $variables['base_path'] = base_path();
  $variables['path_to_boston'] = drupal_get_path('theme', $GLOBALS['theme']);
  // Get settings for HTML5 and responsive support. array_filter() removes
  // items from the array that have been disabled.
  $meta = array_filter((array) theme_get_setting('boston_meta'));
  $variables['add_html5_shim']          = in_array('html5', $meta);
  $variables['default_mobile_metatags'] = in_array('meta', $meta);

  // Attributes for html element.
  $variables['html_attributes_array'] = array(
    'lang' => $variables['language']->language,
    'dir' => $variables['language']->dir,
  );

  // Remove Drupal's sidebar classes.
  $variables['classes_array'] = array_diff($variables['classes_array'],
    array(
      'two-sidebars',
      'one-sidebar sidebar-first',
      'one-sidebar sidebar-second',
      'no-sidebars',
    )
  );

  // <body> classes for sidebars.
  if (isset($variables['page']['sidebar_first']) && isset($variables['page']['sidebar_second'])) {
    $variables['classes_array'][] = 'body-sidebars-both';
  }
  elseif (isset($variables['page']['sidebar_first'])) {
    $variables['classes_array'][] = 'body-sidebars-first';
  }
  elseif (isset($variables['page']['sidebar_second'])) {
    $variables['classes_array'][] = 'body-sidebars-second';
  }
  else {
    $variables['classes_array'][] = 'body-sidebars-none';
  }

  // Send X-UA-Compatible HTTP header to force IE to use the most recent
  // rendering engine or use Chrome's frame rendering engine if available.
  // This also prevents the IE compatibility mode button to appear when using
  // conditional classes on the html tag.
  if (is_null(drupal_get_http_header('X-UA-Compatible'))) {
    drupal_add_http_header('X-UA-Compatible', 'IE=edge,chrome=1');
  }

  $variables['skip_link_anchor'] = check_plain(theme_get_setting('boston_skip_link_anchor'));
  $variables['skip_link_text']   = check_plain(theme_get_setting('boston_skip_link_text'));

  // Return early, so the maintenance page does not call any of the code below.
  if ($hook != 'html') {
    return;
  }

  // Serialize RDF Namespaces into an RDFa 1.1 prefix attribute.
  if ($variables['rdf_namespaces']) {
    $prefixes = array();
    foreach (explode("\n  ", ltrim($variables['rdf_namespaces'])) as $namespace) {
      // Remove xlmns: and ending quote and fix prefix formatting.
      $prefixes[] = str_replace('="', ': ', substr($namespace, 6, -1));
    }
    $variables['rdf_namespaces'] = ' prefix="' . implode(' ', $prefixes) . '"';
  }

  // Classes for body element. Allows advanced theming based on context
  // (home page, node of certain type, etc.).
  if (!$variables['is_front']) {
    // Add unique class for each page.
    $path = drupal_get_path_alias($_GET['q']);
    // Add unique class for each website section.
    list($section,) = explode('/', $path, 2);
    $arg = explode('/', $_GET['q']);
    if ($arg[0] == 'node' && isset($arg[1])) {
      if ($arg[1] == 'add') {
        $section = 'node-add';
      }
      elseif (isset($arg[2]) && is_numeric($arg[1]) && ($arg[2] == 'edit' || $arg[2] == 'delete')) {
        $section = 'node-' . $arg[2];
      }
    }
    $variables['classes_array'][] = drupal_html_class('section-' . $section);
  }

  // When Panels is used on a site, Drupal's sidebar body classes will be wrong,
  // so override those with classes from a Panels layout preprocess.
  // @see boston_preprocess_boston_main().
  $panels_classes_array = &drupal_static('boston_panels_classes_array', array());
  if (!empty($panels_classes_array)) {
    // Remove Drupal's sidebar classes.
    $variables['classes_array'] = array_diff($variables['classes_array'],
      array(
        'two-sidebars',
        'one-sidebar sidebar-first',
        'one-sidebar sidebar-second',
        'no-sidebars',
      )
    );
    // Merge in the classes from the Panels layout.
    $variables['classes_array'] = array_merge($variables['classes_array'], $panels_classes_array);
  }

  // Store the menu item since it has some useful information.
  $variables['menu_item'] = menu_get_item();
  if ($variables['menu_item']) {
    switch ($variables['menu_item']['page_callback']) {
      case 'views_page':
        // Is this a Views page?
        $variables['classes_array'][] = 'page-views';
        break;

      case 'page_manager_blog':
      case 'page_manager_blog_user':
      case 'page_manager_contact_site':
      case 'page_manager_contact_user':
      case 'page_manager_node_add':
      case 'page_manager_node_edit':
      case 'page_manager_node_view_page':
      case 'page_manager_page_execute':
      case 'page_manager_poll':
      case 'page_manager_search_page':
      case 'page_manager_term_view_page':
      case 'page_manager_user_edit_page':
      case 'page_manager_user_view_page':
        // Is this a Panels page?
        $variables['classes_array'][] = 'page-panels';
        break;
    }
  }
  // This needs a weight of -9999 since it definitely needs to load before
  // picturefill.js included by the Picture module. The mediaMatch polyfill
  // included in all.min.js conflicts with the one defined in picturefill.js,
  // and the one in all.min.js is more comprehensive and backwards compatible
  // so we need to use that one.
  drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/dist/js/all.min.js', array(
    'scope' => 'footer',
    'every_page'  => TRUE,
    'weight' => -9999,
  ));

  if (module_exists('bos_content_type_emergency_alert')) {
    drupal_add_js(drupal_get_path('module', 'bos_content_type_emergency_alert') . '/js/emergency_alert.js', array(
      'every_page' => TRUE,
    ));
  }
}

/**
 * Override or insert variables into the html templates.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("html" in this case).
 */
function boston_process_html(array &$variables, $hook) {
  // Flatten out html_attributes.
  $variables['html_attributes'] = drupal_attributes($variables['html_attributes_array']);
}

/**
 * Override or insert variables in the html_tag theme function.
 */
function boston_process_html_tag(array &$variables) {
  $tag = &$variables['element'];

  if ($tag['#tag'] == 'style' || $tag['#tag'] == 'script') {
    // Remove redundant CDATA comments.
    unset($tag['#value_prefix'], $tag['#value_suffix']);

    // Remove redundant type attribute.
    if (isset($tag['#attributes']['type']) && $tag['#attributes']['type'] !== 'text/ng-template') {
      unset($tag['#attributes']['type']);
    }

    // Remove media="all" but leave others unaffected.
    if (isset($tag['#attributes']['media']) && $tag['#attributes']['media'] === 'all') {
      unset($tag['#attributes']['media']);
    }
  }
}

/**
 * Implements hook_html_head_alter().
 */
function boston_html_head_alter(&$head) {
  // Simplify the meta tag for character encoding.
  if (isset($head['system_meta_content_type']['#attributes']['content'])) {
    $head['system_meta_content_type']['#attributes'] = array(
      'charset' => str_replace('text/html; charset=', '', $head['system_meta_content_type']['#attributes']['content']),
    );
  }
}

/**
 * Override or insert variables into the page template.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("page" in this case).
 */

/**
 * Implements hook_preprocess_page().
 */
function boston_preprocess_page(array &$variables) {
  $has_hero = false;

  if (isset($_GET['response_type']) && $_GET['response_type'] == 'embed') {
    $variables['theme_hook_suggestions'][] = 'page__embed';
  }

  // A variable to define the cache buster
  $variables['cache_buster'] = variable_get('css_js_query_string', '0');
  $variables['asset_url'] = variable_get('asset_url', 'https://patterns.boston.gov');
  $variables['asset_name'] = $GLOBALS['theme'] == 'boston_hub' ? 'hub' : 'public';

  // Find the title of the menu used by the secondary links.
  $secondary_links = variable_get('menu_secondary_links_source', 'menu-secondary-menu');
  if ($secondary_links) {
    $menus = function_exists('menu_get_menus') ? menu_get_menus() : menu_list_system_menus();
    $variables['secondary_menu_heading'] = isset($menus[$secondary_links]) ? $menus[$secondary_links] : '';
  }
  else {
    $variables['secondary_menu_heading'] = '';
  }

  // This is done to bring the hero image rendered output to the page level
  // of rendering. Hero image styling fits more naturally at the page level
  // as opposed to the rendered node output in the system block.
  $nid = arg(1);
  if (arg(0) == 'node' && is_numeric($nid)) {
    if (isset($variables['page']['content']['system_main']['nodes'][$nid]['field_intro_image'])) {
      $has_hero = true;
      $background_image = $variables['page']['content']['system_main']['nodes'][$nid]['field_intro_image'];
      $uri = $background_image[0]['#item']['uri'];

      $xlarge_image = image_style_url('rep_wide_2000x700custom_boston_desktop_2x', $uri);
      $large_image = image_style_url('rep_wide_2000x700custom_boston_desktop_1x', $uri);
      $medium_image = image_style_url('rep_wide_2000x700custom_boston_tablet_2x', $uri);
      $small_image = image_style_url('rep_wide_2000x700custom_boston_mobile_2x', $uri);

      $variables['background_image'] = $background_image;
      $variables['header_image'] = $has_hero;
      $variables['xlarge_image'] = $xlarge_image;
      $variables['large_image'] = $large_image;
      $variables['medium_image'] = $medium_image;
      $variables['small_image'] = $small_image;
    }
  }
  // Removes breadcrumbs on node types specified in the array.
  $dont_show_breadcrumbs = array('topic_page', 'landing_page');
  if (isset($variables['node']) && in_array($variables['node']->type, $dont_show_breadcrumbs)) {
    $variables['breadcrumb'] = '';
  }

  // Get the HTTP header so we can have custom 404/403 pages.
  $header = drupal_get_http_header("status");
  if ($header == "404 Not Found") {
    $variables['theme_hook_suggestions'][] = 'page__404';
    $block = module_invoke('bos_blocks', 'block_view', 'search');
    $variables['search_block'] = $block;
  }

  if ($header == "403 Forbidden") {
    $variables['theme_hook_suggestions'][] = 'page__403';
  }

  $no_type_needed = array(
    'listing_page',
    'landing_page',
  );

  // some content types aren't special
  if (isset($variables['node']) && !in_array($variables['node']->type, $no_type_needed)) {
    $type_element = array(
      '#tag' => 'meta', // The #tag is the html tag -
      '#attributes' => array( // Set up an array of attributes inside the tag
        'class' => 'swiftype',
        'name' => 'type',
        'data-type' => 'enum',
        'content' => $variables['node']->type,
      ),
    );
    drupal_add_html_head($type_element, 'swiftype_type');
  }

  // Add a site priority meta tag for swiftype
  $priority_element = array(
    '#tag' => 'meta', // The #tag is the html tag -
    '#attributes' => array( // Set up an array of attributes inside the tag
      'class' => 'swiftype',
      'name' => 'site-priority',
      'data-type' => 'integer',
      'content' => 5,
    ),
  );
  drupal_add_html_head($priority_element, 'swiftype_priority');

  // Create necessary page classes
  if ($variables['node']->type !== 'tabbed_content' && $variables['node']->type !== 'how_to' && !$has_hero) {
    $page_class = 'page';
  } else {
    $page_class = NULL;
  }

  $page_class_alert = $page_class;
  $target_id = NULL;

  if (isset($variables['node'])) {
    $target_id = $variables['node']->nid;

    if ($variables['node']->type == 'topic_page') {
      $page_class = 'page';
    }

    if ($variables['node']->type !== 'landing_page') {
      if ($variables['node']->type !== 'tabbed_content' && $variables['node']->type !== 'how_to') {
        $page_class_alert = 'page page--wa';
      } else {
        $page_class_alert = 'page page--wa page--nm';
      }
    } else {
      $page_class_alert = 'page';
    }

    if (drupal_is_front_page()) {
      $page_class_alert = 'page page--wa page--fp';
    }
  }

  // If we are on the employee directory page, change the title.
  $current_path = current_path();
  if (strpos($current_path, 'user') === 0) {
    $page_class_alert = 'page page--wa';
  }

  $variables['target_id'] = $target_id;
  $variables['page_class'] = $page_class;
  $variables['page_class_alert'] = $page_class_alert;

  $variables['site_info'] = array(
    'front_page' => $variables['front_page'],
    'asset_url' => $variables['asset_url'],
    'asset_name' => $variables['asset_name'],
    'cache_buster' => $variables['cache_buster'],
    'site_name' => $variables['site_name'],
    'hide_logo' => $GLOBALS['theme'] == 'boston_hub',
  );
}

/**
 * Implements hook_process_page().
 */
function boston_process_page(&$variables) {
  _boston_unset_page_title($variables);
}

/**
 * Override or insert variables into the maintenance page template.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("maintenance_page" in this case).
 */
function boston_preprocess_maintenance_page(array &$variables, $hook) {
  boston_preprocess_html($variables, $hook);
  // There's nothing maintenance-related in boston_preprocess_page(). Yet.
  // boston_preprocess_page($variables, $hook);.
}

/**
 * Implements hook_preprocess_THEMEHOOK().
 */
function boston_preprocess_views_exposed_form(&$variables) {
  // Add a theme suggestion based on form id.
  $form_id = $variables['form']['#id'];
  // Offset by 19, accounting for: views-exposed-form-.
  $view = substr($form_id, 19);
  $variables['theme_hook_suggestions'][] = 'views_exposed_form__' . str_replace('-', '_', $view);
}

/**
 * Override or insert variables into the maintenance page template.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("maintenance_page" in this case).
 */
function boston_process_maintenance_page(array &$variables, $hook) {
  boston_process_html($variables, $hook);
  // Ensure default regions get a variable. Theme authors often forget to remove
  // a deleted region's variable in maintenance-page.tpl.
  $regions = array(
    'header',
    'navigation',
    'highlighted',
    'help',
    'content',
    'sidebar_first',
    'sidebar_second',
    'footer',
    'bottom',
  );
  foreach ($regions as $region) {
    if (!isset($variables[$region])) {
      $variables[$region] = '';
    }
  }
}

/**
 * Override or insert variables into the node templates.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("node" in this case).
 */
function boston_preprocess_node(array &$variables, $hook) {
  // Add theme variable
  $variables['theme'] = variable_get('theme_default', 'boston');
  $variables['asset_url'] = variable_get('asset_url', 'https://patterns.boston.gov');
  $variables['asset_name'] = $GLOBALS['theme'] == 'boston_hub' ? 'hub' : 'public';

  // Add theme hook suggestions for node.
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['view_mode'];
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];

  // Add $unpublished variable.
  $variables['unpublished'] = (!$variables['status']) ? TRUE : FALSE;

  // Set preview variable to FALSE if it doesn't exist.
  $variables['preview'] = isset($variables['preview']) ? $variables['preview'] : FALSE;

  // Add pubdate to submitted variable.
  $variables['pubdate'] = '<time pubdate datetime="' . format_date($variables['node']->created, 'custom', 'c') . '">' . $variables['date'] . '</time>';
  if ($variables['display_submitted']) {
    $variables['submitted'] = t('Submitted by !username on !datetime', array('!username' => $variables['name'], '!datetime' => $variables['pubdate']));
  }

  // If the node is unpublished, add the "unpublished" watermark class.
  if ($variables['unpublished'] || $variables['preview']) {
    $variables['classes_array'][] = 'watermark__wrapper';
  }

  // Add a class for the view mode.
  if (!$variables['teaser']) {
    $variables['classes_array'][] = 'view-mode-' . $variables['view_mode'];
  }

  // Add a class to show node is authored by current user.
  if ($variables['uid'] && $variables['uid'] == $GLOBALS['user']->uid) {
    $variables['classes_array'][] = 'node-by-viewer';
  }

  // Add node bundles to this list which should not have with-hero added to
  // their full page view.
  $hero_blacklist = array(
    'topic_page',
    'how_to',
    'tabbed_content',
  );
  // For full view mode nodes, if the node has a hero image, add the with-hero
  // class to the node wrapper.
  if (isset($variables['field_intro_image']) && $variables['view_mode'] == 'full' && !in_array($variables['type'], $hero_blacklist)) {
    $variables['classes_array'][] = 'with-hero';
  }

  _boston_unset_node_wrappers($variables);

  $bundle_preprocess = 'boston_preprocess_node_' . $variables['type'];
  if (function_exists($bundle_preprocess)) {
    $bundle_preprocess($variables);
  }

  if ($variables['type'] == 'listing_page') {
    _boston_listing_page_title($variables);
  }


}

function boston_preprocess_paragraphs_item_news_announcements(&$variables) {
  // Get the call to action.
  $variables['call_to_action'] = bos_core_field_get_call_to_action('paragraphs_item', $variables['paragraphs_item'], 'field_link');
}

function boston_preprocess_paragraphs_item_upcoming_events(&$variables) {
  // Get the call to action.
  $variables['call_to_action'] = bos_core_field_get_call_to_action('paragraphs_item', $variables['paragraphs_item'], 'field_link');
}

function boston_preprocess_paragraphs_item_newsletter(&$variables) {
  $variables['newsletter_url'] = variable_get('newsletter_url', 'https://www.boston.gov');
}

function boston_preprocess_paragraphs_item_bos_signup_emergency_alerts(&$variables) {
  $variables['emergency_alerts_url'] = variable_get('emergency_alerts_url', 'https://www.boston.gov');
}

function boston_preprocess_paragraphs_item_grid_of_cards(&$variables) {
  $theme = bos_core_field_get_first_item('paragraphs_item', $variables['paragraphs_item'], 'field_component_theme')['value'];

  $variables['component_theme'] = $theme;
  $variables['section_header_theme'] = $theme === 'b' ? 'sh--w' : '';
}

function boston_preprocess_paragraphs_item_grid_of_places(&$variables) {
  $theme = bos_core_field_get_first_item('paragraphs_item', $variables['paragraphs_item'], 'field_component_theme')['value'];

  $variables['component_theme'] = isset($theme) ? $theme : 'g';
  $variables['section_header_theme'] = $theme === 'b' ? 'sh--w' : '';
}

function boston_preprocess_paragraphs_item_grid_of_programs_initiatives(&$variables) {
  $theme = bos_core_field_get_first_item('paragraphs_item', $variables['paragraphs_item'], 'field_component_theme')['value'];

  $variables['component_theme'] = isset($theme) ? $theme : 'g';
  $variables['section_header_theme'] = $theme === 'b' ? 'sh--w' : '';
}

function boston_preprocess_paragraphs_item_card(&$variables) {
  $link_id = bos_core_field_get_first_item('paragraphs_item', $variables['paragraphs_item'], 'field_link')['value'];

  if ($link_id) {
    // Load the link references
    $link = paragraphs_item_load($link_id);

    // Return the url
    $variables['card_url'] = bos_core_field_get_link_url($link);
    $variables['card_attr'] = bos_core_field_get_link_attributes($link);
  }

  if ($link->field_lightbox_link) {
      drupal_add_css('https://cdnjs.cloudflare.com/ajax/libs/lity/2.3.1/lity.min.css', array(
          'type' => 'external',
          'scope' => 'header',
      ));

      drupal_add_js('https://cdnjs.cloudflare.com/ajax/libs/lity/2.3.1/lity.min.js', array(
          'every_page' => TRUE,
      ));
      $variables['isLightbox'] = 1;
  } else {
      $variables['isLightbox'] = 0;
  }



}

function boston_preprocess_field_field_how_to_tabs(&$variables) {
  $GLOBALS['how_to_tabs_count'] = 0;
}

function boston_preprocess_paragraphs_item_how_to_tab(&$variables) {
  $variables['how_to_tabs_count'] = $GLOBALS['how_to_tabs_count'];
  $GLOBALS['how_to_tabs_count']++;
}

function boston_preprocess_field_field_how_to_steps(&$variables) {
  $GLOBALS['how_to_step_count'] = 1;
}

function boston_preprocess_paragraphs_item_how_to_text_step(&$variables) {
  $variables['how_to_step_count'] = $GLOBALS['how_to_step_count'];
  $GLOBALS['how_to_step_count']++;
}

/**
 * Implements hook_preprocess_HOOK().
 */
function boston_preprocess_paragraphs_item_how_to_contact_step(&$variables) {
  _boston_unset_node_wrappers($variables);

  $variables['how_to_step_count'] = $GLOBALS['how_to_step_count'];
  $GLOBALS['how_to_step_count']++;
}

function boston_preprocess_paragraphs_item_photo(&$variables) {
  $GLOBALS['photo_component_id'] = rand();
  $variables['photo_id'] = $GLOBALS['photo_component_id'];
}

function boston_preprocess_paragraphs_item_map(&$variables) {
  drupal_add_js(
    $variables['asset_url'] . '/web-components/fleetcomponents.js',
    array(
    'type' => 'external',
    'scope' => 'footer',
  ));

  // Create a unique ID for each map. Some of this is borrowed from the
  // preprocessing for photos.
  $map_id = "map--" . $variables['elements']['#entity']->item_id;
  $GLOBALS['photo_component_id'] = $variables['elements']['#entity']->item_id;

  $variables['map_id']  = $map_id;
  $variables['photo_id'] = $GLOBALS['photo_component_id'];
}

function boston_preprocess_field_field_image(&$variables) {
  if(isset($GLOBALS['photo_component_id'])) {
    $variables['photo_id'] = $GLOBALS['photo_component_id'];
    unset($GLOBALS['photo_component_id']);
  }
}

/**
 * Check whether a group_of_links_* paragraph has an empty left region.
 */
function _boston_paragrpahs_item_group_of_links_is_left_region_empty($paragraph) {
  // Check whether the fields displayed on the left are empty.
  $fields = array(
    'field_call_to_action',
    'field_description',
    'field_subheader',
  );

  $all_fields_empty = TRUE;
  foreach ($fields as $field) {
    $value = $paragraph->{$field};
    if (!empty($value)) {
      $all_fields_empty = FALSE;
      break;
    }
  }

  return $all_fields_empty;
}

/**
 * Implements hook_preprocess_ENTITY_TYPE_BUNDLE().
 */
function boston_preprocess_paragraphs_item_group_of_links_list(&$variables) {
  $all_fields_empty = _boston_paragrpahs_item_group_of_links_is_left_region_empty($variables['paragraphs_item']);
  $variables['call_to_action'] = bos_core_field_get_call_to_action('paragraphs_item', $variables['paragraphs_item'], 'field_link');

  // Let the template know the status of the left region.
  $variables['left_region_is_empty'] = ($all_fields_empty) ? TRUE : FALSE;
}

/**
 * Implements hook_preprocess_ENTITY_TYPE_BUNDLE().
 */
function boston_preprocess_paragraphs_item_group_of_links_grid(&$variables) {
  $all_fields_empty = _boston_paragrpahs_item_group_of_links_is_left_region_empty($variables['paragraphs_item']);
  $variables['call_to_action'] = bos_core_field_get_call_to_action('paragraphs_item', $variables['paragraphs_item'], 'field_link');

  // Let the template know the status of the left region.
  $variables['left_region_is_empty'] = ($all_fields_empty) ? TRUE : FALSE;

  // Tell the field grid links that the grid can be expanded to 4 columns.
  if ($all_fields_empty) {
    if (isset($variables['content']['field_grid_links'])) {
      foreach ($variables['content']['field_grid_links']['#items'] as $key => $data) {
        foreach ($variables['content']['field_grid_links'][$key]['entity']['field_collection_item'] as $fcid => $theme_info) {
          $theme_info['#num_of_cols'] = 4;
          $variables['content']['field_grid_links'][$key]['entity']['field_collection_item'][$fcid] = $theme_info;
        }
      }
    }
  }
}

/**
 * Implements hook_preprocess_node_BUNDLE().
 */
function boston_preprocess_field_collection_item_field_grid_links(&$variables) {
  // The #num_of_cols variable can be set to modify the number of columns used
  // in the template where links are placed. This setting is used by the 'Group
  // of links - Grid' component to allow more links to be shown in one row
  // when the left side of the display is empty. Look at
  // boston_preprocess_paragraphs_item_group_of_links_grid for more information.
  if (isset($variables['elements']['#num_of_cols'])) {
    $variables['classes_array'][] = "desktop-{$variables['elements']['#num_of_cols']}-col";
  }
  else {
    $variables['classes_array'][] = "desktop-3-col";
  }
}

function boston_preprocess_accessibility_toolbar(&$variables) {
  // Set the menus for accessibility and translation
  $variables['accessibilityMenu'] = menu_navigation_links('menu-accessibility-menu');
  $variables['translationMenu'] = menu_navigation_links('menu-translation-menu');
}

/**
 * Implements hook_preprocess_node_BUNDLE().
 */
function boston_preprocess_node_site_alert(&$variables) {
  $item = field_get_items('node', $variables['node'], 'field_theme');

  $excluded_nodes = [];
  $excluded = field_get_items('node', $variables['node'], 'field_excluded_nodes');
  if ($excluded) {
    foreach ($excluded as $key => $value) {
      $excluded_nodes[] = $value['target_id'];
    }
  }

  if ($item && $item[0]) {
    $variables['block_theme'] = $item[0]['value'];
  }

  if ($variables['content']['field_icon'] && $variables['content']['field_icon'][0]) {
    $variables['icon'] = file_get_contents(drupal_realpath(trim(render($variables['content']['field_icon'][0]))));
    $variables['icon'] = filter_xss($variables['icon'], explode(' ', BOS_CORE_SVG_ELEMENTS));
  }

  $variables['excluded_nodes'] = $excluded_nodes;
}

/**
 * Implements hook_preprocess_node_BUNDLE().
 */
function boston_preprocess_node_event(&$variables) {
  $components_field = $variables['field_components']['und'];
  $comp_entity_id_array = array();

  $variables['live_stream_active'] = 0;

  $cancelled = field_get_items('node', $variables['node'], 'field_cancel_event');
  if ($cancelled[0]['value']) {
    $variables['is_cancelled'] = TRUE;
  }

  if ($components_field) {
    foreach ($components_field as $comp) {
      $comp_entity_id_array[] = $comp['value'];
    }

    $components = entity_load('paragraphs_item', $components_field);
    if (!empty($components)) {
      foreach ($components as $comp) {
        $video = field_get_items('paragraphs_item', $comp, 'field_live_stream');
        if (!empty($video)) {
          $variables['live_stream_active'] = 1;
        }
      }
    }
  }

  $time_range_view_modes = array(
    'calendar_listing',
    'full',
  );
  $dates = field_get_items('node', $variables['node'], 'field_event_dates');
  if (in_array($variables['view_mode'], $time_range_view_modes) && $variables['type'] === 'event') {
    // We need to add a variable which contains the time range output to be
    // displayed. We'd have to override some theming otherwise and it's not
    // worth the trouble. The field_event_dates field is required so we don't
    // have to worry about checking for it.
    $dates = field_get_items('node', $variables['node'], 'field_event_dates');
    if ($dates !== FALSE) {
      $timezone = $dates[0]['timezone'];
      // Add '+0000' so that strtotime doesn't try to convert a UTC time, we'll do that in format_date().
      $start_time = strtotime($dates[0]['value'] . " +0000");
      $end_time = strtotime($dates[0]['value2'] . " +0000");
      $time_range = format_date($start_time, 'calendar_time','',$timezone);
      if ($start_time !== $end_time) {
        $time_range .= '-' . format_date($end_time, 'calendar_time', '', $timezone);
      }
      $variables['time_range'] = $time_range;

      // We also want to show the repeat rule, and it needs to be isolated from
      // the full render of the date since it will need to be displayed in a
      // different place than the date.
      if (!empty($dates[0]['rrule'])) {
        $variables['repeat_rule'] = boston_date_repeat_rrule_description($dates[0]['rrule']);
      }
    }
    else {
      $variables['time_range'] = '';
    }
  }
  // If the event has passed, field_event_dates is empty. Need to be able
  // to display date even if the event is over. Thus, this.
  if (!empty($variables['content']['field_event_dates'])) {
    $variables['event_date_canonical'] = $variables['content']['field_event_dates'];
  } else {
    $date_time = $dates[0]['value'];
    $time_zone = $dates[0]['timezone'];
    $start_date = strtotime($date_time . " +0000");
    $event_date = format_date($start_date, 'medium','F j, Y',$time_zone);
    $variables['event_date_canonical'] = $event_date;
  }

  // Checks to see if current time is more than 6 hours past the start
  // time of the event. If so, the featured event is not rendered.
  if ($variables['view_mode'] == "featured_item") {
    $dates = field_get_items('node', $variables['node'], 'field_event_dates');
    $dt = new DateTime();
    $start_time = strtotime($dates[0]['value'] . " +0000");
    $current_time = date_format($dt, U);
    $future_time = $start_time + 21600;

    if ($current_time > $future_time) {
      $variables['is_expired'] = 1;
    } else {
      $variables['is_expired'] = 0;
    }
  }
}

/**
 * Implements hook_preprocess_node_BUNDLE().
 */
function boston_preprocess_node_procurement_advertisement(&$variables) {
  $dates = field_get_items('node', $variables['node'], 'field_date_range');

  if ($dates !== FALSE) {
    $timezone = $dates[0]['timezone'];
    // Add '+0000' so that strtotime doesn't try to convert a UTC time, we'll do that in format_date().
    $start_date = strtotime($dates[0]['value'] . " +0000");
    $end_date = strtotime($dates[0]['value2'] . " +0000");
    $now = time();

    $variables['is_closed'] = $end_date < $now;

    $variables['start_date'] = date('n/j/Y - g:ia', $start_date);
    $variables['end_date'] = date('n/j/Y - g:ia', $end_date);
    $variables['due_date'] = date('F j, Y', $end_date);
  }
  else {
    $variables['time_range'] = '';
  }

  $submissions = $variables['field_bid'];

  $bid_entity_id_array = array();
  foreach ($submissions as $submission) {
    $bid_entity_id_array[] = $submission['value'];
  }

  $awarded = array();
  $other = array();

  // Here we need to load all the components because
  // the not all components have a short title
  // required so we do not create nav link for it.
  $submissions = entity_load('paragraphs_item', $bid_entity_id_array);
  foreach ($submissions as $submission) {
    $bid = array(
      'company' => $submission->field_company_name['und'][0]['value'],
      'amount' => $submission->field_bid_amount['und'][0]['value'],
      'awarded' => $submission->field_awarded['und'][0]['value'],
    );

    if ($bid['awarded'] === '1') {
      $awarded[] = $bid;
    } else {
      $other[] = $bid;
    }
  }

  $variables['bid_awarded'] = $awarded;
  $variables['bid_other'] = $other;

  $award_date = field_get_items('node', $variables['node'], 'field_award_date');
  $awarded = strtotime($award_date[0]['value']);

  $variables['award_date'] = date('F j, Y', $awarded);

  $not_awarded = field_get_items('node', $variables['node'], 'field_not_awarded');
  $variables['not_awarded'] = $not_awarded[0]['value'] === "1";
}

/**
 * Implements hook_preprocess_node_BUNDLE().
 */
function boston_preprocess_node_public_notice(&$variables) {
  $time_range_view_modes = array(
    'calendar_listing',
    'listing',
    'full',
  );

  if (in_array($variables['view_mode'], $time_range_view_modes) && $variables['type'] === 'public_notice') {
    // We need to add a variable which contains the time range output to be
    // displayed. We'd have to override some theming otherwise and it's not
    // worth the trouble. The field_event_dates field is required so we don't
    // have to worry about checking for it.
    $dates = field_get_items('node', $variables['node'], 'field_public_notice_date');
    if ($dates !== FALSE) {
      $timezone = $dates[0]['timezone'];
      // Add '+0000' so that strtotime doesn't try to convert a UTC time, we'll do that in format_date().
      $start_time = strtotime($dates[0]['value'] . " +0000");
      $end_time = strtotime($dates[0]['value2'] . " +0000");
      $time_range = format_date($start_time, 'calendar_time','',$timezone);
      if ($start_time !== $end_time) {
        $time_range .= '-' . format_date($end_time, 'calendar_time', '', $timezone);
      }
      $variables['time_range'] = $time_range;

      // We also want to show the repeat rule, and it needs to be isolated from
      // the full render of the date since it will need to be displayed in a
      // different place than the date.
      if (!empty($dates[0]['rrule'])) {
        $variables['repeat_rule'] = boston_date_repeat_rrule_description($dates[0]['rrule']);
      }
    }
    else {
      $variables['time_range'] = '';
    }
  }

  $cancelled = field_get_items('node', $variables['node'], 'field_cancelled');

  if ($cancelled[0]['value']) {
    $variables['is_cancelled'] = true;
  }

  $has_testimony = field_get_items('node', $variables['node'], 'field_is_there_public_testimony');

  if ($has_testimony[0]['value']) {
    $variables['has_testimony'] = true;
  }

  // Checks to see if current time is more than 6 hours past the start time
  // of the public notice. If so, the featured public notice is not rendered.
  if ($variables['view_mode'] == "featured_item") {
    $dates = field_get_items('node', $variables['node'], 'field_public_notice_date');
    $dt = new DateTime();
    $start_time = strtotime($dates[0]['value'] . " +0000");
    $current_time = date_format($dt, U);
    $future_time = $start_time + 21600;

    if ($current_time > $future_time) {
      $variables['is_expired'] = 1;
    } else {
      $variables['is_expired'] = 0;
    }
  }

  if (isset($variables['node']->published_at)) {
    $variables['notice_date_short'] = format_date($variables['node']->published_at, 'short');
    $variables['notice_date_long'] = format_date($variables['node']->published_at, 'long');
  }
}

/**
 * Implements hook_preprocess_node_BUNDLE().
 */
function boston_preprocess_node_topic_page(array &$variables) {
  if (isset($variables['field_thumbnail']) && $variables['view_mode'] == 'featured_topics') {
    // The field field_thumbnail on the Featured Guides view mode for Topic
    // content uses the Image URL formatter, so the render value will be a URL
    // string.
    $thumbnail_render_array = field_view_field('node', $variables['node'], 'field_thumbnail', 'featured_topics');
    $thumbnail_url = trim(render($thumbnail_render_array));
    $styles = array(
      "background-image: url('$thumbnail_url');",
    );
    $variables['attributes_array']['style'] = implode(';', $styles);
  }
  // Add some custom variables to the topic page template for listing_long.
  if ($variables['view_mode'] == 'listing_long') {
    $lang = $variables['language'];
    $components_field = $variables['field_components'][$lang];
    $num_components = count($components_field);
    $variables['num_components'] = 0;
    // We show three nav links, then want to denote
    // the remainder of the links for the See More link.
    if ($num_components > 3) {
      $variables['num_components'] = $num_components - 3;
    }

    $comp_entity_id_array = array();
    foreach ($components_field as $comp) {
      $comp_entity_id_array[] = $comp['value'];
    }
    // Here we need to load all the components because
    // the not all components have a short title
    // required so we do not create nav link for it.
    $components = entity_load('paragraphs_item', $comp_entity_id_array);
    if (!empty($components)) {
      $nav_links = array();
      $num_nav_links = 0;
      foreach ($components as $comp) {
        $short_title_array = field_get_items('paragraphs_item', $comp, 'field_short_title');
        if (!empty($short_title_array)) {
          $short_title = $short_title_array[0]['safe_value'];
          $short_title = strtoupper($short_title);
          $jump_link = strtolower(trim($short_title));
          $jump_link = str_replace(" ", "-", $jump_link);
          $jump_link = str_replace("&amp;", "n", $jump_link);
          $short_title = str_replace("&AMP;", "&", $short_title);
          $nav_links[] = l(
            $short_title,
            $variables['path']['alias'],
            array(
              'fragment' => $jump_link,
              'attributes' => array(
                'class' => array('scroll-link-js'),
              ),
            ));
          $num_nav_links++;
          // Show only the first three links.
          // After we've computed three links, break.
          if ($num_nav_links == 3) {
            break;
          }
        }
      }
      $variables['nav_links'] = $nav_links;
    }
  }
}

/**
 * Implements hook_preprocess_node_BUNDLE().
 */
function boston_preprocess_node_transaction(array &$variables) {
  $link_id = bos_core_field_get_first_item('node', $variables['node'], 'field_link')['value'];

  if ($link_id) {
    // Load the link references
    $link = paragraphs_item_load($link_id);

    // Return the url
    $url = bos_core_field_get_link_url($link);
  }

  $variables['transaction_url'] = $url;
}

/**
 * Implements hook_preprocess_node_BUNDLE().
 */
function boston_preprocess_paragraphs_item_message_for_the_day(&$variables) {
  $message = $variables['paragraphs_item'];
  $host = _get_message_host($message);

  // Most of this work assumes that the message is part of the status node,
  // which  is not always the case.
  if (isset($host->nid) && $host->type == 'status_item') {
    $status_item = $host;
  }
  // The message is attached to a status override paragraph.
  else {
    $status_item_info = bos_core_field_get_first_item('paragraphs_item', $host, 'field_status_item');
    $status_item = node_load($status_item_info['target_id']);
  }

  // Add a class to help identify specific entities.
  $variables['classes_array'][] = "paragraphs-item-message-for-the-day-{$status_item->nid}";

  // Search for an emergency alert override.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'paragraphs_item');
  $query->entityCondition('bundle', 'status_override');
  $query->fieldCondition('field_status_item', 'target_id', $status_item->nid);
  $results = $query->execute();

  // If we have an override, enhance the current message with the proper data.
  if (!empty($results)) {
    foreach ($results['paragraphs_item'] as $id => $info) {
      $status_override = paragraphs_item_load($id);
      $status_override_host = $status_override->hostEntity();
      // Make sure the override message is on an active emergency node.
      if ($status_override_host->status == 1) {
        $override_message_info = bos_core_field_get_first_item('paragraphs_item', $status_override, 'field_override_message');
        if ($override_message_info) {
          $override_message = paragraphs_item_load($override_message_info['value']);
          boston_override_message($message, $override_message, $variables);
        }
      }
    }
  }

  // Here we are assuming that there is a 1-1 relationship between the Status
  // Item content type and the Message for the Day paragraph item type. They
  // are mutually dependent on each other.
  /** @var \ParagraphsItemEntity $message */
  $use_alert = field_get_items('paragraphs_item', $message, 'field_use_alert', $message->langcode());
  // String will either be 1 or 0, and 0 is empty. So if the value is not empty
  // then we want to use the alert.
  $variables['use_alert'] = !empty($use_alert[0]['value']);

  // Setup renderable arrays for the field_title, field_icon, and
  // field_alert_icon fields on the message for the day to be rendered.
  $variables['content']['field_title'] = field_view_field('node', $status_item, 'field_title', 'full');
  $variables['content']['field_icon'] = field_view_field('node', $status_item, 'field_icon', 'full');
  $filename = drupal_realpath(trim(render($variables['content']['field_icon'][0])));
  // We can't find the file by default in dev, so we avoid trying to
  // do the file_get_contents piece below.
  if ($filename) {
    $variables['icon'] = file_get_contents($filename);
    $variables['icon'] = filter_xss($variables['icon'], explode(' ', BOS_CORE_SVG_ELEMENTS));
  }

  $link_id = bos_core_field_get_first_item('paragraphs_item', $variables['paragraphs_item'], 'field_link')['value'];

  if ($link_id) {
    // Load the link references
    $link = paragraphs_item_load($link_id);

    // Return the url
    $url = bos_core_field_get_link_url($link);
  }

  $variables['card_url'] = $url;
}

/**
 * Replaces status message fields with emergency override message fields.
 */
function boston_override_message($message, $override, &$variables) {
  $relevant_fields = array(
    'field_use_alert',
    'field_message',
    'field_link',
  );
  foreach ($relevant_fields as $field) {
    if (isset($override->{$field})) {
      $message->{$field} = $override->{$field};
      $variables['content'][$field] = field_view_field('paragraphs_item', $message, $field, 'default');
      if (isset($variables['content'][$field]['#title'])) {
        $variables['content'][$field]['#title'] = "";
      }
    }
  }
}

/**
 * Override or insert variables into the comment templates.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("comment" in this case.
 */
function boston_preprocess_comment(array &$variables, $hook) {
  // Add $unpublished variable.
  $variables['unpublished'] = ($variables['status'] == 'comment-unpublished') ? TRUE : FALSE;

  // Add $preview variable.
  $variables['preview'] = ($variables['status'] == 'comment-preview') ? TRUE : FALSE;

  // If comment subjects are disabled, don't display them.
  if (variable_get('comment_subject_field_' . $variables['node']->type, 1) == 0) {
    $variables['title'] = '';
  }

  // Add pubdate to submitted variable.
  $variables['pubdate'] = '<time pubdate datetime="' . format_date($variables['comment']->created, 'custom', 'c') . '">' . $variables['created'] . '</time>';
  $variables['submitted'] = t('!username replied on !datetime', array('!username' => $variables['author'], '!datetime' => $variables['pubdate']));

  // If the comment is unpublished/preview, add a "unpublished" watermark class.
  if ($variables['unpublished'] || $variables['preview']) {
    $variables['classes_array'][] = 'watermark__wrapper';
  }

  // Zebra striping.
  if ($variables['id'] == 1) {
    $variables['classes_array'][] = 'first';
  }
  if ($variables['id'] == $variables['node']->comment_count) {
    $variables['classes_array'][] = 'last';
  }
  $variables['classes_array'][] = $variables['zebra'];

  // Add the comment__permalink class.
  $uri = entity_uri('comment', $variables['comment']);
  $uri_options = $uri['options'] + array('attributes' => array('class' => array('comment__permalink'), 'rel' => 'bookmark'));
  $variables['permalink'] = l(t('Permalink'), $uri['path'], $uri_options);

  // Remove core's permalink class and add the comment__title class.
  $variables['title_attributes_array']['class'][] = 'comment__title';
  $uri_options = $uri['options'] + array('attributes' => array('rel' => 'bookmark'));
  $variables['title'] = l($variables['comment']->subject, $uri['path'], $uri_options);
}

/**
 * Preprocess variables for region.tpl.php.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("region" in this case).
 */
function boston_preprocess_region(array &$variables, $hook) {
  // Sidebar regions get some extra classes and a common template suggestion.
  if (strpos($variables['region'], 'sidebar_') === 0) {
    $variables['classes_array'][] = 'column';
    $variables['classes_array'][] = 'sidebars';
    // Allow a region-specific template to override boston's region--sidebar.
    array_unshift($variables['theme_hook_suggestions'], 'region__sidebar');
  }

  if ($variables['region'] == 'sidebar_first') {
    array_unshift($variables['classes_array'], 'sidebar-first');
  }

  if ($variables['region'] == 'sidebar_second') {
    array_unshift($variables['classes_array'], 'sidebar-second');
  }

  // Use a template with no wrapper for the content region.
  elseif ($variables['region'] == 'content') {
    // Allow a region-specific template to override boston's region--no-wrapper.
    array_unshift($variables['theme_hook_suggestions'], 'region__no_wrapper');
  }
  // Add a SMACSS-style class for header region.
  elseif ($variables['region'] == 'header') {
    array_unshift($variables['classes_array'], 'header__region');
  }
}

/**
 * Implements hook_preprocess_HOOK().
 */
function boston_preprocess_taxonomy_term(array &$variables, $hook) {
  $variables['theme_hook_suggestions'][] = 'taxonomy_term__' . $variables['view_mode'];
  $variables['theme_hook_suggestions'][] = 'taxonomy_term__' . $variables['vocabulary_machine_name'] . '__' . $variables['view_mode'];
}

/**
 * Override or insert variables into the block templates.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("block" in this case).
 */
function boston_preprocess_block(array &$variables, $hook) {
  // Use a template with no wrapper for the page's main content.
  if ($variables['block_html_id'] == 'block-system-main') {
    $variables['theme_hook_suggestions'][] = 'block__no_wrapper';
  }

  // Classes describing the position of the block within the region.
  if ($variables['block_id'] == 1) {
    $variables['classes_array'][] = 'first';
  }
  // The last_in_region property is set in boston_page_alter().
  if (isset($variables['block']->last_in_region)) {
    $variables['classes_array'][] = 'last';
  }
  $variables['classes_array'][] = $variables['block_zebra'];

  $variables['title_attributes_array']['class'][] = 'block__title';

  // Add Aria Roles via attributes.
  switch ($variables['block']->module) {
    case 'system':
      switch ($variables['block']->delta) {
        case 'main':
          // Note: the "main" role goes in the page.tpl, not here.
          break;

        case 'help':
        case 'powered-by':
          $variables['attributes_array']['role'] = 'complementary';
          break;

        default:
          // Any other "system" block is a menu block.
          $variables['attributes_array']['role'] = 'navigation';
          break;
      }
      break;

    case 'menu':
    case 'menu_block':
    case 'blog':
    case 'book':
    case 'comment':
    case 'forum':
    case 'shortcut':
    case 'statistics':
      $variables['attributes_array']['role'] = 'navigation';
      break;

    case 'search':
      $variables['attributes_array']['role'] = 'search';
      break;

    case 'help':
    case 'aggregator':
    case 'locale':
    case 'poll':
    case 'profile':
      $variables['attributes_array']['role'] = 'complementary';
      break;

    case 'node':
      switch ($variables['block']->delta) {
        case 'syndicate':
          $variables['attributes_array']['role'] = 'complementary';
          break;

        case 'recent':
          $variables['attributes_array']['role'] = 'navigation';
          break;
      }
      break;

    case 'user':
      switch ($variables['block']->delta) {
        case 'login':
          $variables['attributes_array']['role'] = 'form';
          break;

        case 'new':
        case 'online':
          $variables['attributes_array']['role'] = 'complementary';
          break;
      }
      break;
  }
}

/**
 * Override or insert variables into the block templates.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("block" in this case).
 */
function boston_process_block(array &$variables, $hook) {
  // Drupal 7 should use a $title variable instead of $block->subject.
  $variables['title'] = isset($variables['block']->subject) ? $variables['block']->subject : '';
}

/**
 * Implements hook_page_alter().
 *
 * Look for the last block in the region. This is impossible to determine from
 * within a preprocess_block function.
 */
function boston_page_alter(array &$page) {
  // Look in each visible region for blocks.
  foreach (system_region_list($GLOBALS['theme'], REGIONS_VISIBLE) as $region => $name) {
    if (!empty($page[$region])) {
      // Find the last block in the region.
      $blocks = array_reverse(element_children($page[$region]));
      while ($blocks && !isset($page[$region][$blocks[0]]['#block'])) {
        array_shift($blocks);
      }
      if ($blocks) {
        $page[$region][$blocks[0]]['#block']->last_in_region = TRUE;
      }
    }
  }
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 *
 * Prevent user-facing field styling from screwing up node edit forms by
 * renaming the classes on the node edit form's field wrappers.
 */
function boston_form_node_form_alter(&$form, &$form_state, $form_id) {
  // Remove if #1245218 is backported to D7 core.
  foreach (array_keys($form) as $item) {
    if (strpos($item, 'field_') === 0) {
      if (!empty($form[$item]['#attributes']['class'])) {
        foreach ($form[$item]['#attributes']['class'] as &$class) {
          // Core bug: the field-type-text-with-summary class is used as a JS
          // hook.
          if ($class != 'field-type-text-with-summary' && strpos($class, 'field-type-') === 0 || strpos($class, 'field-name-') === 0) {
            // Make the class different from that used in theme_field().
            $class = 'form-' . $class;
          }
        }
      }
    }
  }
}


/**
 * Implements hook_form_alter().
 */
function boston_form_alter(&$form, $form_state, $form_id) {
  // Add the name of views with exposed filters to this list
  // that should appear with the bos_search styling.
  if (!empty($form_state['view'])) {
    $bos_search_form = array(
      'places',
      'program_initiatives',
      'transactions',
    );

    if (in_array($form_state['view']->name, $bos_search_form)) {
      $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit'),
        '#attributes' => array(
          'class' => array(
            'sf-i-b',
          ),
        ),
      );
      $form['title']['#attributes']['class'][] = 'sf-i-f';
      $form['#attributes']['class'][] = 'sf';
      $form['title']['#attributes']['title'] = 'Search';
    }

    if ($form_state['view']->name == 'program_initiatives') {
      $form['title']['#attributes']['placeholder'][] = 'Search programs...';
    } else if ($form_state['view']->name == 'transactions') {
      $form['title']['#attributes']['placeholder'][] = 'Search transactions...';
    } else {
      $form['title']['#attributes']['placeholder'][] = 'Search...';
    }
  }
}

/**
 * Implements template_preprocess_menu_tree().
 */
function boston_preprocess_menu_tree(&$variables) {
  $tree = $variables['tree'];
  $variables['menu_classes'] = strpos($tree, '<li class="nv-m-c-bc nv-m-c-b--h"') === 0 ? 'nv-m-c-l-l' : 'nv-m-c-l';
}

/**
 * Implements hook_preprocess_menu_link().
 */
function boston_preprocess_menu_link(array &$variables, $hook) {
  // If it's the footer menu, set it and go
  if (isset($variables['element']['#original_link']['menu_name']) && $variables['element']['#original_link']['menu_name'] == 'menu-footer-menu') {
    $variables['element']['#localized_options']['attributes']['class'] = array('ft-ll-a');
    return;
  }

  // Normalize menu item classes to be an array.
  if (empty($variables['element']['#attributes']['class'])) {
    $variables['element']['#attributes']['class'] = array();
  }
  $menu_item_classes =& $variables['element']['#attributes']['class'];
  if (!is_array($menu_item_classes)) {
    $menu_item_classes = array($menu_item_classes);
  }

  // Normalize menu link classes to be an array.
  if (empty($variables['element']['#localized_options']['attributes']['class'])) {
    $variables['element']['#localized_options']['attributes']['class'] = array();
  }
  $menu_link_classes =& $variables['element']['#localized_options']['attributes']['class'];

  if (!is_array($menu_link_classes)) {
    $menu_link_classes = array($menu_link_classes);
  }

  // Add BEM-style classes to the menu item classes.
  if (!in_array('masquerade', $menu_item_classes)) {
    $extra_classes = $variables['element']['#original_link']['depth'] == '1' ? array('nv-m-c-l-i') : array('nv-m-c-l-l-i');
  } else {
    $extra_classes = array();
  }

  foreach ($menu_item_classes as $key => $class) {
    switch ($class) {
      // Menu module classes.
      case 'expanded':
      case 'collapsed':
      case 'leaf':
      case 'active':
        // Menu block module classes.
      case 'active-trail':
        $extra_classes[] = 'is-' . $class[0];
        break;

      case 'has-children':
        $extra_classes[] = 'nv-m-c-l-i--k';
        break;
    }
  }
  $menu_item_classes = array_merge($extra_classes, $menu_item_classes);

  if (isset($variables['element']['#original_link']['menu_name']) && $variables['element']['#original_link']['menu_name'] == 'main-menu') {
    // Add BEM-style classes to the menu link classes.
    $extra_classes = array(
      'nv-m-c-a',
      'nv-m-c-a--p',
    );
  } else {
    $extra_classes = array();
  }

  if (empty($menu_link_classes)) {
    $menu_link_classes = array();
  }
  else {
    foreach ($menu_link_classes as $key => $class) {
      switch ($class) {
        case 'active':
        case 'active-trail':
          $extra_classes[] = 'is-' . $class[0];
          break;
      }
    }
  }
  $menu_link_classes = array_merge($extra_classes, $menu_link_classes);
}

/**
 * Override or insert variables into the panels-pane templates.
 *
 * @param array $variables
 *   An array of variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("block" in this case).
 */
function boston_preprocess_panels_pane(array &$variables, $hook) {
  // Use no pane wrapper for common page elements.
  switch ($variables['pane']->subtype) {
    case 'page_content':
    case 'pane_header':
    case 'pane_messages':
    case 'pane_navigation':
      // Allow a pane-specific template to override boston's suggestion.
      array_unshift($variables['theme_hook_suggestions'], 'panels_pane__no_wrapper');
      break;
  }
  // Add component-style class name to pane title.
  $variables['title_attributes_array']['class'][] = 'pane__title';
}

/**
 * Implements hook_preprocess_HOOK().
 */
function boston_preprocess_entity(&$variables, $hook) {
  if ($variables['entity_type'] === 'paragraphs_item') {

    $title_optional_bundles = _bos_core_get_components();
    $bundle = $variables['paragraphs_item']->bundle;
    if (in_array($bundle, $title_optional_bundles)) {
      $component_title = field_get_items('paragraphs_item', $variables['paragraphs_item'], 'field_component_title');
      if (empty($component_title)) {
        $variables['classes_array'][] = 'component-no-title';
      }
    }

    $paragraph_preprocess = 'boston_preprocess_paragraphs_item';
    $paragraph_bundle_preprocess = 'boston_preprocess_paragraphs_item_' . $variables['elements']['#bundle'];
    if (function_exists($paragraph_preprocess)) {
      $paragraph_preprocess($variables);
    }
    if (function_exists($paragraph_bundle_preprocess)) {
      $paragraph_bundle_preprocess($variables);
    }
  }
  elseif ($variables['entity_type'] === 'field_collection_item') {
    $bundle = $variables['elements']['#bundle'];
    $function = 'boston_preprocess_field_collection_item_' . $bundle;
    if (function_exists($function)) {
      $function($variables);
    }
  }
}

/**
 * Implements hook_preprocess_file_entity().
 */
function boston_preprocess_file_entity(&$variables) {
  $bundle_preprocess = __FUNCTION__ . '_' . $variables['type'];
  if (function_exists($bundle_preprocess)) {
    $bundle_preprocess($variables);
  }
}

/**
 * Implements hook_preprocess_file_entity_TYPE().
 */
function boston_preprocess_file_entity_image(&$variables) {
  if (!empty($variables['content']['field_image_caption'])) {
    // If the image caption is specified then we want to capture the output of
    // it and expose it in a template variable.
    $caption = $variables['content']['field_image_caption'];
    $variables['caption'] = trim(render($caption));
  }
}

/**
 * Implements hook_preprocess_paragraphs_item().
 */
function boston_preprocess_paragraphs_item(&$variables) {
  // Media bundles.
  $media_bundles = array(
    'sidebar_item',
    'sidebar_item_w_icon',
    'daily_hours',
    'custom_hours_text',
    'social_media_links',
  );
  $bundle = $variables['paragraphs_item']->bundle;
  if (!in_array($bundle, $media_bundles)) {
    $variables['classes_array'][] = 'component-section';
  }

  $variables['asset_url'] = variable_get('asset_url', 'https://patterns.boston.gov');

  $theme = bos_core_field_get_first_item('paragraphs_item', $variables['paragraphs_item'], 'field_component_theme');

  if ($theme) {
    $variables['component_theme'] = $theme['value'];
    if ($theme['value'] == "b" && $variables['paragraphs_item']->bundle == "newsletter") {
      $variables['component_theme'] .= " b--wt";
    }
    $variables['section_header_theme'] = $theme['value'] === 'b' ? 'sh--w' : '';
  }
}

/**
 * Implements hook_preprocess_paragraphs_item_BUNDLE().
 */
function boston_preprocess_paragraphs_item_list(&$variables) {
  // Add a class to the list entity wrapper indicating which view the
  // list is displaying. This is needed to target things like background
  // color for the component.
  $vname = field_get_items('paragraphs_item', $variables['paragraphs_item'], 'field_list');
  if ($vname !== FALSE) {
    $class_name = 'view-' . preg_replace('/[|_]/', '-', $vname[0]['vname']);
    $variables['classes_array'][] = $class_name;
  }

  $theme = bos_core_field_get_first_item('paragraphs_item', $variables['paragraphs_item'], 'field_component_theme')['value'];

  $variables['component_theme'] = isset($theme) ? $theme : 'w';
  $variables['section_header_theme'] = $theme === 'b' ? 'sh--w' : '';
}

/**
 * Implements hook_preprocess_paragraphs_item_BUNDLE().
 */
function boston_preprocess_paragraphs_item_document(&$variables) {
  $variables['document_link'] = $variables['content']['field_document'][0]['#markup'];
  $variables['document_filename'] = $variables['content']['field_document']['#items'][0]['filename'];

  // only want to give a new theme to the transaction grid paragraph type.
  if (isset($variables['paragraphs_item']->hostEntity()->bundle)
    && isset($variables['paragraphs_item']->hostEntity()->hostEntity()->bundle)
    && $variables['paragraphs_item']->hostEntity()->hostEntity()->bundle == "transaction_grid") {
    $variables["is_transaction_grid"] = TRUE;
    $document_link = field_get_items('paragraphs_item', $variables['paragraphs_item'], 'field_document');
    $link_icon = drupal_static("link_icon", NULL);

    if ($document_link !== FALSE) {
      $variables['document_link_path'] = $document_link[0]['url'];
      $variables['document_link_title'] = $variables['field_title'][0]['safe_value'];

      if (isset($link_icon)) {
        $variables['link_icon'] = $link_icon;
        drupal_static_reset("link_icon");
      }
    }
    else {
      $variables['document_link_path'] = '';
      $variables['document_link_title'] = '';
    }
  }
}

/**
 * Implements hook_preprocess_paragraphs_item_iframe().
 */
function boston_preprocess_paragraphs_item_iframe(&$variables) {
  $iframe_height = $variables['content']['field_iframe_size']["#items"][0]['value'];
  $variables['iframe_height'] = $variables['content']['field_iframe_size']["#items"][0]['value'] !== "0" ? $iframe_height . 'px' : false;

  drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/dist/js/resizer.js');
}

/**
 * Implements hook_preprocess_paragraphs_item_iframe().
 */
function boston_preprocess_paragraphs_item_video(&$variables) {
  drupal_add_js('https://www.youtube.com/iframe_api');
  drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/dist/js/calendar-live-stream.js');
}

function boston_preprocess_field_collection_item_field_transactions(&$variables) {
  // We need to get the icon for these and insert them into the link
  $link_icon = &drupal_static("link_icon", null);

  // We go through this, because the link could be external or internal
  if (isset($link_icon)) {
    drupal_static_reset("link_icon");
  }

  // Once we have the link, add it to the variable for use
  $icon = field_get_items('field_collection_item', $variables['field_collection_item'], 'field_icon');

  // Our links also need CSS classes
  $link_icon = array(
    "image" => file_create_url($icon[0]["uri"]),
    "classes" => array(
      "container" => "lwi g--3 g--3--sl m-t200 m-t500--m",
      "icon" => "lwi-ic",
      "text" => "lwi-t",
    ),
  );
}

/**
 * Implements hook_preprocess_paragraphs_item_BUNDLE().
 */
function boston_preprocess_paragraphs_item_internal_link(&$variables) {
  $internal_link = field_get_items('paragraphs_item', $variables['paragraphs_item'], 'field_internal_link');
  $link_icon = drupal_static("link_icon", null);

  if ($internal_link !== FALSE) {
    $variables['internal_link_path'] = base_path() . $internal_link[0]['entity']->path['alias'];
    $variables['internal_link_title'] = check_plain($internal_link[0]['entity']->title);

    if (isset($link_icon)) {
      $variables['link_icon'] = $link_icon;
      drupal_static_reset("link_icon");
    }
  }
  else {
    $variables['internal_link_path'] = '';
    $variables['internal_link_title'] = '';
    $variables['internal_link_icon'] = '';
  }
}

/**
 * Implements hook_preprocess_paragraphs_item_BUNDLE().
 */
function boston_preprocess_paragraphs_item_external_link(&$variables) {
  $external_link = field_get_items('paragraphs_item', $variables['paragraphs_item'], 'field_external_link');
  $link_icon = drupal_static("link_icon", null);

  if ($external_link !== FALSE) {
    $variables['external_link_path'] = $external_link[0]['url'];
    $variables['external_link_title'] = check_plain($external_link[0]['title']);

    if (isset($link_icon)) {
      $variables['link_icon'] = $link_icon;
      drupal_static_reset("link_icon");
    }
  }
  else {
    $variables['external_link_path'] = '';
    $variables['external_link_title'] = '';
  }
}

/**
 * Implements hook_preprocess_paragraphs_item_BUNDLE().
 */
function boston_preprocess_paragraphs_item_lightbox_link(&$variables) {
    $lightbox_link = field_get_items('paragraphs_item', $variables['paragraphs_item'], 'field_lightbox_link');

    if ($lightbox_link !== FALSE) {
        $variables['lightbox_link_path'] = $lightbox_link[0]['url'];
        $variables['lightbox_link_title'] = check_plain($lightbox_link[0]['title']);
    }
    else {
        $variables['lightbox_link_path'] = '';
        $variables['lightbox_link_title'] = '';
    }
}

/**
 * Implements hook_preprocess_paragraphs_item_BUNDLE().
 */
function boston_preprocess_paragraphs_item_header_text(&$variables) {
  // In some cases we will need to bring the host content title into the
  // header text component so we can display it within the header text component
  // template.
  // @var \ParagraphsItemEntity $paragraph.
  $paragraph = $variables['elements']['#entity'];
  $paragraph_host = $paragraph->hostEntity();
  $host_title = check_plain($paragraph_host->title);
  $variables['host_title'] = $host_title;
}

/**
 * Implements hook_preprocess_HOOK().
 */
function boston_preprocess_paragraphs_item_text_two_column(&$variables) {
  $layout = field_get_items('paragraphs_item', $variables['paragraphs_item'], 'field_column_configuration');
  if ($layout !== FALSE) {
    $variables['classes_array'][] = $layout['0']['value'];
  }
}

/**
 * Implements hook_preprocess_HOOK().
 */
function boston_preprocess_field(&$variables, $hook) {
  $suggestions = &$variables['theme_hook_suggestions'];
  $view_mode = $variables['element']['#view_mode'];
  $bundle = $variables['element']['#bundle'];
  $field_name = $variables['element']['#field_name'];
  $entity_type = $variables['element']['#entity_type'];

  $is_component_field = $entity_type == 'paragraphs_item' && in_array($variables['element']['#bundle'], _bos_core_get_components());
  $is_subcomponent_field = $entity_type == 'paragraphs_item' && in_array($variables['element']['#bundle'], _bos_core_get_subcomponents());
  $variables['is_component_field'] = $is_component_field;
  $variables['is_subcomponent_field'] = $is_subcomponent_field;
  if ($is_component_field) {
    $suggestions[] = 'field__component__' . $variables['element']['#field_name'];
  }
  if ($is_subcomponent_field) {
    $suggestions[] = 'field__subcomponent__' . $variables['element']['#field_name'];
  }
  $field_name_preprocess = "boston_preprocess_field_$field_name";
  $base_suggestion = "field__$field_name";
  // Add view mode suggestions.
  $suggestions[] = "{$base_suggestion}__mode__{$view_mode}";
  $suggestions[] = "{$base_suggestion}__{$bundle}__mode__{$view_mode}";
  $suggestions[] = "{$base_suggestion}__type__{$entity_type}__mode__{$view_mode}";

  if (function_exists($field_name_preprocess)) {
    $field_name_preprocess($variables);
  }
}

/**
 * Implements hook_preprocess_HOOK().
 */
function boston_preprocess_field_field_intro_text(&$variables) {
  $variables['classes_array'] = [];
  $variables['classes_array'][] = "intro-text";
  $view_mode = $variables['element']['#view_mode'];
  $bundle = $variables['element']['#bundle'];
  // Add view modes and paragraph items to this array that
  // should not have additional classes.
  $intro_stripped = array(
    'listing',
    'short_listing',
    'long_listing',
    'featured_item',
    'user_action',
  );

  // The squiggle should not be present
  $no_squiggle = array(
    'hero_image',
  );

  // If view mode and paragraph item is not in the $intro_stripped array
  // add additional classes.
  if (!in_array($view_mode, $intro_stripped) && !in_array($bundle, $intro_stripped)) {
    $variables['classes_array'][] = "supporting-text";
    // Don't add squiggle border to intro-field in hero image component.
    if (!in_array($bundle, $no_squiggle)) {
      $variables['classes_array'][] = "squiggle-border-bottom";
    }
  }

  if ($variables['element']['#bundle'] == "hero_image") {
    boston_preprocess_field_field_component_title($variables);
  }
}

/**
 * Implements hook_preprocess_HOOK().
 */
function boston_preprocess_field_field_component_title(&$variables) {
  if ($variables['is_component_field']) {
    $component = $variables['element']['#object'];
    $short_title = field_get_items('paragraphs_item', $component, 'field_short_title');

    if ($short_title !== FALSE) {
      $variables['short_title'] = $short_title[0]['safe_value'];
      $short_title_link = preg_replace('@^[0-9\s]+@','', strtolower($short_title[0]['safe_value']));
      $variables['short_title_link'] = preg_replace('@[^a-z0-9-]+@','-', $short_title_link);
    }
  }
}

/**
 * Implements hook_preprocess_HOOK().
 */
function boston_preprocess_field_field_title(&$variables) {
  if (in_array($variables['element']['#bundle'], ['cabinet', 'fyi'])) {
    return boston_preprocess_field_field_component_title($variables);
  }
}

/**
 * Implements hook_preprocess_HOOK().
 */
function boston_preprocess_field_field_topics(&$variables) {
  if (in_array($variables['element']['#bundle'], ['featured_topics'])) {
    return boston_preprocess_field_field_component_title($variables);
  }
}

/**
 * Implements hook_preprocess_HOOK().
 */
function boston_preprocess_paragraphs_item_text(&$variables) {
  // Provide a class on the text paragraph entity wrapper indicating what
  // the background image of the component should be, if one is specified.
  $background_image = field_get_items('paragraphs_item', $variables['paragraphs_item'], 'field_background_image');
  if ($background_image !== FALSE) {
    $variables['classes_array'][] = $background_image[0]['value'];
  }
}

/**
 * Implements hook_preprocess_HOOK().
 */
function boston_preprocess_paragraphs_item_hero_image(&$variables) {
  // Provide a class on the text paragraph entity wrapper indicating what
  // the background image of the component should be, if one is specified.
  $has_background = true;
  $background_image = field_get_items('paragraphs_item', $variables['paragraphs_item'], 'field_image');

  if ($background_image[0]['uri']) {
    $xlarge_image = image_style_url('rep_wide_2000x700custom_boston_desktop_2x', $background_image[0]['uri']);
    $large_image = image_style_url('rep_wide_2000x700custom_boston_desktop_1x', $background_image[0]['uri']);
    $medium_image = image_style_url('rep_wide_2000x700custom_boston_tablet_2x', $background_image[0]['uri']);
    $small_image = image_style_url('rep_wide_2000x700custom_boston_mobile_2x', $background_image[0]['uri']);
  } else {
    $has_background = false;
  }

  // Set variables for the page
  $variables['has_background'] = $has_background;
  $variables['xlarge_image'] = $xlarge_image;
  $variables['large_image'] = $large_image;
  $variables['medium_image'] = $medium_image;
  $variables['small_image'] = $small_image;
  $variables['asset_url'] = variable_get('asset_url', 'https://patterns.boston.gov');
}

/**
 * Implements hook_preprocess_HOOK().
 */
function boston_preprocess_paragraphs_item_quote(&$variables) {

  if (!isset($variables['field_person_photo'])) {
    $variables['field_default_person_photo'] = '<img src="' . $variables['asset_url'] . '/images/global/icons/quote.svg" alt="No picture available">';
  }
  else {
    $variables['field_default_person_photo'] = render($variables['content']['field_person_photo']);
  }
}

/**
 * Implements hook_preprocess_views_view().
 */
function boston_preprocess_views_view(&$variables) {
  // Add view names to this list which should have exposed filters
  // in a sidebar.
  $view_name = $variables['view']->name;
  $view_sidebar = array(
    'calendar',
    'topic_landing_page',
  );
  // If a view is in the $view_sidebar array add the
  // class 'views-exposed-sidebar'.
  // Otherwise add the class 'views-exposed-topbar'.
  if ($variables['exposed']) {
    if (in_array($view_name, $view_sidebar)) {
      $variables['classes_array'][] = 'views-exposed-sidebar';
    }
    else {
      $variables['classes_array'][] = 'views-exposed-topbar';
    }
  }

  // Run individual preprocess functions per view name.
  $preprocess = __FUNCTION__ . '_' . $view_name;
  if (function_exists($preprocess)) {
    $preprocess($variables);
  }
}

/**
 * Implements hook_preprocess_views_view().
 */
function boston_preprocess_views_view_status_displays(&$variables) {
  // Check if the header should be overriden by an emergency.
  if ($emergency_id = bos_core_active_emergency()) {
    $emergency = node_load($emergency_id);
    // Get the title.
    $title = $emergency->title;

    // Get the theme
    $block_theme = ($item = bos_core_field_get_first_item('node', $emergency, 'field_theme')) ? $item['value'] : "";
    $variables['classes_array'][] = 'emergency ' . $block_theme;

    // Get the last updated date.
    $last_updated = ($item = bos_core_field_get_first_item('node', $emergency, 'field_updated_date')) ? $item['value'] : "";
    $last_updated = strtotime($last_updated);
    $last_updated = format_date($last_updated, 'boston_emergency_updated');

    // Get the emergency description.
    $description = ($item = bos_core_field_get_first_item('node', $emergency, 'field_description')) ? $item['value'] : "";

    // Get the call to action.
    $call_to_action_id = bos_core_field_get_first_item('node', $emergency, 'field_link')['value'];
    if ($call_to_action_id) {
      $call_to_action = paragraphs_item_load($call_to_action_id);
      $view = entity_view('paragraphs_item', array($call_to_action), $block_theme == 'dark-blue' ? 'button_link' : 'button_link_dark');
      $html = render($view);
      $call_to_action = $html;
    }

    $txt_theme = $block_theme == 'dark-blue' ? 'ob' : 'cb';
    $str_theme = $block_theme == 'dark-blue' ? 'b' : 'r';

    $variables['header'] = "<div class='b b--fw b--" . $str_theme . " b--cc b--wt m-b500'><div class='b-c'><div class='t--upper t--sans lh--000 t--" . $txt_theme . "'>Last updated: " . $last_updated . "</div>" .
      "<div class='str str--" . $str_theme . " m-v300'><div class='str-c'><div class='str-t'>" . $title . "</div></div></div>" .
      "<div class='t--sans t--" . $txt_theme . " lh--000 m-b500'>" . $description . "</div>" . $call_to_action . "</div></div>";
  }
  else {
    // Normally this would go in the theme to make the preprocess function more
    // discoverable but it needs to be run against the admin theme as well.
    $view = $variables['view'];
    $timestamp = strtotime($view->args[0]);
    if (FALSE !== $timestamp) {
      // See if this date falls on a special named date (i.e. a holiday or city
      // event, etc.).
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'taxonomy_term')
        ->entityCondition('bundle', 'holidays')
        ->fieldCondition('field_date', 'value', $view->args[0] . 'T00:00:00')
        ->range(0, 1);
      $result = $query->execute();
      if (!empty($result)) {
        $term = taxonomy_term_load(key($result['taxonomy_term']));
        $date = format_date($timestamp, 'status');
        $variables['header'] = "<div class='b b--fw'><div class='b-c b-c--nbp'>";
        $variables['header'] .= "<div class='str'><div class='str-c'>";
        $variables['header'] .= "<div class='str-t str-t--r m-b100'>" . $term->name . "</div>";
        $variables['header'] .= "<div class='str-st'>" . $date . "</div>";
        $variables['header'] .= '</div></div>';
        $variables['header'] .= '</div></div>';
      }
      else {
        $variables['header'] = "<div class='b b--fw'><div class='b-c b-c--nbp'><div class='str'><div class='str-c'><div class='str-t'>" . format_date($timestamp, 'status') . "</div></div></div></div></div>";
      }
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function boston_form_advpoll_choice_form_alter(&$form, &$form_state) {
  // For each form field, add a boolean to indicate this is a poll form. This
  // way, the ID can be removed in theme functions based on if the parent form
  // is a poll or not.
  foreach ($form as $key => $item) {
    if (strpos($key, '#') !== 0 && $key !== 'submit') {
      $form[$key]['#process'][] = 'boston_advpoll_ids';
    }
  }
}

/**
 * Process function to add random string of numbers to the end of element IDs.
 *
 * This adds a random string of numbers to form fields to prevent the issue of
 * there being multiple IDs that are the same on a page.
 *
 * @param array $variables
 *   The variables to use.
 */
function boston_advpoll_ids($variables) {
  if (isset($variables['element']['#id'])) {
    $variables['element']['#id'] .= '--' . rand();
  }
}

/**
 * Helper function for getting the host of a message for the day paragraph.
 *
 * Needed to account for workbench/paragraphs bug where host information
 * is not set on a the paragraph if the content it's attached to has one
 * revision in draft state immediately following a published revision.
 *
 * @param $message
 *   Paragraphs item message for the day.
 *
 * @return
 *   Loaded node object representing the host of the message.
 */
function _get_message_host($message) {
   $host = $message->hostEntity();
   if (!empty($host)) {
     return $host;
   }
   $mid = $message->item_id;
   $query = db_select('field_data_' . $message->field_name, 'fm')
     ->fields('fm', array('entity_id'))
     ->condition('field_messages_value', $mid);
   $result = $query->execute();
   $nid = $result->fetchField(0);
   if (!empty($nid)) {
     return node_load($nid);
   }
   return FALSE;
 }

/**
 * Implements hook_theme_menu_tree() for footer menu block.
 */
 function boston_menu_tree__menu_footer_menu($variables) {
   return '<ul class="ft-ll">' . $variables['tree'] . '</ul>';
 }

 /**
 * Implements theme_menu_link().
 */
function boston_menu_link__menu_footer_menu(array $variables) {
  $element = $variables['element'];

  $element['#attributes']['class'][] = 'ft-ll-a';

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  return '<li class="ft-ll-i">' . $output . "</li>\n";
}

function boston_preprocess_field_field_tabbed_content(&$variables) {
  $GLOBALS['tabbed_content_tabs_count'] = 0;
}

function boston_preprocess_paragraphs_item_tabbed_content_tab(&$variables) {
  $variables['tabbed_content_tabs_count'] = $GLOBALS['tabbed_content_tabs_count'];
  $GLOBALS['tabbed_content_tabs_count']++;
}
