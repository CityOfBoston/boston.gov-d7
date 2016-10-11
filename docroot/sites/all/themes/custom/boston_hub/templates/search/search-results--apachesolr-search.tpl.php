<?php

/**
 * @file
 * Default theme implementation for displaying search results.
 *
 * This template collects each invocation of theme_search_result(). This and
 * the child template are dependent to one another sharing the markup for
 * definition lists.
 *
 * Note that modules may implement their own search type and theme function
 * completely bypassing this template.
 *
 * Available variables:
 * - $search_results: All results as it is rendered through
 *   search-result.tpl.php
 * - $module: The machine-readable name of the module (tab) being searched, such
 *   as "node" or "user".
 *
 * @see template_preprocess_search_results()
 *
 * @ingroup themeable
 */
?>

<div class="search-results-wrapper">
  <div class="container">
    <?php if ($search_results): ?>
      <?php if (!empty($facets)): ?>
        <div class="apachesolr-facets desktop-33-left <?php print $facet_class; ?>">
          <h3><?php print render($facets['subject']); ?></h3>
          <?php print render($facets['content']); ?>
        </div><!-- end .desktop-33-left -->
      <?php endif; ?>
      <?php if (!empty($search_sort)): ?>
        <div class="apachesolr-facets desktop-33-left">
        <h3>Sort By :</h3>
        <?php print render($search_sort['content']); ?>
      </div><!-- end .desktop-33-left -->
    <?php endif; ?>
      <?php if (!empty($facets)): ?>
        <div class="desktop-66-right">
      <?php else: ?>
        <div class="desktop-100">
      <?php endif; ?>
        <ol class="search-results <?php print $module; ?>-results">
          <?php print $search_results; ?>
        </ol>
        <?php print $pager; ?>
      </div><!-- end .desktop-66-right -->
    <?php endif; ?><!-- search_results -->
  </div><!-- end .container -->
</div> <!-- end .search-results-wrapper -->
