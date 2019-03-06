<?php

/**
 * @file
 * Test configuration in settings.php.
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

  private $tests = [
    0 => [
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
    1 => [
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
    2 => [
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
//        ["type" => "preg", "match" => "/.*/"],
      ],
    ],
    3 => [
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
    4 => [
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
    5 => [
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
    6 => [
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
        ["type" => "string", "match" => '<td class="cs__table--centered">-</td>', "bool" => FALSE],
        ["type" => "string", "match" => '<td class="cs__low cs__table--centered">0.22</td>'],
        ["type" => "string", "match" => '<td class="cs__low cs__table--centered">0.33</td>'],
        ["type" => "string", "match" => '<td class="cs__table--centered">3.99</td>'],
        ["type" => "string", "match" => '<td class="cs__table--centered">1.16</td>'],
        ["type" => "string", "match" => '<td class="cs__table--centered">1.29</td>'],
        ["type" => "string", "match" => '<td class="cs__low cs__table--centered">0.99</td>'],
        ["type" => "string", "match" => '<td class="cs__low cs__table--centered">0.11</td>'],
        ["type" => "string", "match" => '<td class="cs__low cs__table--centered">0.44</td>'],
        //        ["type" => "preg", "match" => "/.*/"],
      ],
    ],
    7 => [
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
    8 => [
      "description" => "Retrieves cityscore (json) - expect 3 fields",
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
    9 => [
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
        ["type" => "field", "name" => "message", "value" => "error missing token"],
      ],
    ],
    10 => [
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
        ["type" => "field", "name" => "message", "value" => "error missing token"],
      ],
    ],
    11 => [
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
    12 => [
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
        ["type" => "field", "name" => "status", "value" => "error"],
        ["type" => "field", "name" => "message", "value" => "bad json in payload"],
      ],
    ],
  ];

  /**
   * @var string
   *   Used to track the drupal root.
   */
  private $host = "http://127.0.0.1";

  /**
   * @var array
   *   Used to trap test errors.
   */
  private $errors = [];

  /**
   * @Inheritdoc
   */
  public function __construct(string $name = NULL, array $data = [], string $dataName = '', $host = null) {
    parent::__construct($name, $data, $dataName);
    if (isset($host)) {
      $this->host = $host;
    }
  }

  /**
   * @param $host
   *   Sets/gets the host variable.
   *
   * @return string
   *   The classes current host value.
   */
  public function host($host = null) {
    if (isset($host)) {
      $this->host = $host;
    }
    return $this->host;
  }

  public function test() {

//    require_once __DIR__ . "/../../vendor/autoload.php";

    // Check the settings which should exist in Drupal.
//    $this->checkSettings();

    foreach ($this->tests as $key => $test) {
      if ($test["type"] == "post") {
        $this->postEndpoints($key, $test);
      }
      if ($test["type"] == "get") {
        $this->getEndpoints($key, $test);
      }
    }

    if (!empty($this->errors)) {
      $errString = "";
      foreach ($this->errors as $error) {
        $errString .= $error . "\n";
      }
      $this->fail($errString);
    }

  }

  /**
   * Check the settings provided by the cityscore module.
   */
  protected function checkSettings() {
    // Bootstrap Drupal to get the configuration.
    require_once __DIR__ . "/DrupalBootstrap.php";
    $drupal = new COBDrupalBootstrap();
    $drupal->bootstrapDrupal("/boston.gov/docroot");

    // Run tests.
    $this->assertNotEmpty(variable_get('cityscore_token'), "Missing setting: cityscore_token.");
  }

  /**
 * Run a POST test.
 *
 * @param int $seq
 *   The test number for reporting.
 * @param array $test
 *   The test to execute.
 *
 * @return bool
 *   True if test passed, false if not.
 */
  public function postEndpoints(int $seq, array $test) {
    if (!class_exists("GuzzleHttp\Client")) {
      $this->errors[] = "Test " . $seq . ": Require Guzzle to be installed (via composer).";
      return FALSE;
    }
    // Make POST to endpoint.
    $endpoint =  $this->host . $test["endpoint"];
    try {
      $client = new Client(["headers" => ["Cache-Control" => "no-cache"]]);
      $response = $client->request("POST", $endpoint, [
        'form_params' => $test["body"],
      ]);

      // Check response.
      if ($response->getStatusCode() != $test["response-code"]) {
        $this->errors[] = "Test " . $seq . ": Server returned code " . $response->getStatusCode() . " but expected " . $test["response-code"] . ".";
        return FALSE;
      }
    }
    catch (GuzzleException $e) {
      $this->errors[] = "Test " . $seq . ": Error trapped " . $e->getMessage();
      return FALSE;
    }

    // Do tests.
    if ($test["response-format"] == "json_array") {
      // First decode the JSON into an array.
      if (!$response = json_decode($response->getBody())) {
        $this->errors[] =  "Test " . $seq . ": json not returned from " . $endpoint . ".";
        return FALSE;
      }
      // Run tests on JSON response (if any).
      foreach ($test['tests'] as $testItem) {
        if ($testItem["type"] == "field") {
          if ($response->{$testItem["name"]} != $testItem["value"]) {
            $this->errors[] = "Test " . $seq . ": Unexpected response for " . $testItem["name"] . ": expected '" . $testItem["value"] . "' got '" . $response->{$testItem["name"]} . "'.";
            return FALSE;
          }
        }
      }
    }
    return TRUE;
  }

/**
 * @param array $test
 */
  public function getEndpoints(int $seq, array $test) {
    if (!class_exists("GuzzleHttp\Client")) {
      $this->errors[] = "Test " . $seq . ": Require Guzzle to be installed (via composer).";
      return FALSE;
    }
    // Make POST to endpoint.
    $endpoint = $this->host . $test["endpoint"];
    try {
      $client = new Client(["headers" => ["Cache-Control" => "no-cache"]]);
      $response = $client->request("GET", $endpoint, [
        'query' => $test["query"],
      ]);

      // Check response.
      if ($response->getStatusCode() != $test["response-code"]) {
        $this->errors[] = "Test " . $seq . ": Server returned code " . $response->getStatusCode() . " but expected " . $test["response-code"] . ".";
        return FALSE;
      }
    }
    catch (GuzzleException $e) {
      $this->errors[] = "Test " . $seq . ": Error trapped " . $e->getMessage();
      return FALSE;
    }

    // Do tests.
    if ($test["response-format"] == "json_array") {
      // First decode the JSON into an array.
      if (!$response = json_decode($response->getBody())) {
        $this->errors[] = "Test " . $seq . ": json not returned from " . $endpoint . ".";
        return FALSE;
      }
      // Run tests on JSON response (if any).
      foreach ($test['tests'] as $testItem) {
        if ($testItem["type"] == "field") {
          if ($response->{$testItem["name"]} != $testItem["value"]) {
            $this->errors[] = "Test " . $seq . ": Unexpected response for " . $testItem["name"] . ": expected '" . $testItem["value"] . "' got '" . $response->{$testItem["name"]} . "'.";
            return FALSE;
          }
        }
      }
    }

    elseif ($test["response-format"] == "html_markup") {
      // Run tests on HTML response (if any).
      foreach ($test['tests'] as $type => $testItem) {
        if (!isset($testItem["bool"])) {
          $testItem["bool"] = TRUE;
        }
        switch ($testItem["type"]) {
          case "string":
            if (!$testItem["bool"] && stripos($response->getBody(), $testItem["match"]) !== FALSE) {
              $this->errors[] = "Test " . $seq . ": Found unexpected HTML string '" . $testItem["match"] . "'.";
              return FALSE;
            }
            elseif ($testItem["bool"] && stripos($response->getBody(), $testItem["match"]) === FALSE) {
              $this->errors[] = "Test " . $seq . ": Did not find expected HTML string '" . $testItem["match"] . "'.";
              return FALSE;
            }
            break;

          case "preg":
            if (preg_match($testItem["match"], $response->getBody()) === $testItem['bool']) {
              $this->errors[] = "Test " . $seq . ": Did not find expected HTML pattern '" . $testItem["match"] . "'.";
              return FALSE;
            }
            break;
        }
      }
    }
    return TRUE;
  }
}
