<nav class="nv-m">
  <div class="nv-m-h">
      <div class="nv-m-h-ic">
        <img src="<?php print $asset_url ?>/images/b-dark.svg" title="B" aria-hidden="true" class="nv-m-h-i" />
      </div>
      <div id="nv-m-h-t" class="nv-m-h-t">&nbsp;</div>
  </div>
  <div class="nv-m-c">
    <?php print render($page['navigation']); ?>
  </div>
</nav>

<script>
  'use strict'

  var BostonMenu = (function () {
    // Set height
    var secondaryNavs;
    var secondaryTriggers;
    var listItems;
    var secondaryNavItems;
    var backTriggers;
    var burger;

    function handleBurgerChange(ev) {
      document.body.classList.toggle('no-s');
    }

    function handleTrigger(ev, method) {
      var backTrigger;
      var secondaryNav;
      var trigger = ev.target;
      var parentItem = method === 'reset' ? trigger.parentNode.parentNode.parentNode : trigger.parentNode;
      var title = document.getElementById('nv-m-h-t');

      // Find the secondary nav and trigger
      parentItem.childNodes.forEach(function(child) {
        if (child.classList && child.classList.contains('nv-m-c-l-l')) {
          secondaryNav = child;
        }

        if (child.classList && child.classList.contains('nv-m-c-a')) {
          trigger = child;
        }
      });

      // Find the backTrigger
      secondaryNav.childNodes.forEach(function(child) {
        if (child.classList && child.classList.contains('nv-m-c-bc')) {
          backTrigger = child;
        }
      });

      if (method === 'nav') {
        // Hide all the other menu items
        listItems.forEach(function(listItem) {
          if (parentItem != listItem) {
            listItem.classList.add('nv-m-c-l-i--h');
          }
        });

        // Hide the trigger
        trigger.classList.add('nv-m-c-a--h');

        // Show the secondary nav
        secondaryNav.classList.remove('nv-m-c-l-l--h');

        // Show the back button
        backTrigger.classList.remove('nv-m-c-b--h');

        // Update the title
        title.innerHTML = trigger.innerHTML;
      } else {
        // Hide all the other menu items
        listItems.forEach(function(listItem) {
          if (parentItem != listItem) {
            listItem.classList.remove('nv-m-c-l-i--h');
          }
        });

        // Hide the trigger
        trigger.classList.remove('nv-m-c-a--h');

        // Show the secondary nav
        secondaryNav.classList.add('nv-m-c-l-l--h');

        // Show the back button
        backTrigger.classList.add('nv-m-c-b--h');

        // Update the title
        title.innerHTML = '&nbsp;';
      }
    }

    function start() {
      burger = document.getElementById('brg-tr');
      listItems = document.querySelectorAll('.nv-m-c-l-i');
      backTriggers = document.querySelectorAll('.nv-m-c-b');
      secondaryTriggers = document.querySelectorAll('.nolink');
      secondaryNavs = document.querySelectorAll('.nv-m-c-l-l');
      secondaryNavItems = document.querySelectorAll('.nv-m-c-a--s');

      // Set the secondary navigation menus to hidden
      secondaryNavs.forEach(function(nav) {
        nav.classList.add('nv-m-c-l-l--h');
      });

      // Get the secondary navigation triggers ready
      secondaryTriggers.forEach(function(trigger) {
        // Set to active
        trigger.classList.add('nolink--a');

        // Handle clicks
        trigger.addEventListener('click', function(ev) {
          ev.preventDefault();

          handleTrigger(ev, 'nav');
        });
      });

      // Get the secondary navigation triggers ready
      backTriggers.forEach(function(trigger) {
        // Handle clicks
        trigger.addEventListener('click', function(ev) {
          ev.preventDefault();

          handleTrigger(ev, 'reset');
        });
      });

      // Set the secondary navigation menus to hidden
      secondaryNavItems.forEach(function(nav) {
        nav.classList.remove('nv-m-c-a--s');
        nav.classList.add('nv-m-c-a--p');
      });

      if (burger) {
        burger.addEventListener('change', handleBurgerChange);
      }
    }

    return {
      start: start
    }
  })()

  BostonMenu.start()
</script>

<input type="checkbox" id="brg-tr" class="brg-tr" aria-hidden="true">

<div class="mn">
  <input type="checkbox" id="s-tr" class="s-tr" aria-hidden="true">

  <header class="h" role="header">
    <label for="brg-tr" class="brg" type="button" aria-label="Menu" aria-controls="navigation" aria-expanded="false">
      <div class="brg-w">
        <div class="brg-b"></div>
        <div class="brg-t">Menu</div>
      </div>
    </label>
    <div class="lo">
      <a href="https://www.boston.gov" class="lo-l">
        <img src="<?php print $asset_url ?>/images/public/logo.svg" alt="City of Boston" class="lo-i" />
        <span class="lo-t">Mayor Martin J. Walsh</span>
      </a>
    </div>
    <nav class="nv-h">
      <ul class="nv-h-l">
        <?php foreach ($secondary_menu as &$link) { ?>
          <li class="nv-h-l-i"><?php print l($link['title'], $link['href'], array('absolute' => TRUE, 'attributes' => array('class' => array('nv-h-l-a')))); ?></li>
        <?php } ?>
        <li class="tr nv-h-l-i">
          <a href="#translate" title="Translate" class="nv-h-l-a nv-h-l-a--k--s tr-link">Translate</a>
          <ul class="tr-dd">
              <li><span class="notranslate tr-dd-link tr-dd-link--message">Loading...</span></li>
              <li><a href="#" class="notranslate tr-dd-link" data-ln="ht">Kreyòl Ayisyen</a></li>
              <li><a href="#" class="notranslate tr-dd-link" data-ln="pt">Portugese</a></li>
              <li><a href="#" class="notranslate tr-dd-link" data-ln="es">Español</a></li>
              <li><a href="#" class="notranslate tr-dd-link" data-ln="vi">Tiếng Việt</a></li>
              <li><a href="#" class="notranslate tr-dd-link tr-dd-link--hidden" data-ln="en">English</a></li>
          </ul>
        </li>
        <li class="nv-h-l-i">
          <label for="s-tr" title="Search" class="nv-h-l-a nv-h-l-a--k nv-h-l-a-ic">
            <svg id="Layer_2" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 40 41"><title>Search</title><path class="nv-h-l-a-i" d="M24.2.6C15.8.6 9 7.4 9 15.8c0 3.7 1.4 7.2 3.6 9.8L1.2 37c-.8.8-.8 2 0 2.8.4.4.9.6 1.4.6s1-.2 1.4-.6l11.5-11.5C18 30 21 31 24.2 31c8.4 0 15.2-6.8 15.2-15.2C39.4 7.4 32.6.6 24.2.6zm0 26.5c-6.2 0-11.2-5-11.2-11.2S18 4.6 24.2 4.6s11.2 5 11.2 11.2-5 11.3-11.2 11.3z"/></svg>
          </label>
        </li>
      </ul>
    </nav>
    <div class="h-s">
      <form action="https://search.boston.gov" class="sf" accept-charset="UTF-8" method="get">
        <input name="utf8" type="hidden" value="✓">
        <div class="sf-i">
          <input type="text" name="query" id="query" value="" class="sf-i-f" autocomplete="off">
          <button class="sf-i-b">Search</button>
        </div>
      </form>
    </div>
  </header>

  <div class="mn-c">{{yield}}</div>
  <?php print render($page['footer']); ?>
</div>
