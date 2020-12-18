#include "Display.h"

void CurrentConditionsDisplayNew(CurrentConditionsDisplay *this, WeatherStation *subject)
{
    this->update = CCDUpdate;
    this->isSameObserver = CCDIsSameObserver;
    this->display = CCDDisplay;

    subject->registerObserver(subject, (IObserver *)this);
}
void CCDUpdate(CurrentConditionsDisplay *this, void *data)
{
    this->data = *(WeatherData *)data;
    this->display(this);
}
bool CCDIsSameObserver(CurrentConditionsDisplay *this, IObserver *observer)
{
    return memcmp(this, observer, sizeof(CurrentConditionsDisplay)) == 0;
}
void CCDDisplay(CurrentConditionsDisplay *this)
{
    printf("Current Condition :\n");
    printf("temperature : %0.2f\n", this->data.temperature);
    printf("humidity : %0.2f\n", this->data.humidity);
    printf("pressure : %0.2f\n", this->data.pressure);
}
void StatisticsDisplayNew(StatisticsDisplay *this, WeatherStation *subject)
{
    this->data_count = 0;
    this->update = SDUpdate;
    this->isSameObserver = SDIsSameObserver;
    this->display = SDDisplay;
    this->data.temperature = 0.0;
    this->data.humidity = 0.0;
    this->data.pressure = 0.0;

    subject->registerObserver(subject, (IObserver *)this);
}
void SDUpdate(StatisticsDisplay *this, void *data)
{
    AddWeatherData(&this->data, (WeatherData *)data);
    this->data_count++;
    this->display(this);
}
bool SDIsSameObserver(StatisticsDisplay *this, IObserver *observer)
{
    return memcmp(this, observer, sizeof(StatisticsDisplay)) == 0;
}
void SDDisplay(StatisticsDisplay *this)
{
    printf("Statistics Data :\n");
    printf("avg temperature : %0.2f\n", this->data.temperature / this->data_count);
    printf("avg humidity : %0.2f\n", this->data.humidity / this->data_count);
    printf("avg pressure : %0.2f\n", this->data.pressure / this->data_count);
}