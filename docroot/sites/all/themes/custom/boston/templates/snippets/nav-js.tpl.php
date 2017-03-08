<?php
/**
 * @file
 * Javascript to handle main nav
 *
 */
?>
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
    var placeholder;

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
        title.innerHTML = placeholder;
      }
    }

    function start() {
      burger = document.getElementById('brg-tr');
      listItems = document.querySelectorAll('.nv-m-c-l-i');
      backTriggers = document.querySelectorAll('.nv-m-c-b');
      secondaryTriggers = document.querySelectorAll('.nolink');
      secondaryNavs = document.querySelectorAll('.nv-m-c-l-l');
      secondaryNavItems = document.querySelectorAll('.nv-m-c-a--s');

      placeholder = document.getElementById('nv-m-h-t').innerHTML;

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
