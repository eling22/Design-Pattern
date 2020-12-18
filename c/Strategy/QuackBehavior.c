#include "QuackBehavior.h"

void QuaBehNew(QuackBehavior *quackbeh, quackFun quack_fun)
{
    quackbeh->quack = quack_fun;
}

void Quack(QuackBehavior *quackbeh)
{
    printf("Quack\n");
}

void MuteQuack(QuackBehavior *quackbeh)
{
    printf("<< Slience >>\n");
}

void SQuack(QuackBehavior *quackbeh)
{
    printf("Squack\n");
}
