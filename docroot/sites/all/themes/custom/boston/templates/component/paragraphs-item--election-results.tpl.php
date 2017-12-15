<?php
/**
 * @file
 * Default theme implementation for a single paragraph item.
 *
 * Available variables:
 * - $content: An array of content items. Use render($content) to print them
 *   all, or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity
 *   - entity-paragraphs-item
 *   - paragraphs-item-{bundle}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened into
 *   a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div id="resultsContainer" class="content"<?php print $content_attributes; ?>>
    <a id="sourceLink" href="<?php print render($content['field_source_url']) ?>" class="button">View unofficial election results</a>
  </div>
</div>

<style>
  .table-results table td {
    color: #091F2F;
  }

  .table-results .sh-title {
    word-break: break-all;
  }

  .table-1 {
    font-style: italic;
    font-weight: bold;
    width: 100%;
    padding-left: 0;
    padding-right: 0;
    word-break: break-all;
    margin: 0;
  }

  .table-1 td {
    display: block;
    text-align: left;
  }

  .table-2 {
    margin-top: 0;
  }

  .table-results table tr td:first-child {
    font-style: italic;
    font-weight: bold;
    width: 40%;
    padding-left: 0;
    padding-right: 0;
    word-break: break-all;
  }

  .table-results table tr td {
    padding: 0.45rem 0.5rem;
    font-size: 16px;
    width: 20%;
    line-height: 1.2;
  }

  .table-results table tr td:last-child {
    padding-right: 0;
  }

  .table-results table .table-total td {
    border-bottom: 1px solid #e2e2e2;
    padding-top: 0.75rem;
    padding-bottom: 0.5rem;
  }

  .table-results hr {
    margin: 0.5rem 0;
    background: none;
    border-top: 1px dotted #e2e2e2;
  }
</style>

<script>
  function ready(fn) {
    if (document.readyState != 'loading'){
      fn();
    } else {
      document.addEventListener('DOMContentLoaded', fn);
    }
  }

  function createCORSRequest(method, url) {
    var xhr = new XMLHttpRequest();
    if ("withCredentials" in xhr) {
      // Check if the XMLHttpRequest object has a "withCredentials" property.
      // "withCredentials" only exists on XMLHTTPRequest2 objects.
      xhr.open(method, url, true);
    } else if (typeof XDomainRequest != "undefined") {
      // Otherwise, check if XDomainRequest.
      // XDomainRequest only exists in IE, and is IE's way of making CORS requests.
      xhr = new XDomainRequest();
      xhr.open(method, url);
    } else {
      // Otherwise, CORS is not supported by the browser.
      xhr = null;
    }
    return xhr;
  }

  var ElectionResults = (function( window, undefined ) {
    var container = document.getElementById('resultsContainer');
    var sourceLink = document.getElementById('sourceLink');

    function removeBR() {
      var brs = document.querySelectorAll('#resultsContainer br');

      for (var i = 0; i < brs.length; i++) {
        brs[i].parentNode.removeChild(brs[i]);
      }
    }

    function tagTables() {
      for (var i = 0; i < container.childNodes.length; i++) {
        if (container.childNodes[i].nodeName == 'TABLE') {
          if (i > 0) {
            container.childNodes[i].className = 'table-results table-' + i;
          }
        }
      }

      var tablesToClean = document.querySelectorAll('#resultsContainer > table:not(.table-results)');
      for (var i = 0; i < tablesToClean.length; i++) {
        container.removeChild(tablesToClean[i]);
      }
    }

    function fixHeader() {
      var sections = document.querySelectorAll('.table-results table tr:first-child');
      for (var i = 0; i < sections.length; i++) {
        var block = sections[i];

        for (var j = 0; j < block.childNodes.length; j++) {
          if (block.childNodes[j].nodeName == 'TD' || block.childNodes[j].nodeName == 'TH') {
            if (j === 1) {
              block.childNodes[j].colSpan = 4;
              block.childNodes[j].style.width = '100%'

              var title = block.childNodes[j].innerHTML;
              block.childNodes[j].innerHTML = "<div class='sh' style='margin-bottom: 0'><div class='sh-title'>" + title + "</div></div>";
            } else {
              block.removeChild(block.childNodes[j]);
            }
          }
        }
      }
    }

    function setTotalBar() {
      var totals = document.querySelectorAll('.table-results table tr:nth-child(2)');
      var totalTD = document.querySelectorAll('.table-results table tr:nth-child(2) td:last-child');

      for (var i = 0; i < totals.length; i++) {
        totals[i].className = 'table-total';
      }

      for (var i = 0; i < totalTD.length; i++) {
        totalTD[i].colSpan = 2;
      }
    }

    function cleanupResults() {
      removeBR();
      setLastUpdated();
      tagTables();
      fixHeader();
      setTotalBar();
    }

    function fetchResults() {
      var request = createCORSRequest('GET', sourceLink.href);

      request.onload = function() {
        if (request.status >= 200 && request.status < 400) {
          var resp = request.responseText;
          container.innerHTML = resp;
          cleanupResults();
        } else {
          console.log('There was an error loading the results.')
        }
      };

      request.send();
    }

    function init() {
      fetchResults();

      setInterval(function () {
        fetchResults();
      }, 500000)
    }

    return {
      init: init
    };

  })( window );

  ready(ElectionResults.init);
</script>
