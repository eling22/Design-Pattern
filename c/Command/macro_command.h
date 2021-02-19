#ifndef __MACRO_COMMAND_H__
#define __MACRO_COMMAND_H__

#include "interface/command.h"

#define MAX_COMMAND_NUM 5

typedef struct _MacroCommand
{
    Command(struct _MacroCommand);
    Command *commands[MAX_COMMAND_NUM];
    int command_len;
} MacroCommand;

void MacroCommandNew(MacroCommand *self, Command **commands, int len);
void MacroCommand_execute(MacroCommand *self);
void MacroCommand_undo(MacroCommand *self);

#endif /*__MACRO_COMMAND_H__*/
