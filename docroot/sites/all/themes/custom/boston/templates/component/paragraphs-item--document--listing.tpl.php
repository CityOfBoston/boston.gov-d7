<?php
/**
 * @file
 * External Link View Mode: Token  Field template.
 *
 * If the $field_title is not set, defaults to the filename.
 */
?>

<?php if (isset($content['field_title'])): ?>
  <?php $field_title = render($content['field_title']); ?>
<?php else: ?>
  <?php $field_title = $document_filename; ?>
<?php endif; ?>

<?php
$detail_item_variables = array(
  'label' => 'Downloads:',
  'body' => "<ul><li>" . "<a href='$document_link' title= '$field_title' > $field_title ". "</a>" . "</li></ul>",
  'classes' => array(
    'icon' => 'icon-download',
    'body' => 'detail-item__body--secondary',
  ),
);

print theme('detail_item', $detail_item_variables);
?>



