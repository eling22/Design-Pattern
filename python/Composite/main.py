from menu import Menu, PancakeHouseMenu, DinerMenu, CafeMenu, DessertMenu
from waitress import Waitress

pancake_house_menu = PancakeHouseMenu()
diner_menu = DinerMenu()
cafe_menu = CafeMenu()
dessert_menu = DessertMenu()
all_menu = Menu("ALL MENUS", "All menus combined")
all_menu.add(pancake_house_menu)
all_menu.add(diner_menu)
all_menu.add(cafe_menu)
diner_menu.add(dessert_menu)

waitress = Waitress(all_menu)
waitress.printMenu()