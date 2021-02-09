@startuml

interface       Command {
    execute()
    undo()
}

class LightOnCommand
class LightOffCommand
class Light

class Invoker

Command <|-- LightOnCommand
Command <|-- LightOffCommand

Light <-- LightOnCommand
Light <-- LightOffCommand

Invoker --> Command
Client --> Invoker

@enduml