from abc import ABC, abstractmethod


class Beverage(ABC):
    @abstractmethod
    def getDescription(self) -> str:
        pass

    @abstractmethod
    def cost(self) -> float:
        pass


class Expresso(Beverage):
    def __init__(self):
        self.description = "Expresso"
        self.price = 1.99

    def getDescription(self) -> str:
        return self.description

    def cost(self) -> float:
        return self.price


class HouseBlend(Beverage):
    def __init__(self):
        self.description = "House Blend Coffee"
        self.price = 0.89

    def getDescription(self) -> str:
        return self.description

    def cost(self) -> float:
        return self.price


class DarkRoast(Beverage):
    def __init__(self):
        self.description = "Dark Roast Coffee"
        self.price = 0.99

    def getDescription(self) -> str:
        return self.description

    def cost(self) -> float:
        return self.price
