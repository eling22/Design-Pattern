#include "FlyBehavior.h"
#include "QuackBehavior.h"

typedef struct _DuckBehavior
{
    FlyBehavior flyBehavior;
    QuackBehavior quackBehavior;
    void (*performFly)(struct _DuckBehavior *);
    void (*performQuack)(struct _DuckBehavior *);
    void (*setFlyBehavior)(struct _DuckBehavior *, FlyBehavior);
    void (*setQuackBehavior)(struct _DuckBehavior *, QuackBehavior);
    //virtual void (*display)(struct _DuckBehavior *);
} DuckBehavior;

#define IDuckBehavior(TYPE)                                      \
    DuckBehavior super;                                          \
    void (*display)(struct TYPE *);                              \
    void (*performFly)(struct _DuckBehavior *);                  \
    void (*performQuack)(struct _DuckBehavior *);                \
    void (*setFlyBehavior)(struct _DuckBehavior *, FlyBehavior); \
    void (*setQuackBehavior)(struct _DuckBehavior *, QuackBehavior);

#define DuckBehaviorInherit(duck)                      \
    duck->performFly = duck->super.performFly;         \
    duck->performQuack = duck->super.performQuack;     \
    duck->setFlyBehavior = duck->super.setFlyBehavior; \
    duck->setQuackBehavior = duck->super.setQuackBehavior;

void DuckNew(DuckBehavior *duck, flyFun fly_fun, quackFun quack_fun);
void DuckPerformFly(DuckBehavior *duck);
void DuckPerformQuack(DuckBehavior *duck);
void DuckSetFlyBehavior(struct _DuckBehavior *, FlyBehavior);
void DuckSetQuackBehavior(struct _DuckBehavior *, QuackBehavior);

typedef struct _DuckMallard
{
    IDuckBehavior(_DuckMallard);
} DuckMallard;

void DuckMalNew(DuckMallard *duck_mal);
void DuckMalDisplay(DuckMallard *duck);

typedef struct _DuckModel
{
    IDuckBehavior(_DuckModel);
} DuckModel;

void DuckModNew(DuckModel *duck_mod);
void DuckModDisplay(DuckModel *duck);