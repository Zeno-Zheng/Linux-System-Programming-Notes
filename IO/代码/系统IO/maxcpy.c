#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <sourcename> <destnationname>", argv[0]);
        exit(1);
    }

    int fds = -1;
    int fdd = -1;

    fds = open(argv[1], O_RDONLY);
    if (fds < 0)
    {
        perror("source file open");
        exit(1);
    }

    fdd = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
    if (fdd < 0)
    {
        perror("destnation file open");
        close(fds);
        exit(1);
    }

    printf("fds is %d, fdd is %d\n", fds, fdd);

    char buffer[BUFSIZE];

    while (1)
    {
        ssize_t res = read(fds, buffer, BUFSIZE);
        if (res == 0)
        {
            break;
        }
        else if (res < 0)
        {
            perror("read()");
            break;
        }

        ssize_t wres = write(fdd, buffer, res);
        if (wres < 0)
        {
            perror("write()");
            break;
        }
        
        while (wres != res)
        {
            res = res - wres;
            wres = write(fdd, buffer + wres, res);
        }
    }
    

    close(fdd);
    close(fds);

    exit(0);
}