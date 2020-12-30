#include "Beverage.h"

void ExpressoNew(Expresso *this)
{
    strcpy(this->description, "Expresso");
    this->price = 1.99;
    this->getDescription = ExpGetDescription;
    this->cost = ExpCost;
}
char *ExpGetDescription(Expresso *this)
{
    return this->description;
}
float ExpCost(Expresso *this)
{
    return this->price;
}

void HouseBlendNew(HouseBlend *this)
{
    strcpy(this->description, "HouseBlend");
    this->price = 0.89;
    this->getDescription = HBGetDescription;
    this->cost = HBCost;
}
char *HBGetDescription(HouseBlend *this)
{
    return this->description;
}
float HBCost(HouseBlend *this)
{
    return this->price;
}

void DarkRoastNew(DarkRoast *this)
{
    strcpy(this->description, "DarkRoast");
    this->price = 0.99;
    this->getDescription = DRGetDescription;
    this->cost = DRCost;
}
char *DRGetDescription(DarkRoast *this)
{
    return this->description;
}
float DRCost(DarkRoast *this)
{
    return this->price;
}