(function ($, Drupal, window, document) {

  'use strict';

  Drupal.behaviors.photoComponent = {
    attach: function (context, settings) {
      $('.paragraphs-item-photo').each(function () {
        if ($(this).find('.photo-details').length > 0) {
          $(this).addClass('with-details');
        }
        else {
          $(this).addClass('without-details');
        }
      });
    }
  };

})(jQuery, Drupal, this, this.document);
