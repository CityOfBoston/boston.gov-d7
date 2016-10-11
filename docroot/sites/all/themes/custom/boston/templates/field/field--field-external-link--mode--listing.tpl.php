<?php
/**
 * @file
 * External Link View Mode: Token  Field template.
 */
$detail_item_variables = array(
  'label' => 'Downloads:',
  'body' => "<ul><li>" . render($items) . "</li></ul>",
  'classes' => array(
    'icon' => 'icon-download',
    'body' => 'detail-item__body--secondary',
  ),
);

print theme('detail_item', $detail_item_variables);

?>

