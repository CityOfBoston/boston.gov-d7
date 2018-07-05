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
$counter = 0;
?>
<?php if (!empty($q)): ?>
  <?php
  // This ensures that, if clean URLs are off, the 'q' is added first so that
  // it shows up first in the URL.
  print $q;
  ?>
<?php endif; ?>
<div class="drawer-trigger mobile-only ">
  <div class="drawer-trigger-chevron"></div>
  Filter
</div>
<div class="views-exposed-form drawer mobile-only">
  <bu class="views-exposed-widgets clearfix">
    <?php foreach($widget_groups as $group_id => $widget_group): ?>
    <button type="button" aria-expanded="true/false" aria-controls="drawer-<?php print $counter; ?>" class="drawer-trigger">
          <div class="drawer-trigger-chevron"></div>
          <span>Filter by <?php print $group_id; ?></span>
    </button>
      <div id="drawer-<?php print $counter++; ?>" class="clearfix drawer">
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
    <?php endforeach; ?>

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
