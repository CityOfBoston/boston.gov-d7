<?php
/**
 * @file
 * Contains functions to alter Drupal's markup for the Boston Hub theme.
 */

/**
 * Implements hook_preprocess_page().
 */
function boston_hub_preprocess_page(array &$variables) {
  // Loads Profile fields to variables for logged in users.
  if ($variables['logged_in']) {
    $uid = user_load($variables['user']->uid);
    $profile_main = profile2_load_by_user($uid, 'main');
    // Set profile_name variable to profile real name if it exists,
    // otherwise set it to the username.
    if ($profile_main->field_display_name) {
      $variables['profile_name'] = field_view_field('profile2', $profile_main, 'field_display_name', 'value')['#items'][0]['safe_value'];
      $variables['first_name'] = field_view_field('profile2', $profile_main, 'field_first_name', 'value')['#items'][0]['safe_value'];
    }
    else {
      $variables['profile_name'] = $uid->name;
    }

    if ($profile_main->field_work_email) {
      $field_work_email = field_view_field('profile2', $profile_main, 'field_work_email', 'value')['#items'][0]['safe_value'];

      if ($field_work_email === null) {
        $field_work_email = 'default@boston.gov';
      }

      $variables['field_work_email'] = strtolower($field_work_email);
    }

    // Create necessary page classes
    if ($variables['node']->type !== 'tabbed_content' && $variables['node']->type !== 'how_to') {
      $page_class = 'page';
    } else {
      $page_class = NULL;
    }

    // Set profile_avatar variable to profile picture if it exists,
    // otherwise set it to default image.
    if (!empty($profile_main) && !empty($profile_main->field_user_picture)) {
      $variables['profile_avatar'] = theme_image_style(
        array(
          'style_name' => 'medium_square',
          'path' => field_view_field('profile2', $profile_main, 'field_user_picture')['#items'][0]['uri'],
          'attributes' => array(
            'class' => 'avatar',
          ),
          'width' => NULL,
          'height' => NULL,
        )
      );
    }
    else {
      $variables['profile_avatar'] = '<img src="/' . drupal_get_path('theme', 'boston_hub') . '/dist/img/default-avatar.svg" alt="Missing profile picture">';
    }

    $main_menu_links = menu_load_links('main-menu');
    if (isset($main_menu_links)) {
      foreach ($main_menu_links as $menu_link) {
        // 'My Account' has a Menu Link ID (mlid) of 211746.
        // Check that the current link has Parent Link ID (plid) of My Account.
        // Make sure the current link is not disabled.
        if ($menu_link['plid'] == '211746' && $menu_link['hidden'] == 0) {
          // Change Password.
          if ($menu_link['mlid'] == '211751') {
            $change_pw_full_url = $menu_link['link_path'];
            $change_pw_relative_url = parse_url($change_pw_full_url, PHP_URL_PATH);
            $change_pw_title = $menu_link['link_title'];
          }
          // Security Questions.
          if ($menu_link['mlid'] == '211756') {
            $security_questions_url = $menu_link['link_path'];
            $security_questions_title = $menu_link['link_title'];
          }
          if ($menu_link['mlid'] == '211761') {
            $logout_url = $menu_link['link_path'];
            $logout_title = $menu_link['link_title'];
          }
          // Profile.
          if ($menu_link['mlid'] == '135661') {
            $profile_url = $menu_link['link_path'];
            $profile_title = $menu_link['link_title'];
          }
        }
      }
    }
    if (isset($profile_url)) {
      $variables['profile_path'] = base_path() . $profile_url;
      $variables['profile_title'] = $profile_title;
    }
    if (isset($logout_url)) {
      $variables['logout_path'] = base_path() . $logout_url;
      $variables['logout_title'] = $logout_title;
    }
    if (isset($security_questions_url)) {
      $variables['security_questions_path'] = $security_questions_url;
      $variables['security_questions_title'] = $security_questions_title;
    }
    if (isset($change_pw_relative_url)) {
      $variables['change_password_title'] = $change_pw_title;
      switch ($_ENV['AH_SITE_ENVIRONMENT']) {
        case 'dev':
          $variables['change_password_path'] = 'https://identity-dev.boston.gov' . $change_pw_relative_url;
          break;

        case 'test':
          $variables['change_password_path'] = 'https://identity-test.boston.gov' . $change_pw_relative_url;
          break;

        case 'prod':
          $variables['change_password_path'] = 'https://identity.boston.gov' . $change_pw_relative_url;
          break;

        default:
          $variables['change_password_path'] = 'https://identity.boston.gov/identityiq/changePassword.jsf';
      }
    }
  }

  $current_path = current_path();

  $page_class_alert = $page_class;

  // If we are on the employee directory page, change the title.
  if (strpos($current_path, 'employee-directory') === 0) {
    drupal_set_title('Employee Search');
  }

  // If on search, don't show page title
  $variables['hide_page_title'] = strpos($current_path, 'search') === 0 || strpos($current_path, 'swiftype') === 0 || strpos($current_path, 'employees') === 0;

  // If we are on the employee directory page, change the title.
  if (strpos($current_path, 'swiftype') === 0 || strpos($current_path, 'search') === 0 || strpos($current_path, 'my-profile') === 0 || strpos($current_path, 'user') === 0 || strpos($current_path, 'employees') === 0) {
    $page_class_alert = 'page page--wa';
  }

  // If this is a 404 page, $variables['search_block'] will exist but be NULL,
  // so load this site's search block.
  if (is_null($variables['search_block'])) {
    $block = module_invoke('hub_blocks', 'block_view', 'search');
    $variables['search_block'] = $block;
    $variables['search_id'] = 'block-hub-blocks-search';
  }

  if (isset($variables['node'])) {
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
      $page_class_alert = 'page';
      $page_class = 'page';
    }
  }

  $variables['page_class'] = $page_class;
  $variables['page_class_alert'] = $page_class_alert;

  // Only show logged in menu items
  $nav_menu = array();
  foreach ($variables['secondary_menu'] as $key => $menu) {
    if ($variables['logged_in'] && $menu['title'] != 'Log In') {
      $nav_menu[] = $menu;
    } else if (!$variables['logged_in'] && $menu['title'] == 'Log In') {
      $menu['always_show'] = TRUE;
      $nav_menu[] = $menu;
    }
  }

  $variables['nav_menu'] = $nav_menu;

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
}

