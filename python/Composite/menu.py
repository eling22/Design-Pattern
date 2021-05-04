from abc import ABC, abstractmethod
from typing import Deque, List
from collections import Iterable, deque


class MenuComponent(ABC):
    def print(self):
        pass


class MenuItem(MenuComponent):
    def __init__(
        self, name: str, description: str, vegetarian: bool, price: float
    ) -> None:
        self.name: str = name
        self.description: str = description
        self.vegetarian: bool = vegetarian
        self.price: float = price

    def print(self):
        print(f"{self.name}, {self.price} -- {self.description}")


class Menu(MenuComponent):
    def __init__(self, name, description) -> None:
        self.menu_components: List[MenuComponent] = []
        self.name: str = name
        self.description: str = description

    def add(self, menu_com: MenuComponent):
        self.menu_components.append(menu_com)

    def remove(self, menu_com: MenuComponent):
        self.menu_components.remove(menu_com)

    def print(self):
        print()
        print(f"{self.name}, {self.description}")
        print("--------------------------------")
        for menu_com in self.menu_components:
            menu_com.print()


class PancakeHouseMenu(Menu):
    def __init__(self) -> None:
        super().__init__("PANCAKE HOUSE MENU", "Breakfast")
        self.add(
            MenuItem(
                "K&P Pancake Breakfast",
                "Pancakes with scrambled eggs, and toast",
                True,
                2.99,
            )
        )
        self.add(
            MenuItem(
                "Regular Pancake Breakfast",
                "Pancakes with fried eggs,sausage",
                False,
                2.99,
            )
        )
        self.add(
            MenuItem(
                "Blueberry Pancake", "Pancakes made with fresh blueberries", True, 3.49
            )
        )
        self.add(
            MenuItem(
                "Waffles",
                "Waffles, with your choice of blueberries or strawberries",
                True,
                3.59,
            )
        )


class DinerMenu(Menu):
    def __init__(self) -> None:
        super().__init__("DINER MENU", "Lunch")
        self.add(
            MenuItem(
                "Vegetarian BLT",
                "(Fakin')Bacon with lettuce & tomato on whole wheat",
                True,
                2.99,
            )
        )
        self.add(
            MenuItem("BLT", "Bacon with lettuce & tomato on whole wheat", False, 2.99)
        )
        self.add(
            MenuItem(
                "Soup of the day",
                "Soup of the day, with a side of potato salad",
                False,
                3.29,
            )
        )
        self.add(
            MenuItem(
                "Hotdog",
                "A hot dog, with saurkraut, relish, onions, topped with cheese",
                False,
                3.05,
            )
        )


class CafeMenu(Menu):
    def __init__(self) -> None:
        super().__init__("CAFE MENU", "Dinner")
        self.add(
            MenuItem(
                "Veggie Burger and Air Fries",
                "Veggie burger on a whole wheat bun, lettuce, tomato, and fries",
                True,
                3.99,
            )
        )
        self.add(
            MenuItem(
                "Soup of the day",
                "A cup of the soup of the day, with a side salad",
                False,
                3.69,
            )
        )
        self.add(
            MenuItem(
                "Burrito",
                "A large burrito, with whole pinto beans, salsa, guacamole",
                True,
                4.29,
            )
        )


class DessertMenu(Menu):
    def __init__(self) -> None:
        super().__init__("DESSERT MENU", "Dessert of course")
        self.add(
            MenuItem(
                "Apple Pie",
                "Apple pie with a flakey crust, topped with vanilla icecream",
                True,
                1.59,
            )
        )
        self.add(
            MenuItem(
                "Cheesecake",
                "Creamy New York cheesecake, with a chocolate graham crust",
                True,
                1.99,
            )
        )
        self.add(
            MenuItem("Sorbet", "A scoop of raspberry and a scoop of lime", True, 1.89)
        )
