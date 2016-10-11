/**
 * @file
 * Polls functionality.
 *
 * Provides functionality for polls and renders circle graphs.
 */

(function ($, Drupal, window, document) {

  'use strict';
  window.circle_count = 0;

  // If a vote button is clickd, check the associated radio button and
  // trigger the change event on it.
  $(document).on('click', '.vote-button', function () {
    var text = $(this).prev('.choice_text').text();
    $('label:contains("' + text + '")').prev('input[type=radio]').prop("checked", true).change();
  });

  // Causes forms to auto submit when radio button is selected.
  $(document).on('change', 'input[type=radio]', function () {
    var form = $(this).closest('form');
    $('input[type=submit]', form).mousedown();
  });

  if ($('.node-advpoll').length || $('.paragraphs-item-feedback').length) {
    Drupal.behaviors.renderRawPoll = {
      attach: function (context, settings) {
        // Iterate through each poll stub on the page and replace it with
        // an actual form.
        $('.poll-stub').once('poll-stub').each(function () {
          var nid = $(this).data('poll-id');
          // Grab a different endpoint depending on whether or not the user has
          // already voted. This is to account for caching.
          var element_settings = {
            url: window.location.protocol + '//' + window.location.hostname + settings.basePath + settings.pathPrefix + 'ajax/poll/' + nid,
            event: 'click',
            progress: {
              type: 'throbber'
            }
          };
          $.ajax(element_settings.url)
            .done(function (result) {
              result = JSON.parse(result);
              $(result.selector).html(result.html);
              Drupal.attachBehaviors(context, settings);
            });
        });
      }
    };

    /* global circle_count:true Circles */

    Drupal.behaviors.pollConvertForm = {
      attach: function (context, settings) {
        $.fn.createBosCircle = function () {
          $(this).each(function () {
            var circle_id = 'circle-container-' + circle_count++;
            $(this).attr('id', circle_id);
            var percent = $(this).data('percent');
            var text = $(this).data('text');
            Circles.create({
              id: circle_id,
              radius: 66,
              value: percent,
              maxValue: 100,
              width: 12,
              text: percent + '%',
              colors: ['#ececec', '#091f2f'],
              duration: 200,
              wrpClass: 'circles-wrp',
              textClass: 'circles-text',
              valueStrokeClass: 'circles-valueStroke',
              maxValueStrokeClass: 'circles-maxValueStroke',
              styleWrapper: true,
              styleText: false
            });
            $('#' + circle_id).find('.circles-wrp').after('<div class="choice_text">' + text + '</div>');
          });
        };

        $('div.circles_container').once('circle-generate').createBosCircle();

        if (Drupal.settings.bos_content_type_advpoll !== null) {
          var pollOptions = Drupal.settings.bos_content_type_advpoll;
          pollOptions.forEach(function (myOptions) {
            // Make sure we check against any polls on this page and see if we have their cookie.
            var regex = new RegExp("(advpoll" + myOptions.poll_options.poll_id + "=vote)", "g");
            // Creates the voting button under each circle that is in a poll that the user can vote on
            // and triggers the radio button with the same text when clicked.
            $('#advpoll-form-' + myOptions.poll_options.poll_id + ' .circles_container').each(function () {
              if (!document.cookie.match(regex)) {
                // Use the vote_button_text from the poll node to fill in the button.
                $(this).once('vote-button-add').append('<button class="vote-button button-sm" type="button">' + myOptions.poll_options.vote_button_text + '</button>');
              }
            });
          });
        }
      }
    }
  };
})(jQuery, Drupal, this, this.document);
