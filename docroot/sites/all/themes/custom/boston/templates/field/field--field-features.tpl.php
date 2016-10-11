<?php
/**
 * @file
 * Default markup for field_features.
 */
$detail_item_variables = array(
  'label' => 'Features',
  'body' => render($items),
  'classes' => array(
    'body' => 'detail-item__body--secondary',
  ),
);
print theme('detail_item', $detail_item_variables);
