<?php
/**
 * @file
 * JsonSource.
 */

namespace Drupal\hub_migration;

/**
 * Class JsonSource.
 *
 * @package Drupal\hub_migration
 */
class JsonSource extends \MigrateSourceJSON {
  /**
   * Getter.
   */
  public function getReader() {
    return $this->reader;
  }

  /**
   * Getter.
   */
  public function getSourceUrls() {
    return $this->sourceUrls;
  }

  /**
   * Setter.
   */
  public function setSourceUrls($urls) {
    $this->sourceUrls = $urls;
  }

}
