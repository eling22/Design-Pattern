#include "waitress.h"

void WaitressNew(Waitress *self, Menu *menu)
{
    self->menu = menu;
    self->printMenu = Waitress_printMenu;
}
void Waitress_printMenu(Waitress *self)
{
    self->menu->print(self->menu);
}