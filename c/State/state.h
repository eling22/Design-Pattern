#ifndef __STATE_H__
#define __STATE_H__

#include <stdio.h>
#include <stdlib.h>
// #include "gumball_machine.h"

typedef struct GumballMachine GumballMachine;

typedef struct State
{
    GumballMachine *gumball_machine;
    void (*insert_quarter)(struct State *);
    void (*eject_quarter)(struct State *);
    void (*turn_crank)(struct State *);
    void (*dispense)(struct State *);
    void (*fill_ball)(struct State *, int n);
} State;

void StateNew(State *, GumballMachine *);

void NoQuarterStateNew(struct State *, GumballMachine *);
void HasQuarterStateNew(struct State *, GumballMachine *);
void SoldStateNew(struct State *, GumballMachine *);
void SoldOutStateNew(struct State *, GumballMachine *);
void WinnerStateNew(struct State *, GumballMachine *);

#endif /*__STATE_H__*/
