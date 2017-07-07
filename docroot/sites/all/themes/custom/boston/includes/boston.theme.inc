<?php
/**
 * @file
 * Contains theme overrides for Boston.gov site.
 */

/**
 * @defgroup boston_theme_overrides Boston Theme Overrides
 * @{
 * Theme functions that are defined by modules, but for theming purposes
 * needed to be overridden.
 */

/**
 * Return a themed breadcrumb trail.
 *
 * @param array $variables
 *   - title: An optional string to be used as a navigational heading to give
 *     context for breadcrumb links to screen-reader users.
 *   - title_attributes_array: Array of HTML attributes for the title. It is
 *     flattened into a string within the theme function.
 *   - breadcrumb: An array containing the breadcrumb links.
 *   - display_breadcrumb: A boolean indicating whether the breadcrumbs should
 *     be displayed.
 *   - breadcrumb_separator: A string representing the text to be used as the
 *     breadcrumb separator.
 *   - display_trailing_separator: A boolean indicating whether a trailing
 *     seperator should be added at the end of the breadcrumbs.
 *
 * @return string
 *   A string containing the breadcrumb output.
 */
function boston_breadcrumb(array $variables) {
  $output = '';

  // Determine if we are to display the breadcrumb.
  if ($variables['display_breadcrumb'] && !empty($variables['breadcrumb'])) {
    $variables['title_attributes_array']['class'][] = 'brc-t';
    $separator = '<span class="brc-s">' . $variables['breadcrumb_separator'] . '</span>';
    // Build the breadcrumb trail.
    $output = '<nav class="brc" role="navigation">';
    $output .= '<div class="a11y--h">' . drupal_attributes($variables['title_attributes_array']) . '>' . $variables['title'] . '</div>';
    $output .= '<ul class="brc-l"><li class="brc-l-i">';
    $output .= implode($separator . '</li><li class="brc-l-i">', $variables['breadcrumb']);
    if ($variables['display_trailing_separator']) {
      $output .= $separator;
    }
    $output .= '</li></ul></nav>';
  }

  return $output;
}

/**
 * Returns HTML for status and/or error messages, grouped by type.
 */
function boston_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  // Allow a preprocess function to override the default SVG icons.
  if (!isset($variables['icon'])) {
    $variables['icon'] = array();
    foreach (array('status', 'warning', 'error') as $type) {
      // Add a GPL-licensed icon from IcoMoon. https://icomoon.io/#preview-free
      $icon_size = 'width="24" height="24"';
      // All of the IcoMoon SVGs have the same header.
      $variables['icon'][$type] = '<svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" ' . $icon_size . ' viewBox="0 0 64 64">';
      switch ($type) {
        case 'error':
          $variables['icon'][$type] .= '<path d="M63.416 51.416c-0-0-0.001-0.001-0.001-0.001l-19.415-19.416 19.415-19.416c0-0 0.001-0 0.001-0.001 0.209-0.209 0.36-0.453 0.457-0.713 0.265-0.711 0.114-1.543-0.458-2.114l-9.172-9.172c-0.572-0.572-1.403-0.723-2.114-0.458-0.26 0.097-0.504 0.248-0.714 0.457 0 0-0 0-0.001 0.001l-19.416 19.416-19.416-19.416c-0-0-0-0-0.001-0.001-0.209-0.209-0.453-0.36-0.713-0.457-0.711-0.266-1.543-0.114-2.114 0.457l-9.172 9.172c-0.572 0.572-0.723 1.403-0.458 2.114 0.097 0.26 0.248 0.505 0.457 0.713 0 0 0 0 0.001 0.001l19.416 19.416-19.416 19.416c-0 0-0 0-0 0.001-0.209 0.209-0.36 0.453-0.457 0.713-0.266 0.711-0.114 1.543 0.458 2.114l9.172 9.172c0.572 0.572 1.403 0.723 2.114 0.458 0.26-0.097 0.504-0.248 0.713-0.457 0-0 0-0 0.001-0.001l19.416-19.416 19.416 19.416c0 0 0.001 0 0.001 0.001 0.209 0.209 0.453 0.36 0.713 0.457 0.711 0.265 1.543 0.114 2.114-0.458l9.172-9.172c0.572-0.572 0.723-1.403 0.458-2.114-0.097-0.26-0.248-0.504-0.457-0.713z" fill="#000000"></path>';
          break;

        case 'warning':
          $variables['icon'][$type] .= '<path d="M26,64l12,0c1.105,0 2,-0.895 2,-2l0,-9c0,-1.105 -0.895,-2 -2,-2l-12,0c-1.105,0 -2,0.895 -2,2l0,9c0,1.105 0.895,2 2,2Z" fill="#000000"></path><path d="M26,46l12,0c1.105,0 2,-0.895 2,-2l0,-42c0,-1.105 -0.895,-2 -2,-2l-12,0c-1.105,0 -2,0.895 -2,2l0,42c0,1.105 0.895,2 2,2Z" fill="#000000"></path>';
          break;

        default:
          $variables['icon'][$type] .= '<path d="M54 8l-30 30-14-14-10 10 24 24 40-40z" fill="#000000"></path>';
      }
      $variables['icon'][$type] .= '</svg>';
    }
  }

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );
  foreach (drupal_get_messages($display) as $type => $messages) {
    $output .= "<div class=\"messages--$type\">\n";
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="visually-hidden">' . $status_heading[$type] . "</h2>\n";
    }

    if (!empty($variables['icon'])) {
      $output .= '<div class="messages__icon">';
      switch ($type) {
        case 'error':
        case 'warning':
          $output .= $variables['icon'][$type];
          break;

        default:
          $output .= $variables['icon']['status'];
      }
      $output .= "</div>";
    }

    if (count($messages) > 1) {
      $output .= " <ul class=\"messages__list\">\n";
      foreach ($messages as $message) {
        $output .= '  <li class="messages__item">' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= $messages[0];
    }
    $output .= "</div>\n";
  }
  return $output;
}

