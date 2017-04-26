<?php
/**
 * @file
 * Default template for a grid card.
 *
 * Available variables are:
 * - $image: An optional image to include in the card.
 * - $title: Title of card as link to content.
 * - $description: Description of card content.
 */
?>
<div class="cd g--4 g--4--sl m-t500">
  <?php if (isset($link)): ?>
    <a href="<?php print $link; ?>">
  <?php endif; ?>
  <?php if (isset($image)): ?>
    <div class="cd-ic" style="background-image: url(<?php print $image ?>)"></div>
  <?php endif; ?>
  <div class="cd-c">
    <h3 class="cd-t"><?php print $title; ?></h3>
    <?php if (isset($subtitle)): ?>
    <div class="cd-st t--upper t--subtitle"><?php print $subtitle; ?></div>
    <?php endif; ?>
    <?php if (isset($description)): ?>
    <div class="cd-d"><?php print $description; ?></div>
  </div>
  <?php endif; ?>
  <?php if (isset($link)): ?>
    </a>
  <?php endif; ?>
</div>
