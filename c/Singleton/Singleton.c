#include "Singleton.h"
Singleton singleton;

Singleton *SingletonNew(int a, int b)
{
    singleton.a = a;
    singleton.b = b;
    return &singleton;
}