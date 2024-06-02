#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <sourcefile> <destfile>\n", argv[0]);
        exit(1);
    }

    FILE* fds = NULL;
    FILE* fdd = NULL;

    fds = fopen(argv[1], "r");
    if (fds == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    fdd = fopen(argv[2], "w");
    if (fdd == NULL)
    {
        fclose(fds);
        perror("fopen()");
        exit(1);
    }


    while ((char)fgetc(fds) != EOF)
    {
        char ch = fgetc(fds);
        fputc(ch, fdd);
    }
    

    fclose(fdd);
    fclose(fds);
    exit(0);
}