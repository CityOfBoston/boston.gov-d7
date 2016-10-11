<?php
/**
 * @file
 * hub_settings_apache_solr_local_dev.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hub_settings_apache_solr_local_dev_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "apachesolr" && $api == "apachesolr_environments") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
