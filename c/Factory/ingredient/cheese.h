#ifndef __CHEESE_H__
#define __CHEESE_H__

#include <string.h>

typedef struct _Cheese
{
    char name[100];
} Cheese;

#define Cheese(TYPE) \
    char name[100];

typedef struct _ReggianoCheese
{
    Cheese(struct _ReggianoCheese);
} ReggianoCheese;

void ReggianoCheeseNew(ReggianoCheese *);

typedef struct _MozzarellaCheese
{
    Cheese(struct _MozzarellaCheese);
} MozzarellaCheese;

void MozzarellaCheeseNew(MozzarellaCheese *);

#endif /* __CHEESE_H__ */