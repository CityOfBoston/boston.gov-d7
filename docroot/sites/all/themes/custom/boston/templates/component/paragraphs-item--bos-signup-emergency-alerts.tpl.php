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
        <form class="" action="#" method="post">
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
                <input id="checkbox-call" name="checkbox-call" type="checkbox" value="public_notices" class="cb-f">
                <span class="cb-l cb-l--sans">Call me</span>
              </label>
              <label class="cb">
                <input id="checkbox-text" name="checkbox-text" type="checkbox" value="public_notices" class="cb-f">
                <span class="cb-l cb-l--sans">Text me</span>
              </label>
            </div>
            <hr class="hr hr--sq" />
            <div class="fs-c m-b300">
              <div class="txt">
                <label for="first_name" class="txt-l txt-l--mt000">First name</label>
                <input id="first_name" type="text" value="" placeholder="First name" class="txt-f txt-f--sm">
              </div>
              <div class="txt">
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
            <div class="bc bc--r">
              <button type="submit" class="btn btn--700">Sign Up</button>
            </div>
          </div>
        </form>
      </div>
    </div>
  </div>
</div>
