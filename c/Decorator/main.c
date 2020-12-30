#include "Beverage.h"
#include "Condiment.h"
#include <stdio.h>

#define print_info(beverage) \
    printf("%s $%.2f\n", (beverage)->getDescription(beverage), (beverage)->cost(beverage));

void main()
{
    Expresso beverage;
    ExpressoNew(&beverage);
    print_info(&beverage);

    DarkRoast beverage2;
    DarkRoastNew(&beverage2);
    Mocha beverage2_m;
    MochaNew(&beverage2_m, (IBeverage *)&beverage2);
    Mocha beverage2_mm;
    MochaNew(&beverage2_mm, (IBeverage *)&beverage2_m);
    Whip beverage2_mmw;
    WhipNew(&beverage2_mmw, (IBeverage *)&beverage2_mm);
    print_info(&beverage2_mmw);

    HouseBlend beverage3;
    HouseBlendNew(&beverage3);
    Soy beverage3_s;
    SoyNew(&beverage3_s, (IBeverage *)&beverage3);
    Mocha beverage3_sm;
    MochaNew(&beverage3_sm, (IBeverage *)&beverage3_s);
    Whip beverage3_smw;
    WhipNew(&beverage3_smw, (IBeverage *)&beverage3_sm);
    print_info(&beverage3_smw);
}