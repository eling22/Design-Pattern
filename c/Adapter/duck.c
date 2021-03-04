#include "duck.h"
void MalDuckNew(MallardDuck *self)
{
    self->quack = MalDuckQuack;
    self->fly = MalDuckFly;
}
void MalDuckQuack(MallardDuck *self)
{
    printf("Quack\n");
}
void MalDuckFly(MallardDuck *self)
{
    printf("I'm flying\n");
}