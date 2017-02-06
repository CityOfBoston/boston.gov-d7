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
?>

<?php if(!$is_expired): ?>
  <article id="node-<?php print $node->nid; ?>"
           class="<?php print $classes; ?> event-featured-item-wrapper clearfix">
    <div class="desktop-2-col featured-item-details featured-item-details--relative">
      <div class="date-flag date-flag--blue date-flag--left">
        <?php if (isset($content['field_public_notice_date'])): ?>
          <?php print render($content['field_public_notice_date']); ?>
        <?php endif; ?>
      </div>
      <h3 class="featured-event-title">
        <?php print render($title); ?>
        <div class="department-title" style="font-style:normal;">
          <?php print render($content['field_contact']); ?>
        </div>
      </h3>
      <?php if (isset($content['field_intro_text'])): ?>
        <div class="featured-description">
          <?php print render($content['field_intro_text']); ?>
        </div>
      <?php endif ?>
      <?php if (isset($content['field_details_link'])): ?>
        <div class="external-link external-link--inline">
          <a class="button" href="<?php print render($content['field_details_link']); ?>">Event website<span class="a11y--hidden"> for <?php print $title; ?></span></a>
        </div>
      <?php else: ?>
        <a class="button" href="<?php print $node_url; ?>">Notice details<span class="a11y--hidden"> for <?php print $title; ?></span></a>
      <?php endif; ?>
    </div>
    <div class="desktop-2-col featured-item-thumb" style="background-color: #091f2f;">
      <div class="featured-thumb-wrapper">
        <div class="featured-banner">Featured</div>
        <?php if (isset($content['field_thumbnail'])): ?>
          <?php print render($content['field_thumbnail']); ?>
        <?php else: ?>
          <img src="/<?php print drupal_get_path('theme', $GLOBALS['theme']) ?>/dist/img/icon-public_notice.svg" />
        <?php endif; ?>
      </div>
    </div>
  </article>
<?php endif; ?>
