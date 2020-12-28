from StarbuzzCoffee.beverage import DarkRoast, HouseBlend, Expresso
from StarbuzzCoffee.condiment import Soy, Mocha, Whip


def print_info(beverage):
    print(beverage.getDescription()+" $"+str(beverage.cost()))


beverage = Expresso()
print_info(beverage)

beverage2 = DarkRoast()
beverage2 = Mocha(beverage2)
beverage2 = Mocha(beverage2)
beverage2 = Whip(beverage2)
print_info(beverage2)

beverage3 = HouseBlend()
beverage3 = Soy(beverage3)
beverage3 = Mocha(beverage3)
beverage3 = Whip(beverage3)
print_info(beverage3)
