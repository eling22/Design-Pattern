#include <stdio.h>
#include "pizza_store.h"

int main(void)
{
    NYPizzaStore ny_store;
    NYPizzaStoreNew(&ny_store);
    Pizza *pizza = ny_store.orderPizza((PizzaStore *)&ny_store, "cheese");
    printf("A ordered a %s\n\n", pizza->name);
    free(pizza);

    pizza = ny_store.orderPizza((PizzaStore *)&ny_store, "clam");
    printf("B ordered a %s\n\n", pizza->name);

    ChicagoPizzaStore ch_store;
    ChicagoPizzaStoreNew(&ch_store);
    pizza = ch_store.orderPizza((PizzaStore *)&ch_store, "cheese");
    printf("C ordered a %s\n\n", pizza->name);
}