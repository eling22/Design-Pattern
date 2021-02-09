from .command import Command
from enum import Enum, auto


class Speed(Enum):
    HIGH = auto()
    MEDIUM = auto()
    LOW = auto()
    OFF = auto()


class CeilingFan:
    def __init__(self, place: str = "") -> None:
        self.place = place
        self.speed: Speed = Speed.OFF

    def get_object_str(self) -> str:
        object_str: str = ""
        if self.place == "":
            object_str = "Ceiling fan"
        else:
            object_str = self.place + " ceiling fan"
        return object_str

    def get_speed(self) -> Speed:
        return self.speed

    def high(self):
        self.speed = Speed.HIGH
        self.print()

    def medium(self):
        self.speed = Speed.MEDIUM
        self.print()

    def low(self):
        self.speed = Speed.LOW
        self.print()

    def off(self):
        self.speed = Speed.OFF
        self.print()

    def set_speed(self, speed: Speed):
        self.speed = speed
        self.print()

    def print(self):
        object_str: str = self.get_object_str()
        if self.speed == Speed.HIGH:
            object_str += "is on high"
        elif self.speed == Speed.MEDIUM:
            object_str += "is on medium"
        elif self.speed == Speed.LOW:
            object_str += "is on low"
        elif self.speed == Speed.OFF:
            object_str += "is off"
        print(object_str)


class CeilingFanHighCommand(Command):
    def __init__(self, ceiling_fan: CeilingFan) -> None:
        self.ceiling_fan = ceiling_fan

    def execute(self):
        self.pre_speed = self.ceiling_fan.get_speed()
        self.ceiling_fan.high()

    def undo(self):
        self.ceiling_fan.set_speed(self.pre_speed)


class CeilingFanMediumCommand(Command):
    def __init__(self, ceiling_fan: CeilingFan) -> None:
        self.ceiling_fan = ceiling_fan

    def execute(self):
        self.pre_speed = self.ceiling_fan.get_speed()
        self.ceiling_fan.medium()

    def undo(self):
        self.ceiling_fan.set_speed(self.pre_speed)


class CeilingFanOffCommand(Command):
    def __init__(self, ceiling_fan: CeilingFan) -> None:
        self.ceiling_fan = ceiling_fan

    def execute(self):
        self.pre_speed = self.ceiling_fan.get_speed()
        self.ceiling_fan.off()

    def undo(self):
        self.ceiling_fan.set_speed(self.pre_speed)
