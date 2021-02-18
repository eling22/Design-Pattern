#include "ceiling_fan.h"

void CeilingFanNew(CeilingFan *self, const char *place)
{
    strcpy(self->place, place);
    self->speed = SPEED_OFF;
    self->set_speed = CeilingFan_set_speed;
    self->print = CeilingFan_print;
}
void CeilingFan_set_speed(CeilingFan *self, Speed speed)
{
    self->speed = speed;
    self->print(self);
}
void CeilingFan_print(CeilingFan *self)
{
    if (strlen(self->place) == 0)
        printf("Ceiling fan");
    else
        printf("%s ceiling fan", self->place);

    switch (self->speed)
    {
    case SPEED_HIGH:
        printf(" is on high\n");
        break;
    case SPEED_MEDIUM:
        printf(" is on medium\n");
        break;
    case SPEED_LOW:
        printf(" is on low\n");
        break;
    case SPEED_OFF:
        printf(" is off\n");
        break;
    default:
        break;
    }
}

void CeilingFanHighCommandNew(CeilingFanHighCommand *self, CeilingFan *ceiling_fan)
{
    self->ceiling_fan = ceiling_fan;
    strcpy(self->name, "CeilingFanHighCommand");
    self->execute = CeilingFanHighCommand_execute;
    self->undo = CeilingFanHighCommand_undo;
}
void CeilingFanHighCommand_execute(CeilingFanHighCommand *self)
{
    self->pre_speed = self->ceiling_fan->speed;
    self->ceiling_fan->set_speed(self->ceiling_fan, SPEED_HIGH);
}
void CeilingFanHighCommand_undo(CeilingFanHighCommand *self)
{
    self->ceiling_fan->set_speed(self->ceiling_fan, self->pre_speed);
}

void CeilingFanMediumCommandNew(CeilingFanMediumCommand *self, CeilingFan *ceiling_fan)
{
    self->ceiling_fan = ceiling_fan;
    strcpy(self->name, "CeilingFanMediumCommand");
    self->execute = CeilingFanMediumCommand_execute;
    self->undo = CeilingFanMediumCommand_undo;
}
void CeilingFanMediumCommand_execute(CeilingFanMediumCommand *self)
{
    self->pre_speed = self->ceiling_fan->speed;
    self->ceiling_fan->set_speed(self->ceiling_fan, SPEED_MEDIUM);
}
void CeilingFanMediumCommand_undo(CeilingFanMediumCommand *self)
{
    self->ceiling_fan->set_speed(self->ceiling_fan, self->pre_speed);
}

void CeilingFanOffCommandNew(CeilingFanOffCommand *self, CeilingFan *ceiling_fan)
{
    self->ceiling_fan = ceiling_fan;
    strcpy(self->name, "CeilingFanOffCommand");
    self->execute = CeilingFanOffCommand_execute;
    self->undo = CeilingFanOffCommand_undo;
}
void CeilingFanOffCommand_execute(CeilingFanOffCommand *self)
{
    self->pre_speed = self->ceiling_fan->speed;
    self->ceiling_fan->set_speed(self->ceiling_fan, SPEED_OFF);
}
void CeilingFanOffCommand_undo(CeilingFanOffCommand *self)
{
    self->ceiling_fan->set_speed(self->ceiling_fan, self->pre_speed);
}
