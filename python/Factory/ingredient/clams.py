from abc import ABC, abstractmethod


class Clams(ABC):
    @abstractmethod
    def __init__(self):
        self.name: str = ""


class FreshClams(Clams):
    def __init__(self):
        self.name: str = "Fresh Clams"


class FrozenClam(Clams):
    def __init__(self):
        self.name: str = "Frozen Clam"
