<?php
/**
 * @file
 * Javascript to check for alerts
 *
 */
?>
<script id="alert_script">
  'use strict'

  var BostonAlert = (function () {
    var el = document.getElementById('sa');
    var seal = document.getElementById('seal');
    var exclude = true;

    function getAlert() {
      var request = new XMLHttpRequest();

      request.open('GET', '/api/v1/alerts/site?response_type=embed&' + Math.round(new Date().getTime() / 1000), true);
      request.onload = function() {
        if (request.status >= 200 && request.status < 400) {
          var resp = request.responseText;

          if (resp.length > 0) {
            var classes = el.getAttribute('data-classes');
            var target = el.getAttribute('data-target');

            el.innerHTML = resp;

            var alert = document.getElementById('sa-a');

            if (alert) {
              var excludes = alert.getAttribute('data-excludes');
              
              if (target === ""  ||  excludes.indexOf(target) == -1) {
                exclude = false;
                el.style.display = 'block';
                document.getElementById('page').className = classes;
              }
            }
          }

          if (exclude) {
            el.parentElement.removeChild(el);
          } else {
            seal.parentElement.removeChild(seal);
          }

          var script = document.getElementById('alert_script');
          script.parentElement.removeChild(script);
        }
      };

      request.send();
    }

    return {
      getAlert: getAlert
    }
  })()

  BostonAlert.getAlert()
</script>
