#include <stdio.h>
#include <string.h>
#include "interface/Observer.h"
#include "interface/WeatherData.h"
#include "interface/Subject.h"
#include "interface/DisplayElement.h"
#include "WeatherStation.h"

typedef struct _CurrentConditionsDisplay
{
    IObserver(struct _CurrentConditionsDisplay);
    IDisplayElement(struct _CurrentConditionsDisplay);
    WeatherData data;
} CurrentConditionsDisplay;

void CurrentConditionsDisplayNew(CurrentConditionsDisplay *this, WeatherStation *subject);
void CCDUpdate(CurrentConditionsDisplay *this, void *data);
bool CCDIsSameObserver(CurrentConditionsDisplay *this, IObserver *observer);
void CCDDisplay(CurrentConditionsDisplay *this);

typedef struct _StatisticsDisplay
{
    IObserver(struct _StatisticsDisplay);
    IDisplayElement(struct _StatisticsDisplay);
    WeatherData data;
    int data_count;
} StatisticsDisplay;

void StatisticsDisplayNew(StatisticsDisplay *this, WeatherStation *subject);
void SDUpdate(StatisticsDisplay *this, void *data);
bool SDIsSameObserver(StatisticsDisplay *this, IObserver *observer);
void SDDisplay(StatisticsDisplay *this);