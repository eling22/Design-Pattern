#include "macro_command.h"

#define min(a, b) ((a) > (b) ? (b) : (a))

void MacroCommandNew(MacroCommand *self, Command **commands, int len)
{
    strcpy(self->name, "MacroCommand");
    self->command_len = min(MAX_COMMAND_NUM, len);
    for (int i = 0; i < self->command_len; i++)
    {
        self->commands[i] = commands[i];
    }
    self->execute = MacroCommand_execute;
    self->undo = MacroCommand_undo;
}
void MacroCommand_execute(MacroCommand *self)
{
    printf("--- Push Macro ---\n");
    for (int i = 0; i < self->command_len; i++)
    {
        self->commands[i]->execute(self->commands[i]);
    }
    printf("--- Push Macro End ---\n");
}
void MacroCommand_undo(MacroCommand *self)
{
    printf("--- Push Undo ---\n");
    for (int i = self->command_len - 1; i >= 0; i--)
    {
        self->commands[i]->undo(self->commands[i]);
    }
    printf("--- Push Undo End ---\n");
}
