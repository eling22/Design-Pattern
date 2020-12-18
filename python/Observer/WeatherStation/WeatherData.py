from .interface.Observer import Observer
from .interface.Subject import Subject
from .interface.Data import Data
from typing import List


class WeatherData(Subject):
    def __init__(self):
        self.observer_list: List[Observer] = []
        self.object = Data()

    def registerObserver(self, observer: Observer):
        self.observer_list.append(observer)

    def removeObserver(self, observer: Observer):
        self.observer_list.remove(observer)

    def notifyObserver(self):
        for observer in self.observer_list:
            observer.update(self.object)

    def measurementsChanged(self):
        self.notifyObserver()

    def setMeasurements(self, object: Data):
        self.object = object
        self.measurementsChanged()

    def getTemperature(self) -> float:
        return self.object.temperature

    def getHumidity(self) -> float:
        return self.object.humidity

    def getPressure(self) -> float:
        return self.object.pressure
