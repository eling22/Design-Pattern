#ifndef __DUCK_H__
#define __DUCK_H__

#include <stdio.h>

typedef struct _Duck
{
    void (*quack)(struct _Duck *);
    void (*fly)(struct _Duck *);
} Duck;

#define Duck(TYPE)         \
    void (*quack)(TYPE *); \
    void (*fly)(TYPE *);

typedef struct _MallardDuck
{
    Duck(struct _MallardDuck);
} MallardDuck;

void MalDuckNew(MallardDuck *self);
void MalDuckQuack(MallardDuck *self);
void MalDuckFly(MallardDuck *self);

#endif /*__DUCK_H__*/
