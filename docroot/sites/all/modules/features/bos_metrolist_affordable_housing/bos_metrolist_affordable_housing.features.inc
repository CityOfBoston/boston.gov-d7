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
              "label" : "Bay Village",
              "validFor" : null,
              "value" : "Bay Village"
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
              "label" : "Boston Central - Chinatown",
              "validFor" : null,
              "value" : "Boston Central - Chinatown"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Boston Central - Downtown Crossing",
              "validFor" : null,
              "value" : "Boston Central - Downtown Crossing"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Boston Central - Government Center",
              "validFor" : null,
              "value" : "Boston Central - Government Center"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Boston Central - North End",
              "validFor" : null,
              "value" : "Boston Central - North End"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Boston Central - West End",
              "validFor" : null,
              "value" : "Boston Central - West End"
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
              "label" : "Chinatown\\/Leather District",
              "validFor" : null,
              "value" : "Chinatown\\/Leather District"
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
              "label" : "Dorchester - Adams Village",
              "validFor" : null,
              "value" : "Dorchester - Adams Village"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Dorchester - Bowdoin \\/ Geneva",
              "validFor" : null,
              "value" : "Dorchester - Bowdoin \\/ Geneva"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Dorchester - Codman Square",
              "validFor" : null,
              "value" : "Dorchester - Codman Square"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Dorchester - Fields Corner",
              "validFor" : null,
              "value" : "Dorchester - Fields Corner"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Dorchester - Four Corners",
              "validFor" : null,
              "value" : "Dorchester - Four Corners"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Dorchester - Grove Hall",
              "validFor" : null,
              "value" : "Dorchester - Grove Hall"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Dorchester - Lower Mills",
              "validFor" : null,
              "value" : "Dorchester - Lower Mills"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Dorchester - Savin Hill",
              "validFor" : null,
              "value" : "Dorchester - Savin Hill"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Dorchester - St. Mark\\u0027s",
              "validFor" : null,
              "value" : "Dorchester - St. Mark\\u0027s"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Dorchester - Uphams Corner",
              "validFor" : null,
              "value" : "Dorchester - Uphams Corner"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Downtown",
              "validFor" : null,
              "value" : "Downtown"
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
              "label" : "Fenway\\/Kenmore",
              "validFor" : null,
              "value" : "Fenway\\/Kenmore"
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
              "label" : "Innovation District - Fort Point",
              "validFor" : null,
              "value" : "Innovation District - Fort Point"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Innovation District - Marine Industrial Park",
              "validFor" : null,
              "value" : "Innovation District - Marine Industrial Park"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Innovation District - Waterfront",
              "validFor" : null,
              "value" : "Innovation District - Waterfront"
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
              "label" : "Jamaica Plain - Hyde\\/Jackson",
              "validFor" : null,
              "value" : "Jamaica Plain - Hyde\\/Jackson"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Jamaica Plain - JP Centre\\/South",
              "validFor" : null,
              "value" : "Jamaica Plain - JP Centre\\/South"
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
              "label" : "Mid-Dorchester",
              "validFor" : null,
              "value" : "Mid-Dorchester"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Mission Hill",
              "validFor" : null,
              "value" : "Mission Hill"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Multiple Locations",
              "validFor" : null,
              "value" : "Multiple Locations"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "North End",
              "validFor" : null,
              "value" : "North End"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Outside Boston",
              "validFor" : null,
              "value" : "Outside Boston"
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
              "label" : "Roxbury - Dudley Square",
              "validFor" : null,
              "value" : "Roxbury - Dudley Square"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Roxbury - Egleston Square",
              "validFor" : null,
              "value" : "Roxbury - Egleston Square"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Roxbury - Grove Hall",
              "validFor" : null,
              "value" : "Roxbury - Grove Hall"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Roxbury - Mission Hill",
              "validFor" : null,
              "value" : "Roxbury - Mission Hill"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Roxbury - Newmarket",
              "validFor" : null,
              "value" : "Roxbury - Newmarket"
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
              "label" : "South Easton",
              "validFor" : null,
              "value" : "South Easton"
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
              "label" : "West End",
              "validFor" : null,
              "value" : "West End"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "West Roxbury",
              "validFor" : null,
              "value" : "West Roxbury"
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
          "byteLength" : 3900,
          "calculated" : true,
          "calculatedFormula" : "Property_Manager_Contact__r.Full_Name__c + \\u0022 \\/ \\u0022 +  Property_Manager_Contact__r.Account.Name",
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
          "label" : "Property Manager Contact\\/Account",
          "length" : 1300,
          "name" : "Property_Manager_Contact_Account__c",
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
          "fieldmap_value" : "field_mah_publish_to_metrolist"
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
          "inlineHelpText" : null,
          "label" : "Publish to Metrolist",
          "length" : 0,
          "name" : "Publish_to_Metrolist__c",
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
      },
      {
        "drupal_field" : {
          "fieldmap_type" : "property",
          "fieldmap_value" : "field_mah_lottery_deadline"
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
          "inlineHelpText" : "Enter in the Application Deadline and Time.",
          "label" : "Lottery Application Deadline",
          "length" : 0,
          "name" : "Lottery_Application_Deadline__c",
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
          "soapType" : "xsd:dateTime",
          "sortable" : true,
          "type" : "datetime",
          "unique" : false,
          "updateable" : true,
          "writeRequiresMasterRead" : false
        },
        "key" : false,
        "direction" : "sf_drupal"
      },
      {
        "drupal_field" : {
          "fieldmap_type" : "property",
          "fieldmap_value" : "field_mah_outer_location"
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
          "label" : "Outside Boston Location",
          "length" : 255,
          "name" : "Outside_Boston_Location__c",
          "nameField" : false,
          "namePointing" : false,
          "nillable" : true,
          "permissionable" : true,
          "picklistValues" : [
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Acton",
              "validFor" : null,
              "value" : "Acton"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Amesbury",
              "validFor" : null,
              "value" : "Amesbury"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Arlington",
              "validFor" : null,
              "value" : "Arlington"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Ashland",
              "validFor" : null,
              "value" : "Ashland"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Bedford",
              "validFor" : null,
              "value" : "Bedford"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Bellingham",
              "validFor" : null,
              "value" : "Bellingham"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Belmont",
              "validFor" : null,
              "value" : "Belmont"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Beverly",
              "validFor" : null,
              "value" : "Beverly"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Boxborough",
              "validFor" : null,
              "value" : "Boxborough"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Braintree",
              "validFor" : null,
              "value" : "Braintree"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Brookline",
              "validFor" : null,
              "value" : "Brookline"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Burlington",
              "validFor" : null,
              "value" : "Burlington"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Cambridge",
              "validFor" : null,
              "value" : "Cambridge"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Canton",
              "validFor" : null,
              "value" : "Canton"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Carlisle",
              "validFor" : null,
              "value" : "Carlisle"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Carver",
              "validFor" : null,
              "value" : "Carver"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Chelsea",
              "validFor" : null,
              "value" : "Chelsea"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Cohasset",
              "validFor" : null,
              "value" : "Cohasset"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Concord",
              "validFor" : null,
              "value" : "Concord"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Danvers",
              "validFor" : null,
              "value" : "Danvers"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Dedham",
              "validFor" : null,
              "value" : "Dedham"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Dover",
              "validFor" : null,
              "value" : "Dover"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Duxbury",
              "validFor" : null,
              "value" : "Duxbury"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Essex",
              "validFor" : null,
              "value" : "Essex"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Everett",
              "validFor" : null,
              "value" : "Everett"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Foxborough",
              "validFor" : null,
              "value" : "Foxborough"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Framingham",
              "validFor" : null,
              "value" : "Framingham"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Franklin",
              "validFor" : null,
              "value" : "Franklin"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Gloucester",
              "validFor" : null,
              "value" : "Gloucester"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Groton",
              "validFor" : null,
              "value" : "Groton"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Hamilton",
              "validFor" : null,
              "value" : "Hamilton"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Hanover",
              "validFor" : null,
              "value" : "Hanover"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Hingham",
              "validFor" : null,
              "value" : "Hingham"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Holbrook",
              "validFor" : null,
              "value" : "Holbrook"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Holliston",
              "validFor" : null,
              "value" : "Holliston"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Hopedale",
              "validFor" : null,
              "value" : "Hopedale"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Hopkinton",
              "validFor" : null,
              "value" : "Hopkinton"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Hudson",
              "validFor" : null,
              "value" : "Hudson"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Hull",
              "validFor" : null,
              "value" : "Hull"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Ipswich",
              "validFor" : null,
              "value" : "Ipswich"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Kingston",
              "validFor" : null,
              "value" : "Kingston"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Lexington",
              "validFor" : null,
              "value" : "Lexington"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Lincoln",
              "validFor" : null,
              "value" : "Lincoln"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Littleton",
              "validFor" : null,
              "value" : "Littleton"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Lynn",
              "validFor" : null,
              "value" : "Lynn"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Lynnfield",
              "validFor" : null,
              "value" : "Lynnfield"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Malborough",
              "validFor" : null,
              "value" : "Malborough"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Malden",
              "validFor" : null,
              "value" : "Malden"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Manchester-by-the-Sea",
              "validFor" : null,
              "value" : "Manchester-by-the-Sea"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Marblehead",
              "validFor" : null,
              "value" : "Marblehead"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Marshfield",
              "validFor" : null,
              "value" : "Marshfield"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Maynard",
              "validFor" : null,
              "value" : "Maynard"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Medfield",
              "validFor" : null,
              "value" : "Medfield"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Medford",
              "validFor" : null,
              "value" : "Medford"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Medway",
              "validFor" : null,
              "value" : "Medway"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Melrose",
              "validFor" : null,
              "value" : "Melrose"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Middleton",
              "validFor" : null,
              "value" : "Middleton"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Milford",
              "validFor" : null,
              "value" : "Milford"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Millis",
              "validFor" : null,
              "value" : "Millis"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Milton",
              "validFor" : null,
              "value" : "Milton"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Nahant",
              "validFor" : null,
              "value" : "Nahant"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Nantucket",
              "validFor" : null,
              "value" : "Nantucket"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Natick",
              "validFor" : null,
              "value" : "Natick"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Needham",
              "validFor" : null,
              "value" : "Needham"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Newbury",
              "validFor" : null,
              "value" : "Newbury"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Newburyport",
              "validFor" : null,
              "value" : "Newburyport"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Newton",
              "validFor" : null,
              "value" : "Newton"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Norfolk",
              "validFor" : null,
              "value" : "Norfolk"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "North Reading",
              "validFor" : null,
              "value" : "North Reading"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Norwell",
              "validFor" : null,
              "value" : "Norwell"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Norwood",
              "validFor" : null,
              "value" : "Norwood"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Peabody",
              "validFor" : null,
              "value" : "Peabody"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Pembroke",
              "validFor" : null,
              "value" : "Pembroke"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Plainville",
              "validFor" : null,
              "value" : "Plainville"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Plymouth",
              "validFor" : null,
              "value" : "Plymouth"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Quincy",
              "validFor" : null,
              "value" : "Quincy"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Randolph",
              "validFor" : null,
              "value" : "Randolph"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Raynham",
              "validFor" : null,
              "value" : "Raynham"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Reading",
              "validFor" : null,
              "value" : "Reading"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Revere",
              "validFor" : null,
              "value" : "Revere"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Rockland",
              "validFor" : null,
              "value" : "Rockland"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Rockport",
              "validFor" : null,
              "value" : "Rockport"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Rowley",
              "validFor" : null,
              "value" : "Rowley"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Salem",
              "validFor" : null,
              "value" : "Salem"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Salisbury",
              "validFor" : null,
              "value" : "Salisbury"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Saugus",
              "validFor" : null,
              "value" : "Saugus"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Scituate",
              "validFor" : null,
              "value" : "Scituate"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Sharon",
              "validFor" : null,
              "value" : "Sharon"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Sherborn",
              "validFor" : null,
              "value" : "Sherborn"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Somerville",
              "validFor" : null,
              "value" : "Somerville"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Southborough",
              "validFor" : null,
              "value" : "Southborough"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "South Easton",
              "validFor" : null,
              "value" : "South Easton"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Stoneham",
              "validFor" : null,
              "value" : "Stoneham"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Stoughton",
              "validFor" : null,
              "value" : "Stoughton"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Stow",
              "validFor" : null,
              "value" : "Stow"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Sudbury",
              "validFor" : null,
              "value" : "Sudbury"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Swampscott",
              "validFor" : null,
              "value" : "Swampscott"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Tewksbury",
              "validFor" : null,
              "value" : "Tewksbury"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Topsfield",
              "validFor" : null,
              "value" : "Topsfield"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Wakefield",
              "validFor" : null,
              "value" : "Wakefield"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Walpole",
              "validFor" : null,
              "value" : "Walpole"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Waltham",
              "validFor" : null,
              "value" : "Waltham"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Wareham",
              "validFor" : null,
              "value" : "Wareham"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Watertown",
              "validFor" : null,
              "value" : "Watertown"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Wayland",
              "validFor" : null,
              "value" : "Wayland"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Wellesly",
              "validFor" : null,
              "value" : "Wellesly"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Wenham",
              "validFor" : null,
              "value" : "Wenham"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "West Boylston",
              "validFor" : null,
              "value" : "West Boylston"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Weston",
              "validFor" : null,
              "value" : "Weston"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Westwood",
              "validFor" : null,
              "value" : "Westwood"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Weymouth",
              "validFor" : null,
              "value" : "Weymouth"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Wilmington",
              "validFor" : null,
              "value" : "Wilmington"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Winchester",
              "validFor" : null,
              "value" : "Winchester"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Winthrop",
              "validFor" : null,
              "value" : "Winthrop"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Woburn",
              "validFor" : null,
              "value" : "Woburn"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Wrentham",
              "validFor" : null,
              "value" : "Wrentham"
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
        "drupal_field" : {
          "fieldmap_type" : "property",
          "fieldmap_value" : "field_mah_lottery_url:url"
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
          "label" : "Lottery Advertisement Flyer",
          "length" : 255,
          "name" : "Lottery_Advertisement_Flyer__c",
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
          "type" : "url",
          "unique" : false,
          "updateable" : true,
          "writeRequiresMasterRead" : false
        },
        "key" : false,
        "direction" : "sf_drupal"
      },
      {
        "drupal_field" : {
          "fieldmap_type" : "property",
          "fieldmap_value" : "field_mah_lottery_type"
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
          "label" : "Lottery Type",
          "length" : 255,
          "name" : "Lottery_Type__c",
          "nameField" : false,
          "namePointing" : false,
          "nillable" : true,
          "permissionable" : true,
          "picklistValues" : [
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Rental",
              "validFor" : null,
              "value" : "Rental"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Ownership",
              "validFor" : null,
              "value" : "Ownership"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Resale",
              "validFor" : null,
              "value" : "Resale"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Rental Post Lottery",
              "validFor" : null,
              "value" : "Rental Post Lottery"
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
        "drupal_field" : {
          "fieldmap_type" : "property",
          "fieldmap_value" : "field_mah_lottery_indicator"
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
          "label" : "Lottery",
          "length" : 255,
          "name" : "Lottery__c",
          "nameField" : false,
          "namePointing" : false,
          "nillable" : true,
          "permissionable" : true,
          "picklistValues" : [
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Yes",
              "validFor" : null,
              "value" : "Yes"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "No",
              "validFor" : null,
              "value" : "No"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "No answer",
              "validFor" : null,
              "value" : "No answer"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Unknown",
              "validFor" : null,
              "value" : "Unknown"
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
        "drupal_field" : {
          "fieldmap_type" : "property",
          "fieldmap_value" : "field_mah_not_active"
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
          "inlineHelpText" : null,
          "label" : "Not Active",
          "length" : 0,
          "name" : "Not_Active__c",
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
      },
      {
        "drupal_field" : {
          "fieldmap_type" : "property",
          "fieldmap_value" : "field_mah_household_income_limit"
        },
        "salesforce_field" : {
          "autoNumber" : false,
          "byteLength" : 4099,
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
          "groupable" : false,
          "htmlFormatted" : false,
          "idLookup" : false,
          "inlineHelpText" : null,
          "label" : "Household Income Limits (AMI %)",
          "length" : 4099,
          "name" : "Household_Income_Limits_AMI__c",
          "nameField" : false,
          "namePointing" : false,
          "nillable" : true,
          "permissionable" : true,
          "picklistValues" : [
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "30%",
              "validFor" : null,
              "value" : "30%"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "50%",
              "validFor" : null,
              "value" : "50%"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "60%",
              "validFor" : null,
              "value" : "60%"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "70%",
              "validFor" : null,
              "value" : "70%"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "80%",
              "validFor" : null,
              "value" : "80%"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "80% CDBG",
              "validFor" : null,
              "value" : "80% CDBG"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "90%",
              "validFor" : null,
              "value" : "90%"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "100%",
              "validFor" : null,
              "value" : "100%"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "110%",
              "validFor" : null,
              "value" : "110%"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "120%",
              "validFor" : null,
              "value" : "120%"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "135%",
              "validFor" : null,
              "value" : "135%"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "\\u003E135%",
              "validFor" : null,
              "value" : "\\u003E135%"
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
          "sortable" : false,
          "type" : "multipicklist",
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
