<?php
/**
 * Created by PhpStorm.
 * User: kevin.moylan
 * Date: 6/14/16
 * Time: 2:12 PM
 */
class hub_profile2_main_CrumbsMonoPlugin_UserProfileCrumbsPlugin implements crumbs_MonoPlugin
{

  /**
   * {@inheritdoc}
   */
  function describe($api)
  {
    $api->setTitle('Breadcrumbs for Hub Employee Directory.');
  }
  /**
   * Breadcrumb item title for path "news".
   *
   * @param string $path
   * @param array $item
   *
   * @return string
   *   A candidate for the breadcrumb item title.
   */
  function findTitle($path, $item) {
    $breadcrumb_title = NULL;
    global $user;
    // Make sure we're looking at employee-directory page.
    if (strstr($path, 'employee-directory')) {
      // Set the breadcrumb for the employee search page.
      $breadcrumb_title = t('Employee Directory');
      // If we're on a user's profile or search results page stop the breadcrumbs.
      if (strstr($path, 'employee-directory/')) {
        $breadcrumb_title =  FALSE;
      }
      // If we're going to the user's own profile page
      // set the breadcrumb to My Profile.
      if (!empty($GLOBALS['user'])) {
        if (strstr($_GET['q'], 'user/'.$user->uid)) {
          $breadcrumb_title =  t('My Profile');
        }
      }
    }
    // If we're going to a user page.
    if (strstr($path, 'user')) {
      if (strstr($path, 'user/')) {
        $profile_user = menu_get_object("user");
        // If this profile is not for the logged in user.
        if (!empty($profile_user) && $profile_user->uid != $user->uid) {
          // Get the display_name field from the user profile for the target.
          $profile_main = profile2_load_by_user($profile_user->uid, 'main');
          if (!empty($profile_main)) {
            $breadcrumb_title = field_view_field('profile2', $profile_main, 'field_display_name', 'value')['#items'][0]['safe_value'];
          }
        } else {
          // This is the logged in user, so just stop making breadcrumbs.
          $breadcrumb_title = FALSE;
        }
      }
    }

    if (strstr($path, 'search')) {
      $breadcrumb_title = 'Search';
      if ($path == 'search/results') {
        $breadcrumb_title = FALSE;
      }
      if (strstr($path, 'search/results/')) {
        $clean_title = check_plain(htmlspecialchars_decode($item['page_arguments'][1]));
        $breadcrumb_title = urldecode($clean_title);
      }
    }
    return $breadcrumb_title;
  }

}
