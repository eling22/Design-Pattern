#include "beverage.h"
int main(void)
{
    TeaWithHook tea;
    TeaWithHookNew(&tea);
    CoffeeWithHook coffee;
    CoffeeWithHookNew(&coffee);

    printf("Making tea...\n");
    tea.prepareRecipe(&tea);

    printf("\nMaking coffee...\n");
    coffee.prepareRecipe(&coffee);
    return 0;
}