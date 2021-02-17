#include "command.h"

void NoCommandNew(Command *self)
{
    strcpy(self->name, "NoCommand");
    self->execute = emptyFunc;
    self->undo = emptyFunc;
}

void emptyFunc(Command *self) {}
