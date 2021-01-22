#ifndef __PIZZA_H__
#define __PIZZA_H__

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pizza_ingredient_factory.h"

typedef struct _Pizza
{
    char name[100];
    Dough dough;
    Sauce sauce;
    Cheese cheese;
    Clams clams;
    bool is_cheese_add;
    bool is_clams_add;
    void (*prepare)(struct _Pizza *);
    void (*bake)(struct _Pizza *);
    void (*cut)(struct _Pizza *);
    void (*box)(struct _Pizza *);
} Pizza;

#define Pizza(TYPE)           \
    char name[100];           \
    Dough dough;              \
    Sauce sauce;              \
    Cheese cheese;            \
    Clams clams;              \
    bool is_cheese_add;       \
    bool is_clams_add;        \
    void (*prepare)(Pizza *); \
    void (*bake)(Pizza *);    \
    void (*cut)(Pizza *);     \
    void (*box)(Pizza *);

void PizzaPrepare(Pizza *);
void PizzaBake(Pizza *);
void PizzaCut(Pizza *);
void PizzaBox(Pizza *);

#define PizzaInherit(pizza, ingredient_factory) \
    pizza->dough = ingredient_factory->dough;   \
    pizza->sauce = ingredient_factory->sauce;   \
    pizza->cheese = ingredient_factory->cheese; \
    pizza->clams = ingredient_factory->clams;   \
    pizza->prepare = PizzaPrepare;              \
    pizza->bake = PizzaBake;                    \
    pizza->cut = PizzaCut;                      \
    pizza->box = PizzaBox;

typedef struct _CheesePizza
{
    Pizza(struct _CheesePizza);
} CheesePizza;

void CheesePizzaNew(CheesePizza *, PizzaIngredientFactory *);

typedef struct _ClamPizza
{
    Pizza(struct _ClamPizza);
} ClamPizza;

void ClamPizzaNew(ClamPizza *, PizzaIngredientFactory *);

#endif /* __PIZZA_H__ */