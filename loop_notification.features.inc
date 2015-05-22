<?php
/**
 * @file
 * loop_notification.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function loop_notification_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function loop_notification_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function loop_notification_flag_default_flags() {
  $flags = array();
  // Exported flag: "Message read".
  $flags['message_read'] = array(
    'entity_type' => 'message',
    'title' => 'Message read',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Mark as read',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Mark as unread',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Læst',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'message_notify_email_subject' => 0,
      'message_notify_email_body' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'loop_notification',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Taksonomi".
  $flags['subscribe_taxonomy'] = array(
    'entity_type' => 'taxonomy_term',
    'title' => 'Taxonomy',
    'global' => 0,
    'types' => array(
      0 => 'subject',
    ),
    'flag_short' => 'Subscribe',
    'flag_long' => '',
    'flag_message' => 'You are now subscribed to this term.',
    'unflag_short' => 'Unsubscribe',
    'unflag_long' => '',
    'unflag_message' => 'You are no longer subscribed to this term.',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'api_version' => 3,
    'module' => 'loop_notification',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}

/**
 * Implements hook_default_message_type().
 */
function loop_notification_default_message_type() {
  $items = array();
  $items['comment_added_to_post'] = entity_import('message_type', '{
    "name" : "comment_added_to_post",
    "description" : "Comment added to post",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : {
      "da" : [
        {
          "value" : "Der er kommet et nyt svar til sp\u00f8rgsm\u00e5let: \u003Ca href=\u0022\/node\/[message:field-message-node-reference:nid]\u0022\u003E[message:field-message-node-reference:field_description]\u003C\/a\u003E",
          "format" : "html",
          "safe_value" : "Der er kommet et nyt svar til sp\u00f8rgsm\u00e5let: \u003Ca href=\u0022\/node\/[message:field-message-node-reference:nid]\u0022\u003E[message:field-message-node-reference:field_description]\u003C\/a\u003E"
        }
      ],
      "en" : [
        {
          "value" : "There is a new reply to the question: \u003Ca href=\u0022\/node\/[message:field-message-node-reference:nid]\u0022\u003E[message:field-message-node-reference:field_description]\u003C\/a\u003E",
          "format" : "html",
          "safe_value" : "There is a new reply to the question: \u003Ca href=\u0022\/node\/[message:field-message-node-reference:nid]\u0022\u003E[message:field-message-node-reference:field_description]\u003C\/a\u003E"
        }
      ]
    }
  }');
  $items['post_created_in_taxonomy'] = entity_import('message_type', '{
    "name" : "post_created_in_taxonomy",
    "description" : "Post created in taxonomy",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "da",
    "arguments" : null,
    "message_text" : {
      "da" : [
        {
          "value" : "Der er oprettet \u003Ca href=\u0022\/node\/[message:field-node:nid]\u0022\u003Een ny post\u003C\/a\u003E under emnet [message:field-subject].",
          "format" : "html",
          "safe_value" : "Der er oprettet \u003Ca href=\u0022\/node\/[message:field-node:nid]\u0022\u003Een ny post\u003C\/a\u003E under emnet [message:field-subject]."
        }
      ],
      "en" : [
        {
          "value" : "There is a new post in the taxonomy.",
          "format" : "html",
          "safe_value" : "There is a new post in the taxonomy."
        }
      ]
    }
  }');
  return $items;
}
