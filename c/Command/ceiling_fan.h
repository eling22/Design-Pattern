#ifndef __CEILING_FAN_H__
#define __CEILING_FAN_H__

#include "interface/command.h"

enum _Speed
{
    SPEED_HIGH,
    SPEED_MEDIUM,
    SPEED_LOW,
    SPEED_OFF,
};
typedef enum _Speed Speed;

typedef struct _CeilingFan
{
    char place[100];
    Speed speed;
    void (*set_speed)(struct _CeilingFan *, Speed speed);
    void (*print)(struct _CeilingFan *);
} CeilingFan;

void CeilingFanNew(CeilingFan *self, const char *place);
void CeilingFan_set_speed(CeilingFan *self, Speed speed);
void CeilingFan_print(CeilingFan *self);

typedef struct _CeilingFanHighCommand
{
    Command(struct _CeilingFanHighCommand);
    CeilingFan *ceiling_fan;
    Speed pre_speed;
} CeilingFanHighCommand;

void CeilingFanHighCommandNew(CeilingFanHighCommand *self, CeilingFan *ceiling_fan);
void CeilingFanHighCommand_execute(CeilingFanHighCommand *self);
void CeilingFanHighCommand_undo(CeilingFanHighCommand *self);

typedef struct _CeilingFanMediumCommand
{
    Command(struct _CeilingFanMediumCommand);
    CeilingFan *ceiling_fan;
    Speed pre_speed;
} CeilingFanMediumCommand;

void CeilingFanMediumCommandNew(CeilingFanMediumCommand *self, CeilingFan *ceiling_fan);
void CeilingFanMediumCommand_execute(CeilingFanMediumCommand *self);
void CeilingFanMediumCommand_undo(CeilingFanMediumCommand *self);

typedef struct _CeilingFanOffCommand
{
    Command(struct _CeilingFanOffCommand);
    CeilingFan *ceiling_fan;
    Speed pre_speed;
} CeilingFanOffCommand;

void CeilingFanOffCommandNew(CeilingFanOffCommand *self, CeilingFan *ceiling_fan);
void CeilingFanOffCommand_execute(CeilingFanOffCommand *self);
void CeilingFanOffCommand_undo(CeilingFanOffCommand *self);

#endif /*__CEILING_FAN_H__*/
