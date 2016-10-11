<?php

/**
 * @file
 * Custom Behat Step definitions.
 */

namespace Boston\Contexts;

use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Testwork\Hook\Scope\BeforeSuiteScope;
use Behat\Behat\Hook\Scope\BeforeStepScope;
use Behat\Behat\Hook\Scope\AfterStepScope;
use Behat\Behat\Hook\Scope\BeforeScenarioScope;
use Behat\Behat\Context\SnippetAcceptingContext;
use Behat\Gherkin\Node\TableNode;
use Symfony\Component\Config\Definition\Exception\Exception;

/**
 * Context for adding generic steps available to test suites.
 *
 * @package Boston\Contexts
 */
class FeatureContext extends RawDrupalContext implements SnippetAcceptingContext {

  /**
   * Store context parameters specified in configuration file.
   */
  private $parameters;

  /**
   * Store command line output.
   *
   * @var $output
   *   Command line output.
   */
  protected $output;

  /**
   * Store original window name.
   *
   * @var string
   *   Original Window Name.
   */
  public $originalWindowName = '';

  /**
   * Last user to log in.
   *
   * @var object
   *   Loaded user object.
   */
  public $user;

  /**
   * List of used migrations that we want to clean up.
   *
   * @var array
   */
  private $migrations = array();

  /**
   * Constructor.
   */
  public function __construct(array $parameters = array()) {
    $this->parameters = $parameters;
  }

  /**
   * Truncate the watchdog table so we can check for errors later.
   *
   * @BeforeSuite
   */
  public static function prepare(BeforeSuiteScope $scope) {

    db_truncate('watchdog')->execute();
  }

  /**
   * Returns the current, relative path.
   *
   * Simply using Drupal's current_path() or $_GET['q'] does not work.
   *
   * @return string
   *   The current path.
   */
  public function getCurrentPath() {

    $url = $this->getSession()->getCurrentUrl();
    $parsed_url = parse_url($url);
    $path = trim($parsed_url['path'], '/');
    return $path;
  }

  /**
   * Returns node currently being viewed. Assumes /node/[nid] URL.
   *
   * Using path-based loaders, like menu_load_object(), will not work.
   *
   * @return object
   *   The currently viewed node.
   *
   * @throws \Exception
   *   Thrown if node could not be loaded from URL.
   */
  public function getNodeFromUrl() {

    $path = $this->getCurrentPath();
    $system_path = drupal_lookup_path('source', $path);
    if (!$system_path) {
      $system_path = $path;
    }
    $menu_item = menu_get_item($system_path);
    if ($menu_item['path'] == 'node/%') {
      $node = node_load($menu_item['original_map'][1]);
    }
    else {
      throw new \Exception(sprintf("Node could not be loaded from URL '%s'", $path));
    }
    return $node;
  }

  /**
   * Returns the most recently created node.
   *
   * @return object
   *   The most recently created node.
   */
  public function getLastCreatedNode() {

    $node = end($this->nodes);
    return $node;
  }

  /**
   * Take a screenshot.
   *
   * @Given I take a screenshot
   */
  public function takeScrenshot() {
    $this->saveScreenshot(NULL, $this->parameters['environment']['screenshot_dir']);
  }

  /**
   * Region should not be on the page.
   *
   * @Then /^I should not see the "([^"]*)" region$/
   */
  public function iShouldNotSeeTheRegion($region) {

    $session = $this->getSession();
    $region_obj = $session->getPage()->find('region', $region);
    if ($region_obj) {
      throw new \Exception(
        sprintf('The region "%s" was found on the page %s.', $region, $session->getCurrentUrl())
      );
    }
    return $region_obj;
  }

  /**
   * The CSS selector should be on the current page.
   *
   * @Then /^I should see the css selector "([^"]*)"$/
   * @Then /^I should see the CSS selector "([^"]*)"$/
   */
  public function iShouldSeeTheCssSelector($css_selector) {

    $element = $this->getSession()->getPage()->find("css", $css_selector);
    if (empty($element)) {
      throw new \Exception(sprintf("The page '%s' does not contain the css selector '%s'", $this->getSession()
        ->getCurrentUrl(), $css_selector));
    }
  }

