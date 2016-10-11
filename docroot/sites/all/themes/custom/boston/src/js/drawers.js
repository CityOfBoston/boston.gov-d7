(function ($, Drupal, window, document) {

  'use strict';

  if ($('.dr').length) {
    // Only hide if JS is working
    $('.dr__content').hide().attr('aria-hidden', true);

    // Add show/hide to all drawer headers
    $('.dr__header').click(function () {
      var el       = $(this);
      var isActive = el.hasClass('dr__header--active');
      var content  = el.siblings('.dr__content');

      el.toggleClass('dr__header--active');
      isActive ? content.slideUp().attr('aria-hidden', true) : content.slideDown().attr('aria-hidden', false);
    });
  };

})(jQuery, Drupal, this, this.document);
