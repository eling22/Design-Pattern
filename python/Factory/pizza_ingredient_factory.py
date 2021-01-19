from abc import ABC, abstractmethod
from ingredient.cheese import Cheese, MozzarellaCheese, ReggianoCheese
from ingredient.clams import Clams, FreshClams, FrozenClam
from ingredient.dough import Dough, ThickCrustDough, ThinCrustDough
from ingredient.source import MarinaraSauce, PlumTomatoSauce, Sauce


class PizzaIngredientFactory(ABC):
    @abstractmethod
    def createDough(self) -> Dough:
        pass

    @abstractmethod
    def createSauce(self) -> Sauce:
        pass

    @abstractmethod
    def createCheese(self) -> Cheese:
        pass

    @abstractmethod
    def createClams(self) -> Clams:
        pass


class NYPizzaIngredientFactory(PizzaIngredientFactory):
    def createDough(self) -> Dough:
        return ThinCrustDough()

    def createSauce(self) -> Sauce:
        return MarinaraSauce()

    def createCheese(self) -> Cheese:
        return ReggianoCheese()

    def createClams(self) -> Clams:
        return FreshClams()


class ChicagoPizzaIngredientFactory(PizzaIngredientFactory):
    def createDough(self) -> Dough:
        return ThickCrustDough()

    def createSauce(self) -> Sauce:
        return PlumTomatoSauce()

    def createCheese(self) -> Cheese:
        return MozzarellaCheese()

    def createClams(self) -> Clams:
        return FrozenClam()
