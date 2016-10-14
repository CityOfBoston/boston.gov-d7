<?php
/**
 * @file
 * Edit domain settings.
 */
// Create edit domain variables.
$host = isset($_SERVER['HTTP_HOST']) ? $_SERVER['HTTP_HOST'] : '';
$forwarded_host = (empty($_SERVER['HTTP_X_FORWARDED_HOST'])) ? $host : $_SERVER['HTTP_X_FORWARDED_HOST'];
$conf['is_edit_domain'] = FALSE;
if (strpos($forwarded_host, 'edit') !== FALSE) {
  $conf['is_edit_domain'] = TRUE;
}
