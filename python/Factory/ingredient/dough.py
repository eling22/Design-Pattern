from abc import ABC, abstractmethod


class Dough(ABC):
    @abstractmethod
    def __init__(self):
        self.name: str = ""


class ThickCrustDough(Dough):
    def __init__(self):
        self.name: str = "Thick Crust Dough"


class ThinCrustDough(Dough):
    def __init__(self):
        self.name: str = "Thin Crust Dough"