/**
 * Implements hook_preprocess_html().
 */
function boston_hub_preprocess_html(array &$variables, $hook) {
  // Adding theme's JS to footer.
  drupal_add_js(drupal_get_path('theme', 'boston_hub') . '/dist/js/all.min.js', array(
    'scope' => 'footer',
    'every_page'  => TRUE,
  ));
}

/**
 * Implements hook_preprocess_search_results().
 */
function boston_hub_preprocess_search_results(&$variables) {
  // Get the search term from the URL.
  $query_param = check_plain($variables['query']->getParam('q'));
  $clean_title = check_plain(htmlspecialchars_decode($query_param));
  $search_term = urldecode($clean_title);
  $variables['search_term'] = $search_term;

  // If there are not results from the search, get the text for the Suggestions.
  if (empty($variables['results'])) {
    $variables['no_results_suggestions'] = variable_get('hub_settings_apache_solr_no_results_suggestions');
  }
  else {
    // Add the facets block.
    // Here we add the real block from the cloud, and for testing purposes
    // I'm adding a block that should work for localhost.
    if ($variables['search_page']['page_id'] == "core_search") {
      $cloud_search_block = module_invoke('facetapi', 'block_view', 'iLOyHjPah8Jtd2iAJv073e4vtVtL4H8i');
      $local_search_block = module_invoke('facetapi', 'block_view', 'KDCBPvuidlfD00604jKWQA89mHFb41Lk');
      $facet_title = 'Filter by Type of Content: ';
      $facet_class = "search-facet";
    }
    elseif ($variables['search_page']['page_id'] == "people_directory") {
      $cloud_search_block = module_invoke('facetapi', 'block_view', 'tRH26ZRvaPEp8AQPh9JtZ7QOnV6e1PXs');
      $local_search_block = module_invoke('facetapi', 'block_view', 'X2kMsZBhT5uLJyIit01FTVFpATM9TkSo');
      $facet_title = "Filter by Department";
      $facet_class = "employee-facet";
      $sort_block = module_invoke('apachesolr_search', 'block_view', 'sort');
      $variables['search_sort'] = $sort_block;
      // Use template file search-results--employee-directory.tpl.php.
      $variables['theme_hook_suggestion'] = 'search_results__employee_directory';
      $variables['departments_link'] = base_path() . 'departments';
    }
    $variables['facet_class'] = $facet_class;

    if (!empty($cloud_search_block)) {
      $variables['facets'] = $cloud_search_block;
    }
    elseif (!empty($local_search_block)) {
      $variables['facets'] = $local_search_block;
    }
    if (!empty($variables['facets'])) {
      $variables['facets']['subject'] = $facet_title;
    }
  }
}

