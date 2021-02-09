from .command import Command


class Light:
    def __init__(self, place: str = "") -> None:
        self.place = place

    def get_object_str(self) -> str:
        object_str: str = ""
        if self.place == "":
            object_str = "Light"
        else:
            object_str = self.place + " light"
        return object_str

    def on(self):
        object_str: str = self.get_object_str()
        object_str += "is on"
        print(object_str)

    def off(self):
        object_str: str = self.get_object_str()
        object_str += "is off"
        print(object_str)

    def print(self):
        print("light")


class LightOnCommand(Command):
    def __init__(self, light: Light) -> None:
        self.light = light

    def execute(self):
        self.light.on()

    def undo(self):
        self.light.off()


class LightOffCommand(Command):
    def __init__(self, light: Light) -> None:
        self.light = light

    def execute(self):
        self.light.off()

    def undo(self):
        self.light.on()
