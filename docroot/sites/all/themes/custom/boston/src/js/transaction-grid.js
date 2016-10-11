/**
 * @file
 * Transaction Grid link.
 *
 * Adds wrapping link to transaction grid item.
 */

(function ($, Drupal, window, document) {

  'use strict';

  if ($('.paragraphs-item-transaction-grid').length) {
    // Grabs the url output by the link field adn wraps around entire transaction field.
    $('.field-name-field-transactions').each(function () {
      var linkAddress = $(this).find('.paragraphs-items-field-grid-link a').attr('href');
      // Creates the anchor tag.
      $(this).find('.field-collection-item-field-transactions').wrap('<a href="' + linkAddress + '" class="wrap-link" target="_blank"></a>');
    });
  }
})(jQuery, Drupal, this, this.document);
