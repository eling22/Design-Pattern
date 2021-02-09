from typing import List
from .command import Command


class MacroCommand(Command):
    def __init__(self, commands: List[Command]) -> None:
        self.commands = commands

    def execute(self):
        print("--- Push Macro ---")
        for command in self.commands:
            command.execute()
        print("--- Push Macro End ---")

    def undo(self):
        print("--- Macro Undo ---")
        for command in reversed(self.commands):
            command.undo()
        print("--- Macro Undo End ---")
