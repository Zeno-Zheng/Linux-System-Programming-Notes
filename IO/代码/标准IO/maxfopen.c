#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() 
{
    FILE* file = NULL;
    int count = 0;

    while (1)
    {
        file = fopen("temp", "r");
        if (file == NULL)
        {
            fprintf(stderr, "open file number is %d, %s\n", count, strerror(errno));

            exit(1);
        }
        ++count;
    }
    exit(0);
}