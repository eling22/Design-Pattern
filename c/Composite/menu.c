#include "menu.h"

#define MAX_MENU_ITEM_NUM 20
MenuItem menu_items[MAX_MENU_ITEM_NUM];
int menu_item_len = 0;

static void _add(struct Menu *self, MenuComponent *menu_com);
static void _print(struct Menu *self);
static MenuComponent *_create_menu_item(str name, str description, bool vegetarian, double price);

void MenuNew(Menu *self, str name, str description)
{
    self->add = _add;
    self->print = _print;
    self->name = name;
    self->description = description;
    self->menu_com_length = 0;
}

static void _add(struct Menu *self, MenuComponent *menu_com)
{
    self->menu_coms[self->menu_com_length] = menu_com;
    self->menu_com_length++;
}

static void _print(struct Menu *self)
{
    printf("\n%s, %s\n", self->name, self->description);
    printf("--------------------------------\n");
    //printf("self->menu_com_length = %s\n", self->menu_com_length);

    for (int i = 0; i < self->menu_com_length; i++)
    {
        self->menu_coms[i]->print(self->menu_coms[i]);
    }
}

static MenuComponent *_create_menu_item(str name, str description, bool vegetarian, double price)
{
    MenuItemNew(&menu_items[menu_item_len], name, description, vegetarian, price);
    menu_item_len++;
    return (MenuComponent *)&menu_items[menu_item_len - 1];
}

void PancakeHouseMenuNew(Menu *self)
{
    MenuNew(self, "PANCAKE HOUSE MENU", "Breakfast");
    MenuComponent *menu_com = _create_menu_item("K&P Pancake Breakfast", "Pancakes with scrambled eggs,toast", true, 2.99);
    self->add(self, menu_com);
    menu_com = _create_menu_item("Regular Pancake Breakfast", "Pancakes with fried eggs,sausage", false, 2.99);
    self->add(self, menu_com);
    menu_com = _create_menu_item("Blueberry Pancake", "Pancakes made with fresh blueberries", true, 3.49);
    self->add(self, menu_com);
    menu_com = _create_menu_item("Waffles", "Waffles, with your choice of blueberries or strawberries", true, 3.59);
    self->add(self, menu_com);
}

void DinerMenuNew(Menu *self)
{
    MenuNew(self, "DINER MENU", "Lunch");
    MenuComponent *menu_com = _create_menu_item("Vegetarian BLT",
                                                "(Fakin')Bacon with lettuce & tomato on whole wheat",
                                                true,
                                                2.99);
    self->add(self, menu_com);
    menu_com = _create_menu_item("BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99);
    self->add(self, menu_com);
    menu_com = _create_menu_item("Soup of the day",
                                 "Soup of the day, with a side of potato salad",
                                 false,
                                 3.29);
    self->add(self, menu_com);
    menu_com = _create_menu_item("Hotdog",
                                 "A hot dog, with saurkraut, relish, onions, topped with cheese",
                                 false,
                                 3.05);
    self->add(self, menu_com);
}

void CafeMenuNew(Menu *self)
{
    MenuNew(self, "CAFE MENU", "Dinner");
    MenuComponent *menu_com = _create_menu_item("Veggie Burger and Air Fries",
                                                "Veggie burger on a whole wheat bun, lettuce, tomato, and fries",
                                                true,
                                                3.99);
    self->add(self, menu_com);
    menu_com = _create_menu_item("Soup of the day",
                                 "A cup of the soup of the day, with a side salad",
                                 false,
                                 3.69);
    self->add(self, menu_com);
    menu_com = _create_menu_item("Burrito",
                                 "A large burrito, with whole pinto beans, salsa, guacamole",
                                 true,
                                 4.29);
    self->add(self, menu_com);
}

void DessertMenuNew(Menu *self)
{
    MenuNew(self, "DESSERT MENU", "Dessert of course");
    MenuComponent *menu_com = _create_menu_item("Apple Pie",
                                                "Apple pie with a flakey crust, topped with vanilla icecream",
                                                true,
                                                1.59);
    self->add(self, menu_com);
    menu_com = _create_menu_item("Cheesecake",
                                 "Creamy New York cheesecake, with a chocolate graham crust",
                                 true,
                                 1.99);
    self->add(self, menu_com);
    menu_com = _create_menu_item("Sorbet", "A scoop of raspberry and a scoop of lime", true, 1.89);
    self->add(self, menu_com);
}