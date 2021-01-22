#ifndef __CLAMS_H__
#define __CLAMS_H__

#include <string.h>

typedef struct _Clams
{
    char name[100];
} Clams;

#define Clams(TYPE) \
    char name[100];

typedef struct _FreshClams
{
    Clams(struct _FreshClams);
} FreshClams;

void FreshClamsNew(FreshClams *);

typedef struct _FrozenClam
{
    Clams(struct _FrozenClam);
} FrozenClam;

void FrozenClamNew(FrozenClam *);

#endif /* __CLAMS_H__ */