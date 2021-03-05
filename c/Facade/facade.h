#ifndef __FACADE_H__
#define __FACADE_H__

#include "movie_element.h"

typedef struct _HomeTheterFacade
{
    Amplifier *amp;
    DvdPlayer *dvd;
    Projector *projector;
    Screen *screen;
    TheaterLights *lights;
    PopcornPopper *popper;
    void (*WatchMovie)(struct _HomeTheterFacade *self, const char *movie);
    void (*EndMovie)(struct _HomeTheterFacade *self);
} HomeTheterFacade;

void HTFacadeNew(HomeTheterFacade *self,
                 Amplifier *amp,
                 DvdPlayer *dvd,
                 Projector *projector,
                 Screen *screen,
                 TheaterLights *lights,
                 PopcornPopper *popper);
void HTFacadeWatchMovie(HomeTheterFacade *self, const char *movie);
void HTFacadeEndMovie(HomeTheterFacade *self);

#endif /*__FACADE_H__*/
