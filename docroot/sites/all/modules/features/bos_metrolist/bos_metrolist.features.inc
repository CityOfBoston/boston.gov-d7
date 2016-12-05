<?php
/**
 * @file
 * bos_metrolist.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_metrolist_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function bos_metrolist_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function bos_metrolist_node_info() {
  $items = array(
    'metrolist_project_unit' => array(
      'name' => t('Metrolist - Project Unit'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Unit Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_salesforce_mapping().
 */
function bos_metrolist_default_salesforce_mapping() {
  $items = array();
  $items['metrolist_project_unit'] = entity_import('salesforce_mapping', '{
    "type" : "salesforce_mapping",
    "name" : "metrolist_project_unit",
    "label" : "Metrolist - Project Unit",
    "sync_triggers" : "56",
    "salesforce_object_type" : "Project_Unit__c",
    "salesforce_record_types_allowed" : {
      "012C0000000I8O9IAK" : "012C0000000I8O9IAK",
      "012C0000000I8OAIA0" : 0,
      "012000000000000AAA" : 0
    },
    "salesforce_record_type_default" : "012C0000000I8O9IAK",
    "drupal_entity_type" : "node",
    "drupal_bundle" : "metrolist_project_unit",
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
          "label" : "Unit Name",
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
        "drupal_field" : {
          "fieldmap_type" : "property",
          "fieldmap_value" : "field_mpu_street_number"
        },
        "salesforce_field" : {
          "autoNumber" : false,
          "byteLength" : 150,
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
          "label" : "Unit Street #",
          "length" : 50,
          "name" : "Unit_Street_No__c",
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
          "fieldmap_type" : "property",
          "fieldmap_value" : "field_mpu_street_name"
        },
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
          "label" : "Unit Street Name",
          "length" : 200,
          "name" : "Unit_Street__c",
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
          "fieldmap_value" : "field_mpu_neighborhood"
        },
        "salesforce_field" : {
          "autoNumber" : false,
          "byteLength" : 3900,
          "calculated" : true,
          "calculatedFormula" : "Parcel__r.Neighborhood__c",
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
          "label" : "Unit Neighborhood",
          "length" : 1300,
          "name" : "Unit_Neighborhood__c",
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
        "drupal_field" : { "fieldmap_type" : "property", "fieldmap_value" : "field_mpu_zipcode" },
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
          "label" : "Unit ZIP",
          "length" : 10,
          "name" : "Unit_ZIP__c",
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
        "drupal_field" : { "fieldmap_type" : "property", "fieldmap_value" : "field_mpu_unit_type" },
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
          "label" : "Unit Type",
          "length" : 255,
          "name" : "Unit_Type__c",
          "nameField" : false,
          "namePointing" : false,
          "nillable" : true,
          "permissionable" : true,
          "picklistValues" : [
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Ownership Unit (O)",
              "validFor" : null,
              "value" : "Ownership Unit (O)"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Rental Unit Group (R)",
              "validFor" : null,
              "value" : "Rental Unit Group (R)"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Owner Unit with Rentals (R\\/O)",
              "validFor" : null,
              "value" : "Owner Unit with Rentals (R\\/O)"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Requires Further Review",
              "validFor" : null,
              "value" : "Requires Further Review"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Historical Record",
              "validFor" : null,
              "value" : "Historical Record"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "City Mortgage Only",
              "validFor" : null,
              "value" : "City Mortgage Only"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Foreclosed - Covenant Extinguished",
              "validFor" : null,
              "value" : "Foreclosed - Covenant Extinguished"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Expired Covenant",
              "validFor" : null,
              "value" : "Expired Covenant"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "External Monitoring",
              "validFor" : null,
              "value" : "External Monitoring"
            },
            {
              "active" : true,
              "defaultValue" : false,
              "label" : "Covenant Released",
              "validFor" : null,
              "value" : "Covenant Released"
            }
          ],
          "precision" : 0,
          "referenceTo" : [],
          "relationshipName" : null,
          "relationshipOrder" : null,
          "restrictedDelete" : false,
          "restrictedPicklist" : false,
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
          "fieldmap_value" : "field_mpu_property_email"
        },
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
          "fieldmap_value" : "field_mpu_property_phone"
        },
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
      }
    ],
    "pull_trigger_date" : "LastModifiedDate",
    "push_async" : "0",
    "push_batch" : "0",
    "created" : "1479486333",
    "weight" : "0",
    "locked" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
