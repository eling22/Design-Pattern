#include "facade.h"
int main()
{
    Amplifier amp;
    AmplifierNew(&amp);
    DvdPlayer dvd;
    DvdPlayerNew(&dvd);
    Projector projector;
    ProjectorNew(&projector);
    Screen screen;
    ScreenNew(&screen);
    TheaterLights lights;
    TheaterLightsNew(&lights);
    PopcornPopper popper;
    PopcornPopperNew(&popper);

    HomeTheterFacade home_theater;
    HTFacadeNew(&home_theater, &amp, &dvd, &projector, &screen, &lights, &popper);
    home_theater.WatchMovie(&home_theater, "Raiders of the Lost Ark");
    printf("\n");
    home_theater.EndMovie(&home_theater);

    return 0;
}