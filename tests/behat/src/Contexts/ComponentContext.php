<?php
/**
 * @file
 * Contains ComponentContext class.
 */

namespace Boston\Contexts;

use Behat\Behat\Context\SnippetAcceptingContext;
use Behat\Behat\Hook\Scope\BeforeScenarioScope;
use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Class ComponentContext adds component-specific step definitions.
 *
 * @package Boston\Contexts
 */
class ComponentContext extends RawDrupalContext implements SnippetAcceptingContext {

  /**
   * Reference to the component object added to the page.
   *
   * @var \Behat\Mink\Element\NodeElement
   */
  private $activeComponent;

  /**
   * Reference to the latest subcomponent object added to the page.
   *
   * @var \Behat\Mink\Element\NodeElement
   */
  private $activeSubComponent;

  private $contexts;

  /**
   * Gather all active contexts.
   *
   * @BeforeScenario
   */
  public function gatherContexts(BeforeScenarioScope $scope) {
    $environment = $scope->getEnvironment();
    $this->contexts = $environment->getContexts();
  }

  /**
   * Adds a specific component to a piece of content.
   *
   * @Given I add a :component component
   */
  public function addComponentToContent($component) {
    $this->selectComponentsTab();
    $component = $this->fixStepArgument($component);
    $this->getSession()->getPage()->selectFieldOption("field_components_add_more_type", $component);
    if (isset($this->activeComponent)) {
      $this->getSession()->getPage()->pressButton("Add another Component");
    }
    else {
      $this->getSession()->getPage()->pressButton("Add new Component");
    }
    $this->waitForAjax();
    // Set the active component and reset the active subcomponent.
    $this->activeComponent = $this->getSession()->getPage()->find('xpath', '//div[@id="edit-field-components"]/descendant::tbody[1]/tr[last()]');
    $this->activeSubComponent = NULL;
  }

  /**
   * Press a button in either a component or subcomponent.
   *
   * @Given I press the button :button in the :component
   */
  public function iPressComonentButton($button, $component) {
    $button = $this->fixStepArgument($button);
    $component = $this->fixStepArgument($component);
    $acting_element = $this->getComponent($component);
    $acting_element->pressButton($button);
    $this->waitForAjax();
  }

  /**
   * Fill in text in either a component or subcomponent.
   *
   * @Given I fill in :text in the :field :component field
   */
  public function iFillInInTheComponentField($text, $field, $component) {
    $field = $this->fixStepArgument($field);
    $text = $this->fixStepArgument($text);
    $component = $this->fixStepArgument($component);
    $acting_element = $this->getComponent($component);
    $acting_element->fillField($field, $text);
  }

  /**
   * Fill in text value in a CTA component field.
   *
   * @Given I fill in :text in the :field CTA component field
   */
  public function iFillInInTheCtaField($text, $field) {
    $field = $this->fixStepArgument($field);
    $text = $this->fixStepArgument($text);
    if (isset($this->activeComponent)) {
      $cta = $this->activeComponent->find('css', '.field-name-field-call-to-action');
      $cta->fillField($field, $text);
    }
    else {
      throw new \Exception('There is no active component.');
    }
  }

  /**
   * Attach image to either a component or subcomponent.
   *
   * @Given I attach the image :path to :field in the :component
   */
  public function iAttachImageToField($path, $field, $component) {
    $path = $this->fixStepArgument($path);
    $field = $this->fixStepArgument($field);
    $component = $this->fixStepArgument($component);
    $acting_element = $this->getComponent($component);

    if ($this->getMinkParameter('files_path')) {
      $full_path = rtrim(realpath($this->getMinkParameter('files_path')), DIRECTORY_SEPARATOR) . DIRECTORY_SEPARATOR . $path;
      if (is_file($full_path)) {
        $path = $full_path;
      }
    }

    $acting_element->attachFileToField($field, $path);
  }

