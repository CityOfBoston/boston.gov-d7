<?php
/**
 * @file
 * bos_vocabulary_massachusetts_general_law.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bos_vocabulary_massachusetts_general_law_taxonomy_default_vocabularies() {
  return array(
    'massachusetts_general_law' => array(
      'name' => 'Massachusetts General Law',
      'machine_name' => 'massachusetts_general_law',
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
