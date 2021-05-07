#include "menu.h"
#include "waitress.h"

int main()
{
    Menu all_menu;
    MenuNew(&all_menu, "ALL MENUS", "All menus combined");
    Menu p_menu;
    PancakeHouseMenuNew(&p_menu);
    Menu d_menu;
    DinerMenuNew(&d_menu);
    Menu c_menu;
    CafeMenuNew(&c_menu);
    Menu de_menu;
    DessertMenuNew(&de_menu);
    all_menu.add(&all_menu, (MenuComponent *)&p_menu);
    all_menu.add(&all_menu, (MenuComponent *)&d_menu);
    all_menu.add(&all_menu, (MenuComponent *)&c_menu);
    d_menu.add(&d_menu, (MenuComponent *)&de_menu);

    all_menu.print(&all_menu);

    Waitress waitress;
    WaitressNew(&waitress, &all_menu);
    waitress.printMenu(&waitress);
    return 0;
}
