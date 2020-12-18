#include "WeatherData.h"

void AddWeatherData(WeatherData *this, WeatherData *other)
{
    this->temperature += other->temperature;
    this->humidity += other->humidity;
    this->pressure += other->pressure;
}
