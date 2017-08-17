<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 *
 * @see https://drupal.org/node/1728164
 */
?>

<a href="<?php print $transaction_url; ?>" class="cd m-t400 cd--e">
  <div class="cd-c">
    <div class="g">
      <div class="g--4">
        <div class="cd-t"><?php print $title; ?></div>
      </div>
      <div class="g--8">
        <div class="p-r700">
          <div class="cd-d cd-d--mt0"><?php print render($content['field_description']); ?></div>
        </div>
      </div>
    </div>
  </div>
</a>
