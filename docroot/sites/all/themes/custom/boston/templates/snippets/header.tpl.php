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
