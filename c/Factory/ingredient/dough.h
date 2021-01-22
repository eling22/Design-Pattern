#ifndef __DOUGH_H__
#define __DOUGH_H__

#include <string.h>

typedef struct _Dough
{
    char name[100];
} Dough;

#define Dough(TYPE) \
    char name[100];

typedef struct _ThickCrustDough
{
    Dough(struct _ThickCrustDough);
} ThickCrustDough;

void ThickCrustDoughNew(ThickCrustDough *);

typedef struct _ThinCrustDough
{
    Dough(struct _ThinCrustDough);
} ThinCrustDough;

void ThinCrustDoughNew(ThinCrustDough *);

#endif /* __DOUGH_H__ */