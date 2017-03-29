<?php

/**
 * @file
 * Default theme implementation for profiles.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them
 *   all, or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) profile type label.
 * - $url: The URL to view the current profile.
 * - $page: TRUE if this is the main view page $url points too.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-profile
 *   - profile-{TYPE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>



<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>>
      <a href="<?php print $url; ?>"><?php print $title; ?></a>
    </h2>
  <?php endif; ?>
  <div class="content desktop-100"<?php print $content_attributes; ?>>

    <?php if ($viewing_own) : ?>
      <div class="user-profile-header-block">
        <div class="container">
          <h1>My Profile <label><a href="https://ess.boston.gov" title="Edit profile">Edit profile</a></label></h1>
          <?php if (!empty($header_data)) : ?>
            <div class="profile-header-links">
              <div class="user-profile-header-payroll supporting-text">
                <a href="<?php print render($header_data['payroll_link']); ?>" class="payroll" title="Go to payroll page">Payroll</a>
              </div>
              <div class="user-profile-header-leave supporting-text">
                <a href="<?php print render($header_data['leave_link']); ?>" class="leave" title="Go to leave page">Leave</a>
              </div>
              <div class="user-profile-header-benis supporting-text">
                <a href="<?php print render($header_data['benefits_link']); ?>" class="benefits" title="Go to benefits page">Benefits</a>
              </div>
            </div>
          <?php endif ?>
        </div>
      </div>
    <?php endif; ?>
  <div class="user-profile-info-block">
    <div class="container">
    <div class="user-profile-header-info clearfix">
      <div class="user-profile-picture user-profile-picture-top">
        <div class="user-picture-image" style="background-image: url(//cob-avatars.herokuapp.com/photos/<?php print base64_encode($field_work_email); ?>)"></div>
      </div>
      <div class="user-profile-info">
        <?php if (!empty($content['field_display_name'])) : ?>
          <div class="user-profile-header-display-name">
            <?php if($viewing_own) : ?>
            <h1><?php print $display_name_text; ?></h1>
            <?php else: ?>
            <h1><?php print $display_name_text; ?></h1>
            <?php endif; ?>
          </div>
        <?php endif ?>


            <?php if (!empty($content['field_position_title'])) : ?>
          <div class="user-profile-header-position-title field-output">
            <?php print $job_title_text; ?>
          </div>
        <?php endif ?>
        <div class="user-profile-social flex-at-lg">
          <?php if (!empty($content['field_twitter'])) : ?>
            <div class="user-profile-twitter icon-common icon-position-center-left icon-twitter">
              <?php print $twitter_link; ?>
            </div>
          <?php endif ?>
          <?php if (!empty($content['field_linked_in'])) : ?>
            <div class="user-profile-linked-in icon-common icon-position-center-left icon-linkedin">
              <?php print $linked_in_link; ?>
            </div>
          <?php endif ?>
        </div>
      </div>
    </div>
    <div class="user-profile-section">
      <?php if (!empty($content['field_office_location']) || !empty($content['field_work_phone_number']) || !empty($content['field_work_email'])) : ?>
        <h2>Contact Information</h2>
        <?php if (!empty($content['field_office_location'])) : ?>
          <div class="user-profile-office-location clearfix">
            <div class="user-profile-office-address flex-at-lg">
              <div class="office-location-first-line flex-at-sm flex-width-md">
                <div class="location">
                  <label>Room</label>
                  <div class="field-output"><?php print $office_address['location']; ?></div>
                </div>
                <div class="street">
                  <label>Street Address</label>
                  <div class="field-output"><?php print $office_address['street']; ?></div>
                </div>
              </div>
              <div class="office-location-second-line flex-at-sm">
                <div class="sub-office-location flex-at-sm">
                  <div class="city">
                    <label>City</label>
                    <div class="field-output"><?php print $office_address['city']; ?></div>
                  </div>
                  <div class="state">
                    <label>State</label>
                    <div class="field-output"><?php print $office_address['state']; ?></div>
                  </div>
                </div>
                  <div class="zip sub-office-location">
                    <div class="zip"><label>Zip</label>
                    <div class="field-output"><?php print $office_address['zip']; ?></div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        <?php endif ?>
        <div class="user-profile-phones flex-at-sm">
          <?php if (!empty($content['field_work_phone_number'])) : ?>
            <div class="user-profile-work-phone flex-width-md">
              <label>Phone Number (Office)</label>
              <div class="field-output"><?php print render($content['field_work_phone_number']); ?></div>
            </div>
          <?php endif ?>
        </div>
        <?php if (!empty($content['field_work_email'])) : ?>
          <div class="user-profile-work-email clearfix">
            <label>Email Address</label>
            <div class="field-output"><?php print render($content['field_work_email']); ?></div>
          </div>
        <?php endif ?>
      <?php endif ?>
    </div>


    <div class="user-profile-section">
      <h2>Organizational Information</h2>
      <?php if (!empty($content['field_contact'])) : ?>
        <div class="user-profile-department">
          <label>Department</label>
          <div class="field-output"><?php print render($content['field_contact']); ?></div>
        </div>
      <?php endif ?>
      <?php if (!empty($content['field_manager'])) : ?>
        <div class="user-profile-manager clearfix">
          <label>Manager</label>
          <div class="field-output"><?php print $manager_display_name; ?></div>
        </div>
      <?php endif ?>
    </div>
    </div><!--user-profile-info-block-->
</div>
    <?php if ($viewing_own) : ?>
      <div class="user-profile-section user-profile-personal-info">
        <div class="container">
          <div class="user-help-wrapper">
            <div class="question-help">​​To update your work contact or organizational information, contact:</div>
            <div class="question-help title-text ">Boston Public School Employees</div>
            <div class="question-help">Office of Human Capital at ​<a href="tel:617-635-9600" class="inverted"><span class="a11y-hidden">Call </span>617-635-9600</a></div>
            <div class="question-help"><a href="https://hcm.cityhall.boston.cob/psp/pshrpd3/EMPLOYEE/HRMS/c/ROLE_EMPLOYEE.JPM_PERS_PTSEL_EMP.GBL?PORTALPARAM_PTCNAV=COB_CREF_MY_CURRENT_PRO_UPGRAD&EOPP.SCNode=EMPL&EOPP.SCPortal=EMPLOYEE&EOPP.SCName=COB_ONEB_MY_LEARNING_N_DEV&EOPP.SCLabel=The%20Hub%20Career%20Development&EOPP.SCPTcname=&FolderPath=PORTAL_ROOT_OBJECT.PORTAL_BASE_DATA.CO_NAVIGATION_COLLECTIONS.COB_ONEB_MY_LEARNING_N_DEV.COB_F200707311707005312967314.COB_F200710101209269027375102.COB_CREF_MY_CURRENT_PRO_UPGRAD&IsFolder=false" class="inverted">View BPS licensure and BTU program area information and view or update your accomplishments, skills, and abilities.</a></div>
            <div class="question-help title-text">All Other Employees</div>
            <div class="question-help">Your departmental personnel officer.</div>
          </div>
        </div>
      </div>
    <?php endif; ?>
    <?php if (!$viewing_own) : ?>
      <div class="user-profile-picture user-profile-picture-bottom <?php if ($viewing_own) : ?>hide-from-current<?php endif; ?>">
        <?php if (!empty($content['field_user_picture'])) : ?>
          <?php print render($content['field_user_picture']); ?>
        <?php else :?>
          <img src="/<?php print drupal_get_path('theme', 'boston_hub'); ?>/dist/img/default-avatar-lg.svg" alt="missing profile picture">
        <?php endif ?>
      </div>
    <?php endif; ?>
</div>
