#include "pizza_store.h"

void PizzaStoreNew(PizzaStore *pstore)
{
    PizzaStoreInherit(pstore);
}
Pizza *PizzaStoreOrderPizza(PizzaStore *pstore, char *type)
{
    Pizza *pizza = pstore->createPizza(pstore, type);
    pizza->prepare(pizza);
    pizza->bake(pizza);
    pizza->cut(pizza);
    pizza->box(pizza);
    return pizza;
}

void NYPizzaStoreNew(NYPizzaStore *ny_pstore)
{
    NYPizzaIngredientFactoryNew(&ny_pstore->ingredient_factory);
    PizzaStoreInherit(ny_pstore);
    ny_pstore->createPizza = NYPizzaStoreCreatePizza;
}
Pizza *NYPizzaStoreCreatePizza(PizzaStore *ny_pstore, char *type)
{
    if (strcmp(type, "cheese") == 0)
    {
        CheesePizza *pizza = (CheesePizza *)malloc(sizeof(CheesePizza));
        CheesePizzaNew(pizza, &ny_pstore->ingredient_factory);
        strcpy(pizza->name, "NY Style Sauce and Cheese Pizza");
        return (Pizza *)pizza;
    }
    else if (strcmp(type, "clam") == 0)
    {
        ClamPizza *pizza = (ClamPizza *)malloc(sizeof(ClamPizza));
        ClamPizzaNew(pizza, &ny_pstore->ingredient_factory);
        strcpy(pizza->name, "NY Style Clam Pizza");
        return (Pizza *)pizza;
    }
    else
    {
        printf("this type do not exist");
    }
    return 0;
}

void ChicagoPizzaStoreNew(ChicagoPizzaStore *ch_pstore)
{
    ChicagoPizzaIngredientFactoryNew(&ch_pstore->ingredient_factory);
    PizzaStoreInherit(ch_pstore);
    ch_pstore->createPizza = ChicagoPizzaStoreCreatePizza;
}
Pizza *ChicagoPizzaStoreCreatePizza(PizzaStore *ch_pstore, char *type)
{
    if (strcmp(type, "cheese") == 0)
    {
        CheesePizza *pizza = (CheesePizza *)malloc(sizeof(CheesePizza));
        CheesePizzaNew(pizza, &ch_pstore->ingredient_factory);
        strcpy(pizza->name, "Chicago Style Deep Dish Cheese Pizza");
        return (Pizza *)pizza;
    }
    else
    {
        printf("this type do not exist");
    }
    return 0;
}