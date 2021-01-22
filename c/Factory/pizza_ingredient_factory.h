#ifndef __PIZZA_INGREDIENT_FACTORY_H__
#define __PIZZA_INGREDIENT_FACTORY_H__

#include "ingredient/dough.h"
#include "ingredient/cheese.h"
#include "ingredient/sauce.h"
#include "ingredient/clams.h"

typedef struct _PizzaIngredientFactory
{
    Dough dough;
    Sauce sauce;
    Cheese cheese;
    Clams clams;
} PizzaIngredientFactory;

#define PizzaIngredientFactory(TYPE) \
    Dough dough;                     \
    Sauce sauce;                     \
    Cheese cheese;                   \
    Clams clams;

typedef struct _NYPizzaIngredientFactory
{
    ThinCrustDough dough;
    MarinaraSauce sauce;
    ReggianoCheese cheese;
    FreshClams clams;
} NYPizzaIngredientFactory;

void NYPizzaIngredientFactoryNew(NYPizzaIngredientFactory *);

typedef struct _ChicagoPizzaIngredientFactory
{
    ThickCrustDough dough;
    PlumTomatoSauce sauce;
    MozzarellaCheese cheese;
    FrozenClam clams;
} ChicagoPizzaIngredientFactory;

void ChicagoPizzaIngredientFactoryNew(ChicagoPizzaIngredientFactory *);

#endif /* __PIZZA_INGREDIENT_FACTORY_H__ */