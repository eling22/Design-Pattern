@startuml
interface       Subject{
    registerObserver()
    removeObserver()
    notifyObserver()
}
interface       Observer{
    update()
}
interface       DisplayElement{
    display()
}
object Object{
    float temperature
    float humidity
    float pressure
}

class           WeatherData{
    Object data
    registerObserver()
    removeObserver()
    notifyObserver()
    measurementsChanged()
}
class           CurrentConditionsDisplay{
    Object data
    update()
    display()
}
class           StatisticsDisplay{
    Object data
    update()
    display()
}


Subject <|-- WeatherData
Observer <|-- CurrentConditionsDisplay
Observer <|-- StatisticsDisplay
DisplayElement <|-- CurrentConditionsDisplay
DisplayElement <|-- StatisticsDisplay
Object *-- WeatherData
Object *-- CurrentConditionsDisplay
Object *-- StatisticsDisplay

Subject <-> Observer

@enduml