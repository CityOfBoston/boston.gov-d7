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

<input type="checkbox" id="hb__trigger" class="hb__trigger" aria-hidden="true" />
<div class="main-navigation">
  <div class="main-navigation-wrapper">
    <div class="main-navigation-title"></div>
    <?php print render($page['navigation']); ?>
  </div>
</div>
<div class="page" id="page">
  <header id="main-menu" class="header" role="banner">
    <div class="container">
      <label tabindex="0" for="hb__trigger" class="nav-trigger" type="button" aria-label="Menu" aria-controls="navigation"  aria-expanded="false">
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
            <span class="lo-t">Mayor Martin J. Walsh</span>
          </a>
        </div>
      <?php endif; ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="s">
        <img src="<?php print $asset_url ?>/images/<?php print $asset_name ?>/seal.svg?<?php print $cache_buster ?>" alt="City of Boston Seal" class="s-i" />
      </a>
      <div class="tr">
        <a href="#" class="tr-link">Translate</a>
        <ul class="tr-dd">
          <li><span class="notranslate tr-dd-link tr-dd-link--message">Loading...</span></li>
          <li><a href="#" class="notranslate tr-dd-link" data-ln="ht">Kreyòl Ayisyen</a></li>
          <li><a href="#" class="notranslate tr-dd-link" data-ln="pt">Portugese</a></li>
          <li><a href="#" class="notranslate tr-dd-link" data-ln="es">Español</a></li>
          <li><a href="#" class="notranslate tr-dd-link" data-ln="vi">Tiếng Việt</a></li>
          <li><a href="#" class="notranslate tr-dd-link tr-dd-link--hidden" data-ln="en">English</a></li>
        </ul>
      </div>
      <?php print theme('links__system_secondary_menu', array(
        'links' => $secondary_menu,
        'attributes' => array(
          'class' => array('header-menu', 'links', 'inline', 'clearfix')
        ),
      )); ?>
      <?php print render($page['header']); ?>
    </div>
  </header>
  <?php
  /**
   *
   * We'll use this container to load external content
   */
  ?>
  <div class="main">
    <div class="container">
      <section class="main-content" id="content" role="main">
        <%= yield %>
      </section>
    </div>
  </div>
  <?php print render($page['modal']); ?>
  <?php print render($page['footer']); ?>
</div>

<?php print render($page['bottom']); ?>
