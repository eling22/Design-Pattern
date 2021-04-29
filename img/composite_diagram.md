@startuml

interface       MenuComponent{
    print()
}
class           Menu{
    print()
}
class           MenuItem{
    MenuComponent menuComponent[]
    print()
}

class waitress{
}

waitress -> MenuComponent
Menu --> MenuComponent
Menu -up-|> MenuComponent
MenuItem -up-|> MenuComponent

@enduml