# THE ACTUAL QUESTIONS

## Assignment-4

1. Create a class called shape which has members called calarea() and display(). Calculate the area for three different
   shapes: triangle (scalene triangle), rectangle and circle. Apply method overloading to control the area parameter and
   display the area through main.


2. Create class sum and demonstrate constructor overloading by adding two, three parameters. If someone passes no
   parameter the message will display “ Bucket is empty”.

### Questionnaire

1. Can we overload a method by changing the return type.

```
Method overloading cannot be done done by changing the return type of methods. The most important rule
of method overladed methodsmust have different parameters.
```

2. What is method signature?

```
In Java, a method signature signature is composed of a name and the number, type and order of its parameters.
Return types and thrown exceptions are not considered to be a part of the method signature, nor are the names
of parameters, they are ignored by the compiler for checking method uniqueness.
```

3. Can we overload the main method? If so, what is the consequence? Justify with example.

```
Yes, Main method can be overloaded in Java.
Execution of Java program has no impact on overloading main base because JVM always calls the original main method
and if it doesn't find in class then it throws java.lang.NoSuchMethodError: main Exception in thread "main" 
error at runtime.
```