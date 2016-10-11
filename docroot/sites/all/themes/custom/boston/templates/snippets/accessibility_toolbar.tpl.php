<input type="checkbox" id="tb__trigger" class="tb__trigger" aria-hidden="true" />

<?php if(!empty($accessibilityMenu)) { ?>
  <div id="tb" class="tb">
    <div class="tb__internal">
      <div class="tb__block">
        <div class="tb__title">Accessibility</div>
        <div class="tb__inline">
          <?php print theme('links', array(
            'links' => $accessibilityMenu
          )); ?>
        </div>
      </div>
      <?php if(!empty($translationMenu)) { ?>
        <div class="tb__block tb__right">
          <div class="tb__title">Language</div>
          <input type="checkbox" id="dd__menu__box" class="dd__input">
          <div class="dd" aria-expanded="false">
            <label class="dd__trigger" for="dd__menu__box">
              <span class="dd__trigger__button" id="menu-link" aria-haspopup="true" aria-owns="menu-translation">Select</span>
              <span class="dd__trigger__icon">
                <?php print file_get_contents(drupal_get_path('theme', $GLOBALS['theme']) . '/dist/img/subnav-toggle.svg') ?>
              </span>
            </label>
            <div class="dd__menu" id="menu-translation" role="group" aria-labelledby="menu-link">
              <?php print theme('links', array(
                'links' => $translationMenu
              )); ?>
            </div>
          </div>
        </div>
      <?php } ?>
    </div>
    <label tabindex="0" class="tb__dingus" for="tb__trigger" type="button" aria-label="Acccessibility Toolbar" aria-controls="navigation"  aria-expanded="false">
      <?php print file_get_contents(drupal_get_path('theme', $GLOBALS['theme']) . '/dist/img/icon-gear.svg') ?></span>
    </label>
  </div>
<?php } ?>
