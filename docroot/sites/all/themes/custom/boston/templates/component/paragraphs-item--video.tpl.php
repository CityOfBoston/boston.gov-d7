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
        <div class="plyr__credit"><?php print render($content['field_photo_credit']) ?></div>
        <div class="plyr__play"><img src="/<?php print drupal_get_path('theme', $GLOBALS['theme']); ?>/dist/img/icon-play.svg" alt="Play <?php print render($content['field_title']) ?>" /></div>
      </div>
    </div>
  </div>
</div>


<script>
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
    event_listing = doc.getElementById(event_id);
    playas = doc.getElementsByClassName('plyr__play');
    n = playas.length;
    styleUpdate = "width:100%; max-width:100%; cursor: default;";
    doc.querySelector("article.live-stream-1 .plyr__play").style.cssText = styleUpdate;
    while(n--) {
    playas[n].style.width = '100%';
      playas[n].innerHTML = 'This live stream event hasn\'t started. Check back in \<span id\=\"\plyr__livestream-countdown\"\>\<\/span\>.'
  }
}

var doc = document;
var vids = vids || {};
var live_stream_status = live_stream_status || 0;
vids['<?php print $id; ?>'] = {
    button: document.getElementById("plyr__<?php print $id; ?>")
}


if (live_stream_status == 1) {
  var isLiveStreamStart = live_stream_start.getTime();
  var isNow = new Date().getTime();
  var goTime;
  if (isNow < isLiveStreamStart) {goTime = 0;} else {goTime = 1;}
}

if ( live_stream_status == 1 && goTime == 0 ) {
    liveStreamNotReady();
    initLiveStreamClock('plyr__livestream-countdown', isLiveStreamStart);
} else if ( live_stream_status == 1 && goTime == 1 ) {
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
} else {
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
</script>