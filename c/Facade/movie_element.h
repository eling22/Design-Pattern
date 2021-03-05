#ifndef __MOVIE_ELEMENT_H__
#define __MOVIE_ELEMENT_H__

#include "string.h"
#include "stdio.h"

typedef struct _Amplifier
{
    char name[30];
    void (*Off)(struct _Amplifier *);
    void (*On)(struct _Amplifier *);
} Amplifier;

void AmplifierNew(Amplifier *self);
void AmplifierOff(Amplifier *self);
void AmplifierOn(Amplifier *self);

typedef struct _DvdPlayer
{
    char name[30];
    char movie[30];
    void (*Off)(struct _DvdPlayer *);
    void (*On)(struct _DvdPlayer *);
    void (*Play)(struct _DvdPlayer *, const char *movie);
    void (*Stop)(struct _DvdPlayer *);
} DvdPlayer;

void DvdPlayerNew(DvdPlayer *self);
void DvdPlayerOff(DvdPlayer *self);
void DvdPlayerOn(DvdPlayer *self);
void DvdPlayerPlay(DvdPlayer *self, const char *movie);
void DvdPlayerStop(DvdPlayer *self);

typedef struct _Projector
{
    char name[30];
    void (*Off)(struct _Projector *);
    void (*On)(struct _Projector *);
} Projector;

void ProjectorNew(Projector *self);
void ProjectorOff(Projector *self);
void ProjectorOn(Projector *self);

typedef struct _TheaterLights
{
    char name[30];
    void (*Dim)(struct _TheaterLights *, int num);
    void (*On)(struct _TheaterLights *);
} TheaterLights;

void TheaterLightsNew(TheaterLights *self);
void TheaterLightsDim(TheaterLights *self, int num);
void TheaterLightsOn(TheaterLights *self);

typedef struct _Screen
{
    char name[30];
    void (*Up)(struct _Screen *);
    void (*Down)(struct _Screen *);
} Screen;

void ScreenNew(Screen *self);
void ScreenUp(Screen *self);
void ScreenDown(Screen *self);

typedef struct _PopcornPopper
{
    char name[30];
    void (*Off)(struct _PopcornPopper *);
    void (*On)(struct _PopcornPopper *);
    void (*Pop)(struct _PopcornPopper *);
} PopcornPopper;

void PopcornPopperNew(PopcornPopper *self);
void PopcornPopperOff(PopcornPopper *self);
void PopcornPopperOn(PopcornPopper *self);
void PopcornPopperPop(PopcornPopper *self);

#endif /*__MOVIE_ELEMENT_H__*/
