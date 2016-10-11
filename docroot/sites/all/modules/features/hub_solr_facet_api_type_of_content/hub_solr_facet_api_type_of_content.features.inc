<?php
/**
 * @file
 * hub_solr_facet_api_type_of_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hub_solr_facet_api_type_of_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}
