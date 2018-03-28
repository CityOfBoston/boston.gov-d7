<?php
/**
 * @file
 * bos_content_type_procurement_advertisement.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bos_content_type_procurement_advertisement_taxonomy_default_vocabularies() {
  return array(
    'procurement_footer' => array(
      'name' => 'Procurement Footer',
      'machine_name' => 'procurement_footer',
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
