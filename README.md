# Design-Pattern
the record of Design Pattern Learning

# Stategy

# Observer

![observer diagram](img/observer_diagram.png)

# Decorator

![decorator diagram](img/decorator_diagram.png)

# Factory

## Factory Method

![factory method](img/factory_method.png)

## Abstract Factory

![abstract factory](img/abstract_factory.png)

# Singleton

## Target

Create a global access class for Setting or thread managing ... etc.

## Method
It uses a static variable, a private constructor and a public static function - `getInstance()` to make sure that only one instance of class exists.

![singleton](img/singleton_diagram.png)

# Command

## Target

Decouple the object request the command and perform the command.

## Method

It use a command interface with execute action, and through invoker to active the command behavior. 

![command](img/command_diagram.png)
