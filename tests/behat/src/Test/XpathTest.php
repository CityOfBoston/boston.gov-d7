<?php
/**
 * @file
 * Test Xpath utility class.
 */

namespace Boston\Test;

use Boston\Utility\Xpath;
use PHPUnit_Framework_TestCase;

/**
 * Class XpathTest used to test the Xpath utility class.
 *
 * @package Boston\Test
 */
class XpathTest extends PHPUnit_Framework_TestCase {
  /**
   * Test single quote escape.
   */
  public function testSingleQuoteEscape() {
    $expected = "\"Hell'o world!\"";
    $escaped = Xpath::escapeQuotes("Hell'o world!");
    $this->assertTrue($expected === $escaped);
  }

  /**
   * Test multiple single quotes escape.
   */
  public function testMultiSingleQuoteEscape() {
    $expected = "\"Hell'o w'orld!\"";
    $escaped = Xpath::escapeQuotes("Hell'o w'orld!");
    $this->assertTrue($expected === $escaped);
  }

  /**
   * Test double quote escape.
   */
  public function testDoubleQuoteEscape() {
    $expected = "'Hell\"o world!'";
    $escaped = Xpath::escapeQuotes("Hell\"o world!");
    $this->assertTrue($expected === $escaped);
  }

  /**
   * Test multiple double quotes escape.
   */
  public function testMultiDoubleQuoteEscape() {
    $expected = "'Hell\"o wo\"rld!'";
    $escaped = Xpath::escapeQuotes("Hell\"o wo\"rld!");
    $this->assertTrue($expected === $escaped);
  }

  /**
   * Test escaping a single quote only.
   */
  public function testSingleQuoteOnly() {
    $expected = "\"'\"";
    $escaped = Xpath::escapeQuotes("'");
    $this->assertTrue($expected === $escaped);
  }

  /**
   * Test escaping a double quote only.
   */
  public function testDoubleQuoteOnly() {
    $expected = "'\"'";
    $escaped = Xpath::escapeQuotes("\"");
    $this->assertTrue($expected === $escaped);
  }

  /**
   * Test escaping a single and a double quote.
   */
  public function testOneSingleOneDouble() {
    $expected = "concat('Hell', \"'\", 'o wo\"rld!')";
    $escaped = Xpath::escapeQuotes("Hell'o wo\"rld!");
    $this->assertTrue($expected === $escaped);
  }

}
