#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static off_t GetFileSize(char* filename)
{
    struct stat buffer;
    if (stat(filename, &buffer) == 0)
    {
        return buffer.st_size;
    }

    perror("stat error:");
    exit(1);
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage %s <filename>", argv[0]);
        exit(1);
    }

    printf("%lld\n", (long long)GetFileSize(argv[1])) ;

    exit(0);
}