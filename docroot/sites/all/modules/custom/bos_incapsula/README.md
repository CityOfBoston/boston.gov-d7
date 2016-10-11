# Incapsula Purge Configuration

Incapsula purging for Drupal requires 3 variables be set:

* incapsula_api_id
* incapsula_api_key
* incapsula_site_id

Contact your rep at Incapsula to obtain this information for your site. Once
obtained, either store this information in Drupal variables or expose it through
setting $conf variables in settings.php.

Since this information should be stored confidentially (rather than directly in
Drupal variables, which would store the sensitive data in plain text in the database)
, it is recommended that a separate incapsula.settings.php file be created and
stored outside the Drupal file system and included in settings.php.
