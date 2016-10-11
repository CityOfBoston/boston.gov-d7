<?php
/**
 * @file
 * bos_context_global_footer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_context_global_footer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
