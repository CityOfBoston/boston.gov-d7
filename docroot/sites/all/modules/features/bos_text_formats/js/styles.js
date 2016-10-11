
/**
 * @file
 * Set styles for the site.
 *
 * Create a boston styles set and add site-specific styles to it.
 */
(function ($, Drupal, window, document) {
  Drupal.behaviors.configureCkeditor = {
    attach: function (context, settings) {
      if (typeof(CKEDITOR) !== 'undefined') {
        if (CKEDITOR.stylesSet.get('boston') == null) {
          CKEDITOR.stylesSet.add('boston', [
            // Block styles.
            {
              name: 'Intro Text',
              element: 'p',
              attributes: {
                'class': 'supporting-text'
              }
            },
            // Inline styles.
            {
              name: 'Red Text',
              element: 'span',
              attributes: {
                'class': 'red' // Freedom-trail red.
              }
            }
          ]);

          CKEDITOR.config.stylesSet = 'boston';
        }
        CKEDITOR.config.scayt_autoStartup = true;
      }
    }
  }
})(jQuery, Drupal, this, this.document);
