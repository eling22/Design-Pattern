#include <stdio.h>

typedef struct _QuackBehavior
{
    void (*quack)(struct _QuackBehavior *);
} QuackBehavior;

typedef void (*quackFun)(struct _QuackBehavior *);

void QuaBehNew(QuackBehavior *quackbeh, quackFun quack_fun);
void Quack(QuackBehavior *quackbeh);
void MuteQuack(QuackBehavior *quackbeh);
void SQuack(QuackBehavior *quackbeh);
