<div class="article-contact">
  <address>
    <?php if ($content['department_name']) { ?>
      <h5 class="contact-title">
        <?php if ($content['department_url']) { ?>
          <a href="<?php print render($content['department_url']); ?>">
            <?php print render($content['department_name']); ?>
          </a>
        <?php } else { ?>
          <?php print render($content['department_name']); ?>
        <?php } ?>
      </h5>
    <?php } ?>
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
  </address>
</div>
