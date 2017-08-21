<?php
/**
 * @file
 * Default implementation for page contacts.
 *
 * Available variables:
 * - $title: The title of the contacts section.
 * - $short_title: The short title associated with the section.
 * - $contacts: A renderable array for outputting all contacts.
 */
?>
<section class="b b--g b--fw">
  <div class="b-c">
    <div class="sh m-b500">
      <h2 data-short-title="Departments" class="sh-title"><?php print $title; ?>:</h2>
    </div>
    <div class="g">
      <?php print render($contacts); ?>
    </div>
    <!-- End .departments-wrapper -->
  </div>
  <!-- End topic-departments-container -->
</section><!-- End departments-container -->
