<?php
/**
 * @file
 * Contains ContextsTrait trait.
 */

namespace Boston\Contexts;

use Behat\Behat\Hook\Scope\BeforeScenarioScope;


/**
 * Trait ContextsTrait provides methods for retrieving Behat contexts.
 *
 * @package Boston\Contexts
 */
trait ContextsTrait {

  /**
   * Collection of active scenario contexts.
   *
   * @var array
   */
  protected $contexts;

  /**
   * The environment provided by the scenario.
   *
   * @var \Behat\Testwork\Environment\Environment
   */
  protected $environment;

  /**
   * Set the contexts.
   *
   * @param array $contexts
   *   The contexts that should be available.
   */
  public function setContexts($contexts) {
    $this->contexts = $contexts;
  }

  /**
   * Save the environment!
   *
   * @BeforeScenario
   */
  public function getEnvironment(BeforeScenarioScope $scope) {
    $this->environment = $scope->getEnvironment();
  }

  /**
   * Return the loaded DrupalContext.
   *
   * @return \Drupal\DrupalExtension\Context\DrupalContext
   *   The loaded DrupalContext.
   */
  protected function getDrupalContext() {
    if (!empty($this->environment)) {
      return $this->environment->getContext('Drupal\DrupalExtension\Context\DrupalContext');
    }
    else {
      foreach ($this->contexts as $c) {
        if ($c instanceof \Drupal\DrupalExtension\Context\DrupalContext) {
          return $c;
        }
      }
    }
    return FALSE;
  }

  /**
   * Return the loaded ComponentContext.
   *
   * @return \Boston\Contexts\ComponentContext
   *   The loaded ComponentContext.
   */
  protected function getComponentContext() {
    if (!empty($this->environment)) {
      return $this->environment->getContext('Boston\Contexts\ComponentContext');
    }
    else {
      foreach ($this->contexts as $c) {
        if ($c instanceof \Boston\Contexts\ComponentContext) {
          return $c;
        }
      }
    }
    return FALSE;
  }

  /**
   * Return the loaded FeatureContext.
   *
   * @return \Boston\Contexts\FeatureContext
   *   The loaded FeatureContext.
   */
  protected function getFeatureContext() {
    if (!empty($this->environment)) {
      return $this->environment->getContext('Boston\Contexts\FeatureContext');
    }
    else {
      foreach ($this->contexts as $c) {
        if ($c instanceof \Boston\Contexts\FeatureContext) {
          return $c;
        }
      }
    }
    return FALSE;
  }

  /**
   * Return the loaded RoleContext.
   *
   * @return \Boston\Contexts\RoleContext
   *   The loaded RoleContext.
   */
  protected function getRoleContext() {
    if (!empty($this->environment)) {
      return $this->environment->getContext('Boston\Contexts\RoleContext');
    }
    else {
      foreach ($this->contexts as $c) {
        if ($c instanceof \Boston\Contexts\RoleContext) {
          return $c;
        }
      }
    }
    return FALSE;
  }

  /**
   * Return the loaded WorkflowContext.
   *
   * @return \Boston\Contexts\WorkflowContext
   *   The loaded WorkflowContext.
   */
  protected function getWorkflowContext() {
    if (!empty($this->environment)) {
      return $this->environment->getContext('Boston\Contexts\WorkflowContext');
    }
    else {
      foreach ($this->contexts as $c) {
        if ($c instanceof \Boston\Contexts\WorkflowContext) {
          return $c;
        }
      }
    }
    return FALSE;
  }

  /**
   * Return the loaded FieldContext.
   *
   * @return \Boston\Contexts\FieldContext
   *   The loaded FieldContext.
   */
  protected function getFieldContext() {
    if (!empty($this->environment)) {
      return $this->environment->getContext('Boston\Contexts\FieldContext');
    }
    else {
      foreach ($this->contexts as $c) {
        if ($c instanceof \Boston\Contexts\FieldContext) {
          return $c;
        }
      }
    }
    return FALSE;
  }

}
