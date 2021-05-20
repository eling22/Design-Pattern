#include "state.h"
#include "gumball_machine.h"

void _gumball_machine_set_state(State *self, State *next_state);
void _not_support(State *self);
void _not_support2(State *self, int num);
void _NoQuarterState_insert_quarter(State *self);
void _HasQuarterState_eject_quarter(State *self);
void _HasQuarterState_turn_crank(State *self);
void _SoldState_dispense(State *self);
void _SoldOutState_fill_ball(State *self, int num);
void _WinnerState_dispense(State *self);

void StateNew(State *self, GumballMachine *gumball_machine)
{
    self->gumball_machine = gumball_machine;
    self->dispense = _not_support;
    self->eject_quarter = _not_support;
    self->fill_ball = _not_support2;
    self->insert_quarter = _not_support;
    self->turn_crank = _not_support;
}

void NoQuarterStateNew(struct State *self, GumballMachine *gumball_machine)
{
    StateNew(self, gumball_machine);
    self->insert_quarter = _NoQuarterState_insert_quarter;
}

void HasQuarterStateNew(struct State *self, GumballMachine *gumball_machine)
{
    StateNew(self, gumball_machine);
    self->eject_quarter = _HasQuarterState_eject_quarter;
    self->turn_crank = _HasQuarterState_turn_crank;
}
void SoldStateNew(struct State *self, GumballMachine *gumball_machine)
{
    StateNew(self, gumball_machine);
    self->dispense = _SoldState_dispense;
}
void SoldOutStateNew(struct State *self, GumballMachine *gumball_machine)
{
    StateNew(self, gumball_machine);
    self->fill_ball = _SoldOutState_fill_ball;
}
void WinnerStateNew(struct State *self, GumballMachine *gumball_machine)
{
    StateNew(self, gumball_machine);
    self->dispense = _WinnerState_dispense;
}

void _gumball_machine_set_state(State *self, State *next_state)
{
    self->gumball_machine->set_state(self->gumball_machine, next_state);
}

void _not_support(State *self)
{
    printf("this function is not support\n");
}
void _not_support2(State *self, int num)
{
    _not_support(self);
}

void _NoQuarterState_insert_quarter(State *self)
{
    printf("insert a quarter\n");
    _gumball_machine_set_state(self, &self->gumball_machine->has_quarter_state);
}
void _HasQuarterState_eject_quarter(State *self)
{
    printf("eject the quarter\n");
    _gumball_machine_set_state(self, &self->gumball_machine->no_quarter_state);
}
void _HasQuarterState_turn_crank(State *self)
{
    printf("turn the crank\n");
    int r = rand() % 10;
    printf("get the ramdom %d\n", r);
    if (r == 1)
    {
        _gumball_machine_set_state(self, &self->gumball_machine->winner_state);
    }
    else
    {
        _gumball_machine_set_state(self, &self->gumball_machine->sold_state);
    }
}
void _SoldState_dispense(State *self)
{
    printf("dispense a ball\n");
    self->gumball_machine->ball_count -= 1;
    if (self->gumball_machine->ball_count <= 0)
    {
        printf("sold out\n");
        _gumball_machine_set_state(self, &self->gumball_machine->sold_out_state);
    }
    else
    {
        _gumball_machine_set_state(self, &self->gumball_machine->no_quarter_state);
    }
}
void _SoldOutState_fill_ball(State *self, int num)
{
    printf("fill %d ball(s)\n", num);
    self->gumball_machine->ball_count += num;
    _gumball_machine_set_state(self, &self->gumball_machine->no_quarter_state);
}
void _WinnerState_dispense(State *self)
{
    printf("congratulation, you win the game\n");
    printf("dispense a ball\n");
    self->gumball_machine->ball_count -= 1;
    if (self->gumball_machine->ball_count <= 0)
    {
        printf("sold out\n");
        _gumball_machine_set_state(self, &self->gumball_machine->sold_out_state);
    }
    else
    {
        printf("dispense a ball\n");
        self->gumball_machine->ball_count -= 1;
        if (self->gumball_machine->ball_count <= 0)
        {
            printf("sold out\n");
            _gumball_machine_set_state(self, &self->gumball_machine->sold_out_state);
        }
        else
        {
            _gumball_machine_set_state(self, &self->gumball_machine->no_quarter_state);
        }
    }
}