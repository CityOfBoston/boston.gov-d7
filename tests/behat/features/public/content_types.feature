@api @content
Feature: Content Types
  Given that I am a City of Boston site builder
  Then I want content types available which enable me to build a site

  Scenario Outline: Verify content types exist
    Then content type "<content_type>" exists

    Examples:
      | content_type               |
      | Advanced Poll              |
      | Article                    |
      | Event                      |
      | Department Profile         |
      | Landing Page               |
      | Listing Page               |
      | Person Profile             |
      | Place Profile              |
      | Program Initiative Profile |
      | Post                       |
      | Guide                      |
      | Public Notice              |
