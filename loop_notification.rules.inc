<?php

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
        ),
        'base' => 'loop_notification_rules_process',
    );
    return $items;
}

function loop_notification_rules_process($recipient, $messageType) {
    global $user;
    if ($recipient != null) {
        $message = message_create($messageType, array('uid' => $recipient->uid));
        $wrapper = entity_metadata_wrapper('message', $message);
        $wrapper->field_node->set(menu_get_object());
        $wrapper->field_sender->set($user);
        $wrapper->save();
    }
}
?>