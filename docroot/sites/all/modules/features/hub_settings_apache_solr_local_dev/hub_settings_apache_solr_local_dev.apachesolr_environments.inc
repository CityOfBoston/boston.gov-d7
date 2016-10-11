<?php
/**
 * @file
 * hub_settings_apache_solr_local_dev.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function hub_settings_apache_solr_local_dev_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'localhost server';
  $environment->url = 'http://localhost:8983/solr/collection1';
  $environment->service_class = '';
  $environment->conf = array();
  $environment->index_bundles = array(
    'node' => array(
      0 => 'article',
      1 => 'department_profile',
      2 => 'event',
      3 => 'how_to',
      4 => 'landing_page',
      5 => 'listing_page',
      6 => 'post',
      7 => 'script_page',
      8 => 'tabbed_content',
      9 => 'topic_page',
    ),
    'profile2' => array(
      0 => 'main',
    ),
    'file' => array(
      0 => 'document',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
