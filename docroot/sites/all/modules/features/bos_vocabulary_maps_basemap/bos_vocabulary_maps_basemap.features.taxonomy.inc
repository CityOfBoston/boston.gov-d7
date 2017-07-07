<?php
/**
 * @file
 * bos_vocabulary_maps_basemap.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bos_vocabulary_maps_basemap_taxonomy_default_vocabularies() {
  return array(
    'maps_basemap' => array(
      'name' => 'Maps: Basemap',
      'machine_name' => 'maps_basemap',
      'description' => 'Reference to Mapbox basemap used in Map component',
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
