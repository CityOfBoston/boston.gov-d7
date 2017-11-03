<?php
/**
 * @file
 * bos_slack.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function bos_slack_default_rules_configuration() {
  $items = array();
  $items['rules_slack_alert_node_needs_review'] = entity_import('rules_config', '{ "rules_slack_alert_node_needs_review" : {
      "LABEL" : "Slack alert: Node needs review",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "rules", "slack" ],
      "ON" : { "node_insert" : [], "node_update" : [] },
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } }
      ],
      "DO" : [
        { "slack_send_message" : { "message" : "A Node of type [node:content-type] has been set to \\u0022Needs Review\\u0022 by [site:current-user].\\r\\nNode ID: [node:nid]\\r\\nTitle: [node:title]\\r\\nAuthor: [node:author]\\r\\nURL: [node:url]\\r\\nCreated: [node:created]\\r\\nLast Updated: [node:changed]\\r\\nRevision Log Message: [node:log]" } }
      ]
    }
  }');
  $items['rules_slack_alert_node_published'] = entity_import('rules_config', '{ "rules_slack_alert_node_published" : {
      "LABEL" : "Slack alert: Node published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "rules", "slack" ],
      "ON" : { "node_insert" : [], "node_update" : [] },
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } }
      ],
      "DO" : [
        { "slack_send_message" : { "message" : "A Node of type [node:content-type] has been set to \\u0022Published\\u0022 by [site:current-user].\\r\\nNode ID: [node:nid]\\r\\nTitle: [node:title]\\r\\nAuthor: [node:author]\\r\\nURL: [node:url]\\r\\nCreated: [node:created]\\r\\nLast Updated: [node:changed]\\r\\nRevision Log Message: [node:log]" } }
      ]
    }
  }');
  return $items;
}
