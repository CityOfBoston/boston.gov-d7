/**
 * @file
 * Header styles.
 *
 * Adds seal animation to site header and animation variation on Guides.
 */

(function ($, Drupal, window, document) {

  'use strict';

  var elHeight = 245;
  var timerEl;
  // Repositions header's seal image on scroll.
  $(window).scroll(function () {
    if (timerEl) {
      clearTimeout(timerEl);
    }
    timerEl = setTimeout(function () {
      // Contains the position of the window.
      var scrollPos = $(this).scrollTop();
      // If the window top is greater than value of elHeight.
      if (scrollPos > elHeight) {
        if ($('.node-type-topic-page').length) {
          // Pull seal all the way up and fade in title.
          $('#seal').animate({top: '-104px'}, 150, function () {
            $('.topic-title').fadeIn(175);
          });
        }
        else {
          // Pull seal up.
          $('#seal').animate({top: '-58px'}, 150);
        }
      }
      else {
        if ($('.node-type-topic-page').length) {
          // Reset seal position and fade out title.
          $('#seal').animate({top: '0'}, 200, function () {
            $('.topic-title').fadeOut(5);
          });
        }
        else {
          // Reset seal position.
          $('#seal').animate({top: 0}, 150);
        }
      }
    }, 100);
  });

})(jQuery, Drupal, this, this.document);
