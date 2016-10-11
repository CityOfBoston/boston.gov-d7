<?php
/**
 * @file
 * Contains Xpath utility class.
 */

namespace Boston\Utility;

/**
 * Class Xpath utility class for helping with xpath manipulations.
 *
 * @package Boston\Utility
 */
class Xpath {
  /**
   * Escape quotes in an xpath string.
   *
   * @param string $string
   *   The xpath string to be escaped.
   *
   * @return string
   *   Return a community-accepted string format for quotes in a xpath string.
   */
  public static function escapeQuotes($string) {
    if (strpos($string, "'") === FALSE) {
      return "'$string'";
    }

    if (strpos($string, '"') === FALSE) {
      return "\"$string\"";
    }
    return "concat('" . strtr($string, array("'" => '\', "\'", \'')) . "')";
  }

}
