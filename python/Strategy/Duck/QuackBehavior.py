from abc import ABC, abstractmethod


class QuackBehavior(ABC):
    @abstractmethod
    def quack(self):
        pass


class Quack(QuackBehavior):
    def quack(self):
        print("Quack")


class MuteQuack(QuackBehavior):
    def quack(self):
        print("<< Slience >>")


class SQuack(QuackBehavior):
    def quack(self):
        print("Squack")
