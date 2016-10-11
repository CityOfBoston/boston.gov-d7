/**
 * @file
 * Custom Javascript for Towing Lookup Form.
 *
 * This javascript is loaded on all pages due to issues with shortcodes caching.
 */

(function ($, Drupal, window, document) {
  // Run this code whenever the DOM is fully loaded, regardless of whether or
  // not this script is included in the header or footer scripts.
  $(document).ready(function() {

    function license_plate_validate(plate) {
      var regx = /^[A-Za-z0-9]+$/;
      if (!regx.test(plate) || plate.length < 3 || plate.length > 8) {
        return false;
      }
      return true;
    }

    $("#bos-towing-lookup-form").submit(function (event) {
      $error = $("div.license-plate-error");
      $error.text('');
      event.preventDefault();
      var plate = $("input#edit-license-plate").val();
      var success = license_plate_validate(plate);
      if (success) {
        window.open(
          'http://www.cityofboston.gov/towing/search/?plate=' + plate,
          '_blank'
        );
        $("#edit-license-plate").removeClass('error');
        $error.removeClass('input-error-mssg');
      }
      else {
        $("#edit-license-plate").addClass('error');
        $error.addClass('input-error-mssg');
        $error.text('Error: Valid Plate Required (3 to 8 letters and digits, no spaces or dashes).');
      }
    });
  });

})(jQuery, Drupal, this, this.document);
