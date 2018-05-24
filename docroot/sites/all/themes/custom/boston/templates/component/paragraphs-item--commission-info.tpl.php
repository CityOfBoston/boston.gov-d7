<?php
# We allow you to hide the contact info part so that this component
# can be integrated into department pages that have their own
# contact info.
if ($content['field_show_contact_info']['#items'][0]['value'] == '1') {
?>
<div class="article-contact">
  <address>
    <h5 class="contact-title">
      <?php if ($content['department_url']) { ?>
        <a href="<?php print render($content['department_url']); ?>">
          <?php print render($content['department_name']); ?>
        </a>
      <?php } else { ?>
        <?php print render($content['department_name']); ?>
      <?php } ?>
    </h5>
    <?php if (isset($content['contact_email'])): ?>
      <div class="list-item">
        <?php 
          $name = check_plain($content['contact_name']);
          $email =check_plain($content['contact_email']);
          $detail_item_variables = array(
            'label' => NULL,
            'body' => "$name<br/><a href='mailto:$email' title='Have a question, or just need help? You can send an email to $email through the form below.'>$email</a>",
            'classes' => array(
              'detail' => 'detail-item--middle',
              'icon' => 'icon-email',
              'body' => 'detail-item__body--secondary',
            ),
          );
          print theme('detail_item', $detail_item_variables);
        ?>
      </div>
    <?php endif; ?>
  </address>
</div>
<?php
}
?>

<?php
$detail_item_classes = array(
  'detail' => 'detail-item--secondary',
  'body' => 'detail-item__body--secondary',
);
?>

<div class="list-item">
  <?php
  print theme('detail_item', array(
    'label' => 'Authority:',
    'body' => check_plain($content['authority']),
    'classes' => $detail_item_classes,
  ));
  ?>
</div>

<div class="list-item">
  <?php
  print theme('detail_item', array(
    'label' => 'Term:',
    'body' => check_plain($content['term']),
    'classes' => $detail_item_classes,
  ));
  ?>
</div>

<div class="list-item">
  <?php
  print theme('detail_item', array(
    'label' => 'Stipend:',
    'body' => check_plain($content['stipend']),
    'classes' => $detail_item_classes,
  ));
  ?>
</div>

<div class="list-item">
  <?php
  print theme('detail_item', array(
    'label' => 'Seats:',
    'body' => check_plain($content['seats']),
    'classes' => $detail_item_classes,
  ));
  ?>
</div>

<div class="list-item">
  <?php
  $link = check_plain($content['enabling_legislation_url']);
  print theme('detail_item', array(
    'label' => 'Resources:',
    'body' => <<<EOF
<div class="link-wrapper external-link">
  <a href="$link"
     target="_blank">
     Enabling legislation
  </a>
</div>
EOF
,
    'classes' => array(
      'body' => 'detail-item__body--secondary',
    ),
  ));
  ?>
</div>
