#ifndef __WEATHERDATA_H__
#define __WEATHERDATA_H__

typedef struct _WeatherData
{
    float temperature;
    float humidity;
    float pressure;
} WeatherData;

void AddWeatherData(WeatherData *this, WeatherData *other);

#endif /* __WEATHERDATA_H__ */