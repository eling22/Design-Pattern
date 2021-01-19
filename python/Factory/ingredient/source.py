from abc import ABC, abstractmethod


class Sauce(ABC):
    @abstractmethod
    def __init__(self):
        self.name: str = ""


class MarinaraSauce(Sauce):
    def __init__(self):
        self.name: str = "Marinara Sauce"


class PlumTomatoSauce(Sauce):
    def __init__(self):
        self.name: str = "Plum Tomato Sauce"
