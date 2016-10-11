<?php
/**
 * @file
 * Contains SpinTrait trait.
 */

namespace Boston\Utility;

/**
 * Class SpinTrait.
 *
 * @package Boston\Contexts
 */
trait SpinTrait {

  /**
   * Spin function used to make Behat wait for the web application to catch up.
   *
   * @param object $lambda
   *   Lambda function execute. Must return either TRUE or FALSE.
   * @param int $max_tries
   *   The number of attempts to be made before failing.
   * @param int $seconds
   *   The number of seconds per attempt.
   *
   * @return bool
   *   Whether or not the spin was successful.
   */
  public function spin($lambda, $max_tries = 10, $seconds = 1) {
    $current_attempt = 1;
    while ($current_attempt++ <= $max_tries) {
      try {
        /** @var \Closure $lambda */
        if ($lambda($this)) {
          return TRUE;
        }
      }
      catch (\Exception $e) {
        // Do nothing.
      }
      sleep($seconds);
    }
    return FALSE;
  }

}
