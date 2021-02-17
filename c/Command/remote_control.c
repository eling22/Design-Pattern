#include "remote_control.h"
#include <stdio.h>

Command no_command;

void RemoteControlNew(RemoteControl *self)
{
    NoCommandNew(&no_command);
    for (int i = 0; i < SOLT_NUM; i++)
    {
        self->on_commands[i] = &no_command;
        self->off_commands[i] = &no_command;
    }
    for (int i = 0; i < UNDO_SIZE; i++)
    {
        self->undo_command_stack[i] = &no_command;
    }
    self->set_command = RC_set_command;
    self->on_button_was_pushed = RC_on_button_was_pushed;
    self->off_button_was_pushed = RC_off_button_was_pushed;
    self->undo_button_was_pushed = RC_undo_button_was_pushed;
    self->print = RC_print;
}
void RC_set_command(RemoteControl *self, int solt, Command *on_command, Command *off_command)
{
    self->on_commands[solt] = on_command;
    self->off_commands[solt] = off_command;
}
void RC_on_button_was_pushed(RemoteControl *self, int solt)
{
    self->on_commands[solt]->execute(self->on_commands[solt]);
}
void RC_off_button_was_pushed(RemoteControl *self, int solt)
{
    self->off_commands[solt]->execute(self->on_commands[solt]);
}
void RC_undo_button_was_pushed(RemoteControl *self) {}
void RC_print(RemoteControl *self)
{
    printf("\n----- Remote Control -----\n");
    for (int i = 0; i < SOLT_NUM; i++)
    {
        printf("[solt %d] %s\t%s\n", i, self->on_commands[i]->name, self->off_commands[i]->name);
    }
}