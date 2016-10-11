
/**
 * @file
 * Logic for transposing a vertical-heading table into a horizontal-heading
 * table.
 */
(function ($, Drupal, window, document) {
  if (window.enquire !== undefined) {
    // Transform a vertical header table into a horizontal header table so that
    // it can utilize horizontal header responsive styling.
    $.fn.transposeHorizontal = function () {
      var $this = $(this),
          table = $('<table><thead><tr></tr></thead><tbody></tbody></table>'),
          newRows = [];
      // Add vertical row th elements to the thead element of the horizontal
      // table.
      $('th', this).each(function () {
        $('thead > tr', table).append('<th>' + this.innerHTML + '</th>');
      });
      $this.find('tbody > tr').each(function() {
        var i = 0;
        $(this).find('td').each(function () {
          if (newRows[i] === undefined) {
            newRows[i] = $("<tr></tr>");
          }
          newRows[i++].append($(this));
        });
      });
      $.each(newRows, function() {
        $('tbody', table).append(this);
      });

      // After we've built up the table, add classes and then replace the
      // current table's HTML with the one we've built up.
      $this.addClass('responsive-table responsive-table--vertical transposed');
      $this.html(table.html());
    };
    // Transform a horizontal header table back into a vertical header table so
    // that it can be viewed properly at desktop screen sizes.
    $.fn.transposeVertical = function () {
      var $this = $(this),
        table = $('<table><tbody></tbody></table>'),
        newRows = [];
      $this.find('tbody > tr').each(function() {
        var i = 0;
        $(this).find('td').each(function() {
          if (newRows[i] === undefined) {
            newRows[i] = $("<tr></tr>");
          }
          newRows[i++].append($(this));
        });
      });
      // Add th elements at the beginning of each row.
      $this.find('th').each(function(index, value) {
        newRows[index].prepend(this);
      });
      $.each(newRows, function() {
        $('tbody', table).append(this);
      });

      // After we've built up the table, add classes and then replace the
      // current table's HTML with the one we've built up.
      $this.removeClass('transposed');
      $this.addClass('responsive-table responsive-table--vertical');
      $this.html(table.html());
    };

    enquire.register("screen and (min-width: 768px)", {
      match: function() {
        $('.responsive-table--vertical.transposed').transposeVertical();
      }
    })
    .register("screen and (max-width: 767px)", {
      match: function() {
        $('.responsive-table--vertical').transposeHorizontal();
      }
    });
  }
})(jQuery, Drupal, this, this.document);
