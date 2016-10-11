<?php
/**
 * @file
 * Downloads Field template.
 */
$item_list = array(
  '#theme' => 'item_list',
  '#type' => 'ul',
  '#items' => array(),
);
foreach ($items as $item) {
  $item_list['#items'][] = render($item);
}
$detail_item_variables = array(
  'label' => 'Downloads:',
  'body' => render($item_list),
  'classes' => array(
    'detail' => 'detail-item',
    'icon' => 'icon-download',
    'body' => 'detail-item__body--secondary download-list uppercase-sm-list',
  ),
);
print theme('detail_item', $detail_item_variables);
