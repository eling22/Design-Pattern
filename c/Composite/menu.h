#ifndef __MENU_H__
#define __MENU_H__

#include "menuItem.h"
#include "stdio.h"
#include <string.h>

#define MAX_MENU_COM_NUM 10
typedef struct Menu
{
    MenuComponent(struct Menu);
    MenuComponent *menu_coms[MAX_MENU_COM_NUM];
    int menu_com_length;
    str name;
    str description;
    void (*add)(struct Menu *self, MenuComponent *menu_com);
} Menu;

void MenuNew(Menu *self, str name, str description);
void PancakeHouseMenuNew(Menu *self);
void DinerMenuNew(Menu *self);
void CafeMenuNew(Menu *self);
void DessertMenuNew(Menu *self);

#endif /*__MENU_H__*/
