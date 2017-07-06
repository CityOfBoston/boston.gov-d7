<?php
/**
 * @file
 * Phone number field template.
 */
$phone = $items[0]['#markup'];
?>
<a href="tel:<?php print $phone ?>" class="d-b bg--cb cdp-a ta-c p-a300 t--upper t--sans t--w t--ob--h t--s100"><?php print $phone ?></a>
