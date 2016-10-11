<?php
/**
 * @file
 * Need to Know Field template.
 */
$detail_item_variables = array(
  'label' => 'Need to Know:',
  'body' => render($items),
  'classes' => array(
    'detail' => 'detail-item',
    'icon' => 'icon-alert',
    'body' => 'detail-item__body--tertiary',
  ),
);
print theme('detail_item', $detail_item_variables);
?>
