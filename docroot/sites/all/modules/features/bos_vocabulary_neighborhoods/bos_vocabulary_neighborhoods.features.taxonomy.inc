<?php
/**
 * @file
 * bos_vocabulary_neighborhoods.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bos_vocabulary_neighborhoods_taxonomy_default_vocabularies() {
  return array(
    'neighborhoods' => array(
      'name' => 'Neighborhoods',
      'machine_name' => 'neighborhoods',
      'description' => 'Boston area neighborhoods',
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