/**
 * Implements hook_preprocess_search_result().
 */
function boston_hub_preprocess_search_result(&$variables) {

  // If the result is a node, get the field_updated_date to display.
  if (!empty($variables['result']['node']) && !empty($variables['result']['fields']['dm_field_updated_date'][0])) {
    $my_date = $variables['result']['fields']['dm_field_updated_date'][0];
    $formatted_date = format_date(strtotime($my_date), 'boston_short');
    $variables['updated_date'] = render($formatted_date);
  }
  elseif ($variables['result']['entity_type'] == 'profile2') {
    // Do something to pick out the user fields if we need to.
    $variables['user_picture_url'] = $variables['result']['fields']['ss_user_picture_url'];
    if (!empty($variables['result']['fields']['sm_field_display_name'][0])) {
      $variables['user_display_name'] = $variables['result']['fields']['sm_field_display_name'][0];
    }
    if (!empty($variables['result']['fields']['sm_field_work_email'][0])) {
      $variables['user_work_email'] = $variables['result']['fields']['sm_field_work_email'][0];
    }
    if (!empty($variables['result']['fields']['sm_field_position_title'][0])) {
      $variables['user_position_title'] = $variables['result']['fields']['sm_field_position_title'][0];
    }
    if (!empty($variables['result']['fields']['sm_field_display_name'][0])) {
      $variables['title'] = $variables['result']['fields']['sm_field_display_name'][0];
    }
    if (!empty($variables['result']['fields']['ss_department_name'])) {
      $variables['user_department'] = $variables['result']['fields']['ss_department_name'];
    }
    if (!empty($variables['result']['fields']['sm_field_work_phone_number'][0])) {
      $variables['user_work_phone'] = $variables['result']['fields']['sm_field_work_phone_number'][0];
    }

    if (!empty($_GET['q'])) {
      $search_page = reset(explode('/', $_GET['q']));
      if ($search_page == 'employee-directory') {
        // Use template file search-result--employee-directory.tpl.php.
        $variables['theme_hook_suggestion'] = 'search_result__employee_directory';
        $variables['default_profile_picture'] = '<img src="/' . drupal_get_path('theme', 'boston_hub') . '/dist/img/default-avatar-lg.svg" alt="No profile picture available">';
      }
    }
  }
  // If we have a document and the updated date wasn't set,
  // get the date from the file.
  if (empty($variables['updated_date']) && $variables['result']['bundle'] == 'document') {
    $my_date = $variables['result']['node']->ds_changed;
    $formatted_date = format_date(strtotime($my_date), 'boston_short');
    $variables['updated_date'] = render($formatted_date);
  }
}

/**
 * Implements hook_apachesolr_search_noresults().
 */
