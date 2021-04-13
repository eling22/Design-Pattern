from waitress import Waitress
from menu import PancakeHouseMenu, DinerMenu

pancake_house_menu = PancakeHouseMenu()
diner_menu = DinerMenu()
waitress = Waitress(pancake_house_menu, diner_menu)
waitress.printMenu()