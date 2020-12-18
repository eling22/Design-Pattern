#include <stdio.h>
#include "WeatherStation.h"
#include "Display.h"

void main()
{
    WeatherStation weather_station;
    WeatherStationNew(&weather_station);
    CurrentConditionsDisplay current_display;
    CurrentConditionsDisplayNew(&current_display, &weather_station);
    StatisticsDisplay statistics_display;
    StatisticsDisplayNew(&statistics_display, &weather_station);

    weather_station.setMeasurements(&weather_station, (WeatherData){80, 65, 30.4});
    weather_station.setMeasurements(&weather_station, (WeatherData){82, 70, 29.2});
    weather_station.removeObserver(&weather_station, (IObserver *)&statistics_display);
    weather_station.setMeasurements(&weather_station, (WeatherData){78, 90, 29.2});
}