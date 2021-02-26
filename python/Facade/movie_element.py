class Amplifier:
    def __init__(self) -> None:
        self.name = "Top-O-Line Amplifier"

    def off(self):
        print(self.name, f"off")

    def on(self):
        print(self.name, "on")


class DvdPlayer:
    def __init__(self) -> None:
        self.name = "Top-O-Line Dvd Player"

    def off(self):
        print(self.name, f"off")

    def on(self):
        print(self.name, "on")

    def play(self, movie: str):
        self.movie = movie
        print(self.name, f'playing "{movie}"')

    def stop(self):
        print(self.name, f'stopped "{self.movie}"')


class Projecter:
    def __init__(self) -> None:
        self.name = "Top-O-Line Projector"

    def off(self):
        print(self.name, f"off")

    def on(self):
        print(self.name, "on")


class TheaterLights:
    def __init__(self) -> None:
        self.name = "Thether Ceiling Lights"

    def dim(self, num: int):
        print(self.name, f"dimming to {num}%")

    def on(self):
        print(self.name, "on")


class Screen:
    def __init__(self) -> None:
        self.name = "Thether Screen"

    def up(self):
        print(self.name, "going up")

    def down(self):
        print(self.name, "going down")


class PopcornPopper:
    def __init__(self) -> None:
        self.name = "Popcron Popper"

    def on(self):
        print(self.name, "on")

    def off(self):
        print(self.name, "off")

    def pop(self):
        print(self.name, "poping popcorn!")
