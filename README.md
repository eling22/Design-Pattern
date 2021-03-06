# Design-Pattern
the record of Design Pattern Learning
- [Design-Pattern](#design-pattern)
  - [Stategy](#stategy)
  - [Observer](#observer)
  - [Decorator](#decorator)
  - [Factory](#factory)
  - [Singleton](#singleton)
  - [Command](#command)
  - [Adapter](#adapter)
  - [Facade](#facade)

## Stategy

## Observer

![observer diagram](img/observer_diagram.png)

## Decorator

![decorator diagram](img/decorator_diagram.png)

## Factory

### Factory Method

![factory method](img/factory_method.png)

### Abstract Factory

![abstract factory](img/abstract_factory.png)

## Singleton

### Target

Create a global access class for Setting or thread managing ... etc.

### Method
It uses a static variable, a private constructor and a public static function - `getInstance()` to make sure that only one instance of class exists.

![singleton](img/singleton_diagram.png)

## Command

### Target

Decouple the object request the command and perform the command.

### Method

It uses a command interface with execute action, and through invoker to active the command behavior. 

![command](img/command_diagram.png)

## Adapter

### Target

Make interface convert to another interface.

### Method

It uses a adapter class to turn the original interface to the new one.

![adapter](img/adapter_diagram.png)

## Facade

### Target

Don't provide unnecessary information for client to operate and make client code as simple as possible.

### Method

It uses a facade interface to restructure a set of complex interfaces. It makes the facade interface only provide necessary operate functions for clients.

![facade](img/facade_diagram.png)