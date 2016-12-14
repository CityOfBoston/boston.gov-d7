<?php
/**
 * @file
 * bos_metrolist_affordable_housing.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_metrolist_affordable_housing_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function bos_metrolist_affordable_housing_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function bos_metrolist_affordable_housing_node_info() {
  $items = array(
    'metrolist_affordable_housing' => array(
      'name' => t('Metrolist Affordable Housing'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Affordable Listing Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_salesforce_mapping().
 */
function bos_metrolist_affordable_housing_default_salesforce_mapping() {
  $items = array();
  $items['metrolist_affordable_housing'] = entity_import('salesforce_mapping', '{
    "type" : "salesforce_mapping",
    "name" : "metrolist_affordable_housing",
    "label" : "Metrolist Affordable Housing",
    "sync_triggers" : "56",
    "salesforce_object_type" : "Affordable_Housing__c",
    "salesforce_record_types_allowed" : { "default" : "default" },
    "salesforce_record_type_default" : "default",
    "drupal_entity_type" : "node",
    "drupal_bundle" : "metrolist_affordable_housing",
    "field_mappings" : [
      {
        "drupal_field" : { "fieldmap_type" : "property", "fieldmap_value" : "title" },
        "salesforce_field" : {
          "autoNumber" : false,
          "byteLength" : 240,
          "calculated" : false,
          "calculatedFormula" : null,
          "cascadeDelete" : false,
          "caseSensitive" : false,
          "controllerName" : null,
          "createable" : true,
          "custom" : false,
          "defaultValue" : null,
          "defaultValueFormula" : null,
          "defaultedOnCreate" : true,
          "dependentPicklist" : false,
          "deprecatedAndHidden" : false,
          "digits" : 0,
          "displayLocationInDecimal" : false,
          "externalId" : false,
          "filterable" : true,
          "groupable" : true,
          "htmlFormatted" : false,
          "idLookup" : true,
          "inlineHelpText" : null,
          "label" : "Affordable Listing Name",
          "length" : 80,
          "name" : "Name",
          "nameField" : true,
          "namePointing" : false,
          "nillable" : true,
          "permissionable" : false,
          "picklistValues" : [],
          "precision" : 0,
          "referenceTo" : [],
          "relationshipName" : null,
          "relationshipOrder" : null,
          "restrictedDelete" : false,
          "restrictedPicklist" : false,
          "scale" : 0,
          "soapType" : "xsd:string",
          "sortable" : true,
          "type" : "string",
          "unique" : false,
          "updateable" : true,
          "writeRequiresMasterRead" : false
        },
        "key" : false,
        "direction" : "sf_drupal"
      },
      {
        "drupal_field" : { "fieldmap_type" : "property", "fieldmap_value" : "field_mah_address" },
        "salesforce_field" : {
          "autoNumber" : false,
          "byteLength" : 600,
          "calculated" : false,
          "calculatedFormula" : null,
          "cascadeDelete" : false,
          "caseSensitive" : false,
          "controllerName" : null,
          "createable" : true,
          "custom" : true,
          "defaultValue" : null,
          "defaultValueFormula" : null,
          "defaultedOnCreate" : false,
          "dependentPicklist" : false,
          "deprecatedAndHidden" : false,
          "digits" : 0,
          "displayLocationInDecimal" : false,
          "externalId" : false,
          "filterable" : true,
          "groupable" : true,
          "htmlFormatted" : false,
          "idLookup" : false,
          "inlineHelpText" : null,
          "label" : "Street Address",
          "length" : 200,
          "name" : "Street_Address__c",
          "nameField" : false,
          "namePointing" : false,
          "nillable" : true,
          "permissionable" : true,
          "picklistValues" : [],
          "precision" : 0,
          "referenceTo" : [],
          "relationshipName" : null,
          "relationshipOrder" : null,
          "restrictedDelete" : false,
          "restrictedPicklist" : false,
          "scale" : 0,
          "soapType" : "xsd:string",
          "sortable" : true,
          "type" : "string",
          "unique" : false,
          "updateable" : true,
          "writeRequiresMasterRead" : false
        },
        "key" : false,
        "direction" : "sf_drupal"
      },
      {
        "drupal_field" : { "fieldmap_type" : "property", "fieldmap_value" : "field_mah_zipcode" },
        "salesforce_field" : {
          "autoNumber" : false,
          "byteLength" : 30,
          "calculated" : false,
          "calculatedFormula" : null,
          "cascadeDelete" : false,
          "caseSensitive" : false,
          "controllerName" : null,
          "createable" : true,
          "custom" : true,
          "defaultValue" : null,
          "defaultValueFormula" : null,
          "defaultedOnCreate" : false,
          "dependentPicklist" : false,
          "deprecatedAndHidden" : false,
          "digits" : 0,
          "displayLocationInDecimal" : false,
          "externalId" : false,
          "filterable" : true,
          "groupable" : true,
          "htmlFormatted" : false,
          "idLookup" : false,
          "inlineHelpText" : null,
          "label" : "ZIP Code",
          "length" : 10,
          "name" : "ZIP_Code__c",
          "nameField" : false,
          "namePointing" : false,
          "nillable" : true,
          "permissionable" : true,
          "picklistValues" : [],
          "precision" : 0,
          "referenceTo" : [],
          "relationshipName" : null,
          "relationshipOrder" : null,
          "restrictedDelete" : false,
          "restrictedPicklist" : false,
          "scale" : 0,
          "soapType" : "xsd:string",
          "sortable" : true,
          "type" : "string",
          "unique" : false,
          "updateable" : true,
          "writeRequiresMasterRead" : false
        },
        "key" : false,
        "direction" : "sf_drupal"
      },
      {
        "drupal_field" : {
          "fieldmap_type" : "term_ref",
          "fieldmap_value" : "field_mah_neighborhood"
        },
        "salesforce_field" : {
          "autoNumber" : false,
          "byteLength" : 765,
          "calculated" : false,
          "calculatedFormula" : null,
          "cascadeDelete" : false,
          "caseSensitive" : false,
          "controllerName" : null,
          "createable" : true,
          "custom" : true,
          "defaultValue" : null,
          "defaultValueFormula" : null,
          "defaultedOnCreate" : false,
          "dependentPicklist" : false,
          "deprecatedAndHidden" : false,
          "digits" : 0,
          "displayLocationInDecimal" : false,
          "externalId" : false,
          "filterable" : true,
          "groupable" : true,
          "htmlFormatted" : false,
          "idLookup" : false,
          "inlineHelpText" : null,
          "label" : "Neighborhood",
          "length" : 255,
          "name" : "Neighborhood__c",
          "nameField" : false,
          "namePointing" : false,
          "nillable" : true,
          "permissionable" : true,
          "picklistValues" : [
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Allston",
              "validFor" : null,
              "value" : "Allston"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Back Bay",
              "validFor" : null,
              "value" : "Back Bay"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Beacon Hill",
              "validFor" : null,
              "value" : "Beacon Hill"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Boston Central",
              "validFor" : null,
              "value" : "Boston Central"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Brighton",
              "validFor" : null,
              "value" : "Brighton"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Charlestown",
              "validFor" : null,
              "value" : "Charlestown"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Dorchester",
              "validFor" : null,
              "value" : "Dorchester"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "East Boston",
              "validFor" : null,
              "value" : "East Boston"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Fenway",
              "validFor" : null,
              "value" : "Fenway"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Hyde Park",
              "validFor" : null,
              "value" : "Hyde Park"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Jamaica Plain",
              "validFor" : null,
              "value" : "Jamaica Plain"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Kenmore",
              "validFor" : null,
              "value" : "Kenmore"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Mattapan",
              "validFor" : null,
              "value" : "Mattapan"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Roslindale",
              "validFor" : null,
              "value" : "Roslindale"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Roxbury",
              "validFor" : null,
              "value" : "Roxbury"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "South Boston",
              "validFor" : null,
              "value" : "South Boston"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "South End",
              "validFor" : null,
              "value" : "South End"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Uncertain",
              "validFor" : null,
              "value" : "Uncertain"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "West Roxbury",
              "validFor" : null,
              "value" : "West Roxbury"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "- Outside Boston -",
              "validFor" : null,
              "value" : "- Outside Boston -"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "South Easton",
              "validFor" : null,
              "value" : "South Easton"
            }
          ],
          "precision" : 0,
          "referenceTo" : [],
          "relationshipName" : null,
          "relationshipOrder" : null,
          "restrictedDelete" : false,
          "restrictedPicklist" : true,
          "scale" : 0,
          "soapType" : "xsd:string",
          "sortable" : true,
          "type" : "picklist",
          "unique" : false,
          "updateable" : true,
          "writeRequiresMasterRead" : false
        },
        "key" : false,
        "direction" : "sf_drupal"
      },
      {
        "drupal_field" : { "fieldmap_type" : "property", "fieldmap_value" : "field_mah_contact" },
        "salesforce_field" : {
          "autoNumber" : false,
          "byteLength" : 18,
          "calculated" : false,
          "calculatedFormula" : null,
          "cascadeDelete" : false,
          "caseSensitive" : false,
          "controllerName" : null,
          "createable" : true,
          "custom" : true,
          "defaultValue" : null,
          "defaultValueFormula" : null,
          "defaultedOnCreate" : false,
          "dependentPicklist" : false,
          "deprecatedAndHidden" : false,
          "digits" : 0,
          "displayLocationInDecimal" : false,
          "externalId" : false,
          "filterable" : true,
          "groupable" : true,
          "htmlFormatted" : false,
          "idLookup" : false,
          "inlineHelpText" : "Link the Property Manager Contact record here.",
          "label" : "Property Manager Contact",
          "length" : 18,
          "name" : "Property_Manager_Contact__c",
          "nameField" : false,
          "namePointing" : false,
          "nillable" : true,
          "permissionable" : true,
          "picklistValues" : [],
          "precision" : 0,
          "referenceTo" : [ "Contact" ],
          "relationshipName" : "Property_Manager_Contact__r",
          "relationshipOrder" : null,
          "restrictedDelete" : false,
          "restrictedPicklist" : false,
          "scale" : 0,
          "soapType" : "tns:ID",
          "sortable" : true,
          "type" : "reference",
          "unique" : false,
          "updateable" : true,
          "writeRequiresMasterRead" : false
        },
        "key" : false,
        "direction" : "sf_drupal"
      },
      {
        "drupal_field" : { "fieldmap_type" : "property", "fieldmap_value" : "field_mah_phone" },
        "salesforce_field" : {
          "autoNumber" : false,
          "byteLength" : 3900,
          "calculated" : true,
          "calculatedFormula" : "Property_Manager_Contact__r.Phone",
          "cascadeDelete" : false,
          "caseSensitive" : false,
          "controllerName" : null,
          "createable" : false,
          "custom" : true,
          "defaultValue" : null,
          "defaultValueFormula" : null,
          "defaultedOnCreate" : false,
          "dependentPicklist" : false,
          "deprecatedAndHidden" : false,
          "digits" : 0,
          "displayLocationInDecimal" : false,
          "externalId" : false,
          "filterable" : true,
          "groupable" : false,
          "htmlFormatted" : false,
          "idLookup" : false,
          "inlineHelpText" : null,
          "label" : "Property Manager Contact Phone",
          "length" : 1300,
          "name" : "Property_Manager_Contact_Phone__c",
          "nameField" : false,
          "namePointing" : false,
          "nillable" : true,
          "permissionable" : true,
          "picklistValues" : [],
          "precision" : 0,
          "referenceTo" : [],
          "relationshipName" : null,
          "relationshipOrder" : null,
          "restrictedDelete" : false,
          "restrictedPicklist" : false,
          "scale" : 0,
          "soapType" : "xsd:string",
          "sortable" : true,
          "type" : "string",
          "unique" : false,
          "updateable" : false,
          "writeRequiresMasterRead" : false
        },
        "key" : false,
        "direction" : "sf_drupal"
      },
      {
        "drupal_field" : { "fieldmap_type" : "property", "fieldmap_value" : "field_mah_email" },
        "salesforce_field" : {
          "autoNumber" : false,
          "byteLength" : 3900,
          "calculated" : true,
          "calculatedFormula" : "Property_Manager_Contact__r.Email",
          "cascadeDelete" : false,
          "caseSensitive" : false,
          "controllerName" : null,
          "createable" : false,
          "custom" : true,
          "defaultValue" : null,
          "defaultValueFormula" : null,
          "defaultedOnCreate" : false,
          "dependentPicklist" : false,
          "deprecatedAndHidden" : false,
          "digits" : 0,
          "displayLocationInDecimal" : false,
          "externalId" : false,
          "filterable" : true,
          "groupable" : false,
          "htmlFormatted" : false,
          "idLookup" : false,
          "inlineHelpText" : null,
          "label" : "Property Manager Contact Email",
          "length" : 1300,
          "name" : "Property_Manager_Contact_Email__c",
          "nameField" : false,
          "namePointing" : false,
          "nillable" : true,
          "permissionable" : true,
          "picklistValues" : [],
          "precision" : 0,
          "referenceTo" : [],
          "relationshipName" : null,
          "relationshipOrder" : null,
          "restrictedDelete" : false,
          "restrictedPicklist" : false,
          "scale" : 0,
          "soapType" : "xsd:string",
          "sortable" : true,
          "type" : "string",
          "unique" : false,
          "updateable" : false,
          "writeRequiresMasterRead" : false
        },
        "key" : false,
        "direction" : "sf_drupal"
      },
      {
        "drupal_field" : {
          "fieldmap_type" : "property",
          "fieldmap_value" : "field_mah_metrolist_hold"
        },
        "salesforce_field" : {
          "autoNumber" : false,
          "byteLength" : 0,
          "calculated" : false,
          "calculatedFormula" : null,
          "cascadeDelete" : false,
          "caseSensitive" : false,
          "controllerName" : null,
          "createable" : true,
          "custom" : true,
          "defaultValue" : null,
          "defaultValueFormula" : null,
          "defaultedOnCreate" : true,
          "dependentPicklist" : false,
          "deprecatedAndHidden" : false,
          "digits" : 0,
          "displayLocationInDecimal" : false,
          "externalId" : false,
          "filterable" : true,
          "groupable" : true,
          "htmlFormatted" : false,
          "idLookup" : false,
          "inlineHelpText" : "If this box checked, the record will no be displayed on the Metrolist web page.",
          "label" : "Metrolist hold",
          "length" : 0,
          "name" : "Metrolist_hold__c",
          "nameField" : false,
          "namePointing" : false,
          "nillable" : false,
          "permissionable" : true,
          "picklistValues" : [],
          "precision" : 0,
          "referenceTo" : [],
          "relationshipName" : null,
          "relationshipOrder" : null,
          "restrictedDelete" : false,
          "restrictedPicklist" : false,
          "scale" : 0,
          "soapType" : "xsd:boolean",
          "sortable" : true,
          "type" : "boolean",
          "unique" : false,
          "updateable" : true,
          "writeRequiresMasterRead" : false
        },
        "key" : false,
        "direction" : "sf_drupal"
      }
    ],
    "pull_trigger_date" : "LastModifiedDate",
    "push_async" : "0",
    "push_batch" : "0",
    "created" : "1481649147",
    "weight" : "0",
    "locked" : "0",
    "create_term" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
