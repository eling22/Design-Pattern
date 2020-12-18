#include <stdio.h>

typedef struct _FlyBehavior
{
    void (*fly)(struct _FlyBehavior *);
} FlyBehavior;

typedef void (*flyFun)(struct _FlyBehavior *);

void FlyBehNew(FlyBehavior *flybeh, flyFun fly_fun);
void FlyWithWings(FlyBehavior *flybeh);
void FlyNoWay(FlyBehavior *flybeh);
void FlyRocketPowered(FlyBehavior *flybeh);
