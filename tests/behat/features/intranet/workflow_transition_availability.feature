@api @workflow
Feature: Workflow Transition Availability
  As an authenticated user
  Depending on my role
  I have a set of workflow transitions available to me when working with content

  Scenario Outline: Roles have appropriate workbench permissions
    Given I am logged in as a user with the "<role>" role
    Then I expect to have the workbench permissions I need to moderate content

    Examples:
      | role                        |
      | Site Administrator          |
      | Content Editor              |
      | Content Author              |
      | Status Alert Editor         |

  Scenario Outline: Content types are configured to use workbench
    Given that workbench is setup
    And that content type "<content_type>" exists
    Then I expect "<content_type>" to be enabled for workbench

    Examples:
      | content_type                |
      | Article                     |
      | Department Profile          |
      | Landing Page                |
      | Listing Page                |
      | Post                        |
      | Guide                       |
      | Tabbed Content              |