/**
 * Theme function for formatter: time ranges.
 *
 * Overrides theme_office_hours_time_range to customize time range output
 * for Boston.gov. Used by the daily_hours widget.
 */
function boston_office_hours_time_range($vars = array()) {
  // Add default values to $vars if not set already.
  $vars += array(
    'times' => array(
      'start' => '',
      'end' => '',
    ),
    'format' => 'G:i',
    'separator' => ' - ',
  );
  // Override the format used to always be of this format for time range.
  // This is a Boston.gov customization.
  $vars['format'] = 'g:i A';

  $starttime = _office_hours_time_format($vars['times']['start'], $vars['format']);
  $endtime = _office_hours_time_format($vars['times']['end'], $vars['format']);
  if ($endtime == '0:00' || $endtime == '00:00') {
    $endtime = '24:00';
  }
  $result = $starttime . $vars['separator'] . $endtime;
  return $result;
}

/**
 * Overrides default date repeat rule output.
 *
 * Overriding reasons:
 *   - Customize weekly repeat rule output.
 *
 * @param string $rrule
 *   The iCal rule string.
 * @param string $format
 *   Default format of the string.
 *
 * @return mixed|null|string
 *   The formatted repeat string.
 */
function boston_date_repeat_rrule_description($rrule, $format = 'D M d Y') {
  // Empty or invalid value.
  if (empty($rrule) || !strstr($rrule, 'RRULE')) {
    return NULL;
  }

  module_load_include('inc', 'date_api', 'date_api_ical');
  module_load_include('inc', 'date_repeat', 'date_repeat_calc');

  $parts = date_repeat_split_rrule($rrule);
  $additions = $parts[2];
  $exceptions = $parts[1];
  $rrule = $parts[0];
  if ($rrule['FREQ'] == 'NONE') {
    return NULL;
  }

  // Make sure there will be an empty description for any unused parts.
  $description = array(
    '!interval' => '',
    '!byday' => '',
    '!bymonth' => '',
    '!count' => '',
    '!until' => '',
    '!except' => '',
    '!additional' => '',
    '!week_starts_on' => '',
  );
  $interval = date_repeat_interval_options();
  switch ($rrule['FREQ']) {
    case 'WEEKLY':
      // Customized for Boston.
      $description['!interval'] = format_plural($rrule['INTERVAL'], '', 'every @count weeks') . ' ';
      break;

    case 'MONTHLY':
      $description['!interval'] = format_plural($rrule['INTERVAL'], 'every month', 'every @count months') . ' ';
      break;

    case 'YEARLY':
      $description['!interval'] = format_plural($rrule['INTERVAL'], 'every year', 'every @count years') . ' ';
      break;

    default:
      $description['!interval'] = format_plural($rrule['INTERVAL'], 'every day', 'every @count days') . ' ';
      break;
  }

  if (!empty($rrule['BYDAY'])) {
    $days = date_repeat_dow_day_options();
    $counts = date_repeat_dow_count_options();
    $results = array();
    foreach ($rrule['BYDAY'] as $byday) {
      // Get the numeric part of the BYDAY option, i.e. +3 from +3MO.
      $day = substr($byday, -2);
      $count = str_replace($day, '', $byday);
      if (!empty($count)) {
        // See if there is a 'pretty' option for this count, i.e. +1 => First.
        $order = array_key_exists($count, $counts) ? strtolower($counts[$count]) : $count;
        $results[] = trim(t('!repeats_every_interval on the !date_order !day_of_week',
          array(
            '!repeats_every_interval ' => '',
            '!date_order' => $order,
            '!day_of_week' => $days[$day],
          )));
      }
      else {
        $results[] = trim(t('!repeats_every_interval every !day_of_week',
          array('!repeats_every_interval ' => '', '!day_of_week' => $days[$day])));
      }
    }
    $and = t('and');
    $description['!byday'] = implode(" $and ", $results);
  }
  if (!empty($rrule['BYMONTH'])) {
    if (count($rrule['BYMONTH']) < 12) {
      $results = array();
      $months = date_month_names();
      foreach ($rrule['BYMONTH'] as $month) {
        $results[] = $months[$month];
      }
      if (!empty($rrule['BYMONTHDAY'])) {
        $description['!bymonth'] = trim(t('!repeats_every_interval on the !month_days of !month_names',
          array(
            '!repeats_every_interval ' => '',
            '!month_days' => implode(', ', $rrule['BYMONTHDAY']),
            '!month_names' => implode(', ', $results),
          )));
      }
      else {
        $description['!bymonth'] = trim(t('!repeats_every_interval on !month_names',
          array(
            '!repeats_every_interval ' => '',
            '!month_names' => implode(', ', $results),
          )));
      }
    }
  }
  if ($rrule['INTERVAL'] < 1) {
    $rrule['INTERVAL'] = 1;
  }
  if (!empty($rrule['COUNT'])) {
    $description['!count'] = trim(t('!repeats_every_interval !count times',
      array('!repeats_every_interval ' => '', '!count' => $rrule['COUNT'])));
  }
  if (!empty($rrule['UNTIL'])) {
    $until = date_ical_date($rrule['UNTIL'], 'UTC');
    date_timezone_set($until, date_default_timezone_object());
    $description['!until'] = trim(t('!repeats_every_interval until !until_date',
      array(
        '!repeats_every_interval ' => '',
        '!until_date' => date_format_date($until, 'custom', $format),
      )));
  }
  if ($exceptions) {
    $values = array();
    foreach ($exceptions as $exception) {
      $except = date_ical_date($exception, 'UTC');
      date_timezone_set($except, date_default_timezone_object());
      $values[] = date_format_date($except, 'custom', $format);
    }
    $description['!except'] = trim(t('!repeats_every_interval except !except_dates',
      array(
        '!repeats_every_interval ' => '',
        '!except_dates' => implode(', ', $values),
      )));
  }
  if (!empty($rrule['WKST'])) {
    $day_names = date_repeat_dow_day_options();
    $description['!week_starts_on'] = trim(t('!repeats_every_interval where the week start on !day_of_week',
      array('!repeats_every_interval ' => '', '!day_of_week' => $day_names[trim($rrule['WKST'])])));
  }
  if ($additions) {
    $values = array();
    foreach ($additions as $addition) {
      $add = date_ical_date($addition, 'UTC');
      date_timezone_set($add, date_default_timezone_object());
      $values[] = date_format_date($add, 'custom', $format);
    }
    $description['!additional'] = trim(t('Also includes !additional_dates.',
      array('!additional_dates' => implode(', ', $values))));
  }
  $output = t('Repeats !interval !bymonth !byday !count !until !except. !additional', $description);
  // Removes double whitespaces from Repeat tile.
  $output = preg_replace('/\s+/', ' ', $output);
  // Removes whitespace before full stop ".", at the end of the title.
  $output = str_replace(' .', '.', $output);
  return $output;
}

