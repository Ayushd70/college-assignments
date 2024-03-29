#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int main(void)
{
    pid_t ppid, pid, cpid;
    ppid = getpid();
    pid = fork();
    if (ppid == getpid())
        printf("parent");
    else if (cpid == getpid())
        printf("child");
    if (pid > 0)
    {
        int i = 0;
        while (i++ < 5)
        {
            printf("In the parent process.\n");
            sleep(1);
            if (i == 3)
            {
                kill(pid, SIGKILL); /* SIGKILL Kills the process ( it cannot be caught or ignored)*/
                printf("Child killed. I'm done!!!\n");
            }
        }
    }
    else if (pid == 0)
    {
        int i = 0;
        while (i++ < 10)
        {
            printf("In the child process.\n");
            sleep(1);
        }
    }
    else
    {
        // something bad happened.
        printf("Something bad happened.");
        exit(EXIT_FAILURE);
    }
    return 0;
}
