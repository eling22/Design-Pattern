#include "FlyBehavior.h"

void FlyBehNew(FlyBehavior *flybeh, flyFun fly_fun)
{
    flybeh->fly = fly_fun;
}

void FlyWithWings(FlyBehavior *flybeh)
{
    printf("I'm flying!\n");
}

void FlyNoWay(FlyBehavior *flybeh)
{
    printf("I can't fly!\n");
}

void FlyRocketPowered(FlyBehavior *flybeh)
{
    printf("I'm flying with a rocket!\n");
}
