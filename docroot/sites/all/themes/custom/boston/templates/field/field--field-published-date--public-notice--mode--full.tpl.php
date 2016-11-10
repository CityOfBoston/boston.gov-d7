<?php
/**
 * @file
 * Event contact template.
 */

$items[0]['#markup'] = str_replace(' - 12:00am', '', $items[0]['#markup']);

$detail_item_variables = array(
  'label' => 'Posted:',
  'body' => render($items),
  'classes' => array(
    'detail' => 'detail-item--secondary',
    'body' => 'detail-item__body--secondary',
  ),
);
print theme('detail_item', $detail_item_variables);
