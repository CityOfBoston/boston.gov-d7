<?php
/**
 * @file
 * bos_vocabulary_place_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bos_vocabulary_place_type_taxonomy_default_vocabularies() {
  return array(
    'place_type' => array(
      'name' => 'Place Type',
      'machine_name' => 'place_type',
      'description' => 'A descriptive type for a place, like "Parks"',
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
