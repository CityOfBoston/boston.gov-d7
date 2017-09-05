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

$has_sidebar = isset($content['field_sidebar_components']) || isset($content['field_program_logo']);

?>
<article id="node-<?php print $node->nid; ?>" class="relative-free-article clearfix">
  <?php if (isset($content['field_updated_date'])): ?>
    <div class="brc-lu brc-lu--hack">
      Last updated: <?php print render($content['field_updated_date']); ?>
    </div>
  <?php endif; ?>
  <div class="program-info-wrapper desktop-100">
    <div class="column mobile-100<?php if ($has_sidebar) { ?> desktop-66-left<?php } ?>">
      <h1 class="title"><?php print $title; ?></h1>
      <?php if (isset($content['field_intro_text'])): ?>
        <?php print render($content['field_intro_text']); ?>
      <?php endif; ?>
      <div class="sub-nav-trigger drawer-trigger">
        <div class="sub-nav-chevron"><?php print file_get_contents(drupal_get_path('theme', $GLOBALS['theme']) . '/dist/img/subnav-toggle.svg') ?></div>
        Program Menu
      </div>
      <nav class="topic-nav topic-nav__left">
        <ul></ul>
        <a name="section-nav"></a>
      </nav>
      <?php if (isset($content['body'])): ?>
        <div class="body">
          <?php print render($content['body']); ?>
        </div>
      <?php endif; ?>
    </div>
    <?php if ($has_sidebar) { ?>
      <div class="column mobile-100 desktop-33-right">
        <?php if (isset($content['field_program_logo'])): ?>
          <div class="program-logo">
            <?php print render($content['field_program_logo']); ?>
          </div>
        <?php endif; ?>
        <?php if (isset($content['field_sidebar_components'])): ?>
          <?php print render($content['field_sidebar_components']); ?>
        <?php endif; ?>
      </div>
    <?php } ?>
    <div class="clearfix"></div>
  </div>
  <?php if (isset($content['field_components'])): ?>
  <div class="program-components desktop-100" <?php print $content_attributes; ?>>
    <?php print render($content['field_components']); ?>
  </div>
  <?php endif; ?>
  <?php print theme('page_contacts', array('title' => "Who's Involved", 'contacts' => $content['field_contacts'])); ?>


</article>