  /**
   * The CSS selector should not be on the current page.
   *
   * @Then /^I should not see the css selector "([^"]*)"$/
   * @Then /^I should not see the CSS selector "([^"]*)"$/
   */
  public function iShouldNotSeeTheCssSelector($css_selector) {

    $element = $this->getSession()->getPage()->find("css", $css_selector);
    if (empty($element)) {
      throw new \Exception(sprintf("The page '%s' contains the css selector '%s'", $this->getSession()
        ->getCurrentUrl(), $css_selector));
    }
  }

  /**
   * Click an element with a given CSS selector.
   *
   * @When /^(?:|I )click the element with CSS selector "([^"]*)"$/
   * @When /^(?:|I )click the element with css selector "([^"]*)"$/
   */
  public function iClickTheElementWithCssSelector($css_selector) {

    $element = $this->getSession()->getPage()->find("css", $css_selector);
    if (empty($element)) {
      throw new \Exception(sprintf("The page '%s' does not contain the css selector '%s'", $this->getSession()
        ->getCurrentUrl(), $css_selector));
    }
    $element->click();
  }

  /**
   * The current page is loaded with a specific theme.
   *
   * @Given /^I am viewing the "([^"]*)" theme$/
   */
  public function iAmViewingTheTheme($expected_theme) {

    global $theme;
    if ($theme !== $expected_theme) {
      throw new \Exception(
        sprintf("'%s' is not the active theme. '%s' is active instead.", $expected_theme, $theme)
      );
    }
  }

  /**
   * The select element contains a specific option.
   *
   * @Then /^I should see a select element named "([^"]*)" containing "([^"]*)"
   *   as an option$/
   */
  public function iShouldSeeSelectElementNamedContainingAsAnOption($select, $option_value) {

    $select_element = $this->getSession()
      ->getPage()
      ->find('named', array('select', "\"{$select}\""));
    if (!$select_element) {
      throw new \Exception(sprintf("Did not find a <select> element '%s'.", $select));
    }
    $option_element = $select_element->find('named', array(
      'option',
      "\"{$option_value}\"",
    ));
    if (!$option_element) {
      throw new \Exception(
        sprintf("Did not find a <select> element '%s' with <option> '%s'.", $select, $option_value)
      );
    }
  }

  /**
   * The select element does not contain a specific option.
   *
   * @Given /^I should see a select element named "([^"]*)" that does not
   *   contain "([^"]*)" as an option$/
   */
  public function iShouldSeeSelectElementNamedThatDoesNotContainAsAnOption($select, $option_value) {

    $select_element = $this->getSession()
      ->getPage()
      ->find('named', array('select', "\"{$select}\""));
    if (!$select_element) {
      throw new \Exception(sprintf("Did not find a <select> element '%s'.", $select));
    }
    $option_element = $select_element->find('named', array(
      'option',
      "\"{$option_value}\"",
    ));
    if ($option_element) {
      throw new \Exception(sprintf("Found <select> element '%s' with <option> '%s'.", $select, $option_value));
    }
  }

  /**
   * Clear a specific cache bin.
   *
   * @Given /^the "([^"]*)" cache bin has been cleared$/
   */
  public function theCacheBinHasBeenCleared($bin) {

    if ($bin == 'css' || $bin == 'js') {
      _drupal_flush_css_js();
      drupal_clear_css_cache();
      drupal_clear_js_cache();
    }
    elseif ($bin == 'block') {
      cache_clear_all(NULL, 'cache_block');
    }
    elseif ($bin == 'theme') {
      cache_clear_all('theme_registry', 'cache', TRUE);
    }
    else {
      cache_clear_all(NULL, $bin);
    }
  }

  /**
   * Fills in WYSIWYG editor with specified id.
   *
   * @Given I fill in :text in WYSIWYG editor :for
   */
  public function iFillInInWysiwygEditor($text, $for) {
    $iframe_id = $for . "-iframe";
    try {
      $this->getSession()
        ->executeScript("jQuery('label[for=\"$for\"]').parent().find('iframe').attr('id', '$iframe_id');");
      $this->getSession()->switchToIFrame($iframe_id);
    }
    catch (\Exception $e) {
      throw new \Exception(sprintf("No iframe '%s' found on the page '%s'.", $iframe_id, $this->getSession()
        ->getCurrentUrl()));
    }
    $this->getSession()
      ->executeScript("document.body.innerHTML = '<p>" . $text . "</p>'");
    $this->getSession()->switchToIFrame();
  }

