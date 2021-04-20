#ifndef __MENU_H__
#define __MENU_H__

#include "menuItem.h"
#include "iterator.h"
#include "stdio.h"

typedef struct Menu
{
    Iterator_MenuItem (*createIterator)(struct Menu *);
} Menu;

#define Menu(type) \
    Iterator_MenuItem (*createIterator)(type *);

#define MAX_MENU_ITEM_NUM 4
typedef struct PancakeHouseMenu
{
    Menu(struct PancakeHouseMenu);
    MenuItem menu_items[MAX_MENU_ITEM_NUM];
    int menu_item_length;
    Iterator_MenuItem iter;
} PancakeHouseMenu;

void PancakeHouseMenuNew(PancakeHouseMenu *self);

typedef struct DinerMenu
{
    Menu(struct DinerMenu);
    MenuItemArray menu_items;
    Iterator_MenuItem iter;
} DinerMenu;
void DinerMenuNew(DinerMenu *self);

#endif /*__MENU_H__*/
