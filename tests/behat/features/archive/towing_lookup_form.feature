@api @spy68
Feature: Towing Lookup Form
  As a developer
  I want to be able to integrate with the existing towing application
  so that I can get information on if my vehicle was towed given my license plate as an input.


  Scenario: Verify adding towing form to a text field using full html format.
    Given I am on "having-car-city"
    Then I should see the text "Your License Plate"
    And I fill in "edit-license-plate" with "1ab1234"
    And I should see the button "Submit"

  @javascript
  Scenario: Verify form validation fails for Towing Lookup Form.
    Given I am on "having-car-city"
    Then I should see the text "Your License Plate"
    And I fill in "edit-license-plate" with "1ab1234"
    And I should see the button "Submit"
    And I fill in "edit-license-plate" with "1 1234"
    And I press the "Submit" button
    Then I should see the text "Error: Valid Plate Required (3 to 8 letters and digits, no spaces or dashes)."
    And I fill in "edit-license-plate" with "1!1234"
    And I press the "Submit" button
    Then I should see the text "Error: Valid Plate Required (3 to 8 letters and digits, no spaces or dashes)."
    And I fill in "edit-license-plate" with "1-1234"
    And I press the "Submit" button
    Then I should see the text "Error: Valid Plate Required (3 to 8 letters and digits, no spaces or dashes)."
    And I fill in "edit-license-plate" with "1"
    And I press the "Submit" button
    Then I should see the text "Error: Valid Plate Required (3 to 8 letters and digits, no spaces or dashes)."

  @javascript
  Scenario: Verify submitting towing form redirects to www.cityofboston.gov/towing/search?plate=<plate>.
    Given I am on "having-car-city"
    Then I should see the text "Your License Plate"
    And I fill in "edit-license-plate" with "1ab1234"
    And I should see the button "Submit"
    And I fill in "edit-license-plate" with "1ab1234"
    And I press the "Submit" button
    Then I should not see the text "Error: Valid Plate Required (3 to 8 letters and digits, no spaces or dashes)."
    # Submission of this form opens in a new window, so we need to follow it.
    When I switch to popup
    Then I should be on "http://www.cityofboston.gov/towing/search/?plate=1ab1234"
    And the "txtPlate" field should contain "1ab1234"
