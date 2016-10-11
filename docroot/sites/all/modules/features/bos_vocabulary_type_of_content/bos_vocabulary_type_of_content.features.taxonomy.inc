<?php
/**
 * @file
 * bos_vocabulary_type_of_content.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bos_vocabulary_type_of_content_taxonomy_default_vocabularies() {
  return array(
    'type_of_content' => array(
      'name' => 'Type of Content',
      'machine_name' => 'type_of_content',
      'description' => 'The type of content used for solr facets for filtering.',
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
