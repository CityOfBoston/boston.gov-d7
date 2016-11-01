<?php
  $sso_link = variable_get('sso_login_url', FALSE);
?>

<?php if ($sso_link) { ?>
  <?php if(isset($_GET['local'])) { ?>
    <?php print drupal_render_children($form) ?>
  <?php } else { ?>
    <div style="margin: 50px 0 200px">
      <div class="content"<?php print $content_attributes; ?>>
        <div class="sh">
          <h2 class="component-title">Login</h2>
        </div>
        <div>
          <?php if($sso_link) { ?>
            <a href="<?php echo $sso_link; ?>" title="Login via The Hub" class="button">Login via The Hub</a>
          <?php } else { ?>
            <a href="/user?local" title="Login" class="button">Login</a>
          <?php } ?>
        </div>
      </div>
    </div>

    <style>
      .page-title {
        display: none;
      }

      .tabs.primary {
        display: none;
      }
    </style>
  <?php } ?>
<?php } else { ?>
  <?php print drupal_render_children($form) ?>
<?php } ?>
