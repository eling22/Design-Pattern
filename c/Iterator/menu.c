#include "menu.h"

static void _addItem(PancakeHouseMenu *self, str name, str description, bool vegetarian, double price);
static Iterator_MenuItem PancakeHouseMenu_createIterator(PancakeHouseMenu *self);
static Iterator_MenuItem DinerMenu_createIterator(DinerMenu *self);

void PancakeHouseMenuNew(PancakeHouseMenu *self)
{
    self->createIterator = PancakeHouseMenu_createIterator;
    self->menu_item_length = 0;
    _addItem(self, "K&P Pancake Breakfast", "Pancakes with scrambled eggs,toast", true, 2.99);
    _addItem(self, "Regular Pancake Breakfast", "Pancakes with fried eggs,sausage", false, 2.99);
    _addItem(self, "Blueberry Pancake", "Pancakes made with fresh blueberries", true, 3.49);
    _addItem(self, "Waffles", "Waffles, with your choice of blueberries or strawberries", true, 3.59);
}
static void _addItem(PancakeHouseMenu *self, str name, str description, bool vegetarian, double price)
{
    if (self->menu_item_length >= MAX_MENU_ITEM_NUM)
    {
        printf("Can't add more menu item into this menu!");
    }
    self->menu_items[self->menu_item_length].name = name;
    self->menu_items[self->menu_item_length].description = description;
    self->menu_items[self->menu_item_length].vegetarian = vegetarian;
    self->menu_items[self->menu_item_length].price = price;
    MenuItem item = self->menu_items[self->menu_item_length];
    self->menu_item_length++;
}
static Iterator_MenuItem PancakeHouseMenu_createIterator(PancakeHouseMenu *self)
{
    Iterator_MenuItem_New(&self->iter, self->menu_items, self->menu_item_length);
    return self->iter;
}

void DinerMenuNew(DinerMenu *self)
{
    self->createIterator = DinerMenu_createIterator;
    MenuItemArray_init(&self->menu_items);
    MenuItemArray_addItem(&self->menu_items, "Vegetarian BLT", "(Fakin') Bacon with lettuce & tomato on whole wheat", true, 2.99);
    MenuItemArray_addItem(&self->menu_items, "BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99);
    MenuItemArray_addItem(&self->menu_items, "Soup of the day", "Soup of the day, with a side of potato salad", false, 3.99);
    MenuItemArray_addItem(&self->menu_items, "Hotdog", "A hot dog, with saurkraut, relish, onions, topped with cheese", false, 3.05);
}
static Iterator_MenuItem DinerMenu_createIterator(DinerMenu *self)
{
    Iterator_MenuItem_New(&self->iter, self->menu_items.item, self->menu_items.idx);
    return self->iter;
}