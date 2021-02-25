@startuml

Client -> Facade

package subsystem <<Rectangle>> {
    class A
    class B
    class C
    class D
}

Facade -down-> A
Facade -down-> D

A <-- B
C <-- B
A <-- D
A <-- C
D <-- B

@enduml