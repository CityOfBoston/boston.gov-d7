<?php
/**
 * @file
 * Phone number field template.
 */
$detail_item_variables = array(
  'label' => 'Resources:',
  'body' => render($items),
  'classes' => array(
    'detail' => 'detail-item--secondary',
    'body' => 'detail-item__body--secondary',
  ),
);
print theme('detail_item', $detail_item_variables);
