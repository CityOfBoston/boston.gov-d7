/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document) {
  'use strict';
  var related_content_errors_container = document.getElementById('field-related-content-add-more-wrapper');
  var rc_input_errors = related_content_errors_container.getElementsByClassName('form-text error');
  var errorNode = document.createElement("div");
  errorNode.appendChild(document.createTextNode("This is no longer a valid piece of meta"));
  var count;
  for (count = 0; count < rc_input_errors.length;) {
      rc_input_errors[count].parentNode.appendChild(errorNode.cloneNode(true));
      count ++;
  };
})(jQuery, Drupal, this, this.document);
