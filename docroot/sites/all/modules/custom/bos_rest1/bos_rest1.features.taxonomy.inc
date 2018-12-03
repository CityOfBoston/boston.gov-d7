<?php
/**
 * @file
 * bos_rest1.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bos_rest1_taxonomy_default_vocabularies() {
  return array(
    'cityscore_metrics' => array(
      'name' => 'Cityscore Metrics',
      'machine_name' => 'cityscore_metrics',
      'description' => 'Database for City Score Metrics',
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
