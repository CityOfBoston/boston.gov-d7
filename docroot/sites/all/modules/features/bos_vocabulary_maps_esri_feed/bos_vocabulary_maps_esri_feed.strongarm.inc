<?php
/**
 * @file
 * bos_vocabulary_maps_esri_feed.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_vocabulary_maps_esri_feed_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_taxonomy_term_maps_esri_feed';
  $strongarm->value = array(
    'entity' => 'taxonomy_term',
    'bundle' => 'maps',
    'info' => array(
      'label' => 'Maps',
      'admin' => array(
        'path' => 'admin/structure/taxonomy/%taxonomy_vocabulary_machine_name/edit',
        'real path' => 'admin/structure/taxonomy/maps/edit',
        'bundle argument' => 3,
        'access arguments' => array(
          0 => 'administer taxonomy',
        ),
      ),
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:Concept',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'rdfs:label',
            1 => 'skos:prefLabel',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'skos:definition',
          ),
        ),
        'vid' => array(
          'predicates' => array(
            0 => 'skos:inScheme',
          ),
          'type' => 'rel',
        ),
        'parent' => array(
          'predicates' => array(
            0 => 'skos:broader',
          ),
          'type' => 'rel',
        ),
      ),
      'xmlsitemap' => array(
        'entity' => 'taxonomy_term',
        'bundle' => 'maps',
        'status' => '0',
        'priority' => '0.5',
      ),
    ),
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_taxonomy_term_maps_esri_feed'] = $strongarm;

  return $export;
}
