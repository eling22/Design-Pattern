#include "menuItem.h"

void MenuItemArray_init(MenuItemArray *self)
{
    self->idx = 0;
}
void MenuItemArray_addItem(MenuItemArray *self, str name, str description, bool vegetarian, double price)
{
    self->item[self->idx].name = name;
    self->item[self->idx].description = description;
    self->item[self->idx].vegetarian = vegetarian;
    self->item[self->idx].price = price;
    self->idx++;
}