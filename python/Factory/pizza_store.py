from abc import ABC, abstractmethod


class PizzaStore(ABC):
    @abstractmethod
    def order_pizza(self):
        pass


class NYPizzaStore(PizzaStore):
    def order_pizza(self):
        pass


class ChicagoPizzaStore(PizzaStore):
    def order_pizza(self):
        pass
