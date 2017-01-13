<?php
/**
 * @file
 * Contains functions to alter Drupal's markup for the STARTERKIT theme.
 */

/**
 * Returns HTML for primary and secondary local tasks.
 *
 * @ingroup themeable
 */
function boston_admin_menu_local_tasks(array &$variables) {
  // Attaches JS for extending validation messages
  drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/js/related-content-messaging.js', array('type' => 'file', 'scope' => 'footer'));

  $output = '';

  // Add theme hook suggestions for tab type.
  foreach (array('primary', 'secondary') as $type) {
    if (!empty($variables[$type])) {
      foreach (array_keys($variables[$type]) as $key) {
        if (isset($variables[$type][$key]['#theme']) && ($variables[$type][$key]['#theme'] == 'menu_local_task' || is_array($variables[$type][$key]['#theme']) && in_array('menu_local_task', $variables[$type][$key]['#theme']))) {
          $variables[$type][$key]['#theme'] = array('menu_local_task__' . $type, 'menu_local_task');
        }
      }
    }
  }

  // Add 'tabs primary' and 'tabs secondary' here so that we can move
  // the tabs into the admin toolbar for authenticated users.
  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="visually-hidden">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs bos-primary">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="visually-hidden">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs--secondary tabs bos-secondary">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}
