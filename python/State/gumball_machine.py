from state import (
    HasQuarterState,
    NoQuarterState,
    SoldOutState,
    SoldState,
    State,
    WinnerState,
)


class GumballMachine:
    def __init__(self) -> None:
        self.current_state: State
        self.no_quarter_state: NoQuarterState = NoQuarterState(self)
        self.has_quarter_state: HasQuarterState = HasQuarterState(self)
        self.sold_state: SoldState = SoldState(self)
        self.sold_out_state: SoldOutState = SoldOutState(self)
        self.winner_state: WinnerState = WinnerState(self)
        self.current_state = self.no_quarter_state
        self.ball_count = 10

    def set_state(self, state: State):
        self.current_state = state

    def insert_quarter(self):
        self.current_state.insert_quarter()

    def eject_quarter(self):
        self.current_state.eject_quarter()

    def turn_crank(self):
        self.current_state.turn_crank()

    def dispense(self):
        self.current_state.dispense()

    def fill_ball(self, num: int):
        self.current_state.fill_ball(num)