  /**
   * Select an option from a field.
   *
   * @When /^I select the following <fields> with <values>$/
   */
  public function iSelectTheFollowingFieldsWithValues(TableNode $table) {

    $multiple = TRUE;
    $table = $table->getHash();
    foreach ($table as $key => $value) {
      $select = $this->getSession()
        ->getPage()
        ->findField($table[$key]['fields']);
      if (empty($select)) {
        throw new \Exception(
          "The page does not have the field with id|name|label|value '" . $table[$key]['fields'] . "'"
        );
      }
      // If multiple is always TRUE we get "value cannot be an array" error for
      // single select fields.
      $multiple = $select->getAttribute('multiple') ? TRUE : FALSE;
      $this->getSession()
        ->getPage()
        ->selectFieldOption($table[$key]['fields'], $table[$key]['values'], $multiple);
    }
  }

  /**
   * Sleep for a specified number of seconds.
   *
   * @Given /^I wait (\d+) seconds$/
   */
  public function iWaitSeconds($seconds) {

    sleep($seconds);
  }

  /**
   * Determines whether the current browser is Internet Explorer.
   *
   * @return int
   *   If the browser is IE, the IE version will be returned. Otherwise, -1.
   */
  public function getIeVersion() {

    $ie_version = $this->getSession()->evaluateScript('
            var rv = -1; // Return value assumes failure.
            if (navigator.appName == "Microsoft Internet Explorer")
            {
              var ua = navigator.userAgent;
              var re  = new RegExp("MSIE ([0-9]{1,}[\.0-9]{0,})");
              if (re.exec(ua) != null)
                rv = parseFloat( RegExp.$1 );
            }
            return rv;
          ');
    return $ie_version;
  }

  /**
   * Resize the screen to 1440x900 when running tests.
   *
   * @BeforeScenario
   */
  public function sizeWindow(BeforeScenarioScope $scope) {
    try {
      $this->getSession()->getDriver()->resizeWindow(1440, 900);
    }
    catch (\Behat\Mink\Exception\UnsupportedDriverActionException $e) {
      // Can't resize the window since it's unsupported in this instance.
    }
  }

  /**
   * For javascript enabled scenarios, always wait for AJAX before clicking.
   *
   * @BeforeStep @javascript
   */
  public function beforeStep(BeforeStepScope $scope) {

    $text = $scope->getStep()->getText();
    if (preg_match('/(follow|press|click|submit)/i', $text)) {
      $this->iWaitForAjaxToFinish();
    }
  }

  /**
   * For javascript enabled scenarios, always wait for AJAX after clicking.
   *
   * @AfterStep @javascript
   */
  public function afterStep(AfterStepScope $scope) {

    $text = $scope->getStep()->getText();
    if (preg_match('/(follow|press|click|submit)/i', $text)) {
      $this->iWaitForAjaxToFinish();
    }
  }

  /**
   * Switch to a popup window.
   *
   * @When /^I switch to popup$/
   */
  public function iSwitchToPopup() {

    $original_window_name = $this->getSession()->getWindowName();
    if (empty($this->originalWindowName)) {
      $this->originalWindowName = $original_window_name;
    }

    $popup_name = $this->getNewPopup($original_window_name);

    // $this->getSession()->switchToWindow($arg1);
    // Switch to the popup Window.
    $this->getSession()->switchToWindow($popup_name);
  }

  /**
   * Switch back to the original window.
   *
   * @Then /^I switch back to original window$/
   */
  public function iSwitchBackToOriginalWindow() {

    // Switch to the original window.
    $this->getSession()->switchToWindow($this->originalWindowName);
  }

  /**
   * This gets the window name of the new popup.
   *
   * @param string $original_window_name
   *   The name of the original window.
   *
   * @return string
   *   Returns the last window.
   */
  private function getNewPopup($original_window_name = NULL) {

    // Get all of the window names first.
    $names = $this->getSession()->getWindowNames();

    // Now it should be the last window name.
    $last = array_pop($names);

    if (!empty($original_window_name)) {
      while ($last == $original_window_name && !empty($names)) {
        $last = array_pop($names);
      }
    }

    return $last;
  }

  /**
   * Remove terms that we probably created.
   *
   * Nodes are handled because when a user is deleted their content is deleted
   * as well. This not TRUE for terms that they create though.
   *
   * @AfterScenario
   */
  public function cleanupTerms() {

    $query = new \EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'taxonomy_term')
      ->propertyCondition('name', 'BDD_', 'STARTS_WITH')
      ->execute();
    if (isset($result['taxonomy_term'])) {
      $tids = array_keys($result['taxonomy_term']);
      foreach ($tids as $tid) {
        taxonomy_term_delete($tid);
      }
    }
  }

