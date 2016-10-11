(function ($, Drupal, window, document) {

  'use strict';

  Drupal.behaviors.feedbackOverlay = {
    attach: function (context, settings) {
      var fadeSpeed             = 100;
      var modalTrigger          = '.modal-link';
      var modalOverlay          = '.modal-overlay';

      // When trigger link is clicked, display corresponding modal block.
      $(modalTrigger).on('click', function (e) {
        e.preventDefault();
        var modal_id = $(this).data('modal');

        if ($('#hb__trigger').is(':checked')) {
          $('.nav-trigger').trigger('click');
        }

        $(modalOverlay + ' span.modal-id:contains("' + modal_id + '")').closest(modalOverlay).fadeIn(fadeSpeed);
        $(this).closest('.popover').fadeOut(fadeSpeed);

        // Prevents body from scrolling.
        if ($(modalOverlay).is(':visible')) {
          $('body').addClass('noscroll');
          $('#feedback_url').val(window.location.href);
          $('#feedback_browser').val(navigator.userAgent);
        }
      });

      // Hide overlay when close button is clicked.
      $('.close-button').on('click', function () {
        $(this).closest(modalOverlay).fadeOut(fadeSpeed);
        $('body').removeClass('noscroll');
      });

      // Hide overlay when clicking anywhere outside of the overlay container
      $(modalOverlay).mouseup(function (e) {
        var container = $(modalOverlay + ' .container');
        if (!container.is(e.target) && container.has(e.target).length === 0) {
          $(this).closest(modalOverlay).fadeOut(fadeSpeed);
          $('body').removeClass('noscroll');
        }
      });

      // Close modal when esc key (27) is released.
      $(document).keyup(function (e) {
        if (e.keyCode === 27) {
          $(modalOverlay).fadeOut(fadeSpeed);
          $('body').removeClass('noscroll');
        }
      });

      // Find Feedback modal and add class to control unique width
      $('.modal-id:contains("feedback")').closest('.feedback-container').addClass('container-max-width');

      $('#feedback_form').on('submit', function (ev) {
        ev.preventDefault();

        var formEl = $(this);
        var submitButton = $('input[type=submit]', formEl);

        $.ajax({
          type: 'POST',
          url: formEl.prop('action'),
          accept: {
            javascript: 'application/javascript'
          },
          data: formEl.serialize(),
          beforeSend: function() {
            submitButton.prop('disabled', 'disabled');
          }
        }).done(function(data) {
          $('#feedback_form_container').html('Thank you for your submission').addClass('is-centered');
        });
      });
    }
  };

})(jQuery, Drupal, this, this.document);
