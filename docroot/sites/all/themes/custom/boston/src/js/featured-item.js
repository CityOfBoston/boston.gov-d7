/**
 * @file
 * Featured Item behaviors.
 *
 * Adds height control for image column in feauted items.
 * Currently used for header items: featured events and featured posts.
 */

(function ($, Drupal, window, document) {

  'use strict';

  $(window).on('load resize', function () {
    if ($(window).width() > 980) {
      var colHeight = $('.featured-item-details').outerHeight();
      $('.featured-item-thumb').css('height', colHeight + 'px');
    }
  });

})(jQuery, Drupal, this, this.document);
