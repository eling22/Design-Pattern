@startuml

interface       Target
class           Adaptee
class           Adapter

Target <|-- Adapter
Adaptee <-- Adapter

@enduml