/**
 * Returns HTML for primary and secondary local tasks.
 */
function boston_menu_local_tasks(array &$variables) {
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

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="visually-hidden">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs primary">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="visually-hidden">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs--secondary tabs secondary">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}

/**
 * Returns HTML for a single local task link.
 */
function boston_menu_local_task($variables) {
  $type = $class = FALSE;

  $link = $variables['element']['#link'];
  $link_text = $link['title'];

  // Check for tab type set in boston_menu_local_tasks().
  if (is_array($variables['element']['#theme'])) {
    $type = in_array('menu_local_task__secondary', $variables['element']['#theme']) ? 'tabs--secondary' : 'tabs';
  }

  // Add SMACSS-style class names.
  if ($type) {
    $link['localized_options']['attributes']['class'][] = $type . '__tab-link';
    $class = $type . '__tab';
  }

  if (!empty($variables['element']['#active'])) {
    // Add text to indicate active tab for non-visual users.
    $active = ' <span class="visually-hidden">' . t('(active tab)') . '</span>';

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link['localized_options']['html'] = TRUE;
    $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));

    if (!$type) {
      $class = 'active';
    }
    else {
      $link['localized_options']['attributes']['class'][] = 'is-active';
      $class .= ' is-active';
    }
  }

  return '<li' . ($class ? ' class="' . $class . '"' : '') . '>' . l($link_text, $link['href'], $link['localized_options']) . "</li>\n";
}

