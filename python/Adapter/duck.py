from abc import ABC, abstractmethod


class Duck(ABC):

    @abstractmethod
    def quack(self):
        pass

    @abstractmethod
    def fly(self):
        pass


class MallardDuck(Duck):
    def __init__(self):
        pass

    def quack(self):
        print("Quack")

    def fly(self):
        print("I'm flying")
