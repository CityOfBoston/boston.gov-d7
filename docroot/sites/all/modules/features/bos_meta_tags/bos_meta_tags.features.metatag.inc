<?php
/**
 * @file
 * bos_meta_tags.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function bos_meta_tags_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global:frontpage.
  $config['global:frontpage'] = array(
    'instance' => 'global:frontpage',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[site:name]',
      ),
    ),
  );

  // Exported Metatag config instance: node.
  $config['node'] = array(
    'instance' => 'node',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[node:title] | [site:name]',
      ),
      'description' => array(
        'value' => '[node:summary]',
      ),
      'og:title' => array(
        'value' => '[node:title]',
      ),
      'og:description' => array(
        'value' => '[node:summary]',
      ),
      'og:updated_time' => array(
        'value' => '[node:changed:custom:c]',
      ),
      'og:image' => array(
        'value' => '[node:field_thumbnail]',
      ),
      'og:image:url' => array(
        'value' => '[node:field_thumbnail]',
      ),
      'og:image:secure_url' => array(
        'value' => '[node:field_thumbnail]',
      ),
      'article:published_time' => array(
        'value' => '[node:created:custom:c]',
      ),
      'article:modified_time' => array(
        'value' => '[node:changed:custom:c]',
      ),
      'twitter:creator' => array(
        'value' => '@CityOfBoston',
      ),
      'twitter:creator:id' => array(
        'value' => 124455872,
      ),
      'twitter:title' => array(
        'value' => '[node:title]',
      ),
      'twitter:description' => array(
        'value' => '[node:summary]',
      ),
      'twitter:image' => array(
        'value' => '[node:field_thumbnail]',
      ),
    ),
  );

  return $config;
}
