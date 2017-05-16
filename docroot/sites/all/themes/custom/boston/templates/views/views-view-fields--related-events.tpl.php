<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
 $node_type = node_load($row->nid)->type;
 if (!empty($node_type)) { $type_class = 'news-item-' . $node_type; } else { $class_type = 'news-item-news'; };
?>

<div class="mobile-1-col tablet-1-col xxl-desktop-2-col clearfix news-item news-item-short-listing <?php echo $type_class; ?>">
  <a href="<?php print $fields['path']->content; ?>" class="item-link"></a>
  <div class="news-item-wrapper">
    <div class="thumb-wrapper float-left">
      <?php if ($fields['field_thumbnail']->content != ""): ?>
        <?php print $fields['field_thumbnail']->content; ?>
      <?php else: ?>
          <?php if ($fields['field_intro_image']->content != "default"): ?>
            <?php print $fields['field_intro_image']->content; ?>
          <?php else: ?>
            <div class="news-item-default-image">
              <span>Image for <?php print $fields['title']->content; ?></span>
            </div>
          <?php endif; ?>
      <?php endif; ?>
      <div class="date-flag">
        <?php if (isset($fields['field_event_dates']->content)): ?>
          <?php print $fields['field_event_dates']->content; ?>
        <?php elseif (isset($fields['field_public_notice_date']->content)): ?>
          <?php print $fields['field_public_notice_date']->content; ?>
        <?php endif; ?>
      </div>
    </div>
    <div class="text-wrapper">
      <h3 class="title">
        <?php print $fields['title']->content; ?>
      </h3>
    </div>
  </div>
</div>
