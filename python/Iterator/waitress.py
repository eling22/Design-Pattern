from menu import PancakeHouseMenu


class Waitress:
    def __init__(self, pancake_house_menu: PancakeHouseMenu, diner_menu) -> None:
        self.pancake_house_menu = pancake_house_menu
        self.diner_menu = diner_menu

    def printMenu(self) -> None:
        print("Menu")
        print("-----")
        print("BREAKFAST")
        self.__printMenu(self.pancake_house_menu)
        print("")
        print("LUNCH")
        self.__printMenu(self.diner_menu)

    def __printMenu(self, menu) -> None:
        for m in menu.createIterator():
            print(f"{m.name}, {m.price} -- {m.description}")
