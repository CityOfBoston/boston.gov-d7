<?php
/**
 * @file
 * Contains FieldContext class.
 */

namespace Boston\Contexts;

use Behat\Behat\Context\SnippetAcceptingContext;
use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Class FieldContext.
 */
class FieldContext extends RawDrupalContext implements SnippetAcceptingContext {

  private $activeContentType;
  private $entityInfo;
  private $entityLabelMap;

  /**
   * Initialize data members.
   */
  public function __construct() {
    $this->entityInfo = entity_get_info();
    $this->entityLabelMap = array();
    foreach ($this->entityInfo as $entity_type => $info) {
      foreach ($info['bundles'] as $machine_name => $bundle_info) {
        $this->entityLabelMap[$entity_type][$bundle_info['label']] = $machine_name;
      }
    }
  }

  /**
   * Go to the add form for the content type.
   *
   * @Given I am adding a :content_type content
   */
  public function iAmAddingContent($content_type) {
    $this->activeContentType = $content_type;
    $this->visitPath('node/add/' . str_replace('_', '-', $this->entityLabelMap['node'][$content_type]));
  }

  /**
   * Select all valid components on the page.
   *
   * @Then I am only able to select available components for that content type
   */
  public function iAmAbleToSelectAllAvailableComponentsForThatContentType() {
    $available_components = _bos_core_get_components();
    $page = $this->getSession()->getPage();
    $component_select = $page->findField('Component type');
    if (empty($component_select)) {
      throw new \Exception("Component type field not found.");
    }
    foreach ($available_components as $component) {
      $component_select->selectOption($component);
    }
    $select_options = $component_select->findAll('css', 'option');
    if (count($select_options) !== count($available_components)) {
      throw new \Exception("Invalid components are available.");
    }
  }

}
