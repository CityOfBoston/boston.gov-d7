<?php
/**
 * @file
 * bos_vocabulary_program_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bos_vocabulary_program_type_taxonomy_default_vocabularies() {
  return array(
    'program_type' => array(
      'name' => 'Program Type',
      'machine_name' => 'program_type',
      'description' => 'A type for Programs and Initiatives to differentiate them.',
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
