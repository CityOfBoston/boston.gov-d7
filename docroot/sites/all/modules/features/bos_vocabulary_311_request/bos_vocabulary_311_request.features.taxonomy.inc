<?php
/**
 * @file
 * bos_vocabulary_311_request.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bos_vocabulary_311_request_taxonomy_default_vocabularies() {
  return array(
    '311_request' => array(
      'name' => '311 Request',
      'machine_name' => '311_request',
      'description' => '311 Requests organization mechanism.',
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
