<?php
/**
 * @file
 * Default template for an advanced poll bar.
 *
 * Based on default Drupal Poll template.
 *
 * Variables available:
 * - $title: The title of the poll.
 * - $votes: The number of votes for this choice
 * - $percentage: The percentage of votes for this choice.
 * - $vote: The choice number of the current user's vote.
 * - $voted: Set to TRUE if the user voted for this choice.
 */

// Add extra class to wrapper so that user's selected vote can have a different
// style.
$voted_class = $voted ? 'voted' : '';
?>
<!-- destination for circle code -->
<div data-percent="<?php print $percentage; ?>"
     data-text="<?php print $title; ?>"
     class="circles_container inner_circle"></div>
