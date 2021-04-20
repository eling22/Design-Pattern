#ifndef __MENUITEM_H__
#define __MENUITEM_H__

#include "stdbool.h"

typedef const char *str;

typedef struct MenuItem
{
    str name;
    str description;
    bool vegetarian;
    double price;
} MenuItem;

typedef struct MenuItemArray
{
    MenuItem item[10];
    int idx;
} MenuItemArray;

void MenuItemArray_init(MenuItemArray *self);
void MenuItemArray_addItem(MenuItemArray *self, str name, str description, bool vegetarian, double price);

#endif /*__MENUITEM_H__*/
