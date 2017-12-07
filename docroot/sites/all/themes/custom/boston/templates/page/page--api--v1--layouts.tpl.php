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
</nav>
<div class="page mn" id="page">
  <input type="checkbox" id="s-tr" class="s-tr" aria-hidden="true">
  <header id="main-menu" class="h" role="banner" data-swiftype-index="false">
    <?php print theme('burger'); ?>
    <?php print theme('logo', $site_info); ?>
    <?php print theme('seal', $site_info); ?>
    <?php print theme('search', array('search_form_url' => '/search')); ?>
    <?php print render($page['header']); ?>
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
