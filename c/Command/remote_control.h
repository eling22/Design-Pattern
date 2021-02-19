#ifndef __REMOTE_CONTROL_H__
#define __REMOTE_CONTROL_H__

#endif /*__REMOTE_CONTROL_H__*/

#include "interface/command.h"

#define SOLT_NUM 7
#define UNDO_SIZE 100

typedef struct _RemoteControl
{
    Command *on_commands[SOLT_NUM];
    Command *off_commands[SOLT_NUM];
    Command *undo_command_stack[UNDO_SIZE];
    int undo_idx;
    int undo_len;
    void (*set_command)(struct _RemoteControl *, int solt, Command *on_command, Command *off_command);
    void (*on_button_was_pushed)(struct _RemoteControl *, int solt);
    void (*off_button_was_pushed)(struct _RemoteControl *, int solt);
    void (*undo_button_was_pushed)(struct _RemoteControl *);
    void (*print)(struct _RemoteControl *);
} RemoteControl;

void RemoteControlNew(RemoteControl *self);
void RC_set_command(RemoteControl *self, int solt, Command *on_command, Command *off_command);
void RC_on_button_was_pushed(RemoteControl *self, int solt);
void RC_off_button_was_pushed(RemoteControl *self, int solt);
void RC_undo_button_was_pushed(RemoteControl *self);
void RC_print(RemoteControl *self);
