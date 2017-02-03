@api @spy297
Feature: Site Roles
  As a developer
  I want the system roles to exist
  So that I can configure permissions when I am completing tasks

  Scenario Outline: Verify that site roles exist through the administration interface
    Then the site role "<role>" exists

    Examples:
    | role                    |
    | Site Administrator      |
    | Content Editor          |
    | Content Author          |
    | Press Release Editor    |
    | Events Editor           |
    | Status Alert Editor     |
    | Manager                 |
    | Guide Author            |
    | Landing Author          |
