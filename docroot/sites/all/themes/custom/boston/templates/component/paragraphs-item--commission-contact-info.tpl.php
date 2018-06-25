<div class="article-contact">
  <address>
    <h5 class="contact-title">
      Contact Information
    </h5>
    <div class="t--subinfo m-b300" style="text-transform: none; letter-spacing: 0;">
      If you have questions, please email or call:
    </div>
    <?php if ($content['contact_email']): ?>
      <div class="list-item">
        <?php 
          $name = check_plain($content['contact_name']);
          $email = check_plain($content['contact_email']);
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

    <?php if ($content['contact_phone']): ?>
      <div class="list-item">
        <?php 
          $phone = check_plain($content['contact_phone']);
          $detail_item_variables = array(
            'label' => NULL,
            'body' => "<a href='tel:$phone'>$phone</a>",
            'classes' => array(
              'detail' => 'detail-item--middle',
              'icon' => 'icon-phone',
              'body' => 'detail-item__body--secondary',
            ),
          );
          print theme('detail_item', $detail_item_variables);
        ?>
      </div>
    <?php endif; ?>
  </address>
</div>
