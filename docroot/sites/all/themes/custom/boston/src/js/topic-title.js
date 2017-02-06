/**
 * @file
 * Prepends a .topic-title header to the page.
 */

(function ($, Drupal, window, document) {

  'use strict';

  Drupal.behaviors.topicHeaderTitle = {
    attach: function (context, settings) {
      // Exit if there is no topic text to handle.
      if (!$('.topic-hero-text-wrapper h1').length) {
        return;
      }

      // Stores topic title text.
      var topicTitle = $('.topic-hero-text-wrapper h1');
      var topicTitleText = topicTitle.text();

      // Outputs the topic title text into the header for windows larger than 820 and removes on smaller screens.
      $(window).on('load resize', function () {
        if (!$('.topic-title').length) {
          if ($(window).width() > 1400) {
            $('.header').prepend('<h3 class="topic-title">' + topicTitleText + '</h3>');
          }
        }
        else {
          if ($(window).width() < 1400) {
            $('.topic-title').remove();
          }
        }
      });

      document.body.addEventListener('seal:hidden', function () {
        $('.topic-title').fadeIn(80);
      });

      document.body.addEventListener('seal:down', function () {
        $('.topic-title').fadeOut(30);
      });
    }
  };

})(jQuery, Drupal, this, this.document);
