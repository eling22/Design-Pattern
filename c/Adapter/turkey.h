#ifndef __TURKEY_H__
#define __TURKEY_H__

#include <stdio.h>
#include "duck.h"

typedef struct _Turkey
{
    void (*gobble)(struct _Turkey *);
    void (*fly)(struct _Turkey *);
} Turkey;

#define Turkey(TYPE)        \
    void (*gobble)(TYPE *); \
    void (*fly)(TYPE *);

typedef struct _WildTurkey
{
    Turkey(struct _WildTurkey);
} WildTurkey;

void WildTurkeyNew(WildTurkey *self);
void WildTurkeyGobble(WildTurkey *self);
void WildTurkeyFly(WildTurkey *self);

typedef struct _TurkeyAdapter
{
    Duck(struct _TurkeyAdapter);
    Turkey *turkey;
} TurkeyAdapter;

void TurkeyAdapterNew(TurkeyAdapter *self, Turkey *turkey);
void TurkeyAdapterQuack(TurkeyAdapter *self);
void TurkeyAdapterFly(TurkeyAdapter *self);

#endif /*__TURKEY_H__*/
