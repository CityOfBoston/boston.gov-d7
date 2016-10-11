/**
 * @file
 * Tabbed Pages.
 *
 * Moves breadcrumbs to article element on pages that use tab functionality.
 * How To and Tabbed Content Node Types.
 */

(function ($, Drupal, window, document) {

  'use strict';
  if ($('.node-type-how-to').length || $('.node-type-tabbed-content').length) {
    $('#breadcrumb').prependTo('article');
  }

})(jQuery, Drupal, this, this.document);
