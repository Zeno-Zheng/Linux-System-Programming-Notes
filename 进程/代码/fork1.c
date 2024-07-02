#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("[%d] : Begin\n", getpid());
    fflush(NULL);     /**fork进程之前，一定要清空缓存区中的缓存，否则缓存也会有两份 */

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