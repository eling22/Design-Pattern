from abc import ABC, abstractmethod

# from gumball_machine import 'GumballMachine'
from random import randint


class State(ABC):
    def __init__(self, gumball_machine: "GumballMachine") -> None:
        self.gumball_machine: "GumballMachine" = gumball_machine

    def not_support(self):
        print("this function is not support")

    def insert_quarter(self):
        self.not_support()

    def eject_quarter(self):
        self.not_support()

    def turn_crank(self):
        self.not_support()

    def dispense(self):
        self.not_support()

    def fill_ball(self, num: int):
        self.not_support()


class NoQuarterState(State):
    def __init__(self, gumball_machine: "GumballMachine") -> None:
        super().__init__(gumball_machine)

    def insert_quarter(self):
        print("insert a quarter")
        self.gumball_machine.set_state(self.gumball_machine.has_quarter_state)


class HasQuarterState(State):
    def __init__(self, gumball_machine: "GumballMachine") -> None:
        super().__init__(gumball_machine)

    def eject_quarter(self):
        print("eject the quarter")
        self.gumball_machine.set_state(self.gumball_machine.no_quarter_state)

    def turn_crank(self):
        print("turn the crank")
        r = randint(1, 10)
        print(f"get the ramdom {r}")
        if r == 1:
            self.gumball_machine.set_state(self.gumball_machine.winner_state)
        else:
            self.gumball_machine.set_state(self.gumball_machine.sold_state)


class SoldState(State):
    def __init__(self, gumball_machine: "GumballMachine") -> None:
        super().__init__(gumball_machine)

    def dispense(self):
        print("dispense a ball")
        self.gumball_machine.ball_count -= 1
        if self.gumball_machine.ball_count <= 0:
            print("sold out")
            self.gumball_machine.set_state(self.gumball_machine.sold_out_state)
        else:
            self.gumball_machine.set_state(self.gumball_machine.no_quarter_state)


class SoldOutState(State):
    def __init__(self, gumball_machine: "GumballMachine") -> None:
        super().__init__(gumball_machine)

    def fill_ball(self, num: int):
        print(f"fill {num} ball(s)")
        self.gumball_machine.ball_count += num
        self.gumball_machine.set_state(self.gumball_machine.no_quarter_state)


class WinnerState(State):
    def __init__(self, gumball_machine: "GumballMachine") -> None:
        super().__init__(gumball_machine)

    def dispense(self):
        print("congratulation, you win the game")
        print("dispense a ball")
        self.gumball_machine.ball_count -= 1
        if self.gumball_machine.ball_count <= 0:
            print("sold out")
            self.gumball_machine.set_state(self.gumball_machine.sold_out_state)
        else:
            print("dispense a ball")
            self.gumball_machine.ball_count -= 1
            if self.gumball_machine.ball_count <= 0:
                print("sold out")
                self.gumball_machine.set_state(self.gumball_machine.sold_out_state)
            else:
                self.gumball_machine.set_state(self.gumball_machine.no_quarter_state)
