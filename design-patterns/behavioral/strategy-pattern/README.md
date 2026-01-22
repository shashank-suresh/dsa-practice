# Strategy Pattern

The strategy pattern is used when the parent class has a feature that has common implementations among child classes. This basically allows us to create a family of interchangeable implementations and use them at runtime to allow an object's behavior to change without altering the object itself.

For example, if a client wants to checkout then there are different payment methods that they can choose from. If we implement the different payment methods as strategies - CreditCardStrategy, UPIStrategy, etc - then the client can switch back and forth and it would simply require us to swap out one strategy for the other.
