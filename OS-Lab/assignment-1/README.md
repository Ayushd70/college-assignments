# THE ACTUAL QUESTIONS

## Assignment-1

### Login to UNIX system and perform the following:

Prerequisites:

```
~ mkdir os
~ cd os
~ mkdir assignment-1
~ cd as*
```

1. Create five empty files empty1, empty2, empty3, empty4 and empty5.

```
~ touch empty1
~ touch empty2
~ touch empty3
~ touch empty4
~ touch empty5
```

2. Create a file called text and store your name, age and address in it.

```
~ cat > text
```

3. Display the contents of thefile text on the screen.

```
~ cat text
```

4. Make a copy of the file text into another file newtext.

```
~ cp text newtext
```

5. Create a file matter and typeany 2 sentences in it.

```
~ cat > matter
```

6. Combine the contents of the file text and matter into another file txtmat.

```
~ cat text matter >txtmat
```

7. Delete the file text.

```
~ rm text
```

8. Change the permission of the file newtext to 666.

```
~ chmod 666 newtext
```

9. Rename the file newtext to oldtext.

```
~ mv newtext oldtext
```

10. Create a directory mydir in the current directory.

```
~ mkdir mydir
```

11. Move the files oldtext and matter to the directory mydir.

```
~ mv oldtext mydir/
~ mv matter mydir/
```

12. Create another directory mydir in the current directory.

```
~ mkdir mydir
```

13. Copy the contents of mydir directory to the new dirdirectory.

```
~ cp -r mydir/* newdir/
```

14. Display the current date in the format dd/mm/yyyy..

```
~ date +%d-%m-%Y
```

15. Check the current users.

```
~ who
```

16. Obtain a complete listing of all files and directories in the whole system.

```
~ ls -R /
```

17. Count the number of users currently logged into the system..

```
~ who -q
```
