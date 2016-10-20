(function ($, Drupal, window, document) {

  'use strict';

  Drupal.behaviors.translations = {
    attach: function (context, settings) {
      var translateLink = $('.tr-dd-link');
      var translateTrigger = $('.tr-link');
      var language = localStorage.getItem('language');

      function onProgress() {
      }

      function onError(error) {
        alert('There was an error translating this page. If it continues, please contact digital@boston.gov');
      }

      function onComplete() {
        Microsoft.Translator.Widget.domTranslator.showHighlight = false;
        Microsoft.Translator.Widget.domTranslator.showTooltips = false;
        $('.tr-dd').hide();
      }

      // Fires when the user clicks on the exit box of the floating widget
      function onRestoreOriginal() {
      }

      var setLanguage = function (language) {
        localStorage.setItem('language', language);
      }

      var translatePage = function (to, el) {
        Microsoft.Translator.Widget.Translate('en', to, onProgress, onError, onComplete, onRestoreOriginal, 2000);
      }

      translateTrigger.on('click', function (ev) {
        ev.preventDefault();

        $('.tr-dd').toggle();
      });

      translateLink.click(function(ev) {
        ev.preventDefault();

        var el = $(this);
        var language = el.data('ln');

        // Set the language
        setLanguage(language);

        // Translate the page
        translatePage(language, el);

        // Hide the toggle
        $('.tr-dd').hide();

        // If the language isn't English, show it
        if (language !== 'en') {
          $('.tr-dd-link--hidden').show();
        } else {
          $('.tr-dd-link--hidden').hide();
        }
      });

      if (language && language !== 'en') {
        translatePage(language);

        // If the language isn't English, show it
        if (language !== 'en') {
          $('.tr-dd-link--hidden').show();
        } else {
          $('.tr-dd-link--hidden').hide();
        }
      }
    }
  };

})(jQuery, Drupal, this, this.document);
