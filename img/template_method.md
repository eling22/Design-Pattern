@startuml

abstract  AbstractClass{
    templateMethod()
    primitiveOperation1()
    primitiveOperation2()
}
class ConcreteClass{
    primitiveOperation1()
    primitiveOperation2()
}
component comp [
    primitiveOperation1()
    primitiveOperation2()
]
AbstractClass <|-- ConcreteClass
AbstractClass::templateMethod --right--> comp #line.dotted

@enduml