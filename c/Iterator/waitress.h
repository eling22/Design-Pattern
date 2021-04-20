#ifndef __WAITRESS_H__
#define __WAITRESS_H__

#include "menu.h"

typedef struct Waitress
{
    PancakeHouseMenu *p_menu;
    DinerMenu *d_menu;
    void (*printMenu)(struct Waitress *);
} Waitress;

void WaitressNew(Waitress *self, PancakeHouseMenu *p_menu, DinerMenu *d_menu);
void Waitress_printMenu(Waitress *self);

#endif /*__WAITRESS_H__*/
