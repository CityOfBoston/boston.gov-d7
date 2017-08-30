<?php
/**
 * @file
 * bos_settings_linkit_editor.linkit_profiles.inc
 */

/**
 * Implements hook_default_linkit_profiles().
 */
function bos_settings_linkit_editor_default_linkit_profiles() {
  $export = array();

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'bos_settings_linkit_editor';
  $linkit_profile->admin_title = 'bos_settings_linkit_editor';
  $linkit_profile->admin_description = 'A content editor profile has the ability to search for and link to internal content in the WYSIWYG w/o having to copy paste the URL in.';
  $linkit_profile->profile_type = '1';
  $linkit_profile->data = array(
    'text_formats' => array(
      'filtered_html' => 'filtered_html',
      'full_html' => 'full_html',
      'plain_text' => 0,
      'script_source_url' => 0,
    ),
    'button_text' => 'Search',
    'search_plugins' => array(
      'entity:salesforce_mapping' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:salesforce_mapping_object' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:menu_link' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'entity:node' => array(
      'result_description' => '',
      'bundles' => array(
        'advpoll' => 0,
        'article' => 0,
        'change' => 0,
        'department_profile' => 0,
        'emergency_alert' => 0,
        'event' => 0,
        'topic_page' => 0,
        'how_to' => 0,
        'landing_page' => 0,
        'listing_page' => 0,
        'metrolist_affordable_housing' => 0,
        'person_profile' => 0,
        'place_profile' => 0,
        'post' => 0,
        'program_initiative_profile' => 0,
        'public_notice' => 0,
        'script_page' => 0,
        'site_alert' => 0,
        'status_item' => 0,
        'tabbed_content' => 0,
        'transaction' => 0,
      ),
      'group_by_bundle' => 1,
      'include_unpublished' => 0,
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'contact' => 0,
        'news_tags' => 0,
        'event_type' => 0,
        'neighborhoods' => 0,
        'political_party' => 0,
        'profile_type' => 0,
        'program_type' => 0,
        'place_type' => 0,
        'features' => 0,
        'icons' => 0,
        'topic_category' => 0,
        'type_of_content' => 0,
        '311_request' => 0,
        'holidays' => 0,
        'public_notice_type' => 0,
        'newsletters' => 0,
        'maps_esri_feed' => 0,
        'maps_basemap' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_advpoll' => 0,
        'comment_node_article' => 0,
        'comment_node_change' => 0,
        'comment_node_department_profile' => 0,
        'comment_node_emergency_alert' => 0,
        'comment_node_event' => 0,
        'comment_node_topic_page' => 0,
        'comment_node_how_to' => 0,
        'comment_node_landing_page' => 0,
        'comment_node_listing_page' => 0,
        'comment_node_metrolist_affordable_housing' => 0,
        'comment_node_person_profile' => 0,
        'comment_node_place_profile' => 0,
        'comment_node_post' => 0,
        'comment_node_program_initiative_profile' => 0,
        'comment_node_public_notice' => 0,
        'comment_node_script_page' => 0,
        'comment_node_site_alert' => 0,
        'comment_node_status_item' => 0,
        'comment_node_tabbed_content' => 0,
        'comment_node_transaction' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:salesforce_mapping' => array(
      'result_description' => '',
    ),
    'entity:salesforce_mapping_object' => array(
      'result_description' => '',
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'url_type' => 'direct',
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'entity:menu_link' => array(
      'result_description' => '',
      'bundles' => array(
        'menu-accessibility-menu' => 0,
        'menu-footer-menu' => 0,
        'main-menu' => 0,
        'management' => 0,
        'navigation' => 0,
        'menu-secondary-menu' => 0,
        'menu-translation-menu' => 0,
        'user-menu' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'insert_plugin' => array(
      'url_method' => '3',
    ),
    'attribute_plugins' => array(
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'imce' => 0,
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $linkit_profile->weight = 0;
  $export['bos_settings_linkit_editor'] = $linkit_profile;

  return $export;
}
