/**
 * @file
 * Custom Javascript for Neighborhood Lookup Form.
 *
 * This javascript is loaded on all pages due to issues with shortcodes caching.
 */

(function ($, Drupal, window, document) {
  // Run this code whenever the DOM is fully loaded, regardless of whether or
  // not this script is included in the header or footer scripts.
  $(document).ready(function() {
    function validate_address(address) {
      return address && address !== '';
    }

    $("#bos-neighborhood-lookup-form").submit(function (event) {
      $error = $("div.address-error");
      $error.text('');
      event.preventDefault();
      var address = $("input#edit-street-address").val();
      var success = validate_address(address);
      if (success) {
        window.open(
          'https://www.cityofboston.gov/myneighborhood/?q=' + address,
          '_blank'
        );
        $("#edit-street-address").removeClass('error');
        $error.removeClass('input-error-mssg');
      }
      else {
        $("#edit-street-address").addClass('error');
        $error.addClass('input-error-mssg');
        $error.text('Please enter a valid street address.');
      }
    });
  });

})(jQuery, Drupal, this, this.document);
