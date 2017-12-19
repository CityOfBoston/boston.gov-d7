<?php
/**
 * @file
 * bos_vocabulary_procurement_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bos_vocabulary_procurement_type_taxonomy_default_vocabularies() {
  return array(
    'procurement_type' => array(
      'name' => 'Procurement Type',
      'machine_name' => 'procurement_type',
      'description' => '',
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
