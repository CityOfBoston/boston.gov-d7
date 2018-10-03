<?php
  /**
   * @file
   * Library for connecting to Swiftype.
   */
  $info = $results['body']->info;
  $search_term = $info->page->query;
  $has_results = $info->page->total_result_count > 0;
  $records = $results['body']->records->page;
  $facets = $info->page->facets->type;
?>
<form id="searchForm" class="m-t500" action="<?php print $bos_search_url; ?>" accept-charset="UTF-8" method="get">
  <input name="utf8" type="hidden" value="✓">
  <div class="b b--fw">
    <div class="b-c b-c--ntp" style="margin-top: -25px">
      <div class="sf">
        <div class="sf-i">
          <input type="text" name="query" id="query" class="sf-i-f" value="<?php print $search_term ?>">
          <button class="sf-i-b">Search</button>
        </div>
      </div>
    </div>
  </div>
  <div class="b b--fw b--g">
    <div class="b-c b-c--mh">
      <?php if ($has_results) { ?>
        <div class="g m-t000">
            <?php if ($facets) { ?>
              <div class="g--3">
                <div class="co">
                  <input id="collapsible" type="checkbox" class="co-f d-n" aria-hidden="true">
                  <label for="collapsible" class="co-t">Filter</label>
                  <div class="co-b co-b--pl">
                    <div class="t--intro m-b200">Filter by type</div>
                    <div class="m-b300">
                      <?php foreach ($facets as $key => $facet) { ?>
                        <?php if (bos_swiftype_facet_type($key)) { ?>
                          <label class="cb" for="check_<?php print $key ?>">
                            <input type="checkbox" name="facet[]" id="check_<?php print $key ?>" value="<?php print $key ?>" class="cb-f" <?php if(in_array($key, $selected_facets)) { ?>checked<?php } ?>>
                            <span class="cb-l"><?php print bos_swiftype_facet_type($key) ?> (<?php print $facet ?>)</span>
                          </label>
                        <?php } ?>
                      <?php } ?>
                    </div>
                    <button type="submit" class="btn btn--sb">Apply</button>
                    <script type="text/javascript">
                      var reset_button = document.getElementById('resetForm');

                      reset_button.style.display = 'inline-block';
                      reset_button.addEventListener('click', function (e) {
                        e.preventDefault()

                        var checks = document.querySelectorAll('input.cb-f');
                        for (var i = 0; i < checks.length; i++) {
                          checks[i].checked = false;
                        }

                        document.getElementById('searchForm').submit();
                      });
                    </script>
                  </div>
                </div>
              </div>
            <?php } ?>
            <div class="g--9">
              <ul class="m-a000 p-a000">
                <?php foreach ($records as $key => $record) { ?>
                  <li class="n-li">
                    <a class="n-li-b n-li-b--r n-li-b--fw n-li--in g g--mt0" href="<?php print bos_swiftype_result_url($record, $search_term) ?>">
                      <div class="n-li-t g--8"><?php print(bos_swiftype_clean_result($record->title)) ?></div>
                      <div class="n-li-ty n-li-ty--r g--44 ta--r"><?php print bos_swiftype_facet_type($record->type) ?></div>
                    </a>
                  </li>
                <?php } ?>
              </ul>
              <?php if ($info->page->num_pages > 1) { ?>
                <ul class="pg">
                  <li class="pg-li">
                    <?php if ($info->page->current_page > 1) { ?>
                      <a class="pg-li-i pg-li-i--a pg-li-i--link" href="<?php print $bos_search_url; ?>?page=<?php print $info->page->current_page - 1 ?>&amp;query=<?php print $search_term ?>&amp;<?php print http_build_query(array('facet' => $selected_facets)) ?>">
                        <span class="pg-li-i-h">&lt; previous</span>
                      </a>
                    <?php } else { ?>
                      <span class="pg-li-i">&lt; previous</span>
                    <?php } ?>
                  </li>
                  <?php foreach ($range as $number) { ?>
                    <li class="pg-li"><a class="pg-li-i pg-li-i--link<?php if ($number == $info->page->current_page) { ?> pg-li-i--a<?php } ?>" href="<?php print $bos_search_url; ?>?page=<?php print $number ?>&amp;query=<?php print $search_term ?>&amp;<?php print http_build_query(array('facet' => $selected_facets)) ?>"><?php print $number ?></a></li>
                  <?php } ?>
                  <li class="pg-li">
                    <?php if ($info->page->current_page === $info->page->num_pages) { ?>
                      <span class="pg-li-i">next &gt;</span>
                    <?php } else { ?>
                      <a class="pg-li-i pg-li-i--a pg-li-i--link" href="<?php print $bos_search_url; ?>?page=<?php print $info->page->current_page + 1 ?>&amp;query=<?php print $search_term ?>&amp;<?php print http_build_query(array('facet' => $selected_facets)) ?>">
                        <span class="pg-li-i-h">next &gt;</span>
                      </a>
                    <?php } ?>
                  </li>
                </ul>
              <?php } ?>
            </div>
          </div>
      <?php } else { ?>
        <h2 class="h2 m-t000 m-b300">No Results Found</h2>
        <div class="intro-text supporting-text lh--200">Thomas Paine noted "These are the times that try men's souls." Well this is a time to try another search.</div>
      <?php } ?>
    </div>
  </div>
</form>
<div class="b">
  <div class="b-c">
    <div class="h2 tt-u ta-c p-h300">Can't find what you're looking for?</div>
    <hr class="hr hr--sq m-h300 m-v500">
    <div class="ta-c p-h200 t--intro">
      Our 311 operators are available 24/7 to help point you in the right direction. Call <a href="tel:311">311</a>, or <a href="tel:617-635-4500">617-635-4500</a>.
    </div>
  </div>
</div>
