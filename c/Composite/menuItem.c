#include "menuItem.h"

static void MenuItem_print(MenuItem *self);

void MenuItemNew(MenuItem *self, str name, str description, bool vegetarian, double price)
{
    self->name = name;
    self->description = description;
    self->vegetarian = vegetarian;
    self->price = price;
    self->print = MenuItem_print;
}

void MenuItemArray_init(MenuItemArray *self)
{
    self->idx = 0;
}
void MenuItemArray_addItem(MenuItemArray *self, str name, str description, bool vegetarian, double price)
{
    MenuItemNew(&self->item[self->idx], name, description, vegetarian, price);
    self->idx++;
}

static void MenuItem_print(MenuItem *self)
{
    printf("%s, %.2f -- %s\n", self->name, self->price, self->description);
}