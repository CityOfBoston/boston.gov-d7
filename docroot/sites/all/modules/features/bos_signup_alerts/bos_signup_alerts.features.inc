<?php
/**
 * @file
 * bos_signup_alerts.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function bos_signup_alerts_paragraphs_info() {
  $items = array(
    'bos_signup_emergency_alerts' => array(
      'name' => 'Signup Emergency Alerts',
      'bundle' => 'bos_signup_emergency_alerts',
      'locked' => '1',
    ),
  );
  return $items;
}
