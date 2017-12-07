/**
 * @file
 * Drawer behaviors.
 *
 * Adds functionality for drawers across the site.
 */

(function ($, Drupal, window, document) {

  'use strict';

  if ($('.drawer').length) {
    $('.drawer-trigger').click(function () {
      // If .draw-trigger is clicked and has the class .active, remove active and slide up (close) the closest .drawer.
      if ($(this).hasClass('active')) {
        $(this).toggleClass('active').next('.active').toggleClass('active').slideUp(400);
        $('#query').blur();
      }
      // Otherwise add  the class .active and slide down (open) the closest .drawer.
      else {
        $(this).toggleClass('active').next('.drawer').toggleClass('active').slideDown(400);
        // And remove .active class from all other drawers and drawer-treggers.
        $(this).parent('.drawer-wrapper').siblings('.drawer-wrapper').children('.drawer').removeClass('active').slideUp(400);
        $(this).parent('.drawer-wrapper').siblings('.drawer-wrapper').children('.drawer-trigger').removeClass('active');

        if ($(this).hasClass('search-trigger')) {
          $('#query').focus();
          $('input[name=search_block_form]').focus();
        }
      }
    });
    // Drawer close button removes active state from .drawer and drawer-trigger and toggles the drawer shut.
    $('.drawer-close-button').click(function () {
      $(this).closest('.drawer.active').toggleClass('active').slideUp(400).prev('.drawer-trigger.active').toggleClass('active');
      $('#query').blur();
    });
  }

  if ($('.drawer.mobile-only').length) {
    $(window).resize(function () {
      // Resets filterdrawers when window is resized.
      $('.active').removeClass('active');
      // If window is resized to more than 980px, display: none is removed from
      // style attribute so exposed filters to remain hidden from mobile states.
      if ($(window).width() > 980) {
        $('.drawer.mobile-only').css('display', '');
      }
    });
  }

  // Expand drawers so users can search within them easily.
  $(document).on("keydown", function (e) {
    // Check for CTRL+f input.
    if (e.keyCode == 70 && (e.ctrlKey || e.metaKey)) {
      // Loop through each label that controls a hidden checkbox.
      $('.dr-h').each(function() {
        // Only execute on drawers that are closed.
        if (!$(this).hasClass('expanded')) {
          // Simulate a click on the drawer label to open it.
          $(this).click();
          // Add a class so we know this drawer is now open.
          $(this).addClass('expanded');
        }
      });
    }
    // Check for ESC input.
    if (e.keyCode == 27) {
      // Loop through each label that controls a hidden checkbox.
      $('.dr-h').each(function() {
        // Only execute on drawers that are open.
        if ($(this).hasClass('expanded')) {
          // Simulate a click on the drawer label to close it.
          $(this).click();
          // Remove a class so we know this drawer is now closed.
          $(this).removeClass('expanded');
        }
      });
    }
  });
  // Check for clicks outside of browser search.
  $('.dr-h').click(function() {
    // Check if the clicked drawer is already open.
    if ($(this).hasClass('expanded')) {
      // Remove the class so we know this drawer was closed manually.
      $(this).removeClass('expanded');
    // If the drawer is closed already.
    } else {
      // Add a class so we know if was just opened.
      $(this).addClass('expanded');
    }
  });

})(jQuery, Drupal, this, this.document);
