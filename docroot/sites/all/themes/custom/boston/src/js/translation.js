(function ($, Drupal, window, document) {

  'use strict';

  Drupal.behaviors.translations = {
    attach: function (context, settings) {
      var translateLink = $('.tr-dd-link');
      var translateTrigger = $('.tr-link');
      var language = localStorage.getItem('language');
      var scriptLoaded = false;

      function onProgress() {
      }

      function onError(error) {
        console.log('Error: ' + error);
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

      var loadScript = function (cb) {
        var success = cb;

        if (!scriptLoaded) {
          $.ajax({
            url: "https://www.microsoftTranslator.com/ajax/v3/WidgetV3.ashx?siteData=ueOIGRSKkd965FeEGM5JtQ**",
            dataType: "script",
            timeout: 2 * 1000
          }).done(function() {
            $('.tr-dd-link--message').remove();
            $('.tr-dd').addClass('tr-dd--loaded');
            scriptLoaded = true;
            success();
          })
          .fail(function() {
            $('.tr-dd-link--message').html('Translations are down temporarily.')
          });
        } else {
          success();
        }
      }

      translateTrigger.on('click', function (ev) {
        ev.preventDefault();

        $('.tr-dd').toggle();

        loadScript(function () {

        });
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
        loadScript(function() {
          translatePage(language);

          // If the language isn't English, show it
          if (language !== 'en') {
            $('.tr-dd-link--hidden').show();
          } else {
            $('.tr-dd-link--hidden').hide();
          }
        });
      }

      $('.tr').addClass('tr--visible');
    }
  };

})(jQuery, Drupal, this, this.document);
