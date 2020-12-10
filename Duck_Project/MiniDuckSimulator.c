#include "Duck.h"

void main()
{
    DuckMallard mallard_duck;
    DuckMalNew(&mallard_duck);
    mallard_duck.performQuack(&mallard_duck.super);
    mallard_duck.performFly(&mallard_duck.super);

    DuckModel model_duck;
    DuckModNew(&model_duck);
    model_duck.performFly(&model_duck.super);
    FlyBehavior fly_bef;
    FlyBehNew(&fly_bef, FlyRocketPowered);
    model_duck.setFlyBehavior(&model_duck.super, fly_bef);
    model_duck.performFly(&model_duck.super);
}