/**
 * Returns HTML for a marker for new or updated content.
 */
function boston_mark($variables) {
  $type = $variables['type'];

  if ($type == MARK_NEW) {
    return ' <mark class="new">' . t('new') . '</mark>';
  }
  elseif ($type == MARK_UPDATED) {
    return ' <mark class="updated">' . t('updated') . '</mark>';
  }
}

/**
 * Implements theme_menu_tree__[MENU NAME].
 */
function boston_menu_tree__main_menu($variables) {
  return '<ul class="' . $variables['menu_classes'] . '">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_link__[MENU NAME].
 */
function boston_menu_link__main_menu($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    // Add a Back button to subnav items in the main menu. Sort the array and
    // so Back is always first, and tell Drupal to re-render the render array.
    $back_button[] = array('#markup' => '<li class="nv-m-c-bc nv-m-c-b--h"><button class="nv-m-c-b">Back</button></li>');
    $element['#below'] = $back_button + $element['#below'];
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Alters the default Panels render callback so it removes the panel separator.
 */
function boston_panels_default_style_render_region($variables) {
  return implode('', $variables['panes']);
}

/**
 * Overrides default pager output.
 */
function boston_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // Current is the page we are currently paged to.
  $pager_current = $pager_page_array[$element] + 1;
  // First is the first page listed by this pager piece (re quantity).
  $pager_first = $pager_current - $pager_middle + 1;
  // Last is the last page listed by this pager piece (re quantity).
  $pager_last = $pager_current + $quantity - $pager_middle;
  // Max is the maximum page number.
  $pager_max = $pager_total[$element];
  // End of marker calculations.
  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.
  $prev_content = t('prev');
  $next_content = t('next');

  $li_previous = theme('pager_previous', array(
    'text' => (isset($tags[1]) ? $tags[1] : $prev_content),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
  ));
  $li_next = theme('pager_next', array(
    'text' => (isset($tags[3]) ? $tags[3] : t('next')),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
  ));

  if ($pager_total[$element] > 1) {
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => $li_previous,
      );
    }
    else {
      $items[] = array(
        'class' => array('pager-disabled'),
        'data' => $prev_content,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array(
              'text' => $i,
              'element' => $element,
              'interval' => ($pager_current - $i),
              'parameters' => $parameters,
            )),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current'),
            'data' => $i,
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array(
              'text' => $i,
              'element' => $element,
              'interval' => ($i - $pager_current),
              'parameters' => $parameters,
            )),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next,
      );
    }
    else {
      $items[] = array(
        'class' => array('pager-disabled'),
        'data' => $next_content,
      );
    }
    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager')),
    ));
  }
}

/**
 * @} End of "Boston Theme Overrides".
 */
