<?php
/**
 * @file
 * Template for poll stub.
 */
// This needs to be called so that the proper JS is loaded and attached to the
// page. Otherwise AJAX submission of the poll's form will not be possible.
render($content);
?>
<div class="poll-stub" data-poll-id="<?php print $nid; ?>">

</div>
