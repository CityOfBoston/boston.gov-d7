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
<link href='//cob-cityscore.herokuapp.com/assets/fenway.css' rel='stylesheet' type='text/css' />

<div class="sh">
  <?php if (isset($content['field_component_title'])): ?>
    <?php print render($content['field_component_title']); ?>
  <?php endif; ?>
</div>
<div class="cs">
  <div class="cs__block--chart cs--block">
    <ul class="cs--chart">
      <li class="cs--chartPoint">
        <span class="cs--large cs--less">&lt;</span>
        <p>
          <?php if (isset($content['field_extra_info'])): ?>
            <?php print render($content['field_extra_info']); ?>
          <?php endif; ?>
        </p>
      </li>
      <li class="cs--chartPoint">
        <span>1.0</span>
      </li>
      <li class="cs--chartPoint">
        <span class="cs--large cs--greater">&gt;</span>
        <p>
          <?php if (isset($content['field_short_description'])): ?>
            <?php print render($content['field_short_description']); ?>
          <?php endif; ?>
        </p>
      </li>
      <li class="cs--chartAmount">
        <span class="cs--chartAmount--label">Today's Score</span>
        <strong class="cs--chartAmount--value">-</strong>
      </li>
    </ul>
  </div>
  <div id="scoreTable" class="cs--block"></div>
</div>

<script>
  var CityScore = (function( window, undefined ) {
    var numberDisplay = document.querySelector('.cs--chartAmount--value');
    var numberContainer = document.querySelector('.cs--chartAmount');
    var dateContainer = document.querySelector('.brc-lu');
    var dateDisplay = document.querySelector('.date-display-single');
    var todaysScore = false;

    // Hide the date container
    dateContainer.style.display = 'none';

    function handleResize() {
      renderTodaysScore(todaysScore);
    }

    function loadScores() {
      jQuery.ajax({
        url: "//cob-cityscore.herokuapp.com/scores/latest",
        type:'GET',
        contentType: 'text/plain',
        dataType: "html",
        success: function( html ){
          jQuery('#scoreTable').html( html );
        }
      });
    }

    function loadTodaysScore() {
      jQuery.getJSON( "//cob-cityscore.herokuapp.com/totals/latest" )
        .done(function( json ) {
          if (json.day) {
            todaysScore = json.day;
            renderDateUpdated(json.date_posted);
            renderTodaysScore(json.day);

            // Then start to load other scores
            loadScores();
          } else {
            renderError("The day value is missing from the total response");
          }
        })
        .fail(function( jqxhr, textStatus, error ) {
          var err = textStatus + ", " + error;
          console.log( "Request Failed: " + err );
          dateContainer.style.display = 'block';
        });
    }

    function percentIt(num) {
      var num = num;

      if (num > 1) {
        num = "100%";
      } else if (num < 0) {
        num = "0%";
      } else {
        num = (num * 100) + "%";
      }

      return num;
    }

    function renderDateUpdated(date) {
      dateDisplay.innerHTML = date;
      dateContainer.style.display = 'block';
    }

    function renderTodaysScore(score) {
      var score = roundIt(score);
      var percentage = percentIt(score / 2);

      numberDisplay.innerHTML = score;

      if (document.body.clientWidth > 767) {
        numberContainer.style.top = 'auto';
        numberContainer.style.left = percentage;
      } else {
        numberContainer.style.left = '50px';
        numberContainer.style.top = percentage;
      }
    }

    function renderError(msg) {
      console.log(msg)
    }

    function roundIt(num) {
      return Math.round(num * 100) / 100;
    }

    function init() {
      jQuery.support.cors = true;
      loadTodaysScore();
    }

    return {
      init: init,
      handleResize: handleResize
    };

  })( window );

  jQuery(document).ready(CityScore.init);
  jQuery(window).resize(CityScore.handleResize);
</script>
