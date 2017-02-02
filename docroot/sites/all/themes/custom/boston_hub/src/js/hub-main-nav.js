/**
 * @file
 * Menu Title behaviors specific to hub.
 */

(function ($, Drupal, window, document) {
  'use strict';
    // Overrides base theme's main menu behavior, setting menu title to 'Menu' if it has no value.
    $('.menu-item-back a.menu-link-back').on('click', function (event) {
      // Gets the parent submenu's title and stores it in a variable.
      var parentTitle = $(this).parents('.menu__item.expanded').eq(1).children('.nolink').text();
      // If the variable's content is empty, sets value to 'Menu'.
      if (parentTitle === '') {
        parentTitle = 'Menu';
      }
      // Adds the submenu's title to the menu header.
      $('.main-navigation-title').text(parentTitle);
    });
})(jQuery, Drupal, this, this.document);
