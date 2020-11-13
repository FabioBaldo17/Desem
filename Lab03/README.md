# This is the lab 03 of DesEm

In order to solve the  exercise:

The Button class has an ISR that reacts to interrupts from a GPIO connected to a push
button. This means that it receives two kind of interrupts:
- when the push button is pressed
- when the push button is released
The button class, that exists in the HAL package, can call the buttonPressed() and the
buttonReleased() methods in another class called ButtonController. This class exists in
the Application package. On the other hand, the Button class provides a method called
checkButton() that returns whether the push button is in pressed or released state at
the moment of it’s call.
The chief software engineer requires that all the methods have to be „callable“ only
from Button respectively ButtonController objects.