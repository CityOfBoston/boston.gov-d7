<?php
/**
 * @file
 * bos_vocabulary_bid_offering.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_vocabulary_bid_offering_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
