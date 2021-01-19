from abc import ABC, abstractmethod
from typing import List, Union
from ingredient.cheese import Cheese
from ingredient.clams import Clams
from ingredient.dough import Dough
from ingredient.source import Sauce

from pizza_ingredient_factory import PizzaIngredientFactory


class Pizza(ABC):
    @abstractmethod
    def __init__(self):
        self.name: str
        self.dough: Dough
        self.sauce: Sauce
        self.toppings: List[Union[Cheese, Clams]]
        pass

    def prepare(self):
        print("Prepare "+self.name)
        print(f"Tossing {self.dough.name} ...")
        print(f"Adding {self.sauce.name} ...")
        print("Adding toppings: ")
        for toppings in self.toppings:
            print("\t"+toppings.name)

    def bake(self):
        print("Bake for 25 minutes at 350")

    def cut(self):
        print("Cutting the pizza into diagonal slices")

    def box(self):
        print("Place pizza in official PizzaStore box")


class CheesePizza(Pizza):
    def __init__(self, name: str, ingredient_factory: PizzaIngredientFactory):
        self.name: str = name
        self.dough: Dough = ingredient_factory.createDough()
        self.sauce: Sauce = ingredient_factory.createSauce()
        self.toppings: List[Union[Cheese, Clams]] = [
            ingredient_factory.createCheese()]


class ClamPizza(Pizza):
    def __init__(self, name: str, ingredient_factory: PizzaIngredientFactory):
        self.name: str = name
        self.dough: Dough = ingredient_factory.createDough()
        self.sauce: Sauce = ingredient_factory.createSauce()
        self.toppings: List[Union[Cheese, Clams]] = [
            ingredient_factory.createClams()]
