## QUESTIONNAIRES:

#### 1.What are the advantages of using slice of strings?
Ans:-Slicing is a technique in Python that allows us to access specific element(character of a string) or a subset of elements(more than one character) from a container object(string) using their index values.
Slicing avoids writing of loop statements to go through the indexes of a string to find or access certain substring.

#### 2.Can you directly replace a character in a string just by assigning ?If not,state the reason.Also give the solution.
Ans:-No,we cannot directly replace a character in a string just by assigning because in python string datatype is immutable which means a string value cannot be updated.

How to replace character in a string

```
<SYNTAX>
s=”Python”
‘J’+s[1:]

Output will be—‘Jython’
```
#### 3.What is the use of negative index?
Ans:-The negative index is used to remove any new line spaces from the string.The negative index is also used to show the index to represent the string in correct order.
