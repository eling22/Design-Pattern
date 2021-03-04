#include "duck.h"
#include "turkey.h"

void testDuck(Duck *duck)
{
    duck->quack(duck);
    duck->fly(duck);
}

void testTurkey(Turkey *turkey)
{
    turkey->gobble(turkey);
    turkey->fly(turkey);
}

int main()
{
    MallardDuck duck;
    MalDuckNew(&duck);
    WildTurkey turkey;
    WildTurkeyNew(&turkey);
    TurkeyAdapter turkey_adapter;
    TurkeyAdapterNew(&turkey_adapter, (Turkey *)&turkey);

    printf("The Turkey says...\n");
    testTurkey((Turkey *)&turkey);

    printf("\nThe Duck says...\n");
    testDuck((Duck *)&duck);

    printf("\nThe TurkeyAdapter says...\n");
    testDuck((Duck *)&turkey_adapter);
    return 0;
}