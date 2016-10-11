/**
 * @file
 * Employee Search.
 *
 * Adds functionality for employee search page.
 */

(function ($, Drupal, window, document) {

  'use strict';
  if ($('.page-employee-directory').length) {
    // Adds active filters to an array and outputs them
    // as an HTML string in the page.
    var filterResults = [];
    $('.facetapi-active').each(function () {
      var filterContent = $(this).parent('li').clone().children().remove().end().text();
      filterResults.push(filterContent);
    });
    var filterResultsOutput = filterResults.join(', ');
    var activeFilters = '<div class="active-filters"><span class="applied-filters-label">Filters applied: </span>' + filterResultsOutput + '</div>';
    if ($('.facetapi-active').length) {
      $('h1.page-title').after(activeFilters);
    }

    // Adds .descending class to solr solr sort filter
    // to change direction of chevron.
    if (window.location.href.indexOf("solrsort=ss_field_last_name%20desc") > -1) {
      $('.solr-search-sort').removeClass('descending');
    }
    else {
      $('.solr-search-sort').addClass('descending');
    }
  }

})(jQuery, Drupal, this, this.document);
