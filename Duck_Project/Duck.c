#include "Duck.h"

void DuckPerformFly(DuckBehavior *duck)
{
    duck->flyBehavior.fly(&duck->flyBehavior);
}

void DuckPerformQuack(DuckBehavior *duck)
{
    duck->quackBehavior.quack(&duck->quackBehavior);
}

void DuckSetFlyBehavior(struct _DuckBehavior *duck, FlyBehavior flybeh)
{
    duck->flyBehavior = flybeh;
}
void DuckSetQuackBehavior(struct _DuckBehavior *duck, QuackBehavior quackbeh)
{
    duck->quackBehavior = quackbeh;
}

void DuckNew(DuckBehavior *duck, flyFun fly_fun, quackFun quack_fun)
{
    FlyBehNew(&duck->flyBehavior, fly_fun);
    QuaBehNew(&duck->quackBehavior, quack_fun);
    duck->performFly = DuckPerformFly;
    duck->performQuack = DuckPerformQuack;
    duck->setFlyBehavior = DuckSetFlyBehavior;
    duck->setQuackBehavior = DuckSetQuackBehavior;
}

void DuckMalNew(DuckMallard *duck_mal)
{
    DuckNew(&duck_mal->super, FlyWithWings, Quack);
    DuckBehaviorInherit(duck_mal);
    duck_mal->display = DuckMalDisplay;
}

void DuckMalDisplay(DuckMallard *duck)
{
    printf("I'm a real Mallard duck\n");
}

void DuckModNew(DuckModel *duck_mod)
{
    DuckNew(&duck_mod->super, FlyNoWay, Quack);
    DuckBehaviorInherit(duck_mod);
    duck_mod->display = DuckModDisplay;
}

void DuckModDisplay(DuckModel *duck)
{
    printf("I'm a model duck\n");
}