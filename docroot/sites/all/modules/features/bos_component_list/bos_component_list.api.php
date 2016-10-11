<?php
/**
 * @file
 * API documentation for Boston Component List module.
 */

/**
 * Provide contextual filter options on views select fields.
 *
 * The callback will be passed $vargs_default, which is an array
 * containing the default values for the form elements you are constructing. The
 * provided defaults are generated from the vargs subfield.
 *
 * @return array
 *   display - The view|display id pair provided by the views select list.
 *   callback - Callback which when invoked will provide a collection of
 *    select list elements, one for each contextual filter provided by
 *    the associated view display.
 */
function hook_list_view_options() {
  return array(
    'view|display_id' => 'callback_providing_form_options',
  );
}
