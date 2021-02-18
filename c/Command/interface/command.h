#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <stdio.h>
#include "string.h"
#define NAME_SIZE 100

typedef struct _Command
{
    char name[100];
    void (*execute)(struct _Command *);
    void (*undo)(struct _Command *);
} Command;

#define Command(TYPE)        \
    char name[100];          \
    void (*execute)(TYPE *); \
    void (*undo)(TYPE *);

void NoCommandNew(Command *self);

void emptyFunc(Command *self);

#endif /*__COMMAND_H__*/