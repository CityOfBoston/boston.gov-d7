<?php
/**
 * @file
 * bos_vocabulary_contact.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_vocabulary_contact_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
