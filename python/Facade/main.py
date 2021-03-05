from movie_element import (
    Amplifier,
    DvdPlayer,
    PopcornPopper,
    Projector,
    Screen,
    TheaterLights,
)
from facade import HomeTheterFacade


def main():

    home_theater = HomeTheterFacade(
        amp=Amplifier(),
        dvd=DvdPlayer(),
        projector=Projector(),
        screen=Screen(),
        lights=TheaterLights(),
        popper=PopcornPopper(),
    )
    home_theater.watch_movie("Raiders of the Lost Ark")
    print()
    home_theater.end_movie()


if __name__ == "__main__":
    main()
