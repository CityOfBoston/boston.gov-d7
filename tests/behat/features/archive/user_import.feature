@api @spy649 @spy650
Feature: Site Roles
  As a developer
  I want the user migrations to work
  So that users can exist and be updated in the hub

  Scenario: Verify that the user migrations are working correctly
    Given the hub-user migrations are working
    Then not-migrated user data should stay pristine during a user's update
