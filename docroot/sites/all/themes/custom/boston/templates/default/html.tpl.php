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

  <!--[if !IE]><!-->
	<link href='<?php print $asset_url ?>/css/<?php print $asset_name ?>.css?<?php print $cache_buster ?>' rel='stylesheet' type='text/css'>
    <link href='<?php print $asset_url ?>/legacy/<?php print $asset_name ?>.css?<?php print $cache_buster ?>' rel='stylesheet' type='text/css'>
  <!--<![endif]-->
  <!--[if lt IE 10]>
    <link href='<?php print $asset_url ?>/css/ie.css?<?php print $cache_buster ?>' rel='stylesheet' type='text/css'>
  <![endif]-->

<!--   <link href='https://localhost:3030/css/print.css?--><?php //print $cache_buster ?><!--' rel="stylesheet" type="text/css" media="print">-->

  <?php if ($default_mobile_metatags): ?>
    <meta name="viewport" content="width=device-width, initial-scale=1">
  <?php endif; ?>

  <?php print $styles; ?>
  <?php print $scripts; ?>

  <!--[if IE 9]>
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
  <?php if ($asset_name !== 'hub'): ?>
    <script id="contactFormTemplate" type="text/x-template">
      <div class="md">
        <div class="md-c">
          <button class="md-cb">Close</button>
          <div class="mb-b p-a300 p-a600--xl">
            <div class="sh m-b500">
              <div class="sh-title">Contact Us</div>
            </div>
            <div>
              <div id="contactMessage" class="t--info m-b500">Have a question, or just need help? You can send an email through the form below.</div>
              <form id="contactForm" action="<?php print $contact_url; ?>" method="POST">
                <input id="contactFormToAddress" name="email[to_address]" type="hidden" value="">
                <input id="contactFormURL" name="email[url]" type="hidden" value="">
                <input id="contactFormBrowser" name="email[browser]" type="hidden" value="">
                <div class="fs">
                  <div class="fs-c">
                    <div class="txt m-b300">
                      <label for="contact-name" class="txt-l txt-l--mt000">Full Name</label>
                      <input id="contact-name" name="email[name]" type="text" class="txt-f bos-contact-name" size="10" value="">
                    </div>
                    <div class="txt m-b300">
                      <label for="contact-address" class="txt-l txt-l--mt000">Email Address</label>
                      <input id="contact-address" name="email[from_address]" type="text" placeholder="email@address.com" class="txt-f bos-contact-email" value="">
                    </div>
                    <div class="txt m-b300">
                      <label for="contact-subject" class="txt-l txt-l--mt000">Subject</label>
                      <input id="contact-subject" name="email[subject]" type="text" class="txt-f bos-contact-subject" size="10" value="">
                    </div>
                    <div class="txt m-b300">
                      <label for="contact-message" class="txt-l txt-l--mt000">Message</label>
                      <textarea id="contact-message" name="email[message]" type="text" class="txt-f bos-contact-message" rows="10"></textarea>
                    </div>
                  </div>
                  <div class="bc bc--r p-t500">
                    <button type="submit" class="btn btn--700">Send Message</button>
                  </div>
                </div>
              </form>
            </div>
          </div>
        </div>
      </div>
    </script>
  <?php endif; ?>
</body>
</html>
