<?php
/**
 * @file
 * Phone number field template.
 */
$phone = $items[0]['#markup'];
?>
<a href="tel:<?php print $phone ?>" class="t--upper t--sans"><?php print $phone ?></a>
