#include "WeatherStation.h"

void WeatherStationNew(WeatherStation *this)
{
    this->registerObserver = WSRegisterObserver;
    this->removeObserver = WSRemoveObserver;
    this->notifyObserver = WSNotifyObserver;
    this->observer_count = 0;
    this->measurementsChanged = WSMeasurementsChanged;
    this->setMeasurements = WSSetMeasurements;
}
void WSRegisterObserver(WeatherStation *this, IObserver *observer)
{
    if (this->observer_count >= MAX_OBSERVER_NUM)
    {
        printf("the observer count is full\n");
        return;
    }
    this->observer_list[this->observer_count] = observer;
    this->observer_count++;
}
void WSRemoveObserver(WeatherStation *this, IObserver *observer)
{
    for (int i = 0; i < this->observer_count; i++)
    {
        if (observer->isSameObserver(observer, this->observer_list[i]))
        {
            this->observer_list[i] = this->observer_list[this->observer_count - 1];
            this->observer_count--;
            return;
        }
    }
    printf("Can not find this observer\n");
}
void WSNotifyObserver(WeatherStation *this)
{
    for (int i = 0; i < this->observer_count; i++)
    {
        this->observer_list[i]->update(this->observer_list[i], &this->data);
    }
}
void WSMeasurementsChanged(WeatherStation *this)
{
    this->notifyObserver(this);
}
void WSSetMeasurements(WeatherStation *this, WeatherData data)
{
    printf("******************************** REFRESH DATA *********************************************\n");
    this->data = data;
    this->measurementsChanged(this);
}