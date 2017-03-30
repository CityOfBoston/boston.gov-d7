<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 *
 * @see https://drupal.org/node/1728148
 */

 $avatar_email = $field_work_email != '' ? $field_work_email : 'default@boston.gov';
?>

<input type="checkbox" id="brg-tr" class="brg-tr" aria-hidden="true" />

<nav class="nv-m">
  <div class="nv-m-h">
    <div class="nv-m-h-ic">
      <img src="<?php print $asset_url ?>/images/hub/seal.svg" title="The Hub" aria-hidden="true" class="nv-m-h-i" />
    </div>
    <div id="nv-m-h-t" class="nv-m-h-t">Menu</div>
  </div>
  <div class="nv-m-c">
    <?php print render($page['navigation']); ?>
  </div>
  <?php print theme('nav_js'); ?>
</nav>

<div <?php if ($page_class): ?>class="<?php print $page_class; ?>"<?php endif; ?> id="page">
  <header class="header" role="banner">
    <div class="header-container">

      <label for="brg-tr" class="nav-trigger" type="button" aria-label="Menu" aria-controls="navigation" aria-expanded="false">
        <div class="hb">
          <span class="hb__box">
            <span class="hb__inner"></span>
          </span>
          <span class="hb__label">Menu</span>
        </div>
      </label>

      <?php if ($site_name): ?>
        <div class="lo lo--abs">
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="lo-l">
            <img src="<?php print $asset_url ?>/images/<?php print $asset_name ?>/logo.svg?<?php print $cache_buster ?>" alt="<?php print $site_name; ?>" class="lo-i" />
          </a>
        </div>
      <?php endif; ?>

      <a id="seal" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="s">
        <img src="<?php print $asset_url ?>/images/<?php print $asset_name ?>/seal.svg?<?php print $cache_buster ?>" alt="City of Boston Seal" class="s-i" />
      </a>

      <div class="header-right">
        <?php print theme('links__system_secondary_menu', array(
          'links' => $secondary_menu,
          'attributes' => array(
            'class' => array('header-menu', 'links', 'inline', 'clearfix'),
          ),
        )); ?>
        <?php if ($logged_in): ?>
          <div class="user_info">
            <input type="checkbox" id="dd__menu__box" class="dd__input">
            <div class="dd" aria-expanded="false">
              <label class="dd__trigger user-menu-trigger" for="dd__menu__box">
                <span id="menu-link" aria-haspopup="true" aria-owns="menu-translation">
                  <div class="avatar-wrapper" style="background-image: url(//cob-avatars.herokuapp.com/photos/<?php print base64_encode($avatar_email); ?>)">User Menu</div>
                </span>
              </label>
              <div class="dd__menu menu-user" id="menu-user" role="group" aria-labelledby="menu-link">
                <ul>
                  <li>
                    <a href="<?php print $profile_path; ?>" title="Visit my profile">
                      My Profile
                    </a>
                  </li>
                  <li>
                    <a href="<?php print $change_password_path; ?>" title="Change password">
                      Change password
                    </a>
                  </li>
                  <li>
                    <a href="<?php print $logout_path; ?>" title="log out">
                      Log Out
                    </a>
                  </li>
                </ul>
              </div>
            </div>
          </div>
        <?php endif; ?>
        <?php print render($page['header']); ?>
      </div>

    </div>
  </header>

  <div id="sa" data-target="<?php print $target_id; ?>" data-classes="<?php print $page_class_alert ?>" class="d--n"></div>
  <?php print theme('alert_js'); ?>

  <div class="main">
    <div class="container">
      <section class="main-content" id="content" role="main">
        <?php print render($page['highlighted']); ?>
        <a href="#skip-link" class="visually-hidden--focusable" id="main-content" data-swiftype-index="false">Back to top</a>
        <?php if (!isset($header_image) || (!empty($node) && ($node->type == 'tabbed_content' || $node->type == 'how_to'))): ?>
          <?php if ($breadcrumb): ?>
            <div id="breadcrumb" class="breadcrumb-outter" data-swiftype-index="false"><?php print $breadcrumb; ?></div>
          <?php endif; ?>
        <?php endif; ?>
        <?php print render($title_prefix); ?>
        <?php if ($title): ?>
          <h1 class="page-title" data-swiftype-name="title" data-swiftype-type="string"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php print $messages; ?>
        <?php print render($tabs); ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
        <?php if (isset($header_image)): ?>
          <?php if (!empty($node) && ($node->type !== 'tabbed_content' && $node->type !== 'how_to')): ?>
            <div class="hero-image fullwidth">
              <div class="hero-image-wrapper <?php print $hero_classes; ?>">
                <?php print render($header_image); ?>
              </div>
            </div>
          <?php endif; ?>
          <?php if (!empty($node) && ($node->type !== 'tabbed_content' && $node->type !== 'how_to')): ?>
            <?php if ($breadcrumb): ?>
              <div id="breadcrumb" class="breadcrumb-wrapper with-hero" data-swiftype-index="false"><?php print $breadcrumb; ?></div>
            <?php endif; ?>
          <?php endif; ?>
        <?php endif; ?>

        <?php print render($page['content']); ?>
        <?php print $feed_icons; ?>
      </section>

    </div>
  </div>
  <?php print render($page['modal']); ?>
  <?php print render($page['footer']); ?>

</div>

<?php print render($page['bottom']); ?>
