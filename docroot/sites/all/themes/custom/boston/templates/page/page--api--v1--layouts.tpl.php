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

<input type="checkbox" id="brg-tr" class="brg-tr" aria-hidden="true" />
<nav class="nv-m">
  <div class="nv-m-h">
      <div class="nv-m-h-ic">
        <a href="/" title="Go to home page">
          <img src="<?php print $asset_url ?>/images/b-dark.svg" title="B" aria-hidden="true" class="nv-m-h-i" />
        </a>
      </div>
      <div id="nv-m-h-t" class="nv-m-h-t">&nbsp;</div>
  </div>
  <div class="nv-m-c">
    <?php print render($page['navigation']); ?>
  </div>
  <?php print theme('nav_js'); ?>
</nav>
<div class="page" id="page">
  <header id="main-menu" class="header" role="banner">
    <div class="container">
      <label tabindex="0" for="brg-tr" class="nav-trigger" type="button" aria-label="Menu" aria-controls="navigation"  aria-expanded="false">
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
        <div class="ext-c">
          <a href="#skip-link" class="visually-hidden--focusable" id="main-content">Back to top</a>
          <?php if (!isset($header_image) || !empty($node) && $node->type == 'how_to'): ?>
            <?php if ($breadcrumb): ?>
              <div class="breadcrumb">
                <a href="/">Home</a>
                <span class="crumbs-separator"> &gt; </span>
                Search
              </div>
            <?php endif; ?>
          <?php endif; ?>
          <%= yield %>
        </div>
      </section>
    </div>
  </div>
  <?php print render($page['footer']); ?>
</div>

<?php print render($page['bottom']); ?>
