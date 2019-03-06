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
   * @var string
   *   Used to track the drupal root.
   */
  private $drupalRoot = "";

  /**
   * Bootstraps Drupal prior to test.
   */
  public function bootstrapDrupal($drupalRoot = null) {
    $this->drupalRoot = getcwd();
    if (isset($drupalRoot)) {
      $this->drupalRoot = $drupalRoot;
    }
    echo $drupalRoot;
    if (!defined('DRUPAL_ROOT')) {
      define('DRUPAL_ROOT', $this->drupalRoot);
    }
    require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
    $_SERVER['REMOTE_ADDR'] = '127.0.0.1';

    // Bootstrap Drupal.
    drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
  }

}
