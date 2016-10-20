<?php
/**
 * @file
 * Returns the HTML for the basic html structure of a single Drupal page.
 *
 * Complete documentation for this file is available online.
 *
 * @see https://drupal.org/node/1728208
 */
?><!DOCTYPE html>
<!--[if lte IE 8]><html class="lt-ie9" <?php print $html_attributes; ?>><![endif]-->
<!--[if (gte IE 9)|(gt IEMobile 7)]><!--><html <?php print $html_attributes . $rdf_namespaces; ?>><!--<![endif]-->

<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>

  <link href='https://fonts.googleapis.com/css?family=Lora:400,700,400italic,700italic|Montserrat:400,700' rel='stylesheet' type='text/css'>

  <?php if ($default_mobile_metatags): ?>
    <meta name="viewport" content="width=device-width, initial-scale=1">
  <?php endif; ?>

  <?php print $styles; ?>
  <?php print $scripts; ?>

  <script src="https://www.microsoftTranslator.com/ajax/v3/WidgetV3.ashx?siteData=ueOIGRSKkd965FeEGM5JtQ**" type="text/javascript"></script>

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
