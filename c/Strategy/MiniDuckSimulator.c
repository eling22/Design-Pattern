#include "Duck.h"

void main()
{
    DuckMallard mallard_duck;
    DuckMalNew(&mallard_duck);
    DuckBehavior *beh = (DuckBehavior *)&mallard_duck;
    mallard_duck.performQuack(beh);
    mallard_duck.performFly(beh);

    DuckModel model_duck;
    DuckModNew(&model_duck);
    model_duck.performFly(&model_duck.super);
    FlyBehavior fly_bef;
    FlyBehNew(&fly_bef, FlyRocketPowered);
    model_duck.setFlyBehavior(&model_duck.super, fly_bef);
    model_duck.performFly(&model_duck.super);

    DuckTest test_duck;
    DuckTestNew(&test_duck);
    test_duck.performFly(&test_duck.super);
    FlyBehavior fly_bef2;
    FlyBehNew(&fly_bef2, FlyRocketPowered);
    test_duck.setFlyBehavior(&test_duck.super, fly_bef);
    test_duck.performFly(&test_duck.super);
}