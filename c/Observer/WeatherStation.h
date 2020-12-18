#ifndef __WEATHERSTATION_H__
#define __WEATHERSTATION_H__

#include <stdio.h>
#include "interface/Observer.h"
#include "interface/WeatherData.h"
#include "interface/Subject.h"

#define MAX_OBSERVER_NUM 5
typedef struct _WeatherStation
{
    ISubject(struct _WeatherStation);
    IObserver *observer_list[MAX_OBSERVER_NUM];
    int observer_count;
    WeatherData data;
    void (*measurementsChanged)(struct _WeatherStation *);
    void (*setMeasurements)(struct _WeatherStation *, WeatherData);
} WeatherStation;

void WeatherStationNew(WeatherStation *this);
void WSRegisterObserver(WeatherStation *this, IObserver *observer);
void WSRemoveObserver(WeatherStation *this, IObserver *observer);
void WSNotifyObserver(WeatherStation *this);
void WSMeasurementsChanged(WeatherStation *this);
void WSSetMeasurements(WeatherStation *this, WeatherData data);

#endif /* __WEATHERSTATION_H__ */