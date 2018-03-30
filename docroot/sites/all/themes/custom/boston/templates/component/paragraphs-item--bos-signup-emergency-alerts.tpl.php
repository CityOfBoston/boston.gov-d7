<?php
/**
 * @file
 * Default theme implementation for a single paragraph item.
 *
 * Available variables:
 * - $content: An array of content items. Use render($content) to print them
 *   all, or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity
 *   - entity-paragraphs-item
 *   - paragraphs-item-{bundle}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened into
 *   a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="b b--<?php print $component_theme; ?> b--fw<?php if ($component_theme === 'b'): ?> b--wt<?php endif; ?>">
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
        <div class="p-r500">
          <div id="alert_content" class="m-b500">
            <div class="t--intro m-b300"><?php print render($content['field_intro_text']); ?></div>
            <div><?php print render($content['field_description']); ?></div>
          </div>
          <div id="alert_success" class="m-b500 p-t400">
            <div class="di di--c<?php if ($component_theme === 'b'): ?> di--c--w<?php endif; ?> di--c--l fl--l m-r400">
              <div class="di-a">
                <img src="<?php print render($content['field_icon']); ?>" role="presentation" />
              </div>
            </div>
            <div class="t--intro m-t300" style="display: none">You have been subscribed to the City of Boston's emergency alerts</div>
          </div>
        </div>
      </div>
      <div class="g--5">
        <form id="bosAlertForm" action="<?php print $emergency_alerts_url ?>" method="post">
          <div class="fs">
            <div class="fs-c m-b300">
              <div class="txt">
                <label for="email" class="txt-l txt-l--mt000">Your email address</label>
                <input id="email" name="email" type="text" value="" placeholder="email@address.com" class="txt-f">
              </div>
              <div class="sep m-b300<?php if ($component_theme === 'b'): ?> sep--w<?php endif; ?>">
                <div class="sep-l"></div>
                <div class="sep-c">or</div>
                <div class="sep-l"></div>
              </div>
              <div class="txt">
                <label for="phone_number" class="txt-l txt-l--w txt-l--mt000">Your phone number</label>
                <input id="phone_number" name="phone_number" type="text" value="" placeholder="Phone number" class="txt-f">
              </div>
            </div>
            <div class="fs-c fs-c--i">
              <label class="cb">
                <input id="checkbox-text" name="text" type="checkbox" value="1" class="cb-f" checked>
                <span class="cb-l cb-l--sans">Text me</span>
              </label>
              <label class="cb">
                <input id="checkbox-call" name="call" type="checkbox" value="1" class="cb-f">
                <span class="cb-l cb-l--sans">Call me</span>
              </label>
            </div>
            <div class="t--subinfo<?php if ($component_theme === 'b'): ?> t--w<?php endif; ?> m-t100">Message &amp; data rates may apply</div>
            <hr class="hr hr--sq" />
            <div class="fs-c m-b300">
              <div class="txt">
                <label for="first_name" class="txt-l txt-l--mt000">First name</label>
                <input id="first_name" name="first_name" type="text" value="" placeholder="First name" class="txt-f">
              </div>
            </div>
            <div class="fs-c m-b300">
              <div class="txt">
                <label for="last_name" class="txt-l txt-l--mt000">Last name</label>
                <input id="last_name" name="last_name" type="text" value="" placeholder="Last name" class="txt-f">
              </div>
            </div>
            <div class="fs-c m-b300">
              <div class="txt">
                <label for="zip_code" class="txt-l txt-l--w txt-l--mt000">Zip code</label>
                <input id="zip_code" name="zip" type="text" value="" placeholder="Zip code" class="txt-f" size="10">
              </div>
            </div>
            <div class="fs-c m-b300">
              <div class="sel">
                <label for="emergency-alerts-language" class="txt-l txt-l--w txt-l--mt000">Language</label>
                <div class="sel-c sel-c--fw">
                  <select class="sel-f sel-f--fw" name="language" id="emergency-alerts-language">
                    <option value="en" selected>English</option>
                    <option value="es">Español</option>
                    <option value="fr">Français</option>
                    <option value="zh_TW">繁體中文</option>
                  </select>
                </div>
              </div>
            </div>
            <div id="message" class="m-b300" style="display: none"></div>
            <div id="button" class="fs-c fs-c--i fs-c--c">
              <div class="m-lAAA m-t400 m-t300--mo">
                <button id="alert_submit" type="submit" class="btn btn--700">Sign Up</button>
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
        button,
        phone_number,
        first_name,
        last_name,
        call,
        zip,
        language,
        text;

    function handleAlertSignup(ev) {
      ev.preventDefault();

      var isValid = validateForm();

      if (isValid) {
        var data = form.serialize();

        button.attr('disabled', true).html('loading');

        jQuery.ajax({
          url: form.attr('action'),
          method: 'post',
          data: data,
          success: handleSuccess,
          error: function (req, err) {
            button.attr('disabled', false).html('Sign Up');

            if (req.responseJSON && req.responseJSON.errors) {
              jQuery('#message').append('<div class="t--subinfo t--err m-t100">' + req.responseJSON.errors + '</div>').show();
            } else {
              jQuery('#message').append('<div class="t--subinfo t--err m-t100">There was an error. Please try again or email <a href="mailto:feedback@boston.gov">feedback@boston.gov</a>.</div>').show();
            }
          },
        });
      }
    }

    function handleSuccess(data) {
      triggerSuccess(email, data.contact.email);
      triggerSuccess(phone_number, data.contact.phone_number);
      triggerSuccess(first_name, data.contact.first_name);
      triggerSuccess(last_name, data.contact.last_name);
      triggerSuccess(zip, data.contact.zip);
      triggerSuccess(language, data.contact.language_name);
      triggerSuccess(call, data.contact.call ? 'Yes' : 'No');
      triggerSuccess(text, data.contact.text ? 'Yes' : 'No');
      form.find('#message, #button').remove();
      form.find('.t--subinfo').remove();
      jQuery('#alert_content').remove();
      jQuery('#alert_success .t--intro').show();
    }

    function validateForm() {
      var valid = true;

      resetForm();

      if (email.val() == '' && phone_number.val() == '') {
        triggerError(email, "Please enter a valid email or phone number", 'txt-f--err');
        triggerError(phone_number, "Please enter a valid phone number or email", 'txt-f--err');
        valid = false;
      }

      if (first_name.val() == '' && last_name.val() == '') {
        triggerError(first_name, "Please enter your first or last name", 'txt-f--err');
        triggerError(last_name, "Please enter your first or last name", 'txt-f--err');
        valid = false;
      }

      return valid;
    }

    function resetForm() {
      jQuery('.t--err').remove();
      jQuery('.txt-l').css({color: ''});
      jQuery('.txt-f').css({borderColor: ''});
    }

  function triggerSuccess(el, msg) {
    var parent = el.closest('.txt, .sel');

    if (msg) {
      parent.find('input, .sel-c').remove();
      parent.append('<div class="t--info" style="text-transform: none">' + msg + '</div>');

      if (parent.hasClass('cb')) {
        parent.css({'display': 'block'});
        parent.find('.cb-l').css({'margin-left': 0});
      }
    } else {
      parent.remove();
    }
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
      first_name = jQuery('#first_name');
      last_name = jQuery('#last_name');
      call = jQuery('#checkbox-call');
      text = jQuery('#checkbox-text');
      zip = jQuery('#zip_code');
      language = jQuery('#emergency-alerts-language');
      button = jQuery('#alert_submit');
      form.submit(handleAlertSignup)
    }

    return {
      start: start
    }
  })()

  BostonEmergencyAlerts.start()
</script>
