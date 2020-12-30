#ifndef __BEVERAGE_H__
#define __BEVERAGE_H__

#include "interface/IBeverage.h"
#include <string.h>

typedef struct _Expresso
{
    IBeverage(struct _Expresso);
} Expresso;

void ExpressoNew(Expresso *this);
char *ExpGetDescription(Expresso *this);
float ExpCost(Expresso *this);

typedef struct _HouseBlend
{
    IBeverage(struct _HouseBlend);
} HouseBlend;

void HouseBlendNew(HouseBlend *this);
char *HBGetDescription(HouseBlend *this);
float HBCost(HouseBlend *this);

typedef struct _DarkRoast
{
    IBeverage(struct _DarkRoast);
} DarkRoast;

void DarkRoastNew(DarkRoast *this);
char *DRGetDescription(DarkRoast *this);
float DRCost(DarkRoast *this);

#endif /* __BEVERAGE_H__ */