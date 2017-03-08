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

<nav class="nv-m">
  <div class="nv-m-h">
      <div class="nv-m-h-ic">
        <img src="<?php print $asset_url ?>/images/b-dark.svg" title="B" aria-hidden="true" class="nv-m-h-i" />
      </div>
      <div id="nv-m-h-t" class="nv-m-h-t">&nbsp;</div>
  </div>
  <div class="nv-m-c">
    <?php print render($page['navigation']); ?>
  </div>
</nav>

<script>
  'use strict'

  var BostonMenu = (function () {
    // Set height
    var secondaryNavs;
    var secondaryTriggers;
    var listItems;
    var secondaryNavItems;
    var backTriggers;
    var burger;

    function handleBurgerChange(ev) {
      document.body.classList.toggle('no-s');
    }

    function handleTrigger(ev, method) {
      var backTrigger;
      var secondaryNav;
      var trigger = ev.target;
      var parentItem = method === 'reset' ? trigger.parentNode.parentNode.parentNode : trigger.parentNode;
      var title = document.getElementById('nv-m-h-t');

      // Find the secondary nav and trigger
      parentItem.childNodes.forEach(function(child) {
        if (child.classList && child.classList.contains('nv-m-c-l-l')) {
          secondaryNav = child;
        }

        if (child.classList && child.classList.contains('nv-m-c-a')) {
          trigger = child;
        }
      });

      // Find the backTrigger
      secondaryNav.childNodes.forEach(function(child) {
        if (child.classList && child.classList.contains('nv-m-c-bc')) {
          backTrigger = child;
        }
      });

      if (method === 'nav') {
        // Hide all the other menu items
        listItems.forEach(function(listItem) {
          if (parentItem != listItem) {
            listItem.classList.add('nv-m-c-l-i--h');
          }
        });

        // Hide the trigger
        trigger.classList.add('nv-m-c-a--h');

        // Show the secondary nav
        secondaryNav.classList.remove('nv-m-c-l-l--h');

        // Show the back button
        backTrigger.classList.remove('nv-m-c-b--h');

        // Update the title
        title.innerHTML = trigger.innerHTML;
      } else {
        // Hide all the other menu items
        listItems.forEach(function(listItem) {
          if (parentItem != listItem) {
            listItem.classList.remove('nv-m-c-l-i--h');
          }
        });

        // Hide the trigger
        trigger.classList.remove('nv-m-c-a--h');

        // Show the secondary nav
        secondaryNav.classList.add('nv-m-c-l-l--h');

        // Show the back button
        backTrigger.classList.add('nv-m-c-b--h');

        // Update the title
        title.innerHTML = '&nbsp;';
      }
    }

    function start() {
      burger = document.getElementById('brg-tr');
      listItems = document.querySelectorAll('.nv-m-c-l-i');
      backTriggers = document.querySelectorAll('.nv-m-c-b');
      secondaryTriggers = document.querySelectorAll('.nolink');
      secondaryNavs = document.querySelectorAll('.nv-m-c-l-l');
      secondaryNavItems = document.querySelectorAll('.nv-m-c-a--s');

      // Set the secondary navigation menus to hidden
      secondaryNavs.forEach(function(nav) {
        nav.classList.add('nv-m-c-l-l--h');
      });

      // Get the secondary navigation triggers ready
      secondaryTriggers.forEach(function(trigger) {
        // Set to active
        trigger.classList.add('nolink--a');

        // Handle clicks
        trigger.addEventListener('click', function(ev) {
          ev.preventDefault();

          handleTrigger(ev, 'nav');
        });
      });

      // Get the secondary navigation triggers ready
      backTriggers.forEach(function(trigger) {
        // Handle clicks
        trigger.addEventListener('click', function(ev) {
          ev.preventDefault();

          handleTrigger(ev, 'reset');
        });
      });

      // Set the secondary navigation menus to hidden
      secondaryNavItems.forEach(function(nav) {
        nav.classList.remove('nv-m-c-a--s');
        nav.classList.add('nv-m-c-a--p');
      });

      if (burger) {
        burger.addEventListener('change', handleBurgerChange);
      }
    }

    return {
      start: start
    }
  })()

  BostonMenu.start()
</script>

<div <?php if (!empty($node) && ($node->type !== 'tabbed_content' && $node->type !== 'how_to')): ?>class="page"<?php endif; ?> id="page">
  <header id="main-menu" class="header" role="banner" data-swiftype-index="false">
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

  <div class="main">
    <div class="container">
      <section class="main-content" id="content" role="main">
        <?php print render($page['highlighted']); ?>
        <a href="#skip-link" class="visually-hidden--focusable" id="main-content" data-swiftype-index="false">Back to top</a>
        <?php if (!isset($header_image) || (!empty($node) && ($node->type == 'tabbed_content' || $node->type == 'how_to'))): ?>
          <?php if ($breadcrumb): ?>
            <div id="breadcrumb" data-swiftype-index="false"><?php print $breadcrumb; ?></div>
          <?php endif; ?>
        <?php endif; ?>
        <?php print render($title_prefix); ?>
        <?php if ($title): ?>
          <h1 class="page-title"><?php print $title; ?></h1>
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