function boston_hub_apachesolr_search_noresults() {

  // Get the search term from the URL, it's the last element in the URL.
  $url = current_path();
  $params = explode('/', $url);

  $query_param = check_plain(end($params));
  $clean_title = check_plain(htmlspecialchars_decode($query_param));
  $search_term = urldecode($clean_title);
  $build = "";
  $search_page = apachesolr_search_page_load('core_search');
  $current_path = current_path();

  // Add the 0 results text and suggestions.
  if ($current_path != $search_page['search_path']) {
    // Return a renderable array so that we can insert the Suggestions block
    // when needed.
    $build = array(
      '#prefix' => '<div class="search-results-wrapper"><div class="container">',
      '#suffix' => '</div></div>',
      'search_found' => array(
        '#prefix' => '<div class="search_found_zero desktop-66-left">',
        '#suffix' => '</div>',
        0 => array(
          '#markup' => 'Found 0 results containing: ' . $search_term,
        ),
      ),
      'search_tips' => array(
        '#prefix' => '<div class="desktop-33-right search-suggestions">',
        '#suffix' => '</div>',
        0 => array(
          '#markup' => variable_get('hub_settings_apache_solr_no_results_suggestions')['value'],
        ),
      ),
    );
  }
  return $build;
}

/**
 * Implements hook_facetapi_link_inactive().
 *
 * Remove entire function to add count back to facets
 * or uncomment the "Adds count to link" code below.
 */
function boston_hub_facetapi_link_inactive($variables) {
  // Builds accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => FALSE,
  );
  $accessible_markup = theme('facetapi_accessible_markup', $accessible_vars);

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $variables['text'] = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Adds count to link if one was passed.
  // Commented out to indicate this is overriding existing function
  // and in case we want to add it back in.
  /*if (isset($variables['count'])) {
  $variables['text'] .= ' ' . theme('facetapi_count', $variables);
  }*/

  // Resets link text, sets to options to HTML since we already sanitized the
  // link text and are providing additional markup for accessibility.
  $variables['text'] .= $accessible_markup;
  $variables['options']['html'] = TRUE;
  return theme_link($variables);
}

/**
 * Implements theme_apachesolr_search_snippets__file().
 *
 * Replace the snippet for files with just the name of the file.
 */
function boston_hub_apachesolr_search_snippets__file($vars) {
  $output = reset($vars['flattened_snippets']);
  return $output;
}

/**
 * Implements template_preprocess_entity().
 *
 * Runs a entity specific preprocess function, if it exists.
 */
function boston_hub_preprocess_entity(&$variables, $hook) {
  $function = __FUNCTION__ . '_' . $variables['entity_type'];
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}

/**
 * Implements hook_menu_local_tasks_alter().
 */
function boston_hub_menu_local_tasks_alter(&$data, $router_item, $root_path) {
  global $user;

  // Hides View/Edit links on user pages for non-admins.
  if ($user && !in_array('administrator', array_values($user->roles))) {
    if ($data['tabs'][0]['output']) {
      foreach ($data['tabs'][0]['output'] as $key => $value) {
        // Remove 'View' link if it exists.
        if ($value['#link']['path'] == 'user/%/view') {
          unset($data['tabs'][0]['output'][$key]);
        }
        // Remove 'Edit' link if it exists.
        if ($value['#link']['path'] == 'user/%/edit') {
          unset($data['tabs'][0]['output'][$key]);
        }
      }
    }
  }
}

/**
 * Profile2 specific implementation of template_preprocess_entity().
 */
