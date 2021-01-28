@startuml

class  Singleton{
    +{static} uniqueInstance
    - Singleton()
    +{static} getInstance()
}

@enduml