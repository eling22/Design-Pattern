@startuml
interface       Component{
    method_A()
    method_B()
    //other method
}
class ConcreteComponent{
    method_A()
    method_B()
    //other method
}
interface       Decorator{
    method_A()
    method_B()
    //other method
}
class       ConcreteDecorator_A{
    Component wrappedObj
    method_A()
    method_B()
    {method}//other method
}
class       ConcreteDecorator_B{
    Component wrappedObj
    Object newState
    method_A()
    method_B()
    {method}//other method
}

Component <|-- ConcreteComponent
Component <|-- Decorator
Decorator <|-- ConcreteDecorator_A
Decorator <|-- ConcreteDecorator_B

@enduml