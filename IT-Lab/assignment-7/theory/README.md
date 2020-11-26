## QUESTIONNAIRES:

```
a) Save a tuple. Print it. Delete it.
>>> tup=(1,2,3)
>>> print(tup)
(1, 2, 3)
>>> del(tup)
>>> print(tup)
#tuple is immutable .so we can’t modify any element in it.

b) Save two tuples. Concatenate them. Print it without using loops.
>>> tup=(1,2,3)
>>> next=(10,20,30)
>>> new=tup+next
>>> print(new)
(1, 2, 3, 10, 20, 30)
#we can concatenate tuple by using +operator(creates a new tuple)
c.	Suppose a tuple contains one item. Now store the same item for five times without using loop.
>>> tup=(5,)
>>> tup=tup*5
>>> print(tup)
(5, 5, 5, 5, 5)
#we can use *operator to create a new tuple which has same values as 1st tuple repeated given times in it(in the order).

d) Save a tuple. Print ith to jth item without using loop.
>>> tup=(1,2,3,10,20,30)
>>> print(tup[2:4])
(3, 10)
#we can slice a tuple using slice operators([::]).like list,str. 

e) Convert a list in a tuple.
>>> tup=(1,2,3)
>>> new=list(tup)
>>> print(new)
[1, 2, 3]

# we can convert a tuple in a list by passing the tuple in the constructor of list as an argument.

f) Find maximum and minimum item in a tuple. Find the length of a tuple.
>>> tup=(1,2,3,10,20,30)
>>> max(tup)
30
>>> min(tup)
1
>>> len(tup)
6
#tuple has min,max,len operator overloaded. 
1)
WRITE A PROGRAM TO REVERSE A TUPLE
>>> x=("W3RESOURSE")
>>> y=reversed(x)
>>> print(tuple(y))
('E', 'S', 'R', 'U', 'O', 'S', 'E', 'R', '3', 'W')
>>> x=(1,2,3,4,5)
>>> y=reversed(x)
>>> print(tuple(y))
(5, 4, 3, 2, 1)
>>> 

2) WRITE A PROGRAM TO COUNT THE ELEMENTS IN A LIST UNTIL THE ELEMENT IS A TUPLR.
num = [10,20,30,(10,20),40]
ctr = 0
for n in num:
    if isinstance(n, tuple):
        break
    ctr += 1
print(ctr)

OUTPUT
3

3)
Write a Python program to find the index of an item of a tuple. Convert a string to a tuple. Check it for
all possible parameters of index function. Check it for an item which is not present.
tuplex = tuple("index tuple")
print(tuplex)
index = tuplex.index("p")
print(index)
index = tuplex.index("p", 5)
print(index)
index = tuplex.index("e", 3, 6)
print(index)
index = tuplex.index("y")

4)
Write a program in Python to do slicing in all possible ways with all possible parameters, providing
positive and negative values for step. Also, perform slicing from start and end both.

tuplex = (2, 4, 3, 5, 4, 6, 7, 8, 6, 1)
slice = tuplex[3:5]
print(slice)
slice = tuplex[:6]
print(slice)
slice = tuplex[5:]
print(slice)
slice = tuplex[:]
print(slice)
slice = tuplex[-8:-4]
print(slice)
tuplex = tuple("HELLO WORLD")
print(tuplex)
slice = tuplex[2:9:2]
print(slice)
slice = tuplex[::4]
print(slice)
slice = tuplex[9:2:-4]
print(slice)

OUTPUT
(5, 4)
(2, 4, 3, 5, 4, 6)
(6, 7, 8, 6, 1)
(2, 4, 3, 5, 4, 6, 7, 8, 6, 1)
(3, 5, 4, 6)
('H', 'E', 'L', 'L', 'O', ' ', 'W', 'O', 'R', 'L', 'D')
('L', 'O', 'W', 'R')
('H', 'O', 'R')
('L', ' ')
```