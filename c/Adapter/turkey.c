#include "turkey.h"
void WildTurkeyNew(WildTurkey *self)
{
    self->gobble = WildTurkeyGobble;
    self->fly = WildTurkeyFly;
}
void WildTurkeyGobble(WildTurkey *self)
{
    printf("Gobble gobble\n");
}
void WildTurkeyFly(WildTurkey *self)
{
    printf("I'm flying a short distance\n");
}

void TurkeyAdapterNew(TurkeyAdapter *self, Turkey *turkey)
{
    self->turkey = turkey;
    self->quack = TurkeyAdapterQuack;
    self->fly = TurkeyAdapterFly;
}
void TurkeyAdapterQuack(TurkeyAdapter *self)
{
    self->turkey->gobble(self->turkey);
}
void TurkeyAdapterFly(TurkeyAdapter *self)
{
    for (int i = 0; i < 5; i++)
    {
        self->turkey->fly(self->turkey);
    }
}