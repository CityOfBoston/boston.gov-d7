<!DOCTYPE html>
<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>

  <link href='https://fonts.googleapis.com/css?family=Lora:400,700,400italic,700italic|Montserrat:400,700' rel='stylesheet' type='text/css'>

  <!--[if !IE]><!-->
	<link href='<?php print $asset_url ?>/css/<?php print $asset_name ?>.css' rel='stylesheet' type='text/css'>
  <!--<![endif]-->
  <!--[if lt IE 10]>
    <link href='<?php print $asset_url ?>/css/ie.css' rel='stylesheet' type='text/css'>
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
    <p class="skip-link__wrapper">
      <a href="#<?php print $skip_link_anchor; ?>" class="skip-link visually-hidden--focusable" id="skip-link"><?php print $skip_link_text; ?></a>
    </p>
  <?php endif; ?>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>
