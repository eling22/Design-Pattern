from abc import ABC, abstractmethod


class CondimentDecorator(ABC):
    @abstractmethod
    def getDescription(self) -> str:
        pass

    @abstractmethod
    def cost(self) -> float:
        pass


class Mocha(CondimentDecorator):
    def __init__(self, beverage):
        self.beverage = beverage
        self.description = "Mocha"
        self.price = 0.20

    def getDescription(self) -> str:
        return self.beverage.getDescription()+", " + self.description

    def cost(self) -> float:
        return self.beverage.cost() + self.price


class Soy(CondimentDecorator):
    def __init__(self, beverage):
        self.beverage = beverage
        self.description = "Soy"
        self.price = 0.15

    def getDescription(self) -> str:
        return self.beverage.getDescription()+", " + self.description

    def cost(self) -> float:
        return self.beverage.cost() + self.price


class Whip(CondimentDecorator):
    def __init__(self, beverage):
        self.beverage = beverage
        self.description = "Whip"
        self.price = 0.10

    def getDescription(self) -> str:
        return self.beverage.getDescription()+", " + self.description

    def cost(self) -> float:
        return self.beverage.cost() + self.price
