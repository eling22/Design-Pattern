@startuml

interface       Iterator{
    hasNext()
    next()
}
class           PancakeIterator{
    hasNext()
    next()
}
class           DinerIterator{
    hasNext()
    next()
}

interface       Menu{
    createIterator()
}
class           PancakeMenu{
    ArrayList<MenuItem> items
    createIterator()
}
class           DinerMenu{
    MenuItem items[] 
    createIterator()
}

class waitress{
    printMenu()
}

waitress -> Iterator
Menu <- waitress

Menu <|-down- PancakeMenu
Menu <|-down- DinerMenu

Iterator <|-down- PancakeIterator
Iterator <|-down- DinerIterator

PancakeMenu -> PancakeIterator
DinerMenu -> DinerIterator

@enduml