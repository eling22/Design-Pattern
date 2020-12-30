#ifndef __ICONDIMENT_H__
#define __ICONDIMENT_H__

#include "IBeverage.h"

typedef struct ICondiment
{
    IBeverage(struct ICondiment);
    IBeverage *beverage;
    char description_all[256];
} ICondiment;

#define ICondiment(TYPE) \
    IBeverage(TYPE);     \
    IBeverage *beverage; \
    char description_all[256];
#endif /* __ICONDIMENT_H__ */