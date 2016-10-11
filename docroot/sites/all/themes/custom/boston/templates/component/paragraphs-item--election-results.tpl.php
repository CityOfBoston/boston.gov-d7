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

    function fetchResults() {
      var request = createCORSRequest('GET', sourceLink.href);

      request.onload = function() {
        if (request.status >= 200 && request.status < 400) {
          var resp = request.responseText;
          container.innerHTML = resp;
          console.log('LOADED!');
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

<style>
#resultsContainer > br {
  display: none;
}

#resultsContainer table {
  width: 100%;
  margin: 0;
  max-width: 100%;
}

@media screen and (min-width: 768px) {
  #resultsContainer table {
    max-width: 63%;
  }
}

#resultsContainer > table:nth-child(1) {
  border: none;
}

#resultsContainer > table:nth-child(1) table > tbody > tr > td {
  display: block;
  width: 100%;
  padding: 0;
}

#resultsContainer > table:nth-child(1) table > tbody > tr > td:nth-child(1) {
  display: none;
}

#resultsContainer > table:nth-child(1) table {
  margin: 0;
  border: none;
}

#resultsContainer > table:nth-child(1) table > tbody > tr > td:nth-child(3):before {
  content: 'Last updated: ';
}

#resultsContainer > table:nth-child(1) table > tbody > tr > td:nth-child(3) br {
  display: none;
}

#resultsContainer > table:nth-child(3) {
  border: none;
}

#resultsContainer > table:nth-child(3) td {
  display: block;
  width: 100%;
}

#resultsContainer table h4 {
  margin: 0;
}

#resultsContainer table td {
  text-align: left;
}

#resultsContainer table {
  border: 5px solid #f3f3f3;
  margin-bottom: 35px;
}

#resultsContainer table table {
  border: none;
  width: 100%;
  max-width: 100%;
  margin: 0;
}

#resultsContainer table table hr {
  margin: 15px 0;
}


#resultsContainer table table td, #resultsContainer table table th {
  padding: 0.5em;
  word-break: break-all;
  font-size: 0.66em;
  line-height: 1.2;
}

@media screen and (min-width: 768px) {
  #resultsContainer table table td, #resultsContainer table table th {
    font-size: 0.75em;
    padding: 1em;
  }
}

@media screen and (min-width: 900px) {
  #resultsContainer table table td, #resultsContainer table table th {
    font-size: 1em;
  }
}
</style>
