from collections import Iterable, deque
from typing import Deque, List
from dataclasses import dataclass
from abc import ABC, abstractmethod


@dataclass
class MenuItem:
    name: str
    description: str
    vegetarian: bool
    price: float


class Menu(ABC):
    @abstractmethod
    def createIterator(self) -> Iterable[MenuItem]:
        pass


class PancakeHouseMenu(Menu):
    def __init__(self) -> None:
        self.menu_items: Deque[MenuItem] = deque()
        self.add_item(
            "K&P Pancake Breakfast", "Pancakes with scrambled eggs,toast", True, 2.99
        )
        self.add_item(
            "Regular Pancake Breakfast", "Pancakes with fried eggs,sausage", False, 2.99
        )
        self.add_item(
            "Blueberry Pancake", "Pancakes made with fresh blueberries", True, 3.49
        )
        self.add_item(
            "Waffles",
            "Waffles, with your choice of blueberries or strawberries",
            True,
            3.59,
        )

    def createIterator(self) -> Iterable[MenuItem]:
        return self.menu_items

    def add_item(self, name: str, description: str, vegetarian: bool, price: float):
        menu_item = MenuItem(name, description, vegetarian, price)
        self.menu_items.append(menu_item)


class DinerMenu(Menu):
    def __init__(self) -> None:
        self.menu_items: List[MenuItem] = list()
        self.add_item(
            "Vegetarian BLT",
            "(Fakin')Bacon with lettuce & tomato on whole wheat",
            True,
            2.99,
        )
        self.add_item("BLT", "Bacon with lettuce & tomato on whole wheat", False, 2.99)
        self.add_item(
            "Soup of the day",
            "Soup of the day, with a side of potato salad",
            False,
            3.29,
        )
        self.add_item(
            "Hotdog",
            "A hot dog, with saurkraut, relish, onions, topped with cheese",
            False,
            3.05,
        )

    def createIterator(self) -> Iterable[MenuItem]:
        return self.menu_items

    def add_item(self, name: str, description: str, vegetarian: bool, price: float):
        menu_item = MenuItem(name, description, vegetarian, price)
        self.menu_items.append(menu_item)
