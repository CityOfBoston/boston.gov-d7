(function($) {
    Drupal.behaviors.bosContentTypeEmergencyAlert = {
        'attach': function(context) {
            $('.view-status-displays').once("emergency-override", function() {
                $.get( "/emergency-alert", null, callback);
            });
        }
    };

    var callback = function(response) {
        if(response.emergency) {
            var element = $('.view-status-displays');
            element.html(response.html);
        }
    }
})(jQuery);
