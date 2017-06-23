<?php
/**
 * @file
 * bos_vocabulary_maps_esri_feed.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bos_vocabulary_maps_esri_feed_taxonomy_default_vocabularies() {
  return array(
    'maps_esri_feed' => array(
      'name' => 'Maps: ESRI Feed',
      'machine_name' => 'maps_esri_feed',
      'description' => 'Reference to ESRI Feeds used in Map component',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
