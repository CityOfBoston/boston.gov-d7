@api @component
Feature: Component Fields
  Given I am adding components to content
  Then I want to have the appropriate components available for me to choose from

  Scenario Outline: Only valid component available for content types.
    Given that content type "<content_type>" exists
    Then only global components should be available to content "<content_type>"

    Examples:
      | content_type                |
      | Article                     |
      | Department Profile          |
      | Landing Page                |
      | Listing Page                |
      | Post                        |
      | Guide                       |

  Scenario Outline: Only valid component available for paragraphs.
    Given that paragraph "<paragraph>" exists
    Then only global components should be available to paragraph "<paragraph>"

  Examples:
    | paragraph          |
    | Tabbed Content Tab |
