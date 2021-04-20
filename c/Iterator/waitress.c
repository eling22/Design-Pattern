#include "waitress.h"

static void _printMenu(Menu *menu);

void WaitressNew(Waitress *self, PancakeHouseMenu *p_menu, DinerMenu *d_menu)
{
    self->p_menu = p_menu;
    self->d_menu = d_menu;
    self->printMenu = Waitress_printMenu;
}
void Waitress_printMenu(Waitress *self)
{
    printf("Menu\n");
    printf("-----\n");
    printf("BREAKFAST\n");
    _printMenu((Menu *)self->p_menu);
    printf("\n");
    printf("LUNCH\n");
    _printMenu((Menu *)self->d_menu);
}

static void _printMenu(Menu *menu)
{
    Iterator_MenuItem iter = menu->createIterator(menu);
    while (iter.hasNext(&iter))
    {
        MenuItem item = iter.next(&iter);
        printf("%s, %.2f -- %s\n", item.name, item.price, item.description);
    }
}