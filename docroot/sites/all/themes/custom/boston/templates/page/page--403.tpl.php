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
  <header id="main-menu" class="h" role="banner" data-swiftype-index="false">
    <?php print theme('burger'); ?>
    <?php print theme('logo', $site_info); ?>
    <?php print theme('seal', $site_info); ?>
    <?php print theme('secondary_nav', array(
      'secondary_menu' => $nav_menu,
      'asset_url' => $asset_url,
      'profile_path' => $profile_path,
      'profile_title' => $profile_title,
      'change_password_path' => $change_password_path,
      'change_password_title' => $change_password_title,
      'security_questions_path' => $security_questions_path,
      'security_questions_title' => $security_questions_title,
      'logout_path' => $logout_path,
      'logout_title' => $logout_title,
      'first_name' => $first_name,
    )); ?>
    <?php print theme('search', array('search_form_url' => variable_get('hub_search_url'),)); ?>
  </header>
  <div class="container">
    <section class="main-content err-content" id="content" role="main">
      <div class="denied-text error-text column desktop-66-left">
        <h1><?php print $title; ?></h1>
        <?php print token_replace('[boston:403-page-text]'); ?>
      </div>
    </section>
  </div>
</div>
