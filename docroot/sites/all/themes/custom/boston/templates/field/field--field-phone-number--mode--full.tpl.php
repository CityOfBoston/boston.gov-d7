<?php
/**
 * @file
 * Phone number field template on full view mode.
 */
$detail_item_variables = array(
  'label' => NULL,
  'body' => render($items),
  'classes' => array(
    'detail' => 'detail-item--middle',
    'icon' => 'icon-phone',
    'body' => 'detail-item__body--secondary',
  ),
  'phone' => TRUE,
);
print theme('detail_item', $detail_item_variables);
