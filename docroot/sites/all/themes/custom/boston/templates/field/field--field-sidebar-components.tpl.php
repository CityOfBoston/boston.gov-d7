<?php
/**
 * @file
 * Default implementation for field_sidebar_components field render.
 */
?>
<?php foreach ($items as $item):
  // Hack to keep from wrapping the commission info in an extra
  // "list-item", since it’s made up of several list items.
  $paragraphs_item = $item['entity']['paragraphs_item'];
  if (isset($paragraphs_item)
     && $paragraphs_item[key($paragraphs_item)]['#bundle'] == "commission_contact_info") {
    print render($item);
  } else { ?>
    <div class="list-item">
      <?php print render($item); ?>
    </div>
  <?php
  }
endforeach; ?>
