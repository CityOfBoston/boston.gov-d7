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
<div class="grid-card <?php print $classes; ?>">
  <?php if (isset($link)): ?>
    <a href="<?php print $link; ?>">
  <?php endif; ?>
  <?php if (isset($image)): ?>
  <div class="grid-card__image">
    <?php print $image; ?>
  </div>
  <?php endif; ?>
  <div class="grid-card__text">
    <h3 class="grid-card__title">
      <?php print $title; ?>
    </h3>
    <?php if (isset($subtitle)): ?>
    <div class="grid-card__subtitle">
      <?php print $subtitle; ?>
    </div>
    <?php endif; ?>
    <?php if (isset($description)): ?>
    <div class="grid-card__description">
      <?php print $description; ?>
    </div>
  </div>
  <?php endif; ?>
  <?php if (isset($link)): ?>
    </a>
  <?php endif; ?>
</div>
