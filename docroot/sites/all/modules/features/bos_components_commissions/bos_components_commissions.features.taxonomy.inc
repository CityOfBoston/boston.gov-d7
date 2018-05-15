<?php
/**
 * @file
 * bos_components_commissions.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bos_components_commissions_taxonomy_default_vocabularies() {
  return array(
    'commissions' => array(
      'name' => 'Boards and Commissions',
      'machine_name' => 'commissions',
      'description' => 'References boards and commissions from the City Clerk database',
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
