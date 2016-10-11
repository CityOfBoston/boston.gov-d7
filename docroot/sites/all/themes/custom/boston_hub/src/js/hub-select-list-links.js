/**
 * @file
 * Behaviors for Featured style select lists containing links.
 */

(function ($, Drupal, window, document) {
  'use strict';
  if ($('.featured.select-list-links .dropdown').length) {

    // Gets the link for the active option and wraps the
    // current selection in it's corresponding link.
    function link_selected() {
      $('.featured.select-list-links').each(function () {
        var activeOption = $(this).find('li.active').text();
        var activeOptionTrimmed = activeOption.trim();
        var optionLink = $(this).find('option:contains("' + activeOption + '")').val();
        $(this).find('.selected').wrapInner('<a href="' + optionLink + '" target="_blank" title="Go to ' + activeOptionTrimmed + '"></a>');

      });
    }

    // Opens selected link on change.
    // If new window fails, fallsback to same window.
    $('.featured.select-list-links .dropdown').on('change', function () {
      var selector = document.getElementById('select-links');
      var value = selector[selector.selectedIndex].value;
      if (window.open(value, '_blank')) {
      }
      else {
        window.location = value;
      }
    });

    // Calls the link_selected function when DOM is ready
    // and when a link is clicked.
    $(document).ready(link_selected);
    $('.featured.select-list-links .dropdown').on('change', link_selected);

  }
})(jQuery, Drupal, this, this.document);
