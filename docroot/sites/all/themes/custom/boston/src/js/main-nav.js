(function ($, Drupal, window, document) {

  'use strict';
  // Hides menu items
  $.fn.menuHide = function () {
    this.addClass('hide-menu-item').removeClass('show-menu-item');
    return this;
  };

  // Show menu items
  $.fn.menuShow = function () {
    this.addClass('show-menu-item').removeClass('hide-menu-item');
    return this;
  };

  // Resets menu
  $.fn.menuReset = function () {
    this.find('.hide-menu-item').removeClass('hide-menu-item');
    this.find('.show-menu-item').removeClass('show-menu-item');
    this.find('.submenu').menuHide().children('li').menuHide();
    return this;
  };

  $('.nav-trigger').on('click', function () {
    $('.main-navigation').menuReset();
    $('.hb').toggleClass('hb--active');
    $('body').toggleClass('noscroll');

    $(this).attr('aria-expanded', !$('.hb__trigger').is(':checked'));
  });

  $('.hb__trigger').attr('checked', false);

  $('.dd__input').on('change', function () {
    var el = $(this)
    var isChecked = el.is(':checked');

    $('.dd').attr('aria-expanded', isChecked);
  }).attr('checked', false);

  $('.tb__trigger').on('change', function () {
    var el = $(this)
    var isChecked = el.is(':checked');

    el.attr('aria-expanded', !isChecked);

    if (!isChecked && $('.dd__input').is(':checked')) {
      $('.dd__input').attr('checked', false);
    }
  }).attr('checked', false);

  // Resets menu on page load
  $('.main-navigation').menuReset();

  // Shows and hides the appropriate menu items when parent menu item is clicked.
  $('.menu__item.expanded a.nolink').on('click', function (event) {
    event.preventDefault();
    // Hides all necessary menu items.
    $(this).closest('.menu').menuHide()
      .children('.menu__item').menuHide();
    $(this).menuHide().closest('.menu__item.expanded').menuHide()
      .siblings('.menu-item-back').menuHide()
      .siblings('.menu__item.expanded').not(this)
      .children('.nolink').removeClass('show-menu-item');
    // Shows all necessary menu items.
    $(this).closest('.menu__item.expanded')
      .addClass('is-open')
      .children('.submenu').menuShow();
    $(this).siblings('.menu')
      .children('li').menuShow();

    // Gets the submenu's title and stores it in a variable
    var parentTitle = $(this).closest('.menu__item.expanded').children('.nolink').text();
    // Adds the submenu's title to the menu header.
    $('.main-navigation-title').text(parentTitle);
  });

  // Shows and hides the appropriate menu items when menu back button is clicked.
  $('.menu-item-back a.menu-link-back').on('click', function (event) {
    event.preventDefault();
    $(this).closest('.is-open')
      .removeClass('is-open')
    // Traverses up the tree to show/hide menu elements.
    $(this).closest('.menu').menuHide()
      .prev('.menu__link').menuShow()
      .closest('.menu').menuShow()
      .children('li').removeClass('hide-menu-item');
    $(this).closest('.expanded')
      .children('.nolink').removeClass('show-menu-item');
    // Traverses down the tree to show/hide menu elements.
    $(this).closest('.menu-item-back')
      .siblings('.expanded')
      .children('.nolink').removeClass('show-menu-item');
    $(this).closest('.menu')
      .children('li').menuHide();

    // Gets the parent submenu's title and stores it in a variable
    var parentTitle = $(this).parents('.menu__item.expanded').eq(1).children('.nolink').text();
    // Adds the submenu's title to the menu header.
    $('.main-navigation-title').text(parentTitle);
  });
})(jQuery, Drupal, this, this.document);
