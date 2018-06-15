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
          <img src="<?php print $asset_url ?>/images/b-dark.svg" alt="City of Boston" aria-hidden="true" class="nv-m-h-i" />
        </a>
      </div>
      <div id="nv-m-h-t" class="nv-m-h-t">&nbsp;</div>
  </div>
  <div class="nv-m-c">
    <?php print render($page['navigation']); ?>
  </div>
</nav>

<div <?php if (isset($page_class)): ?>class="<?php print $page_class; ?> mn"<?php endif; ?> id="page">
  <input type="checkbox" id="s-tr" class="s-tr" aria-hidden="true">
  <header id="main-menu" class="h" role="banner" data-swiftype-index="false">
    <?php print theme('burger'); ?>
    <?php print theme('logo', $site_info); ?>
    <?php print theme('seal', $site_info); ?>
    <?php print theme('secondary_nav', array('secondary_menu' => $secondary_menu)); ?>
    <?php print theme('search', array('search_form_url' => '/search')); ?>
  </header>

  <div id="sa" data-target="<?php print $target_id; ?>" data-classes="<?php print $page_class_alert ?>  mn" class="d--n"></div>
  <?php print theme('alert_js'); ?>

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
        <?php if ($title && !$hide_page_title): ?>
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
            <?php if ($node->type !== 'topic_page'): ?>
              <style>
                .hro {
                  background-image: url(<?php print $small_image ?>);
                }

                @media screen and (min-width: 768px) {
                  .hro {
                    background-image: url(<?php print $medium_image ?>);
                  }
                }

                @media screen and (min-width: 1024px) {
                  .hro {
                    background-image: url(<?php print $large_image ?>);
                  }
                }

                @media screen and (min-width: 1200px) {
                  .hro {
                    background-image: url(<?php print $xlarge_image ?>);
                  }
                }
              </style>
              <div class="b b--fw">
                <div class="hro hro--pt hro--pb"></div>
              </div>
            <?php else: ?>
              <div class="hero-image fullwidth">
                <div class="hero-image-wrapper <?php print $hero_classes; ?>">
                  <?php print render($background_image); ?>
                </div>
              </div>
            <?php endif; ?>
          <?php endif; ?>
          <?php if (!empty($node) && ($node->type !== 'tabbed_content' && $node->type !== 'how_to')): ?>
            <?php if ($breadcrumb): ?>
              <div<?php if (isset($header_image)): ?> class="brc--wh"<?php endif; ?> data-swiftype-index="false"><?php print $breadcrumb; ?></div>
            <?php endif; ?>
          <?php endif; ?>
        <?php endif; ?>

        <?php print render($page['content']); ?>
        <?php print $feed_icons; ?>
      </section>

    </div>
  </div>
  <?php print render($page['footer']); ?>
</div>

<?php print render($page['bottom']); ?>
