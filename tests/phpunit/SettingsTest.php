<?php

/**
 * @file
 * Test configuration in settings.php.
 */

namespace Drupal;

use PHPUnit_Framework_TestCase;
/**
 * Tests settings.php tests.
 */
class SettingsTest extends PHPUnit_Framework_TestCase {
  /**
   * Sets up require parameters for tests to run.
   *
   * @param string $env
   *   The acquia environment being simulated. E.g., prod, test, dev, etc.
   */
  public function setupParams($env) {

    $this->projectRoot = dirname(dirname(__DIR__));
    $this->drupalRoot = $this->projectRoot . '/docroot';
    if (!defined('DRUPAL_ROOT')) {
      define('DRUPAL_ROOT', $this->drupalRoot);
    }
  }

  /**
   * Test configuration for production environment on ACE.
   */
  public function testProd() {

    $this->setupParams('prod');
    require $this->drupalRoot . '/sites/default/settings.php';

    // Assert cache.settings.php.
    $this->assertEquals(TRUE, $conf['cache']);
    $this->assertEquals(TRUE, $conf['block_cache']);
    $this->assertEquals(TRUE, $conf['page_compression']);
    $this->assertEquals(TRUE, $conf['preprocess_css']);
    $this->assertEquals(TRUE, $conf['preprocess_js']);
    $this->assertEquals(0, $conf['cache_lifetime']);
    $this->assertEquals(21600, $conf['page_cache_maximum_age']);
    $this->assertEquals('sites/all/modules/contrib/memcache/memcache.inc', $conf['cache_backends'][0]);
    $this->assertEquals('MemCacheDrupal', $conf['cache_default_class']);
    $this->assertEquals('DrupalDatabaseCache', $conf['cache_class_cache_form']);
    $this->assertEquals('includes/cache-install.inc', $conf['cache_backends'][1]);
    $this->assertEquals('DrupalFakeCache', $conf['cache_class_cache_page']);
    $this->assertEquals(FALSE, $conf['page_cache_invoke_hooks']);
    $this->assertEquals(TRUE, $conf['page_cache_without_database']);
    $this->assertEquals(TRUE, $conf['redirect_page_cache']);

    // Cron.
    $this->assertEquals(TRUE, $conf['acquia_spi_use_cron']);
    $this->assertEquals(FALSE, $conf['cron_safe_threshold']);

    // Files.
    $this->assertEquals('sites/default/files', $conf['file_public_path']);
    $this->assertEquals('sites/all', $conf['composer_manager_file_dir']);
    $this->assertEquals('sites/all/vendor', $conf['composer_manager_vendor_dir']);
    $this->assertEquals(FALSE, $conf['composer_manager_autobuild_file']);
    $this->assertEquals(FALSE, $conf['composer_manager_autobuild_packages']);
    $this->assertEquals(FALSE, $conf['admin_menu_cache_client']);

    // Testing.
    $this->assertEquals(FALSE, $conf['admin_menu_cache_client']);
  }

  /**
   * Test configuration for test/stg environment on ACE.
   */
  public function testTest() {

    $this->setupParams('test');
    require $this->drupalRoot . '/sites/default/settings.php';

    // Assert cache.settings.php.
    $this->assertEquals('sites/all/modules/contrib/memcache/memcache.inc', $conf['cache_backends'][0]);
    $this->assertEquals('MemCacheDrupal', $conf['cache_default_class']);
    $this->assertEquals('DrupalDatabaseCache', $conf['cache_class_cache_form']);
    $this->assertEquals('includes/cache-install.inc', $conf['cache_backends'][1]);
    $this->assertEquals('DrupalFakeCache', $conf['cache_class_cache_page']);
    $this->assertEquals(FALSE, $conf['page_cache_invoke_hooks']);
    $this->assertEquals(TRUE, $conf['page_cache_without_database']);
    $this->assertEquals(TRUE, $conf['redirect_page_cache']);

    // Cron.
    $this->assertEquals(FALSE, $conf['acquia_spi_use_cron']);

    // Files.
    $this->assertEquals('sites/default/files', $conf['file_public_path']);
    $this->assertEquals('sites/all', $conf['composer_manager_file_dir']);
    $this->assertEquals('sites/all/vendor', $conf['composer_manager_vendor_dir']);
    $this->assertEquals(FALSE, $conf['composer_manager_autobuild_file']);
    $this->assertEquals(FALSE, $conf['composer_manager_autobuild_packages']);
    $this->assertEquals(FALSE, $conf['admin_menu_cache_client']);

    // Testing.
    $this->assertEquals(FALSE, $conf['admin_menu_cache_client']);
  }

  /**
   * Test configuration for dev environment on ACE.
   */
  public function testDev() {

    $this->setupParams('dev');
    require $this->drupalRoot . '/sites/default/settings.php';

    // Assert cache.settings.php.
    $this->assertEquals('sites/all/modules/contrib/memcache/memcache.inc', $conf['cache_backends'][0]);
    $this->assertEquals('MemCacheDrupal', $conf['cache_default_class']);
    $this->assertEquals('DrupalDatabaseCache', $conf['cache_class_cache_form']);
    $this->assertEquals('includes/cache-install.inc', $conf['cache_backends'][1]);
    $this->assertEquals('DrupalFakeCache', $conf['cache_class_cache_page']);
    $this->assertEquals(FALSE, $conf['page_cache_invoke_hooks']);
    $this->assertEquals(TRUE, $conf['page_cache_without_database']);
    $this->assertEquals(TRUE, $conf['redirect_page_cache']);

    // Cron.
    $this->assertEquals(FALSE, $conf['acquia_spi_use_cron']);

    // Files.
    $this->assertEquals('sites/default/files', $conf['file_public_path']);
    $this->assertEquals('sites/all', $conf['composer_manager_file_dir']);
    $this->assertEquals('sites/all/vendor', $conf['composer_manager_vendor_dir']);
    $this->assertEquals(FALSE, $conf['composer_manager_autobuild_file']);
    $this->assertEquals(FALSE, $conf['composer_manager_autobuild_packages']);
    $this->assertEquals(FALSE, $conf['admin_menu_cache_client']);

    // Testing.
    $this->assertEquals(FALSE, $conf['admin_menu_cache_client']);
  }

}
