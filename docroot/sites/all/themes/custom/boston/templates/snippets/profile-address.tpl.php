<?php
/**
 * @file
 * Default implementation for profile address.
 *
 * Available variables:
 * - $address: An address array with street, city, state and zip
 * - $address_type: A string for the address title, 'home' or 'mailing' etc.
 *                  If NULL do not print out the Title and do not include the
 *                  surrounding div as the address is probably in another
 *                  element.
 */
?>
<?php if(!empty($address_type)) : ?>
<div class="user-profile-<?php print trim(strtolower($address_type));?>-address">
  <h2><?php print $address_type;?> Address</h2>
<?php endif; ?>

<div class="profile-address flex-at-md">
  <div class="address-first-line flex-width-md">
    <div class="street">
      <label>Street Address</label>
      <div class="field-output"><?php print $address['street']; ?></div>
      <?php if(!empty($address['location'])) : ?>
        <div class="field-output address-line2"><?php print $address['location']; ?></div>
      <?php endif; ?>
    </div>
  </div>
  <div class="address-second-line flex-at-sm">
    <div class="city">
      <label>City</label>
      <div class="field-output"><?php print $address['city']; ?></div>
    </div>
    <div class="state">
      <label>State</label>
      <div class="field-output"><?php print $address['state']; ?></div>
    </div>
    <div class="zip">
      <label>Zip</label>
      <div class="field-output"><?php print $address['zip']; ?></div>
    </div>
  </div>
</div>


<?php if(!empty($address_type)) : ?>
</div>
<?php endif; ?>
