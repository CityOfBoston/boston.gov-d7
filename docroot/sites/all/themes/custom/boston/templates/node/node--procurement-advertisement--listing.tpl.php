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
hide($content['comments']);
hide($content['links']);
?>

<div class="g g--m0 n-li">
  <div class="g--5 n-li-b n-li-b--br">
    <div class="n-li-t"><a href="<?php print $node_url; ?>" title="<?php print $title; ?>"><?php print $title; ?></a></div>
    <div class="m--b300 t--sans t--upper t--g300 t--s300 lh--000"><?php print render($content['field_event_project_number']); ?></div>
    <?php if ($is_closed) { ?>
      <?php if ($bid_awarded) { ?>
        <div class="n-li-a"><span class="t--sans t--upper t--cb t--s300">Awarded</span></div>
      <?php } else { ?>
        <?php if ($not_awarded) { ?>
          <div><strong class="t--sans t--upper t--err t--s300" data-swiftype-name="bid-status" data-swiftype-type="string">Not Awarded</strong></div>
        <?php } else { ?>
          <div><strong class="t--sans t--upper t--err t--s300" data-swiftype-name="bid-status" data-swiftype-type="string">Closed</strong></div>
        <?php } ?>
      <?php } ?>
    <?php } ?>
  </div>
  <div class="g--7 n-li-b">
    <div class="g g--m0">
      <div class="g--10">
        <ul class="dl">
          <li class="dl-i">
            <span class="dl-t">Due</span>
            <span class="dl-d"><?php print $end_date ?></span>
          </li>
          <?php if (isset($content['field_address'])): ?>
            <li class="dl-i">
              <span class="dl-t">Type</span>
              <span class="dl-d"><?php print render($content['field_procurement']) ?></span>
            </li>
          <?php endif; ?>
          <?php if (isset($start_date)): ?>
            <li class="dl-i">
              <span class="dl-t">Posted</span>
              <span class="dl-d"><?php print $start_date ?></span>
            </li>
          <?php endif; ?>
        </ul>
      </div>
      <div class="g--2 n-li-ic">
        <?php print render($content['field_contact']); ?>
      </div>
    </div>
  </div>
</div>
