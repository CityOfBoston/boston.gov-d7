<?php

/**
 * @file
 * Test configuration in settings.php.
 *
 * Convention would be to create a battery of test functions and run those
 * sequentially and end when an unexpected response is found.
 * For the API CRUD testing we do not use that method because it is more
 * convenient for an endpoint test to define scenarios in an array and test
 * that array.
 */

namespace Drupal\phpunit;

use GuzzleHttp\Client;
use GuzzleHttp\Exception\GuzzleException;
use PHPUnit_Framework_TestCase;

/**
 * Class CityScoreTest: Tests cityscore API.
 *
 * @package Drupal
 */
class CityScoreTest extends PHPUnit_Framework_TestCase {

  /**
   * Define an array of tests.
   *
   * @var array
   */
  private $tests = [
    [
      "description" => "Tries to access endpoint that does not exist.",
      "type" => "get",
      "endpoint" => "/rest/cityscore/xx",
      "query" => [],
      "response-format" => "json_array",
      "response-code" => 500,
      "tests" => [],
    ],
    [
      "description" => "Loads 2 fields into cityscore -success",
      "type" => "post",
      "endpoint" => "/rest/cityscore/load",
      "body" => [
        "api-key" => "9juHD7Y8oZpN2-erChlUQQ",
        "payload" => '
          [
            {
              "metric_name" : "FIELD 1",
              "score_calculated_ts" : "2019-03-04T12:10:59Z",
              "score_final_table_ts" : "2019-03-04T17:11:01Z",
              "previous_day_score" : null,
              "previous_week_score" : null,
              "previous_month_score" : 1.990000,
              "previous_quarter_score" : 1.063380,
              "score_day_name" : "Monday"
            },
            {
              "metric_name" : "FIELD 2",
              "score_calculated_ts" : "2019-03-04T12:10:59Z",
              "score_final_table_ts" : "2019-03-04T17:11:01Z",
              "previous_day_score" : 1.289303,
              "previous_week_score" : 0.990884,
              "previous_month_score" : 0.945510,
              "previous_quarter_score" : 0.781862,
              "score_day_name" : "Monday"
            }
          ]',
      ],
      "response-format" => "json_array",
      "response-code" => 200,
      "tests" => [
        ["type" => "field", "name" => "status", "value" => "success"],
        ["type" => "field", "name" => "message", "value" => "cityscore updated"],
      ],
    ],
    [
      "description" => "Retrieves cityscore (json) - expect 1 field",
      "type" => "get",
      "endpoint" => "/rest/cityscore/json",
      "query" => [],
      "response-format" => "json_array",
      "response-code" => 200,
      "tests" => [
        ["type" => "field", "name" => "day", "value" => '1.29'],
        ["type" => "field", "name" => "week", "value" => '0.99'],
        ["type" => "field", "name" => "month", "value" => '1.47'],
        ["type" => "field", "name" => "quarter", "value" => '0.92'],
        ["type" => "field", "name" => "date_posted", "value" => "03/04/2019"],
      ],
    ],
    [
      "description" => "Retrieves cityscore (html) - expect 2 fields only",
      "type" => "get",
      "endpoint" => "/rest/cityscore/html",
      "query" => [],
      "response-format" => "html_markup",
      "response-code" => 200,
      "tests" => [
        ["type" => "string", "match" => "jQuery('table.views-table').append"],
        ["type" => "string", "match" => '<td class="cs__table--centered">-</td>'],
        ["type" => "string", "match" => "<td>FIELD 1</td>"],
        ["type" => "string", "match" => "<td>FIELD 2</td>"],
        ["type" => "string", "match" => "<td>FIELD 3</td>", "bool" => FALSE],
        ["type" => "string", "match" => '<td class="cs__table--centered">-</td>'],
        ["type" => "string", "match" => '<td class="cs__table--centered">1.99</td>'],
        ["type" => "string", "match" => '<td class="cs__table--centered">1.06</td>'],
        ["type" => "string", "match" => '<td class="cs__table--centered">1.29</td>'],
        ["type" => "string", "match" => '<td class="cs__low cs__table--centered">0.99</td>'],
        ["type" => "string", "match" => '<td class="cs__low cs__table--centered">0.95</td>'],
        ["type" => "string", "match" => '<td class="cs__low cs__table--centered">0.78</td>'],
      ],
    ],
    [
      "description" => "Retrieves cityscore (html) - expect 2 fields only",
      "type" => "get",
      "endpoint" => "/rest/cityscore/html-table",
      "query" => [],
      "response-format" => "html_markup",
      "response-code" => 200,
      "tests" => [
        ["type" => "string", "match" => "<head>"],
        ["type" => "string", "match" => '<meta property="og:url" content="http://127.0.0.1:8888/rest/cityscore/html-table" />'],
        ["type" => "preg", "match" => '/img.*b-dark.svg.*City of Boston/'],
        ["type" => "string", "match" => '<td class="cs__table--centered">-</td>'],
        ["type" => "string", "match" => "<td>FIELD 1</td>"],
        ["type" => "string", "match" => "<td>FIELD 3</td>", "bool" => FALSE],
        ["type" => "string", "match" => '<td class="cs__table--centered">-</td>'],
        ["type" => "string", "match" => '<td class="cs__table--centered">1.99</td>'],
        ["type" => "string", "match" => '<td class="cs__table--centered">1.06</td>'],
        ["type" => "string", "match" => '<td class="cs__table--centered">1.29</td>'],
        ["type" => "string", "match" => '<td class="cs__low cs__table--centered">0.99</td>'],
        ["type" => "string", "match" => '<td class="cs__low cs__table--centered">0.95</td>'],
        ["type" => "string", "match" => '<td class="cs__low cs__table--centered">0.78</td>'],
      ],
    ],
    [
      "description" => "Loads 3 fields into cityscore - success",
      "type" => "post",
      "endpoint" => "/rest/cityscore/load",
      "body" => [
        "api-key" => "9juHD7Y8oZpN2-erChlUQQ",
        "payload" => '
          [
            {
              "metric_name" : "FIELD 1",
              "score_calculated_ts" : "2019-03-05T12:10:59Z",
              "score_final_table_ts" : "2019-03-05T17:11:01Z",
              "previous_day_score" : 0.22,
              "previous_week_score" : 0.33,
              "previous_month_score" : 3.990000,
              "previous_quarter_score" : 1.163380,
              "score_day_name" : "Tuesday"
            },
            {
              "metric_name" : "FIELD 2",
              "score_calculated_ts" : "2019-03-05T12:10:59Z",
              "score_final_table_ts" : "2019-03-05T17:11:01Z",
              "previous_day_score" : 1.289303,
              "previous_week_score" : 0.990884,
              "previous_month_score" : 0.945510,
              "previous_quarter_score" : 0.781862,
              "score_day_name" : "Tuesday"
            },
            {
              "metric_name" : "FIELD 3",
              "score_calculated_ts" : "2019-03-05T12:10:59Z",
              "score_final_table_ts" : "2019-03-05T17:11:01Z",
              "previous_day_score" : 0.11,
              "previous_week_score" : 0.22,
              "previous_month_score" : 0.33333,
              "previous_quarter_score" : 0.4444,
              "score_day_name" : "Tuesday"
            }
          ]',
      ],
      "response-format" => "json_array",
      "response-code" => 200,
      "tests" => [
        ["type" => "field", "name" => "status", "value" => "success"],
        ["type" => "field", "name" => "message", "value" => "cityscore updated"],
      ],
    ],
    [
      "description" => "Retrieves cityscore (json) - expect 3 fields",
      "type" => "get",
      "endpoint" => "/rest/cityscore/json",
      "query" => [],
      "response-format" => "json_array",
      "response-code" => 200,
      "tests" => [
        ["type" => "field", "name" => "day", "value" => '0.54'],
        ["type" => "field", "name" => "week", "value" => '0.51'],
        ["type" => "field", "name" => "month", "value" => '1.76'],
        ["type" => "field", "name" => "quarter", "value" => '0.8'],
        ["type" => "field", "name" => "date_posted", "value" => "03/05/2019"],
      ],
    ],
    [
      "description" => "Retrieves cityscore (html) - expect 3 fields",
      "type" => "get",
      "endpoint" => "/rest/cityscore/html",
      "query" => [],
      "response-format" => "html_markup",
      "response-code" => 200,
      "tests" => [
        ["type" => "string", "match" => "jQuery('table.views-table').append"],
        ["type" => "string", "match" => "<td>FIELD 1</td>"],
        ["type" => "string", "match" => "<td>FIELD 2</td>"],
        ["type" => "string", "match" => "<td>FIELD 3</td>"],
        [
          "type" => "string",
          "match" => '<td class="cs__table--centered">-</td>',
          "bool" => FALSE,
        ],
        [
          "type" => "string",
          "match" => '<td class="cs__low cs__table--centered">0.22</td>',
        ],
        [
          "type" => "string",
          "match" => '<td class="cs__low cs__table--centered">0.33</td>',
        ],
        [
          "type" => "string",
          "match" => '<td class="cs__table--centered">3.99</td>',
        ],
        [
          "type" => "string",
          "match" => '<td class="cs__table--centered">1.16</td>',
        ],
        [
          "type" => "string",
          "match" => '<td class="cs__table--centered">1.29</td>',
        ],
        [
          "type" => "string",
          "match" => '<td class="cs__low cs__table--centered">0.99</td>',
        ],
        [
          "type" => "string",
          "match" => '<td class="cs__low cs__table--centered">0.11</td>',
        ],
        [
          "type" => "string",
          "match" => '<td class="cs__low cs__table--centered">0.44</td>',
        ],
      ],
    ],
    [
      "description" => "Loads 2 fields into cityscore -success",
      "type" => "post",
      "endpoint" => "/rest/cityscore/load",
      "body" => [
        "api-key" => "9juHD7Y8oZpN2-erChlUQQ",
        "payload" => '
          [
            {
              "metric_name" : "FIELD 1",
              "score_calculated_ts" : "2019-03-06T12:10:59Z",
              "score_final_table_ts" : "2019-03-06T17:11:01Z",
              "previous_day_score" : null,
              "previous_week_score" : null,
              "previous_month_score" : 1.990000,
              "previous_quarter_score" : 1.063380,
              "score_day_name" : "Wednesday"
            },
            {
              "metric_name" : "FIELD 4",
              "score_calculated_ts" : "2019-03-06T12:10:59Z",
              "score_final_table_ts" : "2019-03-06T17:11:01Z",
              "previous_day_score" : 1.289303,
              "previous_week_score" : 0.990884,
              "previous_month_score" : 0.945510,
              "previous_quarter_score" : 0.781862,
              "score_day_name" : "Wednesday"
            }
          ]',
      ],
      "response-format" => "json_array",
      "response-code" => 200,
      "tests" => [
        ["type" => "field", "name" => "status", "value" => "success"],
        ["type" => "field", "name" => "message", "value" => "cityscore updated"],
      ],
    ],
    [
      "description" => "Retrieves cityscore (json) - expect 2 fields",
      "type" => "get",
      "endpoint" => "/rest/cityscore/json",
      "query" => [],
      "response-format" => "json_array",
      "response-code" => 200,
      "tests" => [
        ["type" => "field", "name" => "day", "value" => '1.29'],
        ["type" => "field", "name" => "week", "value" => '0.99'],
        ["type" => "field", "name" => "month", "value" => '1.47'],
        ["type" => "field", "name" => "quarter", "value" => '0.92'],
        ["type" => "field", "name" => "date_posted", "value" => "03/06/2019"],
      ],
    ],
    [
      "description" => "Retrieves cityscore (html) - expect 3 fields",
      "type" => "get",
      "endpoint" => "/rest/cityscore/html",
      "query" => [],
      "response-format" => "html_markup",
      "response-code" => 200,
      "tests" => [
        ["type" => "string", "match" => "jQuery('table.views-table').append"],
        ["type" => "string", "match" => "<td>FIELD 1</td>"],
        ["type" => "string", "match" => "<td>FIELD 2</td>", "bool" => FALSE],
        ["type" => "string", "match" => "<td>FIELD 4</td>"],
        ["type" => "string", "match" => '<td class="cs__table--centered">-</td>'],
        ["type" => "string", "match" => '<td class="cs__table--centered">1.99</td>'],
        ["type" => "string", "match" => '<td class="cs__table--centered">1.06</td>'],
        ["type" => "string", "match" => '<td class="cs__table--centered">1.29</td>'],
        ["type" => "string", "match" => '<td class="cs__low cs__table--centered">0.99</td>'],
      ],
    ],
    [
      "description" => "Tests post error - no API key",
      "type" => "post",
      "endpoint" => "/rest/cityscore/load",
      "body" => [
        "payload" => '
          [
            {
              "metric_name" : "FIELD 1",
              "score_calculated_ts" : "2019-11-28T12:10:59Z",
              "score_final_table_ts" : "2019-11-28T17:11:01Z",
              "previous_day_score" : null,
              "previous_week_score" : null,
              "previous_month_score" : 5.990000,
              "previous_quarter_score" : 1.063380,
              "score_day_name" : "Tuesday"
            },
            {
              "metric_name" : "FIELD 2",
              "score_calculated_ts" : "2019-11-28T12:10:59Z",
              "score_final_table_ts" : "2019-11-28T17:11:01Z",
              "previous_day_score" : null,
              "previous_week_score" : null,
              "previous_month_score" : 5.990000,
              "previous_quarter_score" : 1.063380,
              "score_day_name" : "Tuesday"
            }
          ]',
      ],
      "response-format" => "json_array",
      "response-code" => 200,
      "tests" => [
        ["type" => "field", "name" => "status", "value" => "error"],
        [
          "type" => "field",
          "name" => "message",
          "value" => "error missing token",
        ],
      ],
    ],
    [
      "description" => "Tests post error - bad API key",
      "type" => "post",
      "endpoint" => "/rest/cityscore/load",
      "body" => [
        "api-key" => "123",
        "payload" => '
          [
            {
              "metric_name" : "FIELD 1",
              "score_calculated_ts" : "2019-11-28T12:10:59Z",
              "score_final_table_ts" : "2019-11-28T17:11:01Z",
              "previous_day_score" : null,
              "previous_week_score" : null,
              "previous_month_score" : 5.990000,
              "previous_quarter_score" : 1.063380,
              "score_day_name" : "Tuesday"
            },
            {
              "metric_name" : "FIELD 2",
              "score_calculated_ts" : "2019-11-28T12:10:59Z",
              "score_final_table_ts" : "2019-11-28T17:11:01Z",
              "previous_day_score" : null,
              "previous_week_score" : null,
              "previous_month_score" : 5.990000,
              "previous_quarter_score" : 1.063380,
              "score_day_name" : "Tuesday"
            }
          ]',
      ],
      "response-format" => "json_array",
      "response-code" => 200,
      "tests" => [
        ["type" => "field", "name" => "status", "value" => "error"],
        [
          "type" => "field",
          "name" => "message",
          "value" => "error missing token",
        ],
      ],
    ],
    [
      "description" => "Tests post error - no payload",
      "type" => "post",
      "endpoint" => "/rest/cityscore/load",
      "body" => [
        "api-key" => "9juHD7Y8oZpN2-erChlUQQ",
        "payload" => '',
      ],
      "response-format" => "json_array",
      "response-code" => 200,
      "tests" => [
        ["type" => "field", "name" => "status", "value" => "error"],
        ["type" => "field", "name" => "message", "value" => "error no payload"],
      ],
    ],
    [
      "description" => "Tests post error - bad JSON (metric_name delimiter)",
      "type" => "post",
      "endpoint" => "/rest/cityscore/load",
      "body" => [
        "api-key" => "9juHD7Y8oZpN2-erChlUQQ",
        "payload" => '
          [
            {
              "metric_name" ; "FIELD 1",
              "score_calculated_ts" : "2019-11-28T12:10:59Z",
              "score_final_table_ts" : "2019-11-28T17:11:01Z",
              "previous_day_score" : null,
              "previous_week_score" : null,
              "previous_month_score" : 5.990000,
              "previous_quarter_score" : 1.063380,
              "score_day_name" : "Tuesday"
            }
          ]',
      ],
      "response-format" => "json_array",
      "response-code" => 200,
      "tests" => [
        [
          "type" => "field",
          "name" => "status",
          "value" => "error",
        ],
        [
          "type" => "field",
          "name" => "message",
          "value" => "bad json in payload",
        ],
      ],
    ],
  ];

