<?php
/**
 * @file
 * Contains WorkflowContext class.
 */

namespace Boston\Contexts;

use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;

/**
 * Class WorkflowContext for making workflow steps available.
 *
 * @package Boston\Contexts
 */
class WorkflowContext extends RawDrupalContext implements SnippetAcceptingContext {

  use ContextsTrait;

  protected $activeWorkflowNode;
  protected $statesMachine;
  protected $statesLabel;

  /**
   * Constructor for context.
   */
  public function __construct() {
    $this->statesLabel = workbench_moderation_state_labels();
    $this->statesMachine = array_flip($this->statesLabel);
  }

  /**
   * Finds node with title and assigns it the designated state.
   *
   * @Given I have :title content in :state_label state
   */
  public function iHaveContentInState($title, $state_label) {
    // The DrupalContext will have access to the session user, which is who
    // the content should belong to.
    $feature_context = $this->getFeatureContext();
    // Assign the author to be the logged in user.
    $query = new \EntityFieldQuery();
    $entities = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('title', $title)
      ->range(0, 1)
      ->execute();

    if (!empty($entities['node'])) {
      $keys = array_keys($entities['node']);
      $nodes = array_shift($keys);
      $node = node_load($nodes);
    }
    else {
      throw new \Exception("Content with title \"$title\" was not found.");
    }
    // Get the logged in user's uid.
    $node->uid = $feature_context->user->uid;
    $node->workbench_moderation_state_new = $this->statesMachine[$state_label];
    node_save($node);
    $this->activeWorkflowNode = $node;
  }

  /**
   * Move the content to the given state, and verify it is in that state.
   *
   * The verification happens by observing the user interface rather than
   * checking node properties.
   *
   * @Then I can move the content to :state state
   */
  public function iCanMoveTheContentToState($state) {
    $this->visitPath('node/' . $this->activeWorkflowNode->nid . '/moderation');
    $page = $this->getSession()->getPage();
    $select_element = $page->findField('Moderation state');
    if (empty($select_element)) {
      $unpublish_link = $page->findLink('Unpublish');
      if (empty($unpublish_link)) {
        throw new \Exception('Could not find the Unpublish link, user may not have access to moderation tab.');
      }
      else {
        $page->clickLink('Unpublish');
        $select_element = $page->findField('Set moderation state');
        $select_element->selectOption($state);
        $page->pressButton('Unpublish');
      }
    }
    else {
      $select_element->selectOption($state);
      $page->pressButton('Apply');
    }
    $this->activeWorkflowNode = node_load($this->activeWorkflowNode->nid);
    try {
      if ($state === 'Published') {
        $mod_table_row = $page->find('css', 'tr.published-revision');
        if (empty($mod_table_row)) {
          throw new \Exception('Tried to publish the content, but there is no published revision.');
        }
        else {
          $unpublish_link = $mod_table_row->findLink('Unpublish');
          if (empty($unpublish_link)) {
            throw new \Exception('There was a published revision row, but no Unpublish link.');
          }
        }
      }
      else {
        $this->assertSession()->pageTextContains("The current state is $state");
      }
    }
    catch (\Exception $e) {
      throw new \Exception('State could not be moved to "' . $state . '".');
    }
  }

  /**
   * Confirm moderation permissions exist for a role.
   *
   * @Then I expect to have the workbench permissions I need to moderate content
   */
  public function iExpectToHaveTheWorkbenchPermissionsNeedToModerateContent() {
    $base_permissions = [
      'view all unpublished content',
      'view moderation history',
      'view moderation messages',
      'use workbench_moderation my drafts tab',
      'use workbench_moderation needs review tab',
      'moderate content from draft to needs_review',
      'moderate content from published to draft',
      'moderate content from published to archive',
      'moderate content from archive to draft',
      'moderate content from needs_review to draft',
      'moderate content from needs_review to published',
    ];
    $drupal_context = $this->getDrupalContext();
    $user = $drupal_context->user;
    if (empty($user)) {
      throw new \Exception('No user is logged in to check permissions for.');
    }
    $all_permissions = acquia_permissions_map();
    $role = $user->role;
    $user = user_load($user->uid);
    $role_permissions = array_intersect($base_permissions, $all_permissions[$role]);
    if (count($role_permissions) > 0) {
      $users = array_fill(0, count($role_permissions), $user);
      $access_result = array_map('user_access', $role_permissions, $users);
      if (in_array(FALSE, $access_result)) {
        throw new \Exception('Moderation permissions in the database do not match settings specified in permissions.settings.php.');
      }
    }
  }

  /**
   * Confirm that Workbench Moderation is enabled.
   *
   * @Given that workbench is setup
   */
  public function thatWorkbenchIsSetup() {
    if (!module_exists('workbench_moderation')) {
      throw new \Exception('Workbench Moderation is not enabled.');
    }
  }

  /**
   * Confirm that revisions are enabled for a content type.
   *
   * @param string $content_type
   *   The label of the content type.
   *
   * @Then I expect :content_type to be enabled for workbench
   */
  public function iExpectToBeEnabledForWorkbench($content_type) {
    $types = node_type_get_types();
    foreach ($types as $machine_name => $type_info) {
      if ($type_info->name == $content_type) {
        $node_options = variable_get("node_options_$machine_name", FALSE);
        if (!empty($node_options) && in_array('revision', $node_options) && in_array('moderation', $node_options)) {
          return;
        }
      }
    }
    throw new \Exception("$content_type is not configured for Workbench.");
  }

}
