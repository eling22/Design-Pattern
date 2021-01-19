from abc import ABC, abstractmethod
from pizza import CheesePizza, ClamPizza, Pizza
from pizza_ingredient_factory import ChicagoPizzaIngredientFactory, NYPizzaIngredientFactory, PizzaIngredientFactory


class PizzaStore(ABC):
    @abstractmethod
    def __init__(self) -> None:
        self.ingredient_factory: PizzaIngredientFactory

    def order_pizza(self, type: str) -> Pizza:
        pizza: Pizza = self.create_pizza(type)
        pizza.prepare()
        pizza.bake()
        pizza.cut()
        pizza.box()
        return pizza

    @abstractmethod
    def create_pizza(self, type: str) -> Pizza:
        pass


class NYPizzaStore(PizzaStore):
    def __init__(self) -> None:
        self.ingredient_factory: PizzaIngredientFactory = NYPizzaIngredientFactory()

    def create_pizza(self, type: str) -> Pizza:
        if type == "cheese":
            name = "NY Style Sauce and Cheese Pizza"
            return CheesePizza(name, self.ingredient_factory)
        elif type == "clam":
            name = "NY Style Clam Pizza"
            return ClamPizza(name, self.ingredient_factory)
        else:
            raise Exception("this type do not exist")


class ChicagoPizzaStore(PizzaStore):
    def __init__(self) -> None:
        self.ingredient_factory: PizzaIngredientFactory = ChicagoPizzaIngredientFactory()

    def create_pizza(self, type: str) -> Pizza:
        if type == "cheese":
            name = "Chicago Style Deep Dish Cheese Pizza"
            return CheesePizza(name, self.ingredient_factory)
        else:
            raise Exception("this type do not exist")
