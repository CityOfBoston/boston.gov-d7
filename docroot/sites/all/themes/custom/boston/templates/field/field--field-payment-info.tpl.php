<?php
/**
 * @file
 * Payment Info Field template.
 */
$detail_item_variables = array(
  'label' => 'Payment Info:',
  'body' => render($items),
  'classes' => array(
    'detail' => 'detail-item',
    'icon' => 'icon-payment',
    'body' => 'detail-item__body--tertiary',
  ),
);
print theme('detail_item', $detail_item_variables);
?>
