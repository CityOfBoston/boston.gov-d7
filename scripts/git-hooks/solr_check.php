#!/usr/local/bin/php

<?php
$ret_status = 0;
include_once 'docroot/sites/all/modules/features/hub_settings_apache_solr/hub_settings_apache_solr.apachesolr_environments.inc';
$environments = hub_settings_apache_solr_apachesolr_environments();
$env = reset($environments);
if ($env->env_id != 'acquia_search_server_1' ){
  echo "ERROR: The Apache Solr environment is pointing at " . $env->env_id  .  " not acquia_search_server_1 \n";
  $ret_status += 1;
}


include_once 'docroot/sites/all/modules/features/hub_settings_apache_solr/hub_settings_apache_solr.apachesolr_search_defaults.inc';

$exporters = hub_settings_apache_solr_apachesolr_search_default_searchers();
//walk through the array and make sure solr is not set to the wrong env
//var_dump ($exporters);
foreach ($exporters as $exporter){
  if (!empty($exporter->page_id) && $exporter->page_id == "people_directory"){
    if ($exporter->env_id != 'acquia_search_server_1') {
      echo "ERROR: The Employee Directory search page is using " . $exporter->env_id . " not acquia_search_server_1 as its environment.  \n";
      $ret_status += 1;
    }
  }
}

exit($ret_status);

?>