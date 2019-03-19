<?php

/**
 * @file
 * Bootstrap Drupal if needed.
 */

namespace Drupal\phpunit;

/**
 * Class CityScoreTest: Tests cityscore API.
 *
 * @package Drupal
 */
class COBDrupalBootstrap {

  /**
   * Used to track the drupal root.
   *
   * @var string
   */
  private $drupalRoot = "";

  /**
   * Bootstraps Drupal prior to test.
   */
  public function bootstrapDrupal($drupalroot = NULL) {
    $this->drupalRoot = getcwd();
    if (isset($drupalroot)) {
      $this->drupalRoot = $drupalroot;
    }
    if (!defined('DRUPAL_ROOT')) {
      define('DRUPAL_ROOT', $this->drupalRoot);
    }
    require_once DRUPAL_ROOT . '/includes/bootstrap.inc';

    // Bootstrap Drupal.
    drupal_bootstrap(DRUPAL_BOOTSTRAP_VARIABLES);
  }

}
