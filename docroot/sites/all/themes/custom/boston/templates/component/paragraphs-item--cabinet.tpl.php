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

 $has_chief = isset($content['field_person']);
?>
<div class="b b--fw">
  <div class="b-c b-c--wtb">
    <div class="g">
      <?php if ($has_chief): ?>
        <div class="g--3">
          <?php print render($content['field_person']); ?>
        </div>
      <?php endif; ?>
      <div class="g--<?php if ($has_chief): ?>9<?php else: ?>12<?php endif; ?>">
        <div class="g">
          <div class="g--12 g--8--xl p-t500--mo">
            <h3 class="t--intro m-t000 m-b200"><?php print render($content['field_title']); ?></h3>
            <?php print render($content['field_description']); ?>
          </div>
          <div class="g--12 g--4--xl">
            <?php if (!empty($content['field_contacts'])): ?>
              <h5 class="m-t000 m-b200">Departments, Boards, &amp; Agencies</h5>
              <?php print $cabinet_contacts; ?>
            <?php else: ?>
                &nbsp;
            <?php endif; ?>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
