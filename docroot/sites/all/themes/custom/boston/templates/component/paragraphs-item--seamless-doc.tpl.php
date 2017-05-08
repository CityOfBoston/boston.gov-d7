<?php if (isset($content['field_document_id'])): ?> 
  <script>
    function scriptLoaded() {
      var loader = document.getElementById('scriptLoader');
      loader.parentNode.removeChild(loader)
    }

    function scriptFailed() {
      var loader = document.getElementById('scriptLoader');
      loader.innerHTML = "<h3>Forms temporarily offline</h3><p>We're having trouble with our forms at this time, so we can't process your request. We're working to address the issue, though, and will update this page as soon as we have a fix.</p><p>If you have any questions or concerns, please email <a href='mailto:feedback@boston.gov'>feedback@boston.gov</a>.</p>";
    }
  </script>
  <div id="scriptLoader" class="b" style="border: 3px solid red; padding: 1.25rem 2rem">Loading...</div>
  <script src="https://boston.seamlessdocs.com/s/<?php print render($content['field_document_id']); ?>/embed/iframe" onload="scriptLoaded()" onerror="scriptFailed()"></script>
<?php endif; ?>
