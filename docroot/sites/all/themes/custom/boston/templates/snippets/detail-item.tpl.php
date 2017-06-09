<?php
/**
 * @file
 * Default theme implementation for detail item.
 *
 * Available variables:
 * - $label: The label value of the detail item.
 * - $body: The content value of the detail item.
 * - $classes: Array of classes to be applied to detail, icon, label, and body
 *   elements.
 */
$default_classes = array(
  'detail' => NULL,
  'icon' => NULL,
  'label' => NULL,
  'body' => NULL,
);
$classes += $default_classes;
$detail_classes = explode(' ', $classes['detail']);
$use_left = FALSE;
$left_content = NULL;
if (!empty($classes['icon'])) {
  $left_content = "<div class=\"icon {$classes['icon']}\"></div>";
}
elseif (isset($label) && in_array('detail-item--secondary', $detail_classes)) {
  $left_content = "<div>$label</div>";
}
elseif (isset($image)) {
  $left_content = "<div>$image</div>";
}
?>
<div class="detail-item <?php print $classes['detail'] ?>">
  <?php if (!empty($left_content)): ?>
  <div class="detail-item__left">
    <?php print $left_content; ?>
  </div>
  <?php endif; ?>
  <div class="detail-item__content">
    <?php if (!empty($label) && !in_array('detail-item--secondary', $detail_classes)): ?>
      <div class="detail-item__label <?php print $classes['label']; ?>">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($body)): ?>
    <div class="detail-item__body <?php print $classes['body']; ?>">
      <?php if ($phone) { ?>
        <a href="tel:<?php print $body; ?>"><?php print $body; ?></a>
      <?php } else { ?>
        <?php print $body; ?>
      <?php }?>
    </div>
    <?php endif; ?>
  </div>
</div>
