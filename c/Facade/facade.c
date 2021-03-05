#include "facade.h"
void HTFacadeNew(HomeTheterFacade *self,
                 Amplifier *amp,
                 DvdPlayer *dvd,
                 Projector *projector,
                 Screen *screen,
                 TheaterLights *lights,
                 PopcornPopper *popper)
{
    self->amp = amp;
    self->dvd = dvd;
    self->projector = projector;
    self->screen = screen;
    self->lights = lights;
    self->popper = popper;
    self->WatchMovie = HTFacadeWatchMovie;
    self->EndMovie = HTFacadeEndMovie;
}
void HTFacadeWatchMovie(HomeTheterFacade *self, const char *movie)
{
    printf("Get ready to watch a movie...\n");
    self->popper->On(self->popper);
    self->popper->Pop(self->popper);
    self->lights->Dim(self->lights, 10);
    self->screen->Down(self->screen);
    self->projector->On(self->projector);
    self->amp->On(self->amp);
    self->dvd->On(self->dvd);
    self->dvd->Play(self->dvd, movie);
}
void HTFacadeEndMovie(HomeTheterFacade *self)
{
    printf("Shutting movie theater down...\n");
    self->popper->Off(self->popper);
    self->lights->On(self->lights);
    self->screen->Up(self->screen);
    self->projector->Off(self->projector);
    self->amp->Off(self->amp);
    self->dvd->Stop(self->dvd);
    self->dvd->Off(self->dvd);
}