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

  // Exported Metatag config instance: node:article.
  $config['node:article'] = array(
    'instance' => 'node:article',
    'config' => array(
      'schema_article.@type' => array(
        'value' => 'Article',
      ),
      'schema_article.headline' => array(
        'value' => '[node:title]',
      ),
      'schema_article.description' => array(
        'value' => '[node:body]',
      ),
      'schema_article.author' => array(
        'value' => 'a:3:{s:5:"@type";s:12:"Organization";s:4:"name";s:15:"City of Boston ";s:4:"logo";a:2:{s:5:"@type";s:11:"ImageObject";s:3:"url";s:29:"[boston:social-image-default]";}}',
      ),
      'schema_article.publisher' => array(
        'value' => 'a:3:{s:5:"@type";s:12:"Organization";s:4:"name";s:15:"City of Boston ";s:4:"logo";a:2:{s:5:"@type";s:11:"ImageObject";s:3:"url";s:29:"[boston:social-image-default]";}}',
      ),
      'schema_article.datePublished' => array(
        'value' => '[node:published-at]',
      ),
      'schema_article.dateModified' => array(
        'value' => '[node:changed]',
      ),
      'schema_article.image' => array(
        'value' => 'a:3:{s:5:"@type";s:11:"ImageObject";s:20:"representativeOfPage";s:4:"True";s:3:"url";s:21:"[custom:schema_image]";}',
      ),
    ),
  );

  // Exported Metatag config instance: node:event.
  $config['node:event'] = array(
    'instance' => 'node:event',
    'config' => array(
      'schema_event.@type' => array(
        'value' => 'Event',
      ),
      'schema_event.name' => array(
        'value' => '[node:title]',
      ),
      'schema_event.image' => array(
        'value' => 'a:3:{s:5:"@type";s:11:"ImageObject";s:20:"representativeOfPage";s:4:"True";s:3:"url";s:21:"[custom:schema_image]";}',
      ),
      'schema_event.description' => array(
        'value' => '[node:body]',
      ),
      'schema_event.startDate' => array(
        'value' => '[custom:schema_start_date]',
      ),
      'schema_event.endDate' => array(
        'value' => '[custom:schema_end_date]',
      ),
      'schema_event.location' => array(
        'value' => 'a:3:{s:5:"@type";s:5:"Place";s:4:"name";s:30:"[node:field_address:name-line]";s:7:"address";a:5:{s:5:"@type";s:13:"PostalAddress";s:13:"streetAddress";s:33:"[node:field_address:thoroughfare]";s:15:"addressLocality";s:29:"[node:field_address:locality]";s:13:"addressRegion";s:40:"[node:field_address:administrative-area]";s:10:"postalCode";s:32:"[node:field_address:postal-code]";}}',
      ),
      'schema_event.url' => array(
        'value' => '[node:url]',
      ),
    ),
  );

  // Exported Metatag config instance: node:how_to.
  $config['node:how_to'] = array(
    'instance' => 'node:how_to',
    'config' => array(
      'schema_how_to.@type' => array(
        'value' => 'HowTo',
      ),
      'schema_how_to.name' => array(
        'value' => '[node:title]',
      ),
      'schema_how_to.step' => array(
        'value' => 'a:5:{s:5:"pivot";s:1:"1";s:5:"@type";s:9:"HowToStep";s:4:"name";s:29:"[custom:schema_how_to_titles]";s:4:"text";s:30:"[custom:schema_how_to_details]";s:3:"url";s:10:"[node:url]";}',
      ),
      'schema_how_to.description' => array(
        'value' => '[node:body]',
      ),
      'schema_how_to.image' => array(
        'value' => 'a:3:{s:5:"@type";s:11:"ImageObject";s:20:"representativeOfPage";s:4:"True";s:3:"url";s:21:"[custom:schema_image]";}',
      ),
    ),
  );

  // Exported Metatag config instance: node:person_profile.
  $config['node:person_profile'] = array(
    'instance' => 'node:person_profile',
    'config' => array(
      'schema_person.@type' => array(
        'value' => 'Person',
      ),
      'schema_person.@id' => array(
        'value' => '[current-page:url]',
      ),
      'schema_person.name' => array(
        'value' => '[node:field-first-name] [node:field-last-name]',
      ),
      'schema_person.jobTitle' => array(
        'value' => '[node:field_position_title]',
      ),
      'schema_person.address' => array(
        'value' => 'a:5:{s:5:"@type";s:13:"PostalAddress";s:13:"streetAddress";s:33:"[node:field_address:thoroughfare]";s:15:"addressLocality";s:29:"[node:field_address:locality]";s:13:"addressRegion";s:40:"[node:field_address:administrative-area]";s:10:"postalCode";s:32:"[node:field_address:postal-code]";}',
      ),
      'schema_person.email' => array(
        'value' => '[node:field_email]',
      ),
      'schema_person.telephone' => array(
        'value' => '[node:field_phone_number]',
      ),
      'schema_person.description' => array(
        'value' => '[node:field_description]',
      ),
      'schema_person.image' => array(
        'value' => 'a:3:{s:5:"@type";s:11:"ImageObject";s:20:"representativeOfPage";s:4:"True";s:3:"url";s:25:"[node:field_person_photo]";}',
      ),
      'schema_person.affiliation' => array(
        'value' => 'a:3:{s:5:"@type";s:12:"Organization";s:4:"name";s:15:"City of Boston ";s:4:"logo";a:2:{s:5:"@type";s:11:"ImageObject";s:3:"url";s:29:"[boston:social-image-default]";}}',
      ),
      'schema_person.memberOf' => array(
        'value' => 'a:2:{s:5:"@type";s:17:"ProgramMembership";s:4:"name";s:45:"[node:field-contact:field-department-profile]";}',
      ),
    ),
  );

  return $config;
}
