@startuml

interface       PizzaStore{
    createPizza()
}

class       NYPizzaStore{
    createPizza()
}

class       ChicagoPizzaStore{
    createPizza()
}

interface       Pizza
namespace NYPizza {
    class       NYCheesePizza
    class       NYClamPizza
}
namespace ChicagoPizza {
    class       ChicagoCheesePizza
    class       ChicagoClamPizza
}

PizzaStore <|-- NYPizzaStore
PizzaStore <|-- ChicagoPizzaStore

Pizza <|-- NYPizza.NYCheesePizza
Pizza <|-- NYPizza.NYClamPizza
Pizza <|-- ChicagoPizza.ChicagoCheesePizza
Pizza <|-- ChicagoPizza.ChicagoClamPizza

NYPizzaStore ---> NYPizza
ChicagoPizzaStore ---> ChicagoPizza

@enduml