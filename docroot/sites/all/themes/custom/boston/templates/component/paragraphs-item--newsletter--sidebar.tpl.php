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
<div class="b b--<?php print $component_theme; ?><?php if ($component_theme !== 'w'): ?> p-a300<?php endif; ?>">
  <?php if (isset($content['field_component_title'])): ?>
    <div class="sh sh--sm <?php print $section_header_theme; ?> m-b300">
      <?php print render($content['field_component_title']); ?>
    </div>
  <?php endif; ?>
  <?php if (isset($content['field_description'])): ?>
    <div class="t--info m-b300"><?php print render($content['field_description']); ?></div>
  <?php endif; ?>
  <div>
    <?php if (isset($content['field_newsletter'])): ?>
      <?php $newsletter_id = $content['field_newsletter']['#items'][0]['entity']->field_id['und'][0]['value']; ?>
      <form action="<?php print $newsletter_url ?>?list=<?php print $newsletter_id ?>" method="POST" class="bos-newsletter" novalidate>
        <div class="fs">
          <div class="fs-c">
            <div class="txt">
              <label for="subscriber[email]" class="txt-l txt-l--mt000">Your Email Address</label>
              <input name="subscriber[email]" type="email" value="" placeholder="Email address" class="txt-f bos-newsletter-email">
            </div>
            <div class="txt">
              <label for="subscriber[zipcode]" class="txt-l txt-l--mt000">Zip Code</label>
              <input name="subscriber[zipcode]" type="text" value="" placeholder="Zip Code" class="txt-f bos-newsletter-zip" size="10">
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
