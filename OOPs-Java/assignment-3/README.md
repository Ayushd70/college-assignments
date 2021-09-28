# THE ACTUAL QUESTIONS

## Assignment-3


1. Create a class called Student containing student ID and Student name. Create a default constructor with a default value ID as 122 and name as “STCET student” . Also show if the programmer is not creating any constructor then what is the output.


2. Create a parameterized constructor of class Employee having EID, Ename, Dept ( Sales, IT, accounts, HR). Display the record of five employees having all the mentioned characteristics.


3. Implement the details of five students with the attributes mentioned in question1 using an array of objects.

###  Questionnaire

1. What is a constructor? Why is it called so?
```
In Java, a constructor is a block of codes similar to the method. 
It is called when an instance of the class is created. At the time of calling constructor, memory for the object is allocated in the memory.

It is called constructor because it constructs the values at the time of object creation. It is not necessary to write a constructor for a class.
```

2. What happens if a programmer does not create any constructor?
```
It calls a default constructor if there is no constructor available in the class. 
In such case, Java compiler provides a default constructor by default.
```

3. If we create 5 objects of a class, then how many time constructors will be called?
```
Constructor will be called 5 times on creating 5 objects of the class. 
On every object creation a constructor gets called.
```