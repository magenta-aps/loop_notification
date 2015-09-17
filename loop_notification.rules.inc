<?php
/**
 * @file
 * loop_notification.rules.inc
 */

/**
 * Implements hook_rules_action_info().
 */
function loop_notification_rules_action_info() {
  $items = array();
  $items['loop_notification_rules_process'] = array(
    'label' => t('Send notification to user'),
    'group' => t('Message notify'),
    'parameter' => array(
      'recipient' => array(
        'type' => 'user',
        'label' => t('Recipient'),
        'description' => t('Supply the user.'),
      ),
      'messageType' => array(
        'type' => 'text',
        'label' => t('Message type'),
        'description' => t('Supply the message type (an entry in /admin/structure/messages).'),
      ),
      'node' => array(
        'type' => 'node',
        'label' => t('Message'),
        'description' => t('Supply the created message object'),
      ),
    ),
    'base' => 'loop_notification_rules_process',
  );
  return $items;
}

/**
 * Implements hook_rules_process().
 */
function loop_notification_rules_process($recipient, $message_type, $node) {
  global $user;
  if ($recipient != NULL && $node != NULL) {
    $message = message_create($message_type, array('uid' => $recipient->uid));
    $wrapper = entity_metadata_wrapper('message', $message);
    $wrapper->field_node->set($node);
    $wrapper->field_sender->set($user);
    $wrapper->save();
  }
}
