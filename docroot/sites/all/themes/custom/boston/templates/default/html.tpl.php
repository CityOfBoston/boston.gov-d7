<!DOCTYPE html>
<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>

  <?php if ($google_tag_manager_id) { ?>
    <script>(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':
    new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],
    j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src=
    'https://www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);
    })(window,document,'script','dataLayer','<?php echo $google_tag_manager_id ?>');</script>
  <?php } ?>

  <link href='https://fonts.googleapis.com/css?family=Lora:400,700,400italic,700italic|Montserrat:400,700' rel='stylesheet' type='text/css'>

  <!--[if !IE]><!-->
	<link href='<?php print $asset_url ?>/css/<?php print $asset_name ?>.css?<?php print $cache_buster ?>' rel='stylesheet' type='text/css'>
  <!--<![endif]-->
  <!--[if lt IE 10]>
    <link href='<?php print $asset_url ?>/css/ie.css?<?php print $cache_buster ?>' rel='stylesheet' type='text/css'>
  <![endif]-->

  <?php if ($default_mobile_metatags): ?>
    <meta name="viewport" content="width=device-width, initial-scale=1">
  <?php endif; ?>

  <?php print $styles; ?>
  <?php print $scripts; ?>

  <!--[if IE 9]>
  <link href='<?php print $base_path . path_to_theme(); ?>/dist/ie/shame.css' rel='stylesheet' type='text/css'>
  <script src="<?php print $base_path . path_to_theme(); ?>/dist/ie/flexibility.js"></script>
  <script src="<?php print $base_path . path_to_theme(); ?>/dist/ie/classList.js"></script>
  <script src="<?php print $base_path . path_to_theme(); ?>/dist/ie/cors.js"></script>
  <![endif]-->
  <?php if ($add_html5_shim): ?>
    <!--[if lt IE 9]>
    <script src="<?php print $base_path . path_to_theme(); ?>/bower_components/html5shiv/dist/html5shiv.min.js"></script>
    <![endif]-->
  <?php endif; ?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php if ($skip_link_text && $skip_link_anchor): ?>
    <p class="skip-link__wrapper" data-swiftype-index="false">
      <a href="#<?php print $skip_link_anchor; ?>" class="skip-link visually-hidden--focusable" id="skip-link"><?php print $skip_link_text; ?></a>
    </p>
  <?php endif; ?>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
  <script src="<?php print $asset_url ?>/scripts/all.js?<?php print $cache_buster ?>" async></script>
  <?php if ($google_tag_manager_id) { ?>
    <noscript><iframe src="https://www.googletagmanager.com/ns.html?id=<?php echo $google_tag_manager_id ?>&noscript=true"
  height="0" width="0" style="display:none;visibility:hidden"></iframe></noscript>
  <?php } ?>
  <script id="contactFormTemplate" type="text/x-template">
    <div class="md">
      <div class="md-c">
        <button class="md-cb">Close</button>
        <div class="mb-b p-a300 p-a600--xl">
          <div class="sh m-b500">
            <div class="sh-title">Contact the City&nbsp;of&nbsp;Boston</div>
          </div>
          <div class="t--info m-b500">Our site is live, but not completed. We'll always be adding to and improving on it and need your ideas and to make Boston.gov easier to understand and more delightful to use.</div>
          <form class="https://www.boston.gov" action="https://www.boston.gov" method="GET">
            <div class="fs">
              <div class="fs-c">
                <div class="txt m-b300">
                  <label for="text" class="txt-l txt-l--mt000">First Name</label>
                  <input id="text" type="text" value="" placeholder="Zip Code" class="txt-f txt-f--sm" size="10">
                </div>
                <div class="txt m-b300">
                  <label for="text" class="txt-l txt-l--mt000">Email Address</label>
                  <input id="text" type="text" value="" placeholder="Email address" class="txt-f txt-f--sm">
                </div>
                <div class="txt m-b300">
                  <label for="text" class="txt-l txt-l--mt000">Subject</label>
                  <input id="text" type="text" value="" placeholder="Zip Code" class="txt-f txt-f--sm" size="10">
                </div>
                <div class="txt m-b300">
                  <label for="text" class="txt-l txt-l--mt000">Message</label>
                  <textarea id="text" type="text" value="" placeholder="Zip Code" class="txt-f txt-f--sm" rows="10"></textarea>
                </div>
              </div>
              <div class="bc bc--r p-t500">
                <button type="submit" class="btn btn--700">Sign Up</button>
              </div>
            </div>
          </form>
        </div>
      </div>
    </div>
  </script>
</body>
</html>
