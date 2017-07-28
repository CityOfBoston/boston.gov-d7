<?php

/**
 * @file
 * This template handles the layout of the views exposed filter form.
 *
 * Variables available:
 * - $widgets: An array of exposed form widgets. Each widget contains:
 * - $widget->label: The visible label to print. May be optional.
 * - $widget->operator: The operator for the widget. May be optional.
 * - $widget->widget: The widget itself.
 * - $sort_by: The select box to sort the view using an exposed form.
 * - $sort_order: The select box with the ASC, DESC options to define order. May
 *                be optional.
 * - $items_per_page: The select box with the available items per page. May be
 *                    optional.
 * - $offset: A textfield to define the offset of the view. May be optional.
 * - $reset_button: A button to reset the exposed filter applied. May be
 *                  optional.
 * - $button: The submit button for the form.
 *
 * @ingroup views_templates
 */

?>
<?php if (!empty($q)): ?>
  <?php
  // This ensures that, if clean URLs are off, the 'q' is added first so that
  // it shows up first in the URL.
  print $q;
  ?>
<?php endif; ?>
<div class="co">
  <input id="collapsible" type="checkbox" class="co-f d-n" aria-hidden=true>
  <label for="collapsible" class="co-t">Filter</label>
  <div class="co-b p-t200 p-a000--s">
    <?php $counter = 0; ?>
    <?php foreach($widget_groups as $group_id => $widget_group): ?>
      <div class="dr dr--sm">
        <input type="checkbox" id="dr-tr-<?php print $counter ?>" class="dr-tr a11y--h">
        <label for="dr-tr-<?php print $counter ?>" class="dr-h">
          <div class="dr-ic"><svg xmlns="http://www.w3.org/2000/svg" viewBox="-2 8.5 18 25"><path class="dr-i" d="M16 21L.5 33.2c-.6.5-1.5.4-2.2-.2-.5-.6-.4-1.6.2-2l12.6-10-12.6-10c-.6-.5-.7-1.5-.2-2s1.5-.7 2.2-.2L16 21z"/></svg></div>
          <div class="dr-t">Filter by <?php print $group_id; ?></div>
        </label>
        <div class="dr-c">
          <?php foreach ($widget_group as $widget_id => $widget): ?>
            <div id="<?php print $widget->id; ?>-wrapper" class="views-exposed-widget views-widget-<?php print $widget_id; ?>">
              <?php if (!empty($widget->label)): ?>
                <label for="<?php print $widget->id; ?>">
                  <?php print $widget->label; ?>
                </label>
              <?php endif; ?>
              <?php if (!empty($widget->operator)): ?>
                <div class="views-operator">
                  <?php print $widget->operator; ?>
                </div>
              <?php endif; ?>
              <div class="views-widget">
                <?php print $widget->widget; ?>
              </div>
            </div>
          <?php endforeach; ?>
        </div>
      </div>
      <?php $counter++; ?>
    <?php endforeach; ?>
    <?php if (!empty($sort_by)): ?>
      <div class="views-exposed-widget views-widget-sort-by">
        <?php print $sort_by; ?>
      </div>
      <div class="views-exposed-widget views-widget-sort-order">
        <?php print $sort_order; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($items_per_page)): ?>
      <div class="views-exposed-widget views-widget-per-page">
        <?php print $items_per_page; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($offset)): ?>
      <div class="views-exposed-widget views-widget-offset">
        <?php print $offset; ?>
      </div>
    <?php endif; ?>
    <div class="views-exposed-widget views-submit-button">
      <?php print $button; ?>
    </div>
    <?php if (!empty($reset_button)): ?>
      <div class="views-exposed-widget views-reset-button">
        <?php print $reset_button; ?>
      </div>
    <?php endif; ?>
  </div>
</div>
