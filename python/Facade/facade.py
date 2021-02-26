from movie_element import Amplifier, DvdPlayer, PopcornPopper, Projecter, Screen, TheaterLights


class HomeTheterFacade:
    def __init__(self, amp: Amplifier, dvd: DvdPlayer, projector: Projecter, screen: Screen, lights: TheaterLights, popper: PopcornPopper) -> None:
        self.amp = amp
        self.dvd = dvd
        self.projector = projector
        self.screen = screen
        self.lights = lights
        self.popper = popper

    def watch_movie(self, movie: str):
        print("Get ready to watch a movie...")
        self.popper.on()
        self.popper.pop()
        self.lights.dim(10)
        self.screen.down()
        self.projector.on()
        self.amp.on()
        self.dvd.on()
        self.dvd.play(movie)

    def end_movie(self):
        print("Shutting movie theater down...")
        self.popper.off()
        self.lights.on()
        self.screen.up()
        self.projector.off()
        self.amp.off()
        self.dvd.stop()
        self.dvd.off()
