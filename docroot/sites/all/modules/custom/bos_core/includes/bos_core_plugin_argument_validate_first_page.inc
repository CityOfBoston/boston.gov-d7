<?php
/**
 * @file
 * Contains the first page views validator class.
 */

/**
 * Class bos_core_plugin_argument_validate_first_page.
 */
class bos_core_plugin_argument_validate_first_page extends views_plugin_argument_validate {

  function construct() {
    parent::construct();
  }

  function validate_argument($argument) {
    if (!isset($_GET['page'])) {
      return TRUE;
    }
    // Edge case, since a pager link to the first page will always not include
    // page in the query string.
    return $_GET['page'] == '0';
  }
}
