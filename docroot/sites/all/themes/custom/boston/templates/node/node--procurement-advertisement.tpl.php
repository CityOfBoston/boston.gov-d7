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
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix desktop-100"<?php print $attributes; ?>>
  <?php if (isset($content['field_updated_date'])): ?>
    <div class="brc-lu">
      Last updated:<?php print render($content['field_updated_date']); ?>
    </div>
  <?php endif; ?>
  <div class="department-info-wrapper desktop-100 clearfix">
    <div class="column mobile-100 desktop-66-left">
      <h1 class="title"><?php print $title; ?></h1>
      <?php if (isset($content['field_intro_text'])): ?>
        <?php print render($content['field_intro_text']); ?>
      <?php endif; ?>
      <?php if (isset($content['body'])): ?>
        <div class="body">
          <?php print render($content['body']); ?>
          <?php if (isset($content['field_procurement_footer'])): ?>
            <?php print render($content['field_procurement_footer']); ?>
          <?php endif; ?>
        </div>
      <?php endif; ?>
    </div>
    <div class="column sidebar mobile-100 desktop-33-right">
      <div class="p-t500">
        <ul class="dl">
          <li class="dl-i">
            <?php if ($is_closed) { ?>
              <?php if ($bid_awarded) { ?>
                <div><strong class="t--sans t--upper t--ob t--s400" data-swiftype-name="bid-status" data-swiftype-type="string">Awarded</strong></div>
              <?php } else { ?>
                <?php if ($not_awarded) { ?>
                  <div><strong class="t--sans t--upper t--err t--s400" data-swiftype-name="bid-status" data-swiftype-type="string">Not Awarded</strong></div>
                <?php } else { ?>
                  <div><strong class="t--sans t--upper t--err t--s400" data-swiftype-name="bid-status" data-swiftype-type="string">Closed</strong></div>
                <?php } ?>
              <?php } ?>
            <?php } else { ?>
              <div class="t--intro">Due: <?php print $due_date ?></div>
            <?php } ?>
          </li>
          <li class="dl-i">
            <span class="t--sans t--upper t--cb t--s100"><?php print render($content['field_procurement']) ?></span>
          </li>
          <li class="dl-i">
            <span class="dl-t">Posted</span>
            <span class="dl-d"><?php print $start_date ?></span>
          </li>
          <li class="dl-i">
            <span class="dl-t">Close<?php if ($is_closed) { ?>d<?php } else { ?>s<?php } ?></span>
            <span class="dl-d"><?php print $end_date ?></span>
          </li>
          <li class="dl-i">
            <span class="dl-t">Type</span>
            <span class="dl-d"><?php print render($content['field_bid_type']) ?></span>
          </li>
          <li class="dl-i dl-i--b">
            <div class="dl-t">Awarded by</div>
            <div class="dl-d"><?php print render($content['field_awarded_by']) ?></div>
          </li>
          <li class="dl-i dl-i--b">
            <div class="dl-t">Project Number</div>
            <div class="dl-d"><?php print render($content['field_event_project_number']) ?></div>
          </li>
          <li class="dl-i dl-i--b">
            <div class="dl-t">UNSPSC</div>
            <div class="dl-d"><?php print render($content['field_unspsc']) ?></div>
          </li>
          <li class="dl-i dl-i--b">
            <div class="dl-t">Questions about this page? Contact:</div>
            <div class="dl-d">
              <div><?php print render($content['field_department']) ?></div>
              <div><?php print render($content['field_address']) ?></div>
              <div><?php print render($content['field_email']) ?></div>
              <div><?php print render($content['field_phone_number']) ?></div>
            </div>
          </li>
          <li class="dl-i dl-i--b">
            <div class="dl-t">Related Links</div>
            <div class="dl-d"><?php print render($content['field_related_links']) ?></div>
          </li>
        </ul>
      </div>
      <?php if (isset($content['field_sidebar_components'])): ?>
        <?php print render($content['field_sidebar_components']); ?>
      <?php endif; ?>
    </div>
  </div>
  <?php if (count($bid_other) > 0 || count($bid_awarded) > 0): ?>
    <div class="b b--b b--fw">
      <div class="b-c">
        <div class="sh sh--w">
          <h2 class="sh-title">Submissions</h2>
        </div>
        <?php if ($not_awarded && $is_closed): ?>
          <div class="m-t500">
            <div class="g">This was not awarded</div>
          </div>
        <?php endif; ?>
        <?php if (count($bid_awarded) > 0 && $content['field_not_awarded'] == 0): ?>
          <div class="m-t500">
            <div class="g">
              <div class="g--2">
                <div class="ta--c--large">
                  <img style="width: 110px" src="data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iODEiIGhlaWdodD0iODEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgeG1sbnM6eGxpbms9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkveGxpbmsiPjxkZWZzPjxwYXRoIGlkPSJhIiBkPSJNMCA1My40NjNoNDUuNzgxVi4yOTNIMHoiLz48L2RlZnM+PGcgdHJhbnNmb3JtPSJ0cmFuc2xhdGUoMiAyKSIgZmlsbD0ibm9uZSIgZmlsbC1ydWxlPSJldmVub2RkIj48ZyB0cmFuc2Zvcm09InRyYW5zbGF0ZSgxNS44MzcgMTQuMTk5KSI+PHBhdGggZD0iTTM4LjQ2NSAxNi41ODhjMi43OTQtMi44NzYgNC4xNy02LjI3NSA0LjE3LTEwLjI5N2gtOS4yM1YxOS42OTFjMCAuMTk0LS4wMi4zODQtLjAzMi41NzVsMS4zODYtLjgyMmMxLjM0Ny0uNzk4IDIuNjE1LTEuNzM0IDMuNzA2LTIuODU2em0tMjcuNDQ0IDIuODU2bDEuMzg2LjgyMmMtLjAxMi0uMTkxLS4wMy0uMzgtLjAzLS41NzVWNi4yOUgzLjE0NGMwIDQuMDIyIDEuMzc3IDcuNDIgNC4xNzEgMTAuMjk3IDEuMDkgMS4xMjIgMi4zNTggMi4wNTggMy43MDUgMi44NTZ6TTMzLjQwNSAzLjQ3SDQ1Ljc4djMuNTU5YzAgNS4xLTIuNTk1IDkuOTQtNy4wODggMTMuMjE1bC03Ljc0NyA1LjY1Yy0xLjMyOCAxLjQ1NC0zLjExNCAyLjUzOS01LjE1MyAzLjA3NnY3LjEwMWMwIDEuMDQ0Ljg0OCAxLjg5MSAxLjg5NCAxLjg5MWE0LjcxNiA0LjcxNiAwIDAgMSA0LjcxNiA0LjcxMkgxMy4zNzdjMC0xLjMuNTI5LTIuNDc4IDEuMzgxLTMuMzNhNC43IDQuNyAwIDAgMSAzLjMzNy0xLjM4MiAxLjg5MiAxLjg5MiAwIDAgMCAxLjg5My0xLjg5di03LjEwM2MtMi4wNC0uNTM3LTMuODI1LTEuNjIxLTUuMTUyLTMuMDc0bC03Ljc0OC01LjY1QzIuNTk1IDE2Ljk2NyAwIDEyLjEzIDAgNy4wMjh2LTMuNTZoMTIuMzc2Vi4yOTNoMjEuMDI5VjMuNDd6IiBmaWxsPSIjRkZGIi8+PG1hc2sgaWQ9ImIiIGZpbGw9IiNmZmYiPjx1c2UgeGxpbms6aHJlZj0iI2EiLz48L21hc2s+PHBhdGggZD0iTTEwLjU2NCA1MS43NTVoMjQuNjU0di03Ljg3M0gxMC41NjR2Ny44NzN6bS0xLjcxIDEuNzA4aDI4LjA3M3YtMTEuMjlIOC44NTN2MTEuMjl6IiBmaWxsPSIjRkZGIiBtYXNrPSJ1cmwoI2IpIi8+PHBhdGggZmlsbD0iI0ZGRiIgbWFzaz0idXJsKCNiKSIgZD0iTTE1LjE4NiA1MC4wOTZoMTUuNDF2LTQuMjRoLTE1LjQxeiIvPjwvZz48Y2lyY2xlIHN0cm9rZT0iI0ZGRiIgc3Ryb2tlLXdpZHRoPSIzIiBjeD0iMzguNSIgY3k9IjM4LjUiIHI9IjM4LjUiLz48L2c+PC9zdmc+" alt="Award" />
                </div>
              </div>
              <div class="g--10">
                <div class="g p-t500">
                  <div class="g--4 t--w t--s400"><strong class="t--upper t--sans">Awarded to:</strong> <span class="t--w"><?php print $bid_awarded[0]['company'] ?></span></div>
                  <div class="g--3 t--w t--s400"><strong class="t--upper t--sans">Amount:</strong> <span class="t--w">$<?php print number_format($bid_awarded[0]['amount']) ?></span></div>
                  <div class="g--5 t--w t--s400"><strong class="t--upper t--sans">Awarded on:</strong> <span class="t--w"><?php print $award_date ?></span></div>
                </div>
              </div>
            </div>
          </div>
        <?php endif; ?>
        <?php if (count($bid_other) > 0): ?>
          <div>
            <div class="dr">
              <input type="checkbox" id="dr-tr1" class="dr-tr a11y--h">
              <label for="dr-tr1" class="dr-h">
                <div class="dr-ic"><svg xmlns="http://www.w3.org/2000/svg" viewBox="-2 8.5 18 25"><path class="dr-i" d="M16 21L.5 33.2c-.6.5-1.5.4-2.2-.2-.5-.6-.4-1.6.2-2l12.6-10-12.6-10c-.6-.5-.7-1.5-.2-2s1.5-.7 2.2-.2L16 21z"/></svg></div>
                <div class="dr-t">See <?php print count($bid_other) ?><?php if (count($bid_awarded) > 0): ?> other<?php endif; ?> submission<?php if (count($bid_other) > 1): ?>s<?php endif; ?></div>
              </label>
              <div class="dr-c">
                <?php 
                  $i = 0;
                  $len = count($array);
                  foreach($bid_other as $bid) { 
                ?>
                  <?php if ($i != 0) { ?>
                    <hr class="m-t200 m-b200" />
                  <?php } ?>
                  <div class="g t--cb">
                    <div class="g--4"><strong><?php print $bid['company'] ?></strong></div>
                    <div class="g--8">
                      <?php if ($bid['amount']) { ?>
                        <strong class="t--upper t--sans">Amount:</strong> $<?php print number_format($bid['amount'], 2) ?>
                      <?php } ?>
                    </div>
                  </div>
                <?php 
                    $i++;
                  } 
                ?>
              </div>
            </div>
          </div>
        <?php endif; ?>
      </div>
    </div>
  <?php endif; ?>
  <?php if (isset($content['field_components']) || isset($content['field_ma_general_law'])): ?>
    <div class="department-components desktop-100" <?php print $content_attributes; ?>>
      <?php if (isset($content['field_ma_general_law'])): ?>
        <?php print render($content['field_ma_general_law']) ?>
      </div>
      <?php endif; ?>
      <?php if (isset($content['field_components'])): ?>
        <?php print render($content['field_components']); ?>
      <?php endif; ?>
    </div>
  <?php endif; ?>
  <?php if (isset($content['field_contacts'])): ?>
    <?php print theme('page_contacts', array('title' => "Who's Involved", 'contacts' => $content['field_contacts'])); ?>
  <?php endif; ?>
</article>
