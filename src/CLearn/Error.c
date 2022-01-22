#include <stdio.h>
#include<stdlib.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main()
{
    FILE *pf;
    int errnum;
    pf = fopen("D:/unexist.txt", "rb");
    if (pf == NULL)
    {
        errnum = errno;
        fprintf(stderr, "错误号: %d\n", errno);
        perror("通过 perror 输出错误");
        fprintf(stderr, "打开文件错误: %s\n", strerror(errnum));
    }
    else
    {
        fclose(pf);
    }

    int dividend = 20;
    int divisor = 0;
    int quotient;

    if (divisor == 0)
    {
        fprintf(stderr, "除数为 0 退出运行...\n");
        getchar();
        exit(-1);//EXIT_FAILURE
    }
    quotient = dividend / divisor;
    fprintf(stderr, "quotient 变量的值为 : %d\n", quotient);
    exit(0);//EXIT_SUCCESS

    getchar();
    return 0;
}