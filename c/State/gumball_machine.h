#ifndef __GUMBALL_MACHINE_H__
#define __GUMBALL_MACHINE_H__

#include "state.h"

typedef struct State State;

typedef struct GumballMachine
{
    State *current_state;
    State no_quarter_state;
    State has_quarter_state;
    State sold_state;
    State sold_out_state;
    State winner_state;
    int ball_count;
    void (*set_state)(struct GumballMachine *, State *);
    void (*insert_quarter)(struct GumballMachine *);
    void (*eject_quarter)(struct GumballMachine *);
    void (*turn_crank)(struct GumballMachine *);
    void (*dispense)(struct GumballMachine *);
    void (*fill_ball)(struct GumballMachine *, int num);
} GumballMachine;

void GumballMachineNew(struct GumballMachine *self);

#endif /*__GUMBALL_MACHINE_H__*/
