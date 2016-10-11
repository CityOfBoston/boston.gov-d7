<?php
/**
 * @file
 * bos_vocabulary_topic_category.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bos_vocabulary_topic_category_taxonomy_default_vocabularies() {
  return array(
    'topic_category' => array(
      'name' => 'Topic Category',
      'machine_name' => 'topic_category',
      'description' => 'Categories used for filtering Guides on the Topic Landing Page',
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
