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

<div class="cds g--24">
  <?php if(!empty($card_url)): ?>
    <a href="<?php print $card_url; ?>" class="cds-l d-b m-b500">
  <?php else: ?>
    <div class="cds-l d-b m-b500">
  <?php endif; ?>
    <div class="cds-ic m-b500--l">
      <?php print $icon; ?>
    <?php if ($use_alert): ?>
      <svg class="cds-ia" width="28" height="28" viewBox="-1187 1989 24 24" xmlns="http://www.w3.org/2000/svg"><title>Alert</title><desc>A red exclamation point in a cirlce.</desc><circle class="svg-stroke-hover" stroke="#FB4D42" stroke-width="3" fill="#FFF" fill-rule="evenodd" cx="-1175" cy="2001" r="10.5"/><path d="M-1175 2008.2c-.4 0-.8-.1-1.1-.4-.3-.3-.4-.6-.4-1s.1-.8.4-1c.3-.3.6-.4 1.1-.4.4 0 .8.1 1 .4.2.3.4.6.4 1s-.1.8-.4 1c-.3.2-.6.4-1 .4zm-1.4-14.4h2.8v2.6l-.6 7.2h-1.6l-.6-7.2v-2.6z" class="svg-fill-hover" fill="#FB4D42" fill-rule="evenodd"/></svg>
    <?php endif; ?>
    </div>
    <div class="cds-c">
    <div class="cds-t t--upper t--sans m-b300"><?php print render($content['field_title']); ?></div>
    <div class="cds-d t--subinfo"><?php print render($content['field_message']); ?></div>
    </div>
  <?php if(!empty($card_url)): ?>
    </a>
  <?php else: ?>
  </div>
  <?php endif; ?>
</div>
