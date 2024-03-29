# THE ACTUAL QUESTIONS

## Assignment-4

Programs:

1. Write a program to implement parent child process and explain their concurrent execution.

2. Write a program to implement and explain orphan process.

3. Write a program to implement and explain zombie process.

4. Write a program to implement threads.

Questions:

1. What do you understand by a child process?

```
A process which is created by another process(parent) is called a child process.
Also known as subprocess, it mainly pertains to multitasking operating systems.
```

2. Discuss the fork() function. Discuss the significance of pid and ppid of a process.

```
The fork() function is used to create a new process by duplicating the existing process
from which it is called. The existing process from which this function is called becomes
the parent process and the newly created process becomes the child process.

pid stands for Process ID, which is an unique Identification Number for currently running
process in memory. ppid stands for Parent Process ID, which uniquely identifies the parent of the currently running process.
Their significance lies in identification of the running processes.
```

3. When a process is called zombie? How do you demonstrate the existence of zombie process?

```
A process which has finished the execution but still has entry in the process table to
report to its parent process is known as a zombie process.
- Listing out the running processes in the terminal the presence of <defunct> signifies the presence of a zombie process.

```

4. When a process is called orphan? Discuss its difference with a zombie process. How do you
   demonstrate the existence of orphan process?

```
An orphan process is a computer process whose parent process has finished or terminated,
though it remains running itself.
- An orphan process continues to run even after it's parent is terminated, a zombie process
  however is defunct in nature which has completed it's execution but still has an entry in process table.
- An orphan process has  init (process id –> 1) as parent. Listing out processes we can easily find all the orphan processes in system.
```
