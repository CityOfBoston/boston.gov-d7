(function ($, window, document) {
  if (Modernizr !== undefined) {
    if (Modernizr.flexbox !== true) {
      $('.grid-card').addClass('no-flex');
    }
  }
})(jQuery, this, this.document);
