from abc import ABC, abstractmethod


class Cheese(ABC):
    @abstractmethod
    def __init__(self):
        self.name: str = ""


class ReggianoCheese(Cheese):
    def __init__(self):
        self.name: str = "Reggiano Cheese"


class MozzarellaCheese(Cheese):
    def __init__(self):
        self.name: str = "Mozzarella Cheese"
