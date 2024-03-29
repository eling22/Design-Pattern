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
  - [Template method](#template-method)
  - [Iterator](#iterator)
  - [Composite](#composite)
  - [State](#state)
  - [MVC (Model View Controller)](#mvc-model-view-controller)

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

## Template method

### Target

Decouple low-level & high-level components. make high-level decide algorithms and low-level decide the detail of different class.

### Method

It use an abstract class with functions to build algorithms. When concrete class inherits the abstract class, it can overwrite some of these classes to provide flexibility for different classes.

![template_method](img/template_method.png)

## Iterator

### Target
Through a common interface for traversing the data in any aggregate data structure (ex. array, vector, link list, hash map, etc.)

### Method

It use a interface called Iterator with function - hasNext() & next() to implement traverse feature. Make the aggregate to implement the Iterator interface by themselves. Thus, every aggregate supporting Iterator have the traverse feature.

![iterator](img/iterator_diagram.png)

## Composite

### Target
Make clients treat individual objects and compositions of objects uniformly.

### Method
It puts individual objects and compositions of objects into a tree structure, so that it can handle both in same structure.

![Composite](img/composite_diagram.png)

## State

### Target
The implement of finite-state machines.

### Method
It uses a point of current state. Through changing the current state to do different behavior in same function. 

![State](img/state_diagram.png)

## MVC (Model View Controller)

### Target
Help to structure the program for user interface.

### Method
It is composed of Observer, Strategy, and Composite patterns. The Model uses the Observer pattern for the view. Through the Observer pattern, the view can receive the notice from the model when a value changed. The Controller uses the Strategy pattern for the view. Through the Observer pattern, the view can choose other controllers for implementing the different behavior. The view uses the composite pattern to combine and operate components in the user interface. 

![MVC](img/mvc.png)