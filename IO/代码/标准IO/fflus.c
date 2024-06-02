#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Before while");   //如果不使用fflush,那么这一行输出并不会打印出来
    fflush(stdout);           //清空stdout流中的内容

    //如果不想写fflush，则需要写换行符
    printf("Before while\n");

    while (1);

    printf("After while");    //与“before while”一致
    fflush(NULL);             //清空所有的流
}