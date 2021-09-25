# THE ACTUAL QUESTIONS

## Assignment-1

### Login to UNIX system and perform the following:

Prerequisites:

```
~ cd college-assignments/OS-Lab
~ mkdir assignment-2
~ cd assign*-2
```

1. Create a file named 'teachers' using vi editor. Type 20 lines in this file in a fastion as shown below:

```
TOO1 | P.C | D.S | Kolkata
TOO2 | K.M | O.S | Howrah
TOO3 | J.S | Graphics | Jadavpur

---

---

---

---

---

TO2O | A.P | Automata | Behela
```

Now perform the following operations on this file 'teachers':

```
~ vi teachers
```

a. Show first three lines of the file.

```
~ head -3 teachers
```

b. Explain the result of the following command ls l t | tail 1

```
~ listed all the files and directories in current directory and piped that
output to "tail -1" which printed the last line of piped output to STDOUT.
```

c. Display the first 100 characters of the file.

```
~ head -c 100 teachers
```

d. Display the last three lines of the file.

```
~ tail -3 teachers
```

e. Display the line no. 5 and onwards

```
~ head +5 teachers
```

f. Show the first five lines on the screen as well as store it in a file named "shortlist"?

```
~ head -5 teachers | tee "shortlist"
```

g. Display only the name and city of the teachers from the file "shortlist".

```
~ cat shortlist | cut -d "|" -f 2,4
```

h. Cut the third field from the file "shortlist" and share it in a file "cutlist 1" aswell as show the result on the screen.

```
~ cat shortlist | cut -d "|" -f 3 | tee "cutlist1"
```

i. Cut the 1st, 2nd and 4th fields from the file "Shortlist" and store it in a file. "cutlist 2" without displaying the result on the screen.

```
~ cat shortlist | cut -d "|" -f 1,2,4 > cutlist2
```

j. Now paste the files "cutlist 1" and cutlist.2" laterally.

```
~ paste cutlist2 cutlist1
```

k. Sort the file "teachers" according to the -name of the teachers.

```
~ sort -k 2 teachers
```

l. Sort the file "teachers" in reverse order.

```
~ sort -r teachers
```

m. Is it possible, to sort the file using the following command?
"sort numfile"
where "numfile" contains the following numbers:
2
10
5
27
4
Explain the result, if not possible, how can you overcome the problem?

```
No, It is not possible to sort this file with this above command because this command is used for character sorting
```

n. Replace the character '!' with '~' and change the lower case characters to upper case.

```
~ cat teachers | tr [:lower] [:upper] | tr ["|"] ["-"]
```

o. Display the lines containing the pattern "Kolkata"

```
~ grep -h Kolkata teachers
```

p. Count the no. of occurences of the word 'Howrah'.

```
~ grep -c Howrah teachers
```

q. Display the line no. in which the word 'Jadavpur' appears.

```
~ grep -n Jadavpur teachers
```
