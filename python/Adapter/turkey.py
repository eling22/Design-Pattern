from abc import ABC, abstractmethod
from duck import Duck


class Turkey(ABC):
    @abstractmethod
    def gobble(self):
        pass

    @abstractmethod
    def fly(self):
        pass


class WildTurkey(Turkey):
    def __init__(self):
        pass

    def gobble(self):
        print("Gobble gobble")

    def fly(self):
        print("I'm flying a short distsnce")


class TurkeyAdapter(Duck):
    def __init__(self, turkey: Turkey):
        self.turkey: Turkey = turkey

    def quack(self):
        self.turkey.gobble()

    def fly(self):
        # the distance a turkey fly 5 times reaches the distance a duck fly
        for i in range(5):
            self.turkey.fly()
