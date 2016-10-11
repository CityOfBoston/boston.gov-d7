<?php
/**
 * @file
 * Default template for an advanced poll when results are not available.
 *
 * Conditions under which template will display:
 * 1. When results are set to 'Never' - results will only be visible to those
 *    with permission to view them.
 * 2. When results are set to 'After Close' - results will only be visible when
 *    poll is set to closed.
 *
 * Variables available:
 * - $votes
 * - $nid: Node id of the poll.
 * - $cancel_form: Provides a form for deleting user's votes when they have
 *   permission to do so.
 *
 *   An array containing unique ids of the choice(s) selected by the user.
 * - $data:
 *   object containing the following fields.
 *   choices:
 *      array containing:
 *        choice_id = the unique hex id of the choice
 *        choice =    The text for a given choice.
 *        write_in =  a boolean value indicating whether or not the choice was a
 *                    write in.
 *   start_date:      (int) Start date of the poll
 *   end_date:        (int) End date of the poll
 *   mode:            The mode used to store the vote: normal, cookie, unlimited
 *   cookie_duration: (int) If mode is cookie, the number of minutes to delay
 *                    votes.
 *   state:           Is the poll 'open' or 'close'
 *   behavior:        approval or pool - determines how to treat multiple
 *                    vote/user tally. When plugin is installed, voting will
 *                    default to tabulating values returned from voting API.
 *   max_choices:     (int) How many choices a user can select per vote.
 *   show_results:    When to display results - aftervote, afterclose or never.
 *   electoral:       Boolean - voting restricted to users in an electoral list.
 *   write_in:        Boolean - all write-in voting.
 *   block:           Boolean - Poll can be displayed as a block.
 */
?>

<div class="poll-noresult" id="advpoll-<?php print $nid; ?>">
    <?php if ($data->show_results == 'never'): ?>
    <p><?php print t('The results of this poll are not available.'); ?></p>
    <?php endif; ?>

    <?php if ($data->show_results == 'afterclose'): ?>
        <?php $date = format_date($data->end_date, 'long'); ?>
        <p><?php print t('The results of this poll will be available after @date.', array('@date' => $date)); ?></p>
    <?php endif; ?>

    <?php if ($votes): ?>
    <div class="poll-message"><?php print t('Thank you for voting.'); ?></div>
    <?php endif; ?>

    <?php print $cancel_form; ?>
</div>
