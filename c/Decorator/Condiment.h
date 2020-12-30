#ifndef __CONDIMENT_H__
#define __CONDIMENT_H__

#include "interface/ICondiment.h"
#include "interface/IBeverage.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _Mocha
{
    ICondiment(struct _Mocha);
} Mocha;

void MochaNew(Mocha *this, IBeverage *beverage);
char *MochaGetDescription(Mocha *this);
float MochaCost(Mocha *this);

typedef struct _Soy
{
    ICondiment(struct _Soy);
} Soy;

void SoyNew(Soy *this, IBeverage *beverage);
char *SoyGetDescription(Soy *this);
float SoyCost(Soy *this);

typedef struct _Whip
{
    ICondiment(struct _Whip);
} Whip;

void WhipNew(Whip *this, IBeverage *beverage);
char *WhipGetDescription(Whip *this);
float WhipCost(Whip *this);

#endif /* __CONDIMENT_H__ */