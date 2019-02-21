<?php if ($site_name): ?>
  <div class="lo lo--abs">
    <div class="lo-b">
      <div class="the-b">
        <a href="<?php print $front_page; ?>">
          <img src="<?php print $asset_url ?>/images/b-light.svg?<?php print $cache_buster ?> alt="B Logo" class="the-b-i"  />
        </a>
      </div>
    </div>
    <div class="lo-l">
      <a href="<?php print $front_page; ?>">
        <img src="<?php print $asset_url ?>/images/<?php print $asset_name ?>/logo.svg?<?php print $cache_buster ?>" alt="<?php print $site_name; ?>" class="lo-i" />
      </a>
      <?php if (!$hide_logo) { ?>
        <span class="lo-t"><a href="https://www.boston.gov/mayor">Mayor Martin J. Walsh</a></span>
      <?php } ?>
    </div>
  </div>
<?php endif; ?>
