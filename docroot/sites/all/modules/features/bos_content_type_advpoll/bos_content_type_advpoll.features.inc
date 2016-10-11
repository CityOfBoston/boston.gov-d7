<?php
/**
 * @file
 * bos_content_type_advpoll.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_content_type_advpoll_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
