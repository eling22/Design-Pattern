#ifndef __BEVERAGE_H__
#define __BEVERAGE_H__

#include <stdbool.h>
#include <stdio.h>

typedef struct CaffeineBeverageWithHook
{
    void (*prepareRecipe)(struct CaffeineBeverageWithHook *);
    void (*boilWater)(struct CaffeineBeverageWithHook *);
    void (*PourInCup)(struct CaffeineBeverageWithHook *);
    bool (*CustomerWantsCondiments)(struct CaffeineBeverageWithHook *);
    void (*brew)(struct CaffeineBeverageWithHook *);
    void (*addCondiments)(struct CaffeineBeverageWithHook *);
} CaffeineBeverageWithHook;

#define CaffeineBeverageWithHook(TYPE)       \
    void (*prepareRecipe)(TYPE *);           \
    void (*boilWater)(TYPE *);               \
    void (*PourInCup)(TYPE *);               \
    bool (*CustomerWantsCondiments)(TYPE *); \
    void (*brew)(TYPE *);                    \
    void (*addCondiments)(TYPE *);

void CaffeineBeverageWithHookNew(CaffeineBeverageWithHook *self);
void CBWH_prepareRecipe(CaffeineBeverageWithHook *self);
void CBWH_boilWater(CaffeineBeverageWithHook *self);
void CBWH_PourInCup(CaffeineBeverageWithHook *self);
bool CBWH_CustomerWantsCondiments(CaffeineBeverageWithHook *self);

typedef struct CoffeeWithHook
{
    CaffeineBeverageWithHook(struct CoffeeWithHook);
    char (*getUserInput)(struct CoffeeWithHook *);
} CoffeeWithHook;
void CoffeeWithHookNew(CoffeeWithHook *self);
void CoffeeWH_prepareRecipe(CoffeeWithHook *self);
void CoffeeWH_boilWater(CoffeeWithHook *self);
void CoffeeWH_PourInCup(CoffeeWithHook *self);
bool CoffeeWH_CustomerWantsCondiments(CoffeeWithHook *self);
void CoffeeWH_brew(CoffeeWithHook *self);
void CoffeeWH_addCondiments(CoffeeWithHook *self);
char CoffeeWH_getUserInput(CoffeeWithHook *self);

typedef struct TeaWithHook
{
    CaffeineBeverageWithHook(struct TeaWithHook);
    char (*getUserInput)(struct TeaWithHook *);
} TeaWithHook;
void TeaWithHookNew(TeaWithHook *self);
void TeaWH_prepareRecipe(TeaWithHook *self);
void TeaWH_boilWater(TeaWithHook *self);
void TeaWH_PourInCup(TeaWithHook *self);
bool TeaWH_CustomerWantsCondiments(TeaWithHook *self);
void TeaWH_brew(TeaWithHook *self);
void TeaWH_addCondiments(TeaWithHook *self);
char TeaWH_getUserInput(TeaWithHook *self);

#endif /*__BEVERAGE_H__*/