  /**
   * Used to track the drupal root.
   *
   * @var string
   */
  private $host = "http://127.0.0.1";

  /**
   * Used to trap test errors.
   *
   * @var array
   */
  private $failed = [];

  /**
   * Main test function to test the $tests array.
   */
  public function testEndpoint() {

    // Iterate through the test array and run tests.
    foreach ($this->tests as $key => $test) {
      if ($test["type"] == "post") {
        $this->postEndpoints($key, $test);
      }
      if ($test["type"] == "get") {
        $this->getEndpoints($key, $test);
      }
    }

    // Check for failed tests.
    $err_string = "";
    foreach ($this->failed as $fail_reason) {
      $err_string .= $fail_reason . "\n";
    }
    $this->assertEmpty($err_string, $err_string);

  }

  /**
   * Check the settings provided by the cityscore module.
   */
  public function testSettings() {
    // Bootstrap Drupal to get the configuration.
    require_once __DIR__ . "/DrupalBootstrap.php";
    $drupal = new COBDrupalBootstrap();
    $drupal->bootstrapDrupal("/boston.gov/docroot");

    // Run tests.
    echo module_exists("bos_rest");
    $this->assertNotEmpty(variable_get('cityscore_token'), "Missing setting: cityscore_token.");
  }

  /**
   * POST data from an endpoint and test response.
   *
   * @param int $seq
   *   The test number for reporting.
   * @param array $test
   *   The test to execute.
   *
   * @return bool
   *   True if test passed, false if not.
   */
  public function postEndpoints($seq, array $test) {
    if (!class_exists("GuzzleHttp\Client")) {
      $this->recordFail($seq, "Require Guzzle to be installed (via composer).");
      return FALSE;
    }
    // Make POST to endpoint.
    $endpoint = $this->host . $test["endpoint"];
    try {
      $client = new Client(["headers" => ["Cache-Control" => "no-cache"]]);
      $response = $client->request("POST", $endpoint, [
        'form_params' => $test["body"],
      ]);

      // Check response.
      if ($response->getStatusCode() != $test["response-code"]) {
        $this->recordFail($seq, "Server returned code " . $response->getStatusCode() . " but expected " . $test["response-code"] . ".");
        return FALSE;
      }
    }
    catch (GuzzleException $e) {
      if ($e->getCode() != $test["response-code"]) {
        $this->recordFail($seq, "Expected Code: " . $test["response-code"] . " but returned " . $e->getCode());
        return FALSE;
      }
    }

    // Do tests.
    if ($test["response-format"] == "json_array") {
      // First decode the JSON into an array.
      if (!$response = json_decode($response->getBody())) {
        $this->recordFail($seq, "JSON not returned from " . $endpoint . ".");
        return FALSE;
      }
      // Run tests on JSON response (if any).
      foreach ($test['tests'] as $test_item) {
        if ($test_item["type"] == "field") {
          if ($response->{$test_item["name"]} != $test_item["value"]) {
            $this->recordFail($seq, "Unexpected response for " . $test_item["name"] . ": expected '" . $test_item["value"] . "' got '" . $response->{$test_item["name"]} . "'.");
            return FALSE;
          }
        }
      }
    }
    return TRUE;
  }

