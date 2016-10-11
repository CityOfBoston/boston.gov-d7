<?php
/**
 * @file
 * bos_vocabulary_holidays.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bos_vocabulary_holidays_taxonomy_default_vocabularies() {
  return array(
    'holidays' => array(
      'name' => 'Holidays',
      'machine_name' => 'holidays',
      'description' => 'A collection of string/date pairs indicating city holidays or special events.',
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
