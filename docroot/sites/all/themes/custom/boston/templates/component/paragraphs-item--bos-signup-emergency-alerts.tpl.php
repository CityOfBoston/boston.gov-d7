<div class="b b--<?php print $component_theme; ?> b--fw">
  <div class="b-c">
  	<div class="sh <?php print $section_header_theme; ?>">
      <?php if (isset($content['field_component_title'])): ?>
        <?php print render($content['field_component_title']); ?>
      <?php endif; ?>
	    <?php if (isset($content['field_contact'])): ?>
	      <div class="sh-contact"><?php print render($content['field_contact']); ?></div>
	    <?php endif; ?>
    </div>
    <div class="g m-t500">
      <div class="g--7">
        <div class="t--intro m-b300"><?php print render($content['field_intro_text']); ?></div>
        <div><?php print render($content['field_description']); ?></div>
      </div>
      <div class="g--5">
        <form id="bosAlertForm" action="<?php print $emergency_alerts_url ?>" method="post">
          <div class="fs">
            <div class="fs-c m-b300">
              <div class="txt">
                <label for="email" class="txt-l txt-l--mt000">Your email address</label>
                <input id="email" type="text" value="" placeholder="email@address.com" class="txt-f txt-f--sm">
              </div>
              <div class="txt">
                <label for="phone_number" class="txt-l txt-l--w txt-l--mt000">Your phone number</label>
                <input id="phone_number" type="text" value="" placeholder="Phone number" class="txt-f txt-f--sm">
              </div>
            </div>
            <div class="fs-c fs-c--i">
              <label class="cb">
                <input id="checkbox-call" name="call" type="checkbox" value="public_notices" class="cb-f" checked>
                <span class="cb-l cb-l--sans">Call me</span>
              </label>
              <label class="cb">
                <input id="checkbox-text" name="text" type="checkbox" value="public_notices" class="cb-f">
                <span class="cb-l cb-l--sans">Text me</span>
              </label>
            </div>
            <div class="t--subinfo t--w m-t100">Message &amp; data rates may apply</div>
            <hr class="hr hr--sq" />
            <div class="fs-c fs-c--i m-b300">
              <div class="txt g--6">
                <label for="first_name" class="txt-l txt-l--mt000">First name</label>
                <input id="first_name" type="text" value="" placeholder="First name" class="txt-f txt-f--sm">
              </div>
              <div class="txt g--6">
                <label for="last_name" class="txt-l txt-l--mt000">Last name</label>
                <input id="last_name" type="text" value="" placeholder="Last name" class="txt-f txt-f--sm">
              </div>
            </div>
            <div class="fs-c m-b300">
              <div class="txt">
                <label for="zip_code" class="txt-l txt-l--w txt-l--mt000">Your phone number</label>
                <input id="zip_code" type="text" value="" placeholder="Zip code" class="txt-f txt-f--sm" size="10">
              </div>
            </div>
            <div class="fs-c m-b300">
              <div class="sel">
                <label for="language" class="sel-l sel-l--mt000">Choose a language</label>
                <div class="sel-c sel-c--fw">
                  <select name="language" id="language" class="sel-f sel-f--sm">
                    <option value="en">English</option>
                    <option value="es">Spanish</option>
                    <option value="cn">Chinese</option>
                  </select>
                </div>
              </div>
            </div>
            <div class="fs-c fs-c--i fs-c--c">
              <label class="cb">
                <input id="tdd" name="checkbox-call" type="checkbox" value="tdd" class="cb-f">
                <span class="cb-l cb-l--sans">TDD/TDY Device - Tone Delivery</span>
              </label>
              <div class="m-lAAA m-t300 m-t300--mo">
                <button type="submit" class="btn btn--700">Sign Up</button>
              </div>
            </div>
          </div>
        </form>
      </div>
    </div>
  </div>
</div>
<script>
  'use strict'

  var BostonEmergencyAlerts = (function () {
    var form = jQuery('#bosAlertForm');
    var email,
        phone_number,
        call,
        text;

    function handleAlertSignup(ev) {
      ev.preventDefault();

      var isValid = validateForm();
    }

    function validateForm() {
      resetForm();

      if (email.val() == '' && phone_number.val() == '') {
        triggerError(email, "Please enter a valid email or phone number", 'txt-f--err');
        triggerError(phone_number, "Please enter a valid phone number or email", 'txt-f--err');
        return false;
      }
    }

    function resetForm() {
      jQuery('.t--err').remove();
      jQuery('.txt-l').css({color: ''});
      jQuery('.txt-f').css({borderColor: ''});
    }

    function triggerError(el, msg, className) {
      var el = jQuery(el);
      var parent = el.parent();

      parent.append('<div class="t--subinfo t--err m-t100">' + msg + '</div>');
      parent.find('.txt-l').css({color: '#fb4d42'});
      el.css({borderColor: '#fb4d42'});
    }

    function start() {
      email = jQuery('#email');
      phone_number = jQuery('#phone_number');
      call = jQuery('#checkbox-call');
      text = jQuery('#checkbox-text');
      form.submit(handleAlertSignup)
    }

    return {
      start: start
    }
  })()

  BostonEmergencyAlerts.start()
</script>
