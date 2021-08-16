@startuml

View -> Controller: user do something
Controller -> Model : change your state
Controller -> View : change your view
Model -> View : a value changed
View -> Model : asked for the values

@enduml