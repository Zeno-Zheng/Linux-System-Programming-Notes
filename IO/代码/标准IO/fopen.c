#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() 
{
    FILE* file = NULL;

    file = fopen("temp", "w");
    if (file == NULL)
    {
        // fprintf(stderr, "open failed!, errno is %d\n", errno);
        // perror("fopen()");       //参数是人为规定的字母，是自定义的，函数的输出会自动关联errno的具体内容而不是仅仅是数字
        fprintf(stderr, "fopen():%s\n", strerror(errno));
        exit(1);
    }
    puts("ok");
    fclose(file);
    exit(0);
}