#include "Condiment.h"

void MochaNew(Mocha *this, IBeverage *beverage)
{
    strcpy(this->description, "Mocha");
    this->price = 0.20;
    this->getDescription = MochaGetDescription;
    this->cost = MochaCost;
    this->beverage = beverage;
}
char *MochaGetDescription(Mocha *this)
{
    //printf("%s $%.2f\n", (this->beverage)->getDescription(this->beverage), (this->beverage)->cost(this->beverage));
    strcpy(this->description_all, "");
    strcat(this->description_all, this->beverage->getDescription(this->beverage));
    strcat(this->description_all, ", ");
    strcat(this->description_all, this->description);
    return this->description_all;
}
float MochaCost(Mocha *this)
{
    return this->beverage->cost(this->beverage) + this->price;
}

void SoyNew(Soy *this, IBeverage *beverage)
{
    strcpy(this->description, "Soy");
    this->price = 0.15;
    this->getDescription = SoyGetDescription;
    this->cost = SoyCost;
    this->beverage = beverage;
}
char *SoyGetDescription(Soy *this)
{
    strcpy(this->description_all, "");
    strcat(this->description_all, this->beverage->getDescription(this->beverage));
    strcat(this->description_all, ", ");
    strcat(this->description_all, this->description);
    return this->description_all;
}
float SoyCost(Soy *this)
{
    return this->beverage->cost(this->beverage) + this->price;
}

void WhipNew(Whip *this, IBeverage *beverage)
{
    strcpy(this->description, "Whip");
    this->price = 0.10;
    this->getDescription = WhipGetDescription;
    this->cost = WhipCost;
    this->beverage = beverage;
}
char *WhipGetDescription(Whip *this)
{
    strcpy(this->description_all, "");
    strcat(this->description_all, this->beverage->getDescription(this->beverage));
    strcat(this->description_all, ", ");
    strcat(this->description_all, this->description);
    return this->description_all;
}
float WhipCost(Whip *this)
{
    return this->beverage->cost(this->beverage) + this->price;
}