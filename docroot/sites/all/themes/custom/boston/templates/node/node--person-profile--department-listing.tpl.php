<a href="<?php print $node_url; ?>">
    <div class="cdp-t t--sans t--upper"><?php print $title; ?></div>
    <?php if (isset($content['field_position_title'])): ?>
        <div class="t--g300"><?php print render($content['field_position_title']); ?></div>
    <?php endif; ?>
</a>