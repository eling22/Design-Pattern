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

namespace NYPizza {
    class ThickCrustDough
    class PlumTomatoSauce 
    class MozzarellaCheese
    ThickCrustDough -down[hidden]-> PlumTomatoSauce
    PlumTomatoSauce -down[hidden]-> MozzarellaCheese
}

namespace ChicagoPizza {
    class ThinCrustDough
    class MarinaraSauce 
    class ReggianoCheese
    ThinCrustDough -down[hidden]-> MarinaraSauce
    MarinaraSauce -down[hidden]-> ReggianoCheese
}


Ingredient.Dough <|-- NYPizza.ThickCrustDough
Ingredient.Dough <|-- ChicagoPizza.ThinCrustDough

Ingredient.Sauce <|-- NYPizza.PlumTomatoSauce
Ingredient.Sauce <|-- ChicagoPizza.MarinaraSauce

Ingredient.Cheese <|-- NYPizza.MozzarellaCheese
Ingredient.Cheese <|-- ChicagoPizza.ReggianoCheese

NYPizzaIngredientFactory ---> NYPizza
ChicagoPizzaIngredientFactory ---> ChicagoPizza

class NYPizzaStore

NYPizzaStore -> PizzaIngredientFactory
NYPizzaStore --> Ingredient


@enduml