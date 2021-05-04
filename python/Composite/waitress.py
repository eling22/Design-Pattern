from menu import MenuComponent


class Waitress:
    def __init__(self, menu: MenuComponent) -> None:
        self.menu = menu

    def printMenu(self) -> None:
        self.menu.print()
