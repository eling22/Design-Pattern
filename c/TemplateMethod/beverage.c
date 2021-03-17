#include "beverage.h"
void CaffeineBeverageWithHookNew(CaffeineBeverageWithHook *self)
{
    self->prepareRecipe = CBWH_prepareRecipe;
    self->boilWater = CBWH_boilWater;
    self->PourInCup = CBWH_PourInCup;
    self->CustomerWantsCondiments = CBWH_CustomerWantsCondiments;
}
void CBWH_prepareRecipe(CaffeineBeverageWithHook *self)
{
    self->boilWater(self);
    self->brew(self);
    self->PourInCup(self);
    if (self->CustomerWantsCondiments(self))
    {
        self->addCondiments(self);
    }
}
void CBWH_boilWater(CaffeineBeverageWithHook *self)
{
    printf("Boiling water\n");
}
void CBWH_PourInCup(CaffeineBeverageWithHook *self)
{
    printf("Pouring into cup\n");
}
bool CBWH_CustomerWantsCondiments(CaffeineBeverageWithHook *self)
{
    return true;
}
void CoffeeWithHookNew(CoffeeWithHook *self)
{
    self->prepareRecipe = CoffeeWH_prepareRecipe;
    self->boilWater = CoffeeWH_boilWater;
    self->PourInCup = CoffeeWH_PourInCup;
    self->CustomerWantsCondiments = CoffeeWH_CustomerWantsCondiments;
    self->brew = CoffeeWH_brew;
    self->addCondiments = CoffeeWH_addCondiments;
    self->getUserInput = CoffeeWH_getUserInput;
}
void CoffeeWH_prepareRecipe(CoffeeWithHook *self)
{
    CBWH_prepareRecipe((CaffeineBeverageWithHook *)self);
}
void CoffeeWH_boilWater(CoffeeWithHook *self)
{
    CBWH_boilWater((CaffeineBeverageWithHook *)self);
}
void CoffeeWH_PourInCup(CoffeeWithHook *self)
{
    CBWH_PourInCup((CaffeineBeverageWithHook *)self);
}
bool CoffeeWH_CustomerWantsCondiments(CoffeeWithHook *self)
{
    char c = self->getUserInput(self);
    if (c == 'y' || c == 'Y')
        return true;
    else
        return false;
}
void CoffeeWH_brew(CoffeeWithHook *self)
{
    printf("Dripping Coffee through filter\n");
}
void CoffeeWH_addCondiments(CoffeeWithHook *self)
{
    printf("Adding Sugar and Milk\n");
}
char CoffeeWH_getUserInput(CoffeeWithHook *self)
{
    char s[20];
    printf("Would you like sugar and milk with your coffee (y/n)? ");
    gets(s);
    return s[0];
}

void TeaWithHookNew(TeaWithHook *self)
{
    self->prepareRecipe = TeaWH_prepareRecipe;
    self->boilWater = TeaWH_boilWater;
    self->PourInCup = TeaWH_PourInCup;
    self->CustomerWantsCondiments = TeaWH_CustomerWantsCondiments;
    self->brew = TeaWH_brew;
    self->addCondiments = TeaWH_addCondiments;
    self->getUserInput = TeaWH_getUserInput;
}

void TeaWH_prepareRecipe(TeaWithHook *self)
{
    CBWH_prepareRecipe((CaffeineBeverageWithHook *)self);
}
void TeaWH_boilWater(TeaWithHook *self)
{
    CBWH_boilWater((CaffeineBeverageWithHook *)self);
}
void TeaWH_PourInCup(TeaWithHook *self)
{
    CBWH_PourInCup((CaffeineBeverageWithHook *)self);
}
bool TeaWH_CustomerWantsCondiments(TeaWithHook *self)
{
    char c = self->getUserInput(self);
    if (c == 'y' || c == 'Y')
        return true;
    else
        return false;
}
void TeaWH_brew(TeaWithHook *self)
{
    printf("Steeping the tea\n");
}
void TeaWH_addCondiments(TeaWithHook *self)
{
    printf("Adding Lemon\n");
}
char TeaWH_getUserInput(TeaWithHook *self)
{
    char s[20];
    printf("Would you like lemon with your coffee (y/n)? ");
    gets(s);
    return s[0];
}