  /**
   * GET data from an endpoint and test data provided in response.
   *
   * @param int $seq
   *   The test number for reporting.
   * @param array $test
   *   The test to execute.
   *
   * @return bool
   *   True if test passed, false if not.
   */
  public function getEndpoints($seq, array $test) {
    if (!class_exists("GuzzleHttp\Client")) {
      $this->recordFail($seq, "Require Guzzle to be installed (via composer).");
      return FALSE;
    }
    // GET endpoint.
    $endpoint = $this->host . $test["endpoint"];
    try {
      $client = new Client(["headers" => ["Cache-Control" => "no-cache"]]);
      $query = (isset($test["query"]) ? $test["query"] : []);
      $response = $client->request("GET", $endpoint, $query);

      // Check response.
      if (NULL !== $response && $response->getStatusCode() != $test["response-code"]) {
        $this->recordFail($seq, "Server returned code " . $response->getStatusCode() . " but expected " . $test["response-code"] . ".");
        return FALSE;
      }
    }
    catch (GuzzleException $e) {
      if ($e->getCode() != $test["response-code"]) {
        $this->recordFail($seq, "Expected Code: " . $test["response-code"] . " but returned " . $e->getCode());
        return FALSE;
      }
      $response = NULL;
    }

    if (
      (NULL === $response || empty($response->getBody()))
      && !empty($test['tests'])) {
      $this->recordFail($seq, "No data returned from " . $endpoint . ".");
      return FALSE;
    }

    // Do tests.
    if (!empty($test['tests']) && $test["response-format"] == "json_array") {
      // First decode the JSON into an array.
      if (!$response = json_decode($response->getBody())) {
        $this->recordFail($seq, "JSON not returned from " . $endpoint . ".");
        return FALSE;
      }
      // Run tests on JSON response (if any).
      foreach ($test['tests'] as $test_item) {
        if ($test_item["type"] == "field") {
          if ($response->{$test_item["name"]} != $test_item["value"]) {
            $this->recordFail($seq, "Unexpected response for " . $test_item["name"] . ": expected '" . $test_item["value"] . "' got '" . $response->{$test_item["name"]} . "'.");
            return FALSE;
          }
        }
      }
    }

    elseif (!empty($test['tests']) && $test["response-format"] == "html_markup") {
      // Run tests on HTML response (if any).
      foreach ($test['tests'] as $type => $test_item) {
        if (!isset($test_item["bool"])) {
          $test_item["bool"] = TRUE;
        }
        switch ($test_item["type"]) {
          case "string":
            if (!$test_item["bool"] && stripos($response->getBody(), $test_item["match"]) !== FALSE) {
              $this->recordFail($seq, "Found unexpected HTML string '" . $test_item["match"] . "'.");
              return FALSE;
            }
            elseif ($test_item["bool"] && stripos($response->getBody(), $test_item["match"]) === FALSE) {
              $this->recordFail($seq, "Did not find expected HTML string '" . $test_item["match"] . "'.");
              return FALSE;
            }
            break;

          case "preg":
            if (preg_match($test_item["match"], $response->getBody()) === $test_item['bool']) {
              $this->recordFail($seq, "Did not find expected HTML pattern '" . $test_item["match"] . "'.");
              return FALSE;
            }
            break;
        }
      }
    }
    return TRUE;
  }

  /**
   * Format a fail message for reporting.
   *
   * @param int $seq
   *   The test number for reporting.
   * @param string $fail_reason
   *   The reason the test failed..
   *
   * @return bool
   *   Always true.
   */
  private function recordFail($seq, $fail_reason) {
    $this->failed[] = "Test " . $seq . ": " . $fail_reason;
    return TRUE;
  }

}
