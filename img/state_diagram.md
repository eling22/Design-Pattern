@startuml

class       Machine {
    insert_Quarter()
    eject_Quarter()
    turn_Crank()
    dispense()
}

interface       State {
    insert_Quarter()
    eject_Quarter()
    turn_Crank()
    dispense()
}

class NoQuarterState
class HasQuarterState
class SoldState
class SoldOutState
class WinnerState

State <|-- NoQuarterState
State <|-- HasQuarterState
State <|-- SoldState
State <|-- SoldOutState
State <|-- WinnerState

Machine --> State

@enduml