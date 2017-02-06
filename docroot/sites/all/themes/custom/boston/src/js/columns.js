(function ($, Drupal, window, document) {

  'use strict';

  if ($('.views-exposed-topbar .view-filters').length) {

    $('.form-checkboxes').each(function () {
      var checkboxArr = [];
      var $checkboxList = $(this).find('.bef-checkboxes');

      // Create array of all .form-items in .bef-checkboxes.
      $checkboxList.find('.form-item').each(function () {
        checkboxArr.push($(this).html());
      });

      // Split the array at this point. The original array is altered.
      var colOne = checkboxArr.splice(0, Math.round(checkboxArr.length / 3));
      var colTwo = checkboxArr.splice(0, Math.round(checkboxArr.length / 2));
      ListHTML = '';
      var colThree = checkboxArr;
      var ListHTML = '';

      function createHTML(list) {
        ListHTML = '';
        for (var i = 0; i < list.length; i++) {
          ListHTML += '<div class="form-item form-type-bef-checkbox">' + list[i] + '</div>';
        }
      }

      // Generate HTML for first list.
      createHTML(colOne);
      $checkboxList.html(ListHTML);

      // Generate HTML for second list.
      createHTML(colTwo);
      // Create new list after original one.
      $checkboxList.after('<div class="bef-checkboxes desktop-3-col"></div>').next().html(ListHTML);

      // Generate HTML for third list.
      createHTML(colThree);
      // Create new list after second one.
      $checkboxList.after('<div class="bef-checkboxes desktop-3-col"></div>').next().html(ListHTML);

      // Add .desktop-3-col class to .bef-checkboxes
      $checkboxList.addClass('desktop-3-col');

    });
  }

})(jQuery, Drupal, this, this.document);
