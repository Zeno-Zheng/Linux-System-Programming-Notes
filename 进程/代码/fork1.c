#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("[%d] : Begin\n", getpid());
    pid_t pid = fork();

    printf("pid is [%d]\n", pid);

    if (pid == 0)
    {
        printf("[%d] : child is working\n", getpid());
    }
    else if (pid < 0)
    {
        perror("fork()\n");
        exit(1);
    }
    else
    {
        printf("[%d] : parent is working\n", getpid());
    }

    printf("[%d] : End\n", getpid());
    exit(0);
}