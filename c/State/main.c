#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gumball_machine.h"
#include "state.h"

int main()
{
    srand(time(NULL));
    GumballMachine gumball_machine;
    GumballMachineNew(&gumball_machine);
    printf("i:insert_quarter\n");
    printf("e:eject_quarter\n");
    printf("t:turn_crank\n");
    printf("d:dispense\n");
    printf("f:fill_ball\n");
    printf("q:quit\n");
    printf("===========================\n");
    while (1)
    {
        char c = getchar();
        if (c == 'i')
            gumball_machine.insert_quarter(&gumball_machine);
        else if (c == 'e')
            gumball_machine.eject_quarter(&gumball_machine);
        else if (c == 't')
            gumball_machine.turn_crank(&gumball_machine);
        else if (c == 'd')
            gumball_machine.dispense(&gumball_machine);
        else if (c == 'f')
        {
            printf("the num of fill ball:");
            int n;
            scanf("%d", &n);
            gumball_machine.fill_ball(&gumball_machine, n);
        }
        else if (c == 'q')
            break;
    }

    return 0;
}