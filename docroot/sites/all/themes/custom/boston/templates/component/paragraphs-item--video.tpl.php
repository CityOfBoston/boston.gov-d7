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

 $id = uniqid();
 $live_stream_start = $content['field_event_dates']['#object']->field_event_dates['und']['0']['value'];
 $live_stream_start = new DateTime($live_stream_start, new DateTimeZone('UTC'));
 $live_stream_start->setTimeZone(new DateTimeZone('America/New_York'));
?>

<!-- script goes here -->
<div class="<?php print $classes; ?>">
  <?php if (isset($content['field_short_title'])) : ?>
    <?php print render($content['field_short_title']); ?>
  <?php endif; ?>
  <div id="plyr__<?php print $id; ?>" data-video-id="<?php print trim(render($content['field_extra_info'])); ?>" class="plyr">
    <div id="plyr__<?php print $id; ?>">
      <?php print render($content['field_image']) ?>
      <div id="plyr__vid--<?php print $id; ?>" class="plyr__video"></div>
      <div class="plyr__overlay"></div>
      <div class="plyr__meta">
        <h2 class="sh plyr__title"><?php print render($content['field_title']) ?></h2>
	<?php if (isset($content['field_contact'])) : ?>
        <div class="plyr__credit">
	  Credit: <?php print_r($field_contact[0]['entity']->name) ?>
      	</div>
	<?php endif; ?>
        <div class="plyr__play">
	  <img src="/<?php print drupal_get_path('theme', $GLOBALS['theme']); ?>/dist/img/icon-play.svg" alt="Play <?php print render($content['field_title']) ?>" />
	  <div class="plyr__livestream-not_ready">This live stream event hasn't started.<br />Check back in <span id="plyr__livestream-countdown"></span></div>	  
	</div>
      </div>
    </div>
  </div>
</div>


<script>
function initVideo(){
  vids['<?php print $id; ?>'].button.addEventListener('click', function() {
    vids['<?php print $id; ?>'].video = new YT.Player('plyr__vid--<?php print $id; ?>' , {
      videoId: vids['<?php print $id; ?>'].button.getAttribute('data-video-id'),
      height: "100%",
      width: "100%",
      events: {
          'onReady': function(event) {
          event.target.playVideo();
          }
      }
    });
    vids['<?php print $id; ?>'].button.classList.toggle("plyr--isPlaying");
  });
}

function initLiveStreamClock(id, endtime){
  var clock = document.getElementById(id);
  var timeinterval = setInterval(function(){
    var t = getTimeRemaining(endtime);
    clock.innerHTML = t.days + ' days ' +
            t.hours + ' hours ' +
            t.minutes + ' minutes ' +
            t.seconds + ' seconds';
      if(t.total <= 0){
        clearInterval(timeinterval);
	playerElement.style.cssText = "width: 15%; max-width: 100px; cursor: pointer;";
	imgButton.style.cssText = "display: block; width: auto; height: auto;";
	liveStreamTxt.style.cssText = "display: none;";
	initVideo();
      }
  },1000);
 }

function getTimeRemaining(endtime){
    var t = endtime - Date.parse(new Date());
    var seconds = Math.floor( (t/1000) % 60 );
    var minutes = Math.floor( (t/1000/60) % 60 );
    var hours = Math.floor( (t/(1000*60*60)) % 24 );
    var days = Math.floor( t/(1000*60*60*24) );
    return {
  'total': t,
      'days': days,
      'hours': hours,
      'minutes': minutes,
      'seconds': seconds
      };
}

function liveStreamNotReady(){
    playas = doc.getElementsByClassName('plyr__play');
    n = playas.length;
    imgButton.style.cssText = "display: none;"
    liveStreamTxt.style.cssText = "display: block;";
    playerElement.style.cssText = "width:100%; max-width:100%; cursor: default; display: block;";
    while(n--) {
      playas[n].style.width = '100%';
    }
}

var doc = document;
var vids = vids || {};
var live_stream_status = <?php echo($field_live_stream[0]['value']) ?>;
imgButton = doc.querySelector("article .plyr__play img");
liveStreamTxt = doc.querySelector("article .plyr__play div");
playerElement = doc.querySelector("article .plyr__play");
vids['<?php print $id; ?>'] = { button: document.getElementById("plyr__<?php print $id; ?>") };

if (live_stream_status == 1) {
  var live_stream_start = new Date('<?php echo($live_stream_start->format('Y-m-d H:i:s T')); ?>');
  var isLiveStreamStart = live_stream_start.getTime();
  var isNow = new Date().getTime();
  var goTime;
  if (isNow < isLiveStreamStart) {
     liveStreamNotReady();
     initLiveStreamClock('plyr__livestream-countdown', isLiveStreamStart);
     } else {
     initVideo();
  }
} else {
  initVideo();
}
</script>