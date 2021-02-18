#include "light.h"

void LightNew(Light *self, const char *place)
{
    strcpy(self->place, place);
    self->on = Light_on;
    self->off = Light_off;
    self->print = Light_print;
}
void print_light(char *place)
{
    if (strlen(place) == 0)
    {
        printf("Light");
    }
    else
    {
        printf("%s light", place);
    }
}
void Light_on(Light *self)
{
    print_light(self->place);
    printf("is on\n");
}
void Light_off(Light *self)
{
    print_light(self->place);
    printf("is off\n");
}
void Light_print(Light *self)
{
    printf("light\n");
}

void LightOnCommandNew(LightOnCommand *self, Light *light)
{
    self->light = light;
    strcpy(self->name, "LightOnCommand");
    self->execute = LightOnCommand_execute;
    self->undo = LightOnCommand_undo;
}
void LightOnCommand_execute(LightOnCommand *self)
{
    self->light->on(self->light);
}
void LightOnCommand_undo(LightOnCommand *self)
{
    self->light->off(self->light);
}

void LightOffCommandNew(LightOffCommand *self, Light *light)
{
    self->light = light;
    strcpy(self->name, "LightOffCommand");
    self->execute = LightOffCommand_execute;
    self->undo = LightOffCommand_undo;
}
void LightOffCommand_execute(LightOffCommand *self)
{
    self->light->off(self->light);
}
void LightOffCommand_undo(LightOffCommand *self)
{
    self->light->on(self->light);
}