  /**
   * Check or uncheck a CTA field in a component.
   *
   * @Given I :action :field in the CTA component field
   */
  public function iCheckUncheckInTheCtaField($action, $field) {
    $field = $this->fixStepArgument($field);
    $action = $this->fixStepArgument($action);
    if (isset($this->activeComponent)) {
      // @var $cta \Behat\Mink\Element\NodeElement
      $cta = $this->activeComponent->find('css', '.field-name-field-call-to-action');
      $cta->{$action . 'Field'}($field);
    }
    else {
      throw new \Exception('There is no active component.');
    }
  }

  /**
   * Select a value from a select list in the active component.
   *
   * @Given I select :option from :select in the :component
   */
  public function iSelectFromFieldInComponent($option, $select, $component) {
    $option = $this->fixStepArgument($option);
    $select = $this->fixStepArgument($select);
    $component = $this->fixStepArgument($component);
    $acting_element = $this->getComponent($component);
    $acting_element->selectFieldOption($select, $option);
  }

  /**
   * Click a link in a component.
   *
   * @Given I click :link in the :component
   */
  public function iClickLinkInComponent($link, $component) {
    $component = $this->fixStepArgument($component);
    $link = $this->fixStepArgument($link);
    $acting_element = $this->getComponent($component);
    $acting_element->clickLink($link);
  }

  /**
   * Add a subcomponent to the active component.
   *
   * Currently adding a subcomponent is always done via button.
   *
   * @Given I add a link of type :subcomponent
   * @Given I add a text block of type :subcomponent
   * @Given I add a subcomponent of type :subcomponent
   */
  public function addSubcomponent($subcomponent) {
    $subcomponent = $this->fixStepArgument($subcomponent);
    $this->activeComponent->pressButton("Add " . $subcomponent);
    $this->waitForAjax();
    // Set the active subcomponent.
    $xpath = "//em[text()='$subcomponent']/ancestor::td[2]";
    $this->activeSubComponent = $this->activeComponent->find('xpath', $xpath);
  }

