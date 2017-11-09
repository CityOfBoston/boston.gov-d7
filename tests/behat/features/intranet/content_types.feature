@api @content
Feature: Content Types
  Given that I am a City of Boston site builder
  Then I want content types available which enable me to build a site

  Scenario Outline: Verify content types exist
    Then content type "<content_type>" exists

    Examples:
      | content_type       |
      | Article            |
      | Department Profile |
      | Event              |
      | How-To             |
      | Landing Page       |
      | Listing Page       |
      | Post               |
      | Guide              |
      | Tabbed Content     |
      | Place Profile      |

  Scenario Outline: Verify content types do not exist
    Then content type "<content_type>" does not exist

    Examples:
      | content_type               |
      | Advanced Poll              |
