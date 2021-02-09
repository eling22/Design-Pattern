
from typing import List
from package.command import Command, NoCommand
import copy


class RemoteControl:
    def __init__(self) -> None:
        self.solt_num: int = 7
        self.on_commands: List[Command]
        self.off_commands: List[Command]
        self.undo_command_stack: List[Command] = []

        self.on_commands = [NoCommand() for i in range(self.solt_num)]
        self.off_commands = [NoCommand() for i in range(self.solt_num)]

    def set_command(self, solt: int, on_command: Command, off_command: Command) -> None:
        self.on_commands[solt] = on_command
        self.off_commands[solt] = off_command

    def on_button_was_pushed(self, solt: int) -> None:
        self.on_commands[solt].execute()
        self.undo_command_stack.append(copy.copy(self.on_commands[solt]))

    def off_button_was_pushed(self, solt: int) -> None:
        self.off_commands[solt].execute()
        self.undo_command_stack.append(copy.copy(self.off_commands[solt]))

    def undo_button_was_pushed(self) -> None:
        if len(self.undo_command_stack) == 0:
            print("there is nothing undo\n")
            return
        undo_command = self.undo_command_stack.pop()
        undo_command.undo()

    def __str__(self) -> str:
        string = "\n----- Remote Control -----\n"
        for i in range(self.solt_num):
            string += f"[solt {i}] {self.on_commands[i].__class__.__name__}\t{self.off_commands[i].__class__.__name__}\n"
        return string
