#ifndef __PIZZA_STORE_H__
#define __PIZZA_STORE_H__

#include "pizza.h"
#include "pizza_ingredient_factory.h"
#include <stdlib.h>

typedef struct _PizzaStore
{
    PizzaIngredientFactory ingredient_factory;
    Pizza *(*orderPizza)(struct _PizzaStore *, char *);
    Pizza *(*createPizza)(struct _PizzaStore *, char *);
} PizzaStore;

#define PizzaStore(TYPE)                        \
    Pizza *(*orderPizza)(PizzaStore *, char *); \
    Pizza *(*createPizza)(PizzaStore *, char *);

void PizzaStoreNew(PizzaStore *);
Pizza *PizzaStoreOrderPizza(PizzaStore *, char *);

#define PizzaStoreInherit(pstore) \
    pstore->orderPizza = PizzaStoreOrderPizza;

typedef struct _NYPizzaStore
{
    NYPizzaIngredientFactory ingredient_factory;
    PizzaStore(struct _NYPizzaStore);
} NYPizzaStore;
void NYPizzaStoreNew(NYPizzaStore *);
Pizza *NYPizzaStoreCreatePizza(PizzaStore *, char *);

typedef struct ChicagoPizzaStore
{
    ChicagoPizzaIngredientFactory ingredient_factory;
    PizzaStore(struct ChicagoPizzaStore);
} ChicagoPizzaStore;
void ChicagoPizzaStoreNew(ChicagoPizzaStore *);
Pizza *ChicagoPizzaStoreCreatePizza(PizzaStore *, char *);

#endif /* __PIZZA_STORE_H__ */