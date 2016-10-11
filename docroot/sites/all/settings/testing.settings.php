<?php

/**
 * @file
 * Testing settings.
 */
// Disabling this allows Behat tests run via Selenium2 to find admin menu links.
// In markup. It would be better to conditionally set this to FALSE only when
// a Behat test is being executed.
$conf['admin_menu_cache_client'] = FALSE;
