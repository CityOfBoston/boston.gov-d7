<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 *
 * @see https://drupal.org/node/1728148
 */
?>
<div class="main err err--403">
  <div class="container">
    <section class="main-content err-content" id="content" role="main">
      <div class="denied-text error-text column desktop-66-left">
        <h1><?php print $title; ?></h1>
        <?php print token_replace('[boston:403-page-text]'); ?>
      </div>
    </section>
  </div>
</div>
