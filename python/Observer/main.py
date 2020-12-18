from WeatherStation.WeatherData import WeatherData
from WeatherStation.Display import CurrentConditionsDisplay, StatisticsDisplay
from WeatherStation.interface.Data import Data


def main():
    weather_data: WeatherData = WeatherData()
    current_display: CurrentConditionsDisplay = CurrentConditionsDisplay(
        weather_data)
    statistics_display: StatisticsDisplay = StatisticsDisplay(weather_data)

    weather_data.setMeasurements(Data(80, 65, 30.4))
    weather_data.setMeasurements(Data(82, 70, 29.2))
    weather_data.setMeasurements(Data(78, 90, 29.2))


if __name__ == "__main__":
    main()
