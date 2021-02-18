#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "interface/command.h"

typedef struct _Light
{
    char place[100];
    void (*on)(struct _Light *);
    void (*off)(struct _Light *);
    void (*print)(struct _Light *);
} Light;

void LightNew(Light *self, const char *place);
void Light_on(Light *self);
void Light_off(Light *self);
void Light_print(Light *self);

typedef struct _LightOnCommand
{
    Command(struct _LightOnCommand);
    Light *light;
} LightOnCommand;

void LightOnCommandNew(LightOnCommand *self, Light *light);
void LightOnCommand_execute(LightOnCommand *self);
void LightOnCommand_undo(LightOnCommand *self);

typedef struct _LightOffCommand
{
    Command(struct _LightOffCommand);
    Light *light;
} LightOffCommand;

void LightOffCommandNew(LightOffCommand *self, Light *light);
void LightOffCommand_execute(LightOffCommand *self);
void LightOffCommand_undo(LightOffCommand *self);
#endif /*__LIGHT_H__*/
