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

<?php if ($search_results): ?>
<div class="filter-wrapper clearfix">
  <?php if (!empty($search_sort)): ?>
    <div class="apachesolr-facets <?php print $facet_class; ?> solr-search-sort mobile-hide">
      <div class="solr-sort-button">
        <?php print render($search_sort['content']); ?>
        <div class="drawer-trigger-chevron"></div>
      </div>
    </div><!-- end .solr-search-sort -->
  <?php endif; ?>
  <?php if (!empty($facets)): ?>
    <div class="apachesolr-facets <?php print $facet_class; ?> solr-search-filter">
      <button class="drawer-trigger button">
        <?php print render($facets['subject']); ?>
        <div class="drawer-trigger-chevron"></div>
      </button>
      <div class="drawer"><?php print render($facets['content']); ?></div>
    </div><!-- end .solr-search-filter -->
  <?php endif; ?>
  <?php if (!empty($search_sort)): ?>
    <div class="apachesolr-facets <?php print $facet_class; ?> solr-search-sort mobile-show">
      <button class="button">
        <?php print render($search_sort['content']); ?>
        <div class="drawer-trigger-chevron"></div>
      </button>
    </div><!-- end .solr-search-sort -->
  <?php endif; ?>
  <?php if (!empty($search_sort) || !empty($facets)): ?>
    <div>
      <a class="button refresh-button" href="/employee-directory" title="Refresh Results"> </a>
      </a>
    </div>
  <?php endif; ?>
</div><!-- end .filter-wrapper -->
<div class="department-list-link"><a href="<?php print $departments_link; ?>" title="Go to Deparment List">Browse a department list</a></div>
<div class="search-results-wrapper">
  <div class="container">
      <div class="employee-directory-results b b--fw b--g">
        <div class="container">
          <ol class="search-results <?php print $module; ?>-results g">
            <?php print $search_results; ?>
          </ol>
          <?php print $pager; ?>
        </div><!-- end .container -->
      </div>
    <?php endif; ?><!-- search_results -->
  </div><!-- end .container -->
</div> <!-- end .search-results-wrapper -->
