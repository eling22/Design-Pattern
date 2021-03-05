#include "movie_element.h"

void AmplifierNew(Amplifier *self)
{
    strcpy(self->name, "Top-O-Line Amplifier");
    self->Off = AmplifierOff;
    self->On = AmplifierOn;
}
void AmplifierOff(Amplifier *self)
{
    printf("%s off\n", self->name);
}
void AmplifierOn(Amplifier *self)
{
    printf("%s on\n", self->name);
}

void DvdPlayerNew(DvdPlayer *self)
{
    strcpy(self->name, "Top-O-Line Dvd Player");
    self->Off = DvdPlayerOff;
    self->On = DvdPlayerOn;
    self->Play = DvdPlayerPlay;
    self->Stop = DvdPlayerStop;
}
void DvdPlayerOff(DvdPlayer *self)
{
    printf("%s off\n", self->name);
}
void DvdPlayerOn(DvdPlayer *self)
{
    printf("%s on\n", self->name);
}
void DvdPlayerPlay(DvdPlayer *self, const char *movie)
{
    strcpy(self->movie, movie);
    printf("%s playing \"%s\"\n", self->name, self->movie);
}
void DvdPlayerStop(DvdPlayer *self)
{
    printf("%s stopped \"%s\"\n", self->name, self->movie);
}

void ProjectorNew(Projector *self)
{
    strcpy(self->name, "Top-O-Line Projector");
    self->Off = ProjectorOff;
    self->On = ProjectorOn;
}
void ProjectorOff(Projector *self)
{
    printf("%s off\n", self->name);
}
void ProjectorOn(Projector *self)
{
    printf("%s on\n", self->name);
}

void TheaterLightsNew(TheaterLights *self)
{
    strcpy(self->name, "Theater Ceiling Lights");
    self->Dim = TheaterLightsDim;
    self->On = TheaterLightsOn;
}
void TheaterLightsDim(TheaterLights *self, int num)
{
    printf("%s dimming to %d%%\n", self->name, num);
}
void TheaterLightsOn(TheaterLights *self)
{
    printf("%s on\n", self->name);
}

void ScreenNew(Screen *self)
{
    strcpy(self->name, "Theater Screen");
    self->Up = ScreenUp;
    self->Down = ScreenDown;
}
void ScreenUp(Screen *self)
{
    printf("%s going up\n", self->name);
}
void ScreenDown(Screen *self)
{
    printf("%s going down\n", self->name);
}

void PopcornPopperNew(PopcornPopper *self)
{
    strcpy(self->name, "Popcorn Popper");
    self->On = PopcornPopperOn;
    self->Off = PopcornPopperOff;
    self->Pop = PopcornPopperPop;
}
void PopcornPopperOff(PopcornPopper *self)
{
    printf("%s off\n", self->name);
}
void PopcornPopperOn(PopcornPopper *self)
{
    printf("%s on\n", self->name);
}
void PopcornPopperPop(PopcornPopper *self)
{
    printf("%s poping popcorn!\n", self->name);
}