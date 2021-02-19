#include "ceiling_fan.h"

void SpeedStackNew(SpeedStack *self)
{
    self->pre_speed_idx = 0;
    self->pre_speed_len = 0;
    self->push = SpeedStack_push;
    self->pop = SpeedStack_pop;
}
void SpeedStack_push(SpeedStack *self, Speed speed)
{
    self->pre_speed_idx++;
    if (self->pre_speed_len < MAX_PRE_SPEED)
    {
        self->pre_speed_len++;
    }
    if (self->pre_speed_idx >= MAX_PRE_SPEED)
    {
        self->pre_speed_idx = 0;
    }
    self->pre_speed[self->pre_speed_idx] = speed;
}
Speed SpeedStack_pop(SpeedStack *self)
{
    if (self->pre_speed_len = 0)
        return SPEED_NO_CHANGE;
    Speed speed = self->pre_speed[self->pre_speed_idx];
    self->pre_speed_idx--;
    self->pre_speed_len--;
    return speed;
}

void CeilingFanNew(CeilingFan *self, const char *place)
{
    strcpy(self->place, place);
    self->speed = SPEED_OFF;
    self->set_speed = CeilingFan_set_speed;
    self->print = CeilingFan_print;
}
void CeilingFan_set_speed(CeilingFan *self, Speed speed)
{
    if (speed != SPEED_NO_CHANGE)
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
    SpeedStackNew(&self->pre_speed_stack);
}
void CeilingFanHighCommand_execute(CeilingFanHighCommand *self)
{
    self->pre_speed_stack.push(&self->pre_speed_stack, self->ceiling_fan->speed);
    self->ceiling_fan->set_speed(self->ceiling_fan, SPEED_HIGH);
}
void CeilingFanHighCommand_undo(CeilingFanHighCommand *self)
{
    Speed speed = self->pre_speed_stack.pop(&self->pre_speed_stack);
    self->ceiling_fan->set_speed(self->ceiling_fan, speed);
}

void CeilingFanMediumCommandNew(CeilingFanMediumCommand *self, CeilingFan *ceiling_fan)
{
    self->ceiling_fan = ceiling_fan;
    strcpy(self->name, "CeilingFanMediumCommand");
    self->execute = CeilingFanMediumCommand_execute;
    self->undo = CeilingFanMediumCommand_undo;
    SpeedStackNew(&self->pre_speed_stack);
}

void CeilingFanMediumCommand_execute(CeilingFanMediumCommand *self)
{
    self->pre_speed_stack.push(&self->pre_speed_stack, self->ceiling_fan->speed);
    self->ceiling_fan->set_speed(self->ceiling_fan, SPEED_MEDIUM);
}
void CeilingFanMediumCommand_undo(CeilingFanMediumCommand *self)
{
    Speed speed = self->pre_speed_stack.pop(&self->pre_speed_stack);
    self->ceiling_fan->set_speed(self->ceiling_fan, speed);
}

void CeilingFanOffCommandNew(CeilingFanOffCommand *self, CeilingFan *ceiling_fan)
{
    self->ceiling_fan = ceiling_fan;
    strcpy(self->name, "CeilingFanOffCommand");
    self->execute = CeilingFanOffCommand_execute;
    self->undo = CeilingFanOffCommand_undo;
    SpeedStackNew(&self->pre_speed_stack);
}

void CeilingFanOffCommand_execute(CeilingFanOffCommand *self)
{
    self->pre_speed_stack.push(&self->pre_speed_stack, self->ceiling_fan->speed);
    self->ceiling_fan->set_speed(self->ceiling_fan, SPEED_OFF);
}
void CeilingFanOffCommand_undo(CeilingFanOffCommand *self)
{
    Speed speed = self->pre_speed_stack.pop(&self->pre_speed_stack);
    self->ceiling_fan->set_speed(self->ceiling_fan, speed);
}
