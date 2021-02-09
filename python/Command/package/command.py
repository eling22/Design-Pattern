from abc import ABC, abstractmethod


class Command(ABC):
    @abstractmethod
    def execute(self):
        pass

    @abstractmethod
    def undo(self):
        pass


class NoCommand(Command):
    def __init__(self) -> None:
        pass

    def execute(self):
        pass

    def undo(self):
        pass
