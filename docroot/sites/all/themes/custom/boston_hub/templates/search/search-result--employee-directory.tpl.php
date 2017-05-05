<?php

/**
 * @file
 * Default theme implementation for displaying a single search result.
 *
 * This template renders a single search result and is collected into
 * search-results.tpl.php. This and the parent template are
 * dependent to one another sharing the markup for definition lists.
 *
 * Available variables:
 * - $url: URL of the result.
 * - $title: Title of the result.
 * - $snippet: A small preview of the result. Does not apply to user searches.
 * - $info: String of all the meta information ready for print. Does not apply
 *   to user searches.
 * - $info_split: Contains same data as $info, split into a keyed array.
 * - $module: The machine-readable name of the module (tab) being searched, such
 *   as "node" or "user".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Default keys within $info_split:
 * - $info_split['module']: The module that implemented the search query.
 * - $info_split['user']: Author of the node linked to users profile. Depends
 *   on permission.
 * - $info_split['date']: Last update of the node. Short formatted.
 * - $info_split['comment']: Number of comments output as "% comments", %
 *   being the count. Depends on comment.module.
 *
 * Other variables:
 * - $classes_array: Array of HTML class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $title_attributes_array: Array of HTML attributes for the title. It is
 *   flattened into a string within the variable $title_attributes.
 * - $content_attributes_array: Array of HTML attributes for the content. It is
 *   flattened into a string within the variable $content_attributes.
 *
 * Since $info_split is keyed, a direct print of the item is possible.
 * This array does not apply to user searches so it is recommended to check
 * for its existence before printing. The default keys of 'type', 'user' and
 * 'date' always exist for node searches. Modules may provide other data.
 * @code
 *   <?php if (isset($info_split['comment'])): ?>
 *     <span class="info-comment">
 *       <?php print $info_split['comment']; ?>
 *     </span>
 *   <?php endif; ?>
 * @endcode
 *
 * To check for all available data within $info_split, use the code below.
 * @code
 *   <?php print '<pre>'. check_plain(print_r($info_split, 1)) .'</pre>'; ?>
 * @endcode
 *
 * @see template_preprocess()
 * @see template_preprocess_search_result()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<article class="<?php print $classes; ?> node-<?php print $node->nid; ?> mobile-1-col tablet-2-col desktop-4-col xxl-desktop-5-col"<?php print $attributes; ?>>
  <div class="person-profile-listing-info-wrapper">
    <div class="column">
      <a href="<?php print $url; ?>" title="Go to <?php print $user_display_name; ?>'s profile">
        <div class="person-highlight-area">
          <div class="person-text-data">
            <div class="person-name-and-title">
              <div class="person-profile-display-name">
                <?php print $user_display_name; ?>
              </div>
              <?php if (isset($user_position_title)): ?>
                <div class="person-profile-position-title-list">
                  <?php print $user_position_title; ?>
                </div>
              <?php endif; ?>
            </div>
          </div>
        </div>
      </a>
      <div class="person-preferred-contact">
        <div class="detail-list-item person-profile-email">
          <div class="field-content">
            <?php
            $detail_item_variables = array(
              'label' => NULL,
              'body' => "<a href=mailto:$user_work_email>Send an email<span class='a11y--hidden'> to $user_display_name</span></a>",
              'classes' => array(
                'detail' => 'detail-item--middle',
                'body' => 'detail-item__body--secondary',
              ),
            );
            print theme('detail_item', $detail_item_variables);
            ?>
          </div>
        </div>
      </div>
    </div>
  </div>
</article>
