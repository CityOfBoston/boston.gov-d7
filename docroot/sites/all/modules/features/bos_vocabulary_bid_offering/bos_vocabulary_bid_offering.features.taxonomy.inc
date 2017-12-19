<?php
/**
 * @file
 * bos_vocabulary_bid_offering.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bos_vocabulary_bid_offering_taxonomy_default_vocabularies() {
  return array(
    'bid_offering' => array(
      'name' => 'Bid Offering',
      'machine_name' => 'bid_offering',
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
