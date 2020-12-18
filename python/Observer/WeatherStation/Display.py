from .interface.Observer import Observer
from .interface.Subject import Subject
from .interface.DisplayElement import DisplayElement
from .interface.Data import Data


class CurrentConditionsDisplay(Observer, DisplayElement):
    def __init__(self, weather_data: Subject):
        self.weather_data: Subject = weather_data
        self.object: Data = Data()

        self.weather_data.registerObserver(self)

    def update(self, object: Data):
        self.object = object
        self.display()

    def display(self):
        print("Current Condition :")
        print(f'temperature : {self.object.temperature}')
        print(f'humidity : {self.object.humidity}')
        print(f'pressure : {self.object.pressure}')


class StatisticsDisplay(Observer, DisplayElement):
    def __init__(self, weather_data: Subject):
        self.weather_data: Subject = weather_data
        self.object: Data = Data()
        self.count: int = 0

        self.weather_data.registerObserver(self)

    def update(self, object: Data):
        def caculate(old_data: float, old_count: float, new_data: float) -> float:
            return (old_data*old_count+new_data)/(old_count+1)

        self.object.temperature = caculate(
            self.object.temperature, self.count, object.temperature)
        self.object.humidity = caculate(
            self.object.humidity, self.count, object.humidity)
        self.object.pressure = caculate(
            self.object.pressure, self.count, object.pressure)
        self.count += 1
        self.display()

    def display(self):
        print("Statistics Data :")
        print(f'avg temperature : {self.object.temperature:0.2f}')
        print(f'avg humidity : {self.object.humidity:0.2f}')
        print(f'avg pressure : {self.object.pressure:0.2f}')
