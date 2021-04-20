#include "menu.h"
#include "waitress.h"

int main()
{
    PancakeHouseMenu p_menu;
    PancakeHouseMenuNew(&p_menu);
    DinerMenu d_menu;
    DinerMenuNew(&d_menu);

    Waitress waitress;
    WaitressNew(&waitress, &p_menu, &d_menu);
    waitress.printMenu(&waitress);
    return 0;
}
