<?php
/**
 * @file
 * Event contact template.
 */
$neighborhoods_list = '';
foreach ($items as $item) {
  $neighborhoods_list .= render($item) . '<br/>';
}
$detail_item_variables = array(
  'label' => 'Neighborhoods:',
  'body' => $neighborhoods_list,
  'classes' => array(
    'detail' => 'detail-item--secondary',
    'body' => 'detail-item__body--secondary',
  ),
);
print theme('detail_item', $detail_item_variables);
