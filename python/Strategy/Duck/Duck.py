from abc import ABC, abstractmethod
from .FlyBehavior import FlyBehavior, FlyNoWay, FlyWithWings
from .QuackBehavior import QuackBehavior, Quack, MuteQuack, SQuack


class Duck(ABC):
    def __init__(self):
        self.flyBehavior = None
        self.quackBehavior = None

    @abstractmethod
    def display(self):
        pass

    def performFly(self):
        self.flyBehavior.fly()

    def performQuack(self):
        self.quackBehavior.quack()

    def swim(self):
        print("All ducks float, even decoys!")

    def setFlyBehavior(self, flyBehavior):
        self.flyBehavior = flyBehavior

    def setQuackBehavior(self, quackBehavior):
        self.quackBehavior = quackBehavior


class MallardDuck(Duck):
    def __init__(self):
        self.flyBehavior = FlyWithWings()
        self.quackBehavior = Quack()

    def display(self):
        print("I'm a real Mallard duck")


class ModelDuck(Duck):
    def __init__(self):
        self.flyBehavior = FlyNoWay()
        self.quackBehavior = Quack()

    def display(self):
        print("I'm a model duck")