  /**
   * Add content with title and navigate to node edit page.
   *
   * @Given I am creating a :type with the title :title
   */
  public function creatingContentWithTitle($type, $title) {
    $node = (object) array(
      'title' => $title,
      'type' => $type,
    );
    $saved = $this->nodeCreate($node);
    // Set internal page on the new node.
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid . '/edit'));
  }

  /**
   * Click a vertical tab within the active component.
   *
   * @Given I click the :tab tab in the component
   */
  public function iClickTabInComponent($tab) {
    $this->activeComponent->clickLink($tab);
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
   * Fills in WYSIWYG editor with specified label in sub/component.
   *
   * @Given I fill in :text in the WYSIWYG :field :component field
   */
  public function iFillInInWysiwygEditor($text, $field, $component) {
    $text = $this->fixStepArgument($text);
    $field = $this->fixStepArgument($field);
    $component = $this->fixStepArgument($component);
    $acting_element = $this->getComponent($component);
    // @var $acting_element \Behat\Mink\Element\NodeElement
    $label = $acting_element->find('xpath', "//label[contains(.,'$field')]");
    $for = $label->getAttribute('for');
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
   * Selects the Components tab.
   */
  private function selectComponentsTab() {
    $this->getSession()->getPage()->clickLink("Components");
  }

  /**
   * Instruct the browser to wait until AJAX has completed.
   */
  private function waitForAjax() {
    $this->getSession()->wait(5000, '(typeof(jQuery)=="undefined" || (0 === jQuery.active && 0 === jQuery(\':animated\').length))');
  }

  /**
   * Return either the active component or active subcomponent.
   *
   * Returned value depends on whether or not $component is component or
   * subcomponent.
   *
   * @param string $component
   *   The active item to return, either component or subcomponent.
   *
   * @return \Behat\Mink\Element\NodeElement
   *   Return the active component or subcomponent.
   *
   * @throws \Exception
   *   Thrown if either the active component or subcomponent is not set.
   */
  private function getComponent($component) {
    if (isset($this->activeComponent)) {
      $acting_element = $this->activeComponent;
      if ($component == 'subcomponent') {
        if (!isset($this->activeSubComponent)) {
          throw new \Exception('There is no active subcomponent.');
        }
        $acting_element = $this->activeSubComponent;
      }
      return $acting_element;
    }
    else {
      throw new \Exception('There is no active component.');
    }
  }

  /**
   * Verify global components are assigned to the content type.
   *
   * Non-global components should never be assigned to field_components.
   *
   * @param string $content_type
   *   The content type to check against.
   *
   * @Then only global components should be available to content :content_type
   */
  public function onlyGlobalComponentsShouldBeAvailableToContent($content_type) {
    $types = node_type_get_types();
    $type = NULL;
    foreach ($types as $machine_name => $type_info) {
      if ($type_info->name == $content_type) {
        $type = $machine_name;
        break;
      }
    }
    if (is_null($type)) {
      throw new \Exception("$content_type does not exist.");
    }
    $this->validateGlobalComponents('node', $type);
  }

  /**
   * Verify global components are assigned to the paragraph.
   *
   * Non-global components should never be assigned to field_components.
   *
   * @param string $paragraph
   *   The paragraph type to check against.
   *
   * @Then only global components should be available to paragraph :paragraph
   */
  public function onlyGlobalComponentsShouldBeAvailableToParagraph($paragraph) {
    $results = db_select('paragraphs_bundle', 'pb')
      ->fields('pb')
      ->execute()
      ->fetchAllAssoc('name');
    if (!isset($results[$paragraph])) {
      throw new \Exception("$paragraph does not exist.");
    }
    $this->validateGlobalComponents('paragraphs_item', $results[$paragraph]->bundle);
  }

  /**
   * Verify that a paragraph type exists.
   *
   * @param string $paragraph
   *   The human readable label of the paragraph type.
   *
   * @Given that paragraph :paragraph exists
   */
  public function paragraphExists($paragraph) {
    $results = db_select('paragraphs_bundle', 'pb')
      ->fields('pb')
      ->execute()
      ->fetchAllAssoc('name');
    if (!isset($results[$paragraph])) {
      throw new \Exception("$paragraph does not exist.");
    }
  }

  /**
   * Validate entity bundle's component field.
   *
   * @param string $entity_type
   *   The entity type.
   * @param string $bundle
   *   A bundle of entity type.
   */
  private function validateGlobalComponents($entity_type, $bundle) {
    $components = _bos_core_get_components();
    $component_field_info = field_info_instance($entity_type, 'field_components', $bundle);
    $enabled_components = array_values($component_field_info['settings']['allowed_bundles']);
    $remove_paragraphs = array_diff($enabled_components, $components);
    $allow_paragraphs = array_diff($components, $enabled_components);
    $remove_paragraphs = array_unique($remove_paragraphs);
    $allow_paragraphs = array_unique($allow_paragraphs);
    asort($remove_paragraphs);
    if ($remove_paragraphs[key($remove_paragraphs)] == -1) {
      unset($remove_paragraphs[key($remove_paragraphs)]);
    }
    $message = '';
    if (count($remove_paragraphs) > 0) {
      $remove_paragraphs = array_map(function($bundle) {
        $bundle = paragraphs_bundle_load($bundle);
        return " - " . $bundle->name;
      }, $remove_paragraphs);
      $remove_paragraphs = implode("\n", $remove_paragraphs);
      $message .= "Enabled paragraphs are currently now allowed:\n";
      $message .= $remove_paragraphs . "\n";
    }
    if (count($allow_paragraphs) > 0) {
      $allow_paragraphs = array_map(function($bundle) {
        $bundle = paragraphs_bundle_load($bundle);
        return " - " . $bundle->name;
      }, $allow_paragraphs);
      $allow_paragraphs = implode("\n", $allow_paragraphs);
      $message .= "The following paragraphs should be allowed and are currently not:\n";
      $message .= $allow_paragraphs . "\n";
    }
    if (!empty($message)) {
      throw new \Exception($message);
    }
  }

}
