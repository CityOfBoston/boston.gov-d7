<a href="<?php print $document_link; ?>" title="Download <?php print $document_filename; ?>" class="fyi-l lnk-d">
  <?php if (!empty($content['field_title'])): ?>
  <?php print render($content['field_title']); ?>
  <?php else: ?>
    <?php print $document_filename; ?>
  <?php endif; ?>
</a>
