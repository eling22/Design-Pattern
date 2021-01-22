#include "pizza.h"

void PizzaPrepare(Pizza *pizza)
{
    printf("Prepare %s \n", pizza->name);
    printf("Tossing %s ...\n", pizza->dough.name);
    printf("Adding %s ...\n", pizza->sauce.name);
    printf("Adding toppings: \n");
    if (pizza->is_cheese_add)
    {
        printf("\t%s\n", pizza->cheese.name);
    }
    else if (pizza->is_clams_add)
    {
        printf("\t%s\n", pizza->clams.name);
    }
}
void PizzaBake(Pizza *pizza)
{
    printf("Bake for 25 minutes at 350\n");
}
void PizzaCut(Pizza *pizza)
{
    printf("Cutting the pizza into diagonal slices\n");
}
void PizzaBox(Pizza *pizza)
{
    printf("Place pizza in official PizzaStore box\n");
}

void CheesePizzaNew(CheesePizza *cheese_pizza, PizzaIngredientFactory *ifactory)
{
    cheese_pizza->is_cheese_add = true;
    cheese_pizza->is_clams_add = false;
    strcpy(cheese_pizza->name, "cheese pizza");
    PizzaInherit(cheese_pizza, ifactory);
}

void ClamPizzaNew(ClamPizza *clam_pizza, PizzaIngredientFactory *ifactory)
{
    clam_pizza->is_cheese_add = false;
    clam_pizza->is_clams_add = true;
    strcpy(clam_pizza->name, "clam pizza");
    PizzaInherit(clam_pizza, ifactory);
}