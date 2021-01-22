#ifndef __SAUCE_H__
#define __SAUCE_H__

#include <string.h>

typedef struct _Sauce
{
    char name[100];
} Sauce;

#define Sauce(TYPE) \
    char name[100];

typedef struct _MarinaraSauce
{
    Sauce(struct _MarinaraSauce);
} MarinaraSauce;

void MarinaraSauceNew(MarinaraSauce *);

typedef struct _PlumTomatoSauce
{
    Sauce(struct _PlumTomatoSauce);
} PlumTomatoSauce;

void PlumTomatoSauceNew(PlumTomatoSauce *);

#endif /* __SAUCE_H__ */