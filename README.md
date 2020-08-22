# Using C priority queue library to execute scripts in different languages

#### Runnig C, Python and R scripts using a priority queue developed in C. The queue will accept tasks from user input and execute them based on their priorities.

Compile:
1) first the C script
```bash
$  gcc cprint.c -o cprint
```
2) the program that uses the priority queue library
```bash
$ make proc_pq

gcc -c proc_pq.c
proc_pq.c: In function ‘main’:
proc_pq.c:73:11: warning: implicit declaration of function ‘waitpid’ [-Wimplicit-function-declaration]
   73 |           waitpid(pid, & status, 0);
      |           ^~~~~~~
gcc -c pq.c
ar rcs libpq.a pq.o
gcc proc_pq.o -L./ -lpq -o proc_pq
```

Everything can be compiled at once using **make** command alone, because **makefile** has **all** target.

Run:
```bash
$ ./proc_pq numbers.txt

        Input File is ./numbers.txt

1.Insert process in the queue
2.Execute process from the queue
3.Display the queue

 Please enter your choice: 1

Enter task:
pysum.py

Enter priority:
3

Do you want to continue (press 1 for yes or 0 to exit): 1

1.Insert process in the queue
2.Execute process from the queue
3.Display the queue

 Please enter your choice: 1

Enter task:
rmean.R

Enter priority:
1

Do you want to continue (press 1 for yes or 0 to exit): 1

1.Insert process in the queue
2.Execute process from the queue
3.Display the queue

 Please enter your choice: 3
{
        {'task': pysum.py, 'priority': 3}
        {'task': rmean.R, 'priority': 1}
}

Do you want to continue (press 1 for yes or 0 to exit): 1

1.Insert process in the queue
2.Execute process from the queue
3.Display the queue

 Please enter your choice: 1

Enter task:
cprint

Enter priority:
5

Do you want to continue (press 1 for yes or 0 to exit): 1

1.Insert process in the queue
2.Execute process from the queue
3.Display the queue

 Please enter your choice: 3
{
        {'task': cprint, 'priority': 5}
        {'task': pysum.py, 'priority': 3}
        {'task': rmean.R, 'priority': 1}
}

Do you want to continue (press 1 for yes or 0 to exit): 1

1.Insert process in the queue
2.Execute process from the queue
3.Display the queue

 Please enter your choice: 2

Task (cprint) with priority (5) has been removed

Process ./cprint to be processed using exe ...

        Printing list in C

        Length of list is: 10
        List elements are:
        1       2       3       4       5       6       7       8       9       10

Do you want to continue (press 1 for yes or 0 to exit): 1

1.Insert process in the queue
2.Execute process from the queue
3.Display the queue

 Please enter your choice: 2

Task (pysum.py) with priority (3) has been removed

Process ./pysum.py to be processed using python ...

        Sum of number list in python is: 55

Do you want to continue (press 1 for yes or 0 to exit): 1

1.Insert process in the queue
2.Execute process from the queue
3.Display the queue

 Please enter your choice: 2

Task (rmean.R) with priority (1) has been removed

Process ./rmean.R to be processed using Rscript ...
[1] "\n\tAverage of number list in R is: 5.5\n"

Do you want to continue (press 1 for yes or 0 to exit): 1

1.Insert process in the queue
2.Execute process from the queue
3.Display the queue

 Please enter your choice: 3

        The queue is Empty

Do you want to continue (press 1 for yes or 0 to exit): 0
``` 