function boston_hub_preprocess_entity_profile2(&$variables, $hook) {
  // Get the user we are trying to view.
  $user = user_load($variables['profile2']->uid);
  $user_profile = profile2_load_by_user($user);

  if (!empty($user_profile['main']->field_contact)) {
    $department = taxonomy_term_load($user_profile['main']->field_contact['und'][0]['target_id']);
    $variables["department_id"] = $department->field_department_legacy_id['und'][0]['value'];
    $variables["department_name"] = $department->name;
  }

  // Meta tags for Swiftype
  $last_name_element = array(
    '#tag' => 'meta', // The #tag is the html tag -
    '#attributes' => array( // Set up an array of attributes inside the tag
      'class' => 'swiftype',
      'name' => 'last-name',
      'data-type' => 'enum',
      'content' => $user_profile['main']->field_last_name['und'][0]['value'],
    ),
  );
  drupal_add_html_head($last_name_element, 'swiftype_last_name');

  $department_name_element = array(
    '#tag' => 'meta', // The #tag is the html tag -
    '#attributes' => array( // Set up an array of attributes inside the tag
      'class' => 'swiftype',
      'name' => 'department-name',
      'data-type' => 'string',
      'content' => $variables["department_name"],
    ),
  );
  drupal_add_html_head($department_name_element, 'swiftype_department_name');

  $department_id_element = array(
    '#tag' => 'meta', // The #tag is the html tag -
    '#attributes' => array( // Set up an array of attributes inside the tag
      'class' => 'swiftype',
      'name' => 'department-id',
      'data-type' => 'string',
      'content' => $variables["department_id"],
    ),
  );
  drupal_add_html_head($department_id_element, 'swiftype_department_id');

  // Meta tags for Swiftype
  $work_phone_element = array(
    '#tag' => 'meta', // The #tag is the html tag -
    '#attributes' => array( // Set up an array of attributes inside the tag
      'class' => 'swiftype',
      'name' => 'phone',
      'data-type' => 'string',
      'content' => strtolower($user_profile['main']->field_work_phone['und'][0]['value']),
    ),
  );
  drupal_add_html_head($work_phone_element, 'swiftype_work_phone');

  $work_email_element = array(
    '#tag' => 'meta', // The #tag is the html tag -
    '#attributes' => array( // Set up an array of attributes inside the tag
      'class' => 'swiftype',
      'name' => 'email',
      'data-type' => 'string',
      'content' => strtolower($user_profile['main']->field_work_email['und'][0]['value']),
    ),
  );
  drupal_add_html_head($work_email_element, 'swiftype_work_email');

  // Meta tags for Swiftype
  $type_element = array(
    '#tag' => 'meta', // The #tag is the html tag -
    '#attributes' => array( // Set up an array of attributes inside the tag
      'class' => 'swiftype',
      'name' => 'type',
      'data-type' => 'enum',
      'content' => 'person',
    ),
  );
  drupal_add_html_head($type_element, 'swiftype_type');

  // Meta tags for Swiftype
  $title_element = array(
    '#tag' => 'meta', // The #tag is the html tag -
    '#attributes' => array( // Set up an array of attributes inside the tag
      'class' => 'swiftype',
      'name' => 'title',
      'data-type' => 'string',
      'content' => $user_profile['main']->field_display_name['und'][0]['value'],
    ),
  );
  drupal_add_html_head($title_element, 'swiftype_title');

  $position_element = array(
    '#tag' => 'meta', // The #tag is the html tag -
    '#attributes' => array( // Set up an array of attributes inside the tag
      'class' => 'swiftype',
      'name' => 'position',
      'data-type' => 'string',
      'content' => $user_profile['main']->field_position_title['und'][0]['value'],
    ),
  );
  drupal_add_html_head($position_element, 'swiftype_position');

  // Find the user's manager.
  if (!empty($user_profile['main']->field_manager)) {
    $manager_field = user_load($user_profile['main']->field_manager['und'][0]['target_id']);
    if (!empty($manager_field)) {
      $manager_profile = profile2_load_by_user($manager_field);
      // Get the manager's Display Name so the template can show it.
      if (!empty($manager_profile)) {
        $manager_display_name = reset(field_get_items('profile2', $manager_profile['main'], 'field_display_name'));
        $variables['manager_display_name'] = $manager_display_name['value'];
      }
    }
  }

  $variables['change_password_url'] = variable_get('hub_profile_change_password_url', '');
  drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/dist/js/resizer.js');
}
