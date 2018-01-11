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
<div class="b b--fw b--<?php print $component_theme; ?>">
  <div class="b-c">
    <div class="sh m-b300 <?php print $section_header_theme; ?>">
      <?php if (isset($content['field_component_title'])): ?>
        <?php print render($content['field_component_title']); ?>
      <?php endif; ?>
      <?php if (isset($content['field_contact'])): ?>
        <?php print render($content['field_contact']); ?>
      <?php endif; ?>
    </div>
    <div class="g">
      <?php if (isset($content['field_description'])): ?>
        <div class="g--6">
          <div class="t--intro"><?php print render($content['field_description']); ?></div>
        </div>
      <?php endif; ?>
      <div class="g--<?php if (isset($content['field_description'])): ?>6<?php else: ?>12<?php endif; ?>">
        <?php if (isset($content['field_newsletter'])): ?>
          <?php $newsletter_id = $content['field_newsletter']['#items'][0]['entity']->field_id['und'][0]['value']; ?>
          <form action="<?php print $newsletter_url ?>?list=<?php print $newsletter_id ?>" method="POST" class="bos-newsletter" novalidate>
            <div class="fs">
              <div class="fs-c fs-c--i">
                <div class="txt">
                  <label for="subscriber[email]" class="txt-l">Your Email Address</label>
                  <input name="subscriber[email]" type="email" value="" placeholder="Email address" class="txt-f bos-newsletter-email">
                </div>
                <div class="txt">
                  <label for="subscriber[zipcode]" class="txt-l">Zip Code</label>
                  <input name="subscriber[zipcode]" type="text" value="" placeholder="Zip Code" class="txt-f bos-newsletter-zip" size="18">
                </div>
              </div>
              <div class="bc bc--r">
                <button type="submit" class="btn btn--700">Sign Up</button>
              </div>
            </div>
          </form>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
