<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */

 $has_email = isset($content['field_email']) && $content['field_email'][0]['#markup'] != "";
 $live_stream = $live_stream_active == 1;
?>

<article id="node-<?php print $node->nid; ?>"
     class="<?php print $classes; ?> calendar-listing-wrapper"
     <?php if (!empty($live_stream)): ?>data-livestream="1"<?php endif; ?>>
  <div class="teaser drawer-trigger">
    <div class="drawer-trigger-chevron"></div>
    <?php if (isset($time_range)): ?>
      <span class="time-range">
        <?php if (!empty($live_stream)) :?><span class="live-stream-flag">Live:</span><?php endif; ?>
        <?php print $time_range; ?>
      </span>
    <?php endif; ?>
    <div class="title">
      <?php if (!empty($live_stream)):?><span class="live-stream-flag">Live:</span><?php endif; ?>
      <?php if (!empty($is_cancelled)):?><span class="t--err">Canceled: </span><span class="td-str"><?php endif; ?>
      <?php print $title; ?>
        <?php if (!empty($is_cancelled)):?></span><?php endif; ?>
    </div>
  </div>
  <div class="event-details drawer">
    <?php if (isset($content['field_address'])): ?>
      <div class="list-item">
        <?php print render($content['field_address']); ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($has_email)): ?>
      <div class="list-item">
        <?php print render($content['field_email']); ?>
      </div>
    <?php endif; ?>
    <?php if (isset($content['field_phone_number'])): ?>
      <div class="list-item">
        <?php print render($content['field_phone_number']); ?>
      </div>
    <?php endif; ?>
    <?php if (isset($content['field_cost'])): ?>
      <div class="list-item">
        <?php print render($content['field_cost']); ?>
      </div>
    <?php endif; ?>
    <?php if (isset($content['field_links'])): ?>
      <div class="list-item">
        <?php print render($content['field_links']); ?>
      </div>
    <?php endif; ?>

    <?php if (!empty($is_cancelled)): ?>
      <div class="description supporting-text">Reason for cancellation:<br/>
        <?php
        if (isset($field_extra_info_event['und'][0]['safe_value'])) {
          print $field_extra_info_event['und'][0]['safe_value'];
        }
        else {
          print "Please contact organizer.";
        }
        ?>
      </div>
    <?php else: ?>
      <?php if (isset($content['field_intro_text'])): ?>
        <div class="description">
          <?php print render($content['field_intro_text']); ?>
        </div>
      <?php endif; ?>
    <?php endif; ?>



    <?php if (isset($content['field_details_link'])): ?>
      <div class="external-link external-link--inline">
        <a class="button" href="<?php print render($content['field_details_link']); ?>">Event website<span class="a11y--hidden"> for <?php print $title; ?></span></a>
      </div>
    <?php else: ?>
      <?php if (!empty($live_stream)): ?>
        <a class="button live-stream" href="<?php print $node_url; ?>" title="Live stream for <?php print $title; ?>">Event details<span class="a11y--hidden"> for <?php print $title; ?></span></a>
      <?php else: ?>
        <a class="button" href="<?php print $node_url; ?>" title="get more details">Event details<span class="a11y--hidden"> for <?php print $title; ?></span></a>
      <?php endif; ?>
    <?php endif; ?>
  </div>
</article>
