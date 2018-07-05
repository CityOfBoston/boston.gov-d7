<?php
/**
 * @file
 * Default theme implementation for a single paragraph item.
 *
 * Available variables:
 * - $content: An array of content items. Use render($content) to print them
 *   all, or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity
 *   - entity-paragraphs-item
 *   - paragraphs-item-{bundle}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened into
 *   a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>

<div class="b b--w b--fw">
  <div class="b-c">
    <div class="sh">
      <?php print render($content['field_component_title']) ?>
    </div>

    <table border="1" cellpadding="1" cellspacing="1" class="responsive-table responsive-table--horizontal m-t300">
      <thead>
        <tr>
          <th>Member</th>
          <th>Appointed</th>
          <th>Expires</th>
          <th>Status</th>
        </tr>
      </thead>
      <tbody>
        <?php foreach($content['members'] as $member) { ?>
        <tr>
          <td data-label="Member"><?php print check_plain($member['name']) ?></td>
          <td data-label="Appointed"><?php print $member['appointed'] ?></td>
          <td data-label="Expires"><?php print $member['expires'] ?></td>
          <td data-label="Status"><?php print check_plain($member['status']) ?></td>
        </tr>
        <?php } ?>
      </tbody>
    </table>
  </div>
</div>
