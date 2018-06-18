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

    <?php
    $detail_item_classes = array(
      'detail' => 'detail-item--secondary',
      'body' => 'detail-item__body--secondary',
    );
    ?>

    <div class="g m-t500">
      <div class="g--8">
        <?php if ($content['authority']) { ?>
        <div class="list-item">
          <?php
          print theme('detail_item', array(
            'label' => 'Authority:',
            'body' => check_plain($content['authority']),
            'classes' => $detail_item_classes,
          ));
          ?>
        </div>
        <?php } ?>

        <?php if ($content['term']) { ?>
        <div class="list-item">
          <?php
          print theme('detail_item', array(
            'label' => 'Term:',
            'body' => check_plain($content['term']),
            'classes' => $detail_item_classes,
          ));
          ?>
        </div>
        <?php } ?>

        <?php if ($content['stipend']) { ?>
        <div class="list-item">
          <?php
          print theme('detail_item', array(
            'label' => 'Stipend:',
            'body' => check_plain($content['stipend']),
            'classes' => $detail_item_classes,
          ));
          ?>
        </div>
        <?php } ?>

        <?php if ($content['seats']) { ?>
        <div class="list-item">
          <?php
          print theme('detail_item', array(
            'label' => 'Total Seats:',
            'body' => check_plain($content['seats']),
            'classes' => $detail_item_classes,
          ));
          ?>
        </div>
        <?php } ?>
      </div>

      <div class="g--4">
        <?php if ($content['enabling_legislation_url']) { ?>
        <div class="list-item">
          <i>Resources:</i>

          <div class="detail-item__body--secondary">
            <div class="link-wrapper external-link">
              <a href="<? print render($content['enabling_legislation_url']) ?>"
                target="_blank">
                Enabling legislation
              </a>
            </div>
          </div>
        </div>
        <?php } ?>

        <?php if ($content['apply_url']) { ?>
        <div class="list-item" style="border-bottom: none">
          <i>We have openings:</i>

          <div class="m-v200">
            <a class="btn" href="<? print render($content['apply_url']) ?>">Apply online</a>
          </div>
        </div>
        <?php } ?>

  </div>
</div>
