<?php
/**
 * @file
 * Defines the class RoleContext.
 *
 * Used for defining step definitions around working with site roles.
 */

namespace Boston\Contexts;

use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;

/**
 * Class RoleContext for defining step definitions centered on roles.
 */
class RoleContext extends RawDrupalContext implements SnippetAcceptingContext {

  /**
   * Visit the role admin page.
   *
   * @Given I am on the role administration page
   */
  public function iAmOnTheRoleAdministrationPage() {
    $this->visitPath('/admin/people/permissions/roles');
  }

  /**
   * Verify that all site roles exist on the page.
   *
   * @Then I can see all site roles exist
   */
  public function iCanSeeAllSiteRolesExist() {
    $roles = array(
      'administrator',
      'Site Administrator',
      'Content Editor',
      'Content Author',
      'Guide Author',
      'Landing Author',
      'Events Editor',
      'Press Release Editor',
      'Procurement Editor',
      'Emergency Alert Author',
      'Manager',
    );
    foreach ($roles as $role) {
      $this->assertSession()->pageTextContains($role);
    }
  }

  /**
   * Verify that a role exists.
   *
   * @Given the site role :role_name exists
   */
  public function theSiteRoleExists($role_name) {
    $role = user_role_load_by_name($role_name);
    if (empty($role)) {
      throw new \Exception("Role '$role' doesn't exist.");
    }
  }

}
