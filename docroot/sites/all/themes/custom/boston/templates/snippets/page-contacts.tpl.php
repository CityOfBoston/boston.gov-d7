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
<section class="contact-departments component-section">
  <div class="contact-departments-container container">
    <div class="sh">
      <h2 data-short-title="Departments" class="component-title"><?php print $title; ?>:</h2>
    </div>
    <div class="departments-wrapper">
      <?php print render($contacts); ?>
    </div>
    <!-- End .departments-wrapper -->
  </div>
  <!-- End topic-departments-container -->
</section><!-- End departments-container -->
