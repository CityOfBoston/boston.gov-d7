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
<?php 
	$sso_link = variable_get('sso_login_url', FALSE);
?>
<style>
@media (max-width: 980px){
  .error-text h1{
    padding: 3rem 0 0;
  }
}

</style>
<div class="main err err--403">
  <?php include drupal_get_path('theme', 'boston') . '/templates/snippets/header.tpl.php'; ?>
  <div class="container">
    <section class="main-content err-content" id="content" role="main">
      <div class="denied-text error-text column desktop-66-left">
        <h1>login required</h1>
        <?php //print token_replace('[boston:403-page-text]'); ?>
        <p><em>Please log in through the button below:</em></p>
        <?php if($sso_link) : ?>
            <a href="<?php echo $sso_link; ?>" title="Login" class="button">Login</a>
        <?php else:  ?>
            <a href="/user?local" title="Login" class="button">Login</a>
        <?php endif; ?>
      </div>
    </section>
  </div>
</div>
