<!DOCTYPE html>
<head>
  <?php print $head; ?>
  <title>{{ title }}</title>
  <!--[if !IE]><!-->
	<link href='<?php print $asset_url ?>/css/<?php print $asset_name ?>.css?<?php print $cache_buster ?>' rel='stylesheet' type='text/css'>
  <!--<![endif]-->
  <!--[if lt IE 10]>
    <link href='<?php print $asset_url ?>/css/ie.css?<?php print $cache_buster ?>' rel='stylesheet' type='text/css'>
  <![endif]-->
  <?php if ($default_mobile_metatags): ?>
    <meta name="viewport" content="width=device-width, initial-scale=1">
  <?php endif; ?>
</head>
<body>
  <?php print $page; ?>
</body>
</html>