  /**
   * Fill in a entity reference field with a contact of a given name.
   *
   * @Given I fill in :field with contact term :name
   */
  public function iFillInWithContactTerm($field, $name) {

    $query = new \EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'taxonomy_term')
      ->entityCondition('bundle', 'contact')
      ->propertyCondition('name', $name)
      ->range(0, 1)
      ->execute();
    if (isset($result['taxonomy_term'])) {
      $tid = key($result['taxonomy_term']);
      $field = $this->fixStepArgument($field);
      $this->getSession()->getPage()->fillField($field, "$name ($tid)");
    }
    else {
      throw new \Exception('Term "' . $name . '" not found.');
    }
  }

  /**
   * Add a vocabulary term with specified fields.
   *
   * @Given I have a :vocabulary term with the fields:
   */
  public function iAmHaveTermWithTheFields($vocabulary, TableNode $table) {

    $term = new \stdClass();
    $term->vocabulary_machine_name = $vocabulary;
    foreach ($table as $row) {
      $term->{$row['field']} = $row['value'];
    }
    $this->dispatchHooks('BeforeTermCreateScope', $term);
    $this->parseEntityFields('taxonomy_term', $term);
    $saved = $this->getDriver()->createTerm($term);
    $this->dispatchHooks('AfterTermCreateScope', $saved);
    $this->terms[] = $saved;
    return $saved;
  }

  /**
   * Overrides DrupalContext loggedIn function.
   *
   * @return \Behat\Mink\Element\NodeElement|null
   *   Returns the node element indicating a logged in user.
   */
  public function loggedIn() {
    $session = $this->getSession();
    $session->visit($this->locatePath('/'));

    // If a logout link is found, we are logged in. While not perfect, this is
    // how Drupal SimpleTests currently work as well.
    $element = $session->getPage();
    return $element->find('css', 'body.logged-in');
  }

  /**
   * Returns fixed step argument (with \\" replaced back to ").
   *
   * @param string $argument
   *   Step argument.
   *
   * @return string
   *   The escaped step argument string.
   */
  protected function fixStepArgument($argument) {
    return str_replace('\\"', '"', $argument);
  }

  /**
   * Wait for AJAX to finish.
   *
   * @override Given I wait for AJAX to finish
   *
   * Override to increase the timeout to 10000
   */
  public function iWaitForAjaxToFinish() {
    $this->getSession()->wait(10000,
      '(typeof(jQuery)=="undefined" || (0 === jQuery.active && 0 === jQuery(\':animated\').length))');
  }

  /**
   * Enable the fixtures migrations module so we can load the fixture data.
   *
   * @BeforeSuite
   */
  public static function enableFixtureModules() {
    module_enable(array('bos_fixtures'));
  }

  /**
   * Run all fixtures before a scenario begins.
   *
   * @BeforeScenario @fixtures
   */
  public static function runAllMigrations() {
    $machine_names = self::getAllFixtureMigrations(TRUE);
    foreach ($machine_names as $machine_name) {
      self::runMigration($machine_name);
    }
  }

  /**
   * Revert all migrations after the scenario completes.
   *
   * @AfterScenario @fixtures
   */
  public static function revertAllMigrations() {
    $machine_names = self::getAllFixtureMigrations();
    self::revertMigrations($machine_names);
  }

  /**
   * Collect all fixtures that need to be loaded.
   *
   * @param bool $register
   *   Whether or not we should statically register these migrations.
   *
   * @return array
   *   The fixtures we want to migrate.
   */
  protected static function getAllFixtureMigrations($register = FALSE) {
    if (!module_exists('bos_fixtures')) {
      return array();
    }

    $migrations = bos_fixtures_migrate_api();
    $machine_names = array();
    foreach ($migrations['migrations'] as $name => $migration) {
      $machine_names[] = $name;
    }

    if ($register) {
      migrate_static_registration($machine_names);
    }

    return $machine_names;
  }

  /**
   * Run a migration.
   *
   * @param string $machine_name
   *   The machine name of the migration to run.
   */
  protected static function runMigration($machine_name) {
    $migration = \Migration::getInstance($machine_name);
    $dependencies = $migration->getHardDependencies();
    if ($dependencies) {
      foreach ($dependencies as $name) {
        self::runMigration($name);
      }
    }
    $migration->processImport();
  }

  /**
   * Revert a collection of migrations.
   *
   * @param array $machine_names
   *   The machine names of the migrations to revert.
   */
  protected static function revertMigrations($machine_names) {
    $dependencies = array();
    foreach ($machine_names as $machine_name) {
      $migration = \Migration::getInstance($machine_name);
      $dependencies += $migration->getDependencies();
    }

    foreach ($dependencies as $dependency) {
      $dependencies[$dependency] = $dependency;
    }

    // First revert top level migrations (no dependencies).
    foreach ($machine_names as $machine_name) {
      if (in_array($machine_name, $dependencies)) {
        continue;
      }
      self::revertMigration($machine_name);
    }

    if ($dependencies) {
      self::revertMigrations($dependencies);
    }
  }

  /**
   * Revert a migration.
   *
   * @param string $machine_name
   *   The machine name of the migration to revert.
   */
  protected static function revertMigration($machine_name) {
    $migration = \Migration::getInstance($machine_name);
    $migration->processRollback(array('force' => TRUE));
  }

  /**
   * Login a user with name. It is expected this user originates from a fixture.
   *
   * @Given I logged in as :username
   */
  public function loginAsUser($username) {
    // Check if logged in.
    if ($this->loggedIn()) {
      $this->logout();
    }
    $password = 'test1P*tttt';
    $this->getSession()->visit($this->locatePath('/user'));
    $element = $this->getSession()->getPage();
    $element->fillField($this->getDrupalText('username_field'), $username);
    $element->fillField($this->getDrupalText('password_field'), $password);
    $submit = $element->findButton($this->getDrupalText('log_in'));
    if (empty($submit)) {
      throw new \Exception(sprintf("No submit button at %s", $this->getSession()->getCurrentUrl()));
    }

    // Log in.
    $submit->click();

    if (!$this->loggedIn()) {
      throw new \Exception(sprintf("Failed to log in as user '%s'", $username));
    }
    $this->user = user_load_by_name($username);
  }

  /**
   * Verify that a content type exists.
   *
   * @param string $content_type
   *   The content type's label.
   *
   * @Given (that )content type :content_type exists
   */
  public function thatContentTypeExists($content_type) {
    $types = node_type_get_types();
    foreach ($types as $type) {
      if ($type->name == $content_type) {
        return;
      }
    }
    throw new \Exception("$content_type does not exist.");
  }

  /**
   * Verify that a content type does not exist.
   *
   * @param string $content_type
   *   The content type's label.
   *
   * @Given (that )content type :content_type does not exist
   */
  public function thatContentTypeDoesNotExists($content_type) {
    $types = node_type_get_types();
    foreach ($types as $type) {
      if ($type->name == $content_type) {
        throw new \Exception("$content_type exists.");
      }
    }
  }

  /**
   * Register migrations.
   *
   * @param array $migrations
   *   An array of migration names.
   */
  public function registerMigrations(array $migrations) {
    $this->migrations = array_merge($this->migrations, $migrations);
    foreach ($migrations as $migration) {
      migrate_static_registration($migrations);
    }
  }

  /**
   * Deregister migrations.
   *
   * @param array $migrations
   *   An array of migration names.
   */
  public function deregisterMigrations(array $migrations) {
    // Deregister the migrations.
    foreach ($migrations as $migration) {
      drush_migrate_deregister_migration($migration);
    }
  }

  /**
   * Change a migration to use our sample data for testing.
   */
  private function changeJsonSourceUrl($migration, $source) {
    // Change the source file on the JSON reader. and the source to trigger
    // an update migration.
    $reader = $migration->getSource()->getReader();
    if ($reader) {
      $reader->url = $source;
    }

    $urls = array($source);
    $migration->getSource()->setSourceUrls($urls);
  }

  /**
   * Assert that the hub-user migrations are working.
   *
   * @Given the hub-user migrations are working
   */
  public function theHubUserMigrationsAreWorking() {
    // Create a department node.
    $node_values = array(
      'type' => 'department_profile',
      'title' => 'Test Department',
      'status' => 1,
      'uid' => 1,
    );

    $node = (object) $node_values;
    $node = $this->nodeCreate($node);

    $term_values = array(
      'name' => "Test Department",
      'vocabulary_machine_name' => 'contact',
      'field_department_profile' => $node->title,
      'field_department_legacy_id' => '149000',
    );

    // Create a contact taxonomy term.
    $term = (object) $term_values;
    $this->termCreate($term);

    // Register the new migrations.
    module_load_include('inc', 'migrate', 'migrate.drush');
    $test_migrations = array(
      'User',
      'Profile',
    );

    $this->registerMigrations($test_migrations);

    // Run the migrations.
    foreach ($test_migrations as $machine_name) {
      $migration = \Migration::getInstance($machine_name);

      $src = DRUPAL_ROOT . "/" . drupal_get_path('module', 'hub_migration') . "/data/149000.json";
      $this->changeJsonSourceUrl($migration, $src);

      $dependencies = $migration->getHardDependencies();
      if ($dependencies) {
        foreach ($dependencies as $name) {
          self::runMigration($name);
        }
      }
      $migration->processImport();
    }
  }

  /**
   * Assert that data not related to the migration is not overriden on update.
   *
   * @Then not-migrated user data should stay pristine during a user's update
   */
  public function notMigratedUserDataShouldStayPristineDuringUserUpdate() {
    // Modify a few users by adding twitter data to them.
    $usernames = array(
      'nathan_varthan',
      'liza_orange',
    );

    // Find the users.
    $query = new \EntityFieldQuery();
    $query->entityCondition('entity_type', 'user');
    $query->propertyCondition('name', $usernames, 'IN');
    $results = $query->execute();

    // Set twitter info for these users.
    if (isset($results['user'])) {
      foreach ($results['user'] as $uid => $info) {
        $user = user_load($uid);
        $profile = profile2_by_uid_load($uid, 'main');
        $profile->field_twitter = array(
          LANGUAGE_NONE => array(0 => array('value' => "@{$user->name}")),
        );
        profile2_save($profile);
      }
    }

    // Update the users through re-running migrations.
    foreach ($this->migrations as $machine_name) {
      $migration = \Migration::getInstance($machine_name);

      $src = DRUPAL_ROOT . "/" . drupal_get_path('module', 'hub_migration') . "/data/149000update.json";
      $this->changeJsonSourceUrl($migration, $src);

      $dependencies = $migration->getHardDependencies();
      if ($dependencies) {
        foreach ($dependencies as $name) {
          self::runMigration($name);
        }
      }
      $migration->processImport();
    }

    $updated = array(
      'nathan_varthan' => "Data Proc Sys Analysta",
      'liza_orange' => "Data Procurement Equip Tech",
    );

    if (isset($results['user'])) {
      foreach ($results['user'] as $uid => $info) {
        $user = user_load($uid);
        $profile = profile2_by_uid_load($uid, 'main');

        // Check the update. Positions titles should have been updated.
        if ($items = field_get_items('profile2', $profile, 'field_position_title')) {
          foreach ($items as $item) {
            if ($item['value'] != $updated[$user->name]) {
              throw new Exception("User data for {$user->name} has not been updated.");
            }
          }
        }

        // Check the previously added, twitter data.
        if (field_get_items('profile2', $profile, 'field_twitter') == FALSE) {
          throw new Exception("Twitter data for {$user->name} is gone.");
        }

      }
    }

  }

  /**
   * Clean up migrations.
   *
   * @AfterScenario
   */
  public function cleanUpMigrations() {
    // Revert the migrations.
    foreach ($this->migrations as $migration) {
      $this->revertMigration($migration);
    }
    $this->deregisterMigrations($this->migrations);
  }

}
