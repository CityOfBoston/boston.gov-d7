<?php
/**
 * @file
 * bos_context_global_modal.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_context_global_modal_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
