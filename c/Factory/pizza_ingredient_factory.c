#include "pizza_ingredient_factory.h"
void NYPizzaIngredientFactoryNew(NYPizzaIngredientFactory *self)
{
    ThinCrustDoughNew(&self->dough);
    MarinaraSauceNew(&self->sauce);
    ReggianoCheeseNew(&self->cheese);
    FreshClamsNew(&self->clams);
}
void ChicagoPizzaIngredientFactoryNew(ChicagoPizzaIngredientFactory *self)
{
    ThickCrustDoughNew(&self->dough);
    PlumTomatoSauceNew(&self->sauce);
    MozzarellaCheeseNew(&self->cheese);
    FrozenClamNew(&self->clams);
}
