#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i = 0; i < 2000; i++)
    {
        putchar('a');        //标准IO输出
        write(1, "b", 1);    //文件IO输出
    }
    exit(0);
}