#ifndef __WAITRESS_H__
#define __WAITRESS_H__

#include "menu.h"

typedef struct Waitress
{
    Menu *menu;
    void (*printMenu)(struct Waitress *);
} Waitress;

void WaitressNew(Waitress *self, Menu *menu);
void Waitress_printMenu(Waitress *self);

#endif /*__WAITRESS_H__*/
