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
    ),
    'search_plugins' => array(
      'entity:profile2' => array(
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
      'entity:taxonomy_term' => array(
        'enabled' => 0,
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
    ),
    'entity:node' => array(
      'result_description' => '',
      'bundles' => array(
        'application' => 0,
        'article' => 0,
        'department_profile' => 0,
        'event' => 0,
        'topic_page' => 0,
        'how_to' => 0,
        'landing_page' => 0,
        'listing_page' => 0,
        'post' => 0,
        'script_page' => 0,
        'tabbed_content' => 0,
      ),
      'group_by_bundle' => 1,
      'include_unpublished' => 0,
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'event_type' => 0,
        'neighborhoods' => 0,
        'news_tags' => 0,
        'contact' => 0,
        'topic_category' => 0,
        'icons' => 0,
        'type_of_content' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_application' => 0,
        'comment_node_article' => 0,
        'comment_node_department_profile' => 0,
        'comment_node_event' => 0,
        'comment_node_topic_page' => 0,
        'comment_node_how_to' => 0,
        'comment_node_landing_page' => 0,
        'comment_node_listing_page' => 0,
        'comment_node_post' => 0,
        'comment_node_script_page' => 0,
        'comment_node_tabbed_content' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:profile2' => array(
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
    'insert_plugin' => array(
      'url_method' => '3',
    ),
    'attribute_plugins' => array(
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'imce' => 1,
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['bos_settings_linkit_editor'] = $linkit_profile;

  return $export;
}
