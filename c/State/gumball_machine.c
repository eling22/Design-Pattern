#include "gumball_machine.h"

void _set_state(struct GumballMachine *self, State *state);
void _insert_quarter(struct GumballMachine *self);
void _eject_quarter(struct GumballMachine *self);
void _turn_crank(struct GumballMachine *self);
void _dispense(struct GumballMachine *self);
void _fill_ball(struct GumballMachine *self, int);

void GumballMachineNew(struct GumballMachine *self)
{
    NoQuarterStateNew(&self->no_quarter_state, self);
    HasQuarterStateNew(&self->has_quarter_state, self);
    SoldStateNew(&self->sold_state, self);
    SoldOutStateNew(&self->sold_out_state, self);
    WinnerStateNew(&self->winner_state, self);
    self->set_state = _set_state;
    self->dispense = _dispense;
    self->eject_quarter = _eject_quarter;
    self->fill_ball = _fill_ball;
    self->insert_quarter = _insert_quarter;
    self->turn_crank = _turn_crank;
    self->ball_count = 10;

    self->set_state(self, &self->no_quarter_state);
}

void _set_state(struct GumballMachine *self, State *state)
{
    self->current_state = state;
}
void _insert_quarter(struct GumballMachine *self)
{
    self->current_state->insert_quarter(self->current_state);
}
void _eject_quarter(struct GumballMachine *self)
{
    self->current_state->eject_quarter(self->current_state);
}
void _turn_crank(struct GumballMachine *self)
{
    self->current_state->turn_crank(self->current_state);
}
void _dispense(struct GumballMachine *self)
{
    self->current_state->dispense(self->current_state);
}
void _fill_ball(struct GumballMachine *self, int num)
{
    self->current_state->fill_ball(self->current_state, num);
}