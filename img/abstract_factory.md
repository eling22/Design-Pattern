@startuml

interface       PizzaIngredientFactory {
    createDough()
    createSauce()
    createCheese()
}

class       NYPizzaIngredientFactory{
    createDough()
    createSauce()
    createCheese()
}

class       ChicagoPizzaIngredientFactory{
    createDough()
    createSauce()
    createCheese()
}

PizzaIngredientFactory <|-- NYPizzaIngredientFactory
PizzaIngredientFactory <|-- ChicagoPizzaIngredientFactory

namespace Ingredient {
    interface       Dough
    interface       Sauce
    interface       Cheese
    Dough -down[hidden]-> Sauce
    Sauce -down[hidden]-> Cheese
}

namespace ChicagoPizza {
    class ThickCrustDough
    class PlumTomatoSauce 
    class MozzarellaCheese
    ThickCrustDough -down[hidden]-> PlumTomatoSauce
    PlumTomatoSauce -down[hidden]-> MozzarellaCheese
}

namespace NYPizza {
    class ThinCrustDough
    class MarinaraSauce 
    class ReggianoCheese
    ThinCrustDough -down[hidden]-> MarinaraSauce
    MarinaraSauce -down[hidden]-> ReggianoCheese
}


Ingredient.Dough <|-- ChicagoPizza.ThickCrustDough
Ingredient.Dough <|-- NYPizza.ThinCrustDough

Ingredient.Sauce <|-- ChicagoPizza.PlumTomatoSauce
Ingredient.Sauce <|-- NYPizza.MarinaraSauce

Ingredient.Cheese <|-- ChicagoPizza.MozzarellaCheese
Ingredient.Cheese <|-- NYPizza.ReggianoCheese

NYPizzaIngredientFactory ---> NYPizza
ChicagoPizzaIngredientFactory ---> ChicagoPizza

class NYPizzaStore

NYPizzaStore -> PizzaIngredientFactory
NYPizzaStore --> Ingredient


@enduml