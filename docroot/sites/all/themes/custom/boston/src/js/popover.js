(function ($, Drupal, window, document) {

  'use strict';

  var fadeSpeed = 100;
  $('.translate-trigger').on ('click', function (e) {
    e.preventDefault();
    $('.popover').fadeToggle(fadeSpeed);
  });
  $(document).click(function (e) {
    e.stopPropagation();
    if ($(e.target).is('.popover, .translate-trigger'))  return false;
    else $('.popover').fadeOut(fadeSpeed);
  });

})(jQuery, Drupal, this, this.document);
