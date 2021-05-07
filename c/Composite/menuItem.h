#ifndef __MENUITEM_H__
#define __MENUITEM_H__

#include "stdbool.h"
#include "stdio.h"

typedef const char *str;

typedef struct MenuComponent
{
    str type;
    void (*print)(struct MenuComponent *self);
} MenuComponent;

#define MenuComponent(typ) \
    str type;              \
    void (*print)(typ * self);

typedef struct MenuItem
{
    MenuComponent(struct MenuItem);
    str name;
    str description;
    bool vegetarian;
    double price;
} MenuItem;

void MenuItemNew(MenuItem *self, str name, str description, bool vegetarian, double price);

typedef struct MenuItemArray
{
    MenuItem item[10];
    int idx;
} MenuItemArray;

void MenuItemArray_init(MenuItemArray *self);
void MenuItemArray_addItem(MenuItemArray *self, str name, str description, bool vegetarian, double price);

#endif /*__MENUITEM_H__*/
