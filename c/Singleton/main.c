#include <stdio.h>
#include "Singleton.h"

void main()
{
    Singleton *obj1 = SingletonNew(10, 20);
    Singleton *obj2 = SingletonNew(100, 200);
    printf("obj1 %d %d\n", obj1->a, obj1->b);
    printf("obj2 %d %d\n", obj2->a, obj2->b);
}