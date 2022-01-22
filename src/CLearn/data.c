#include <stdio.h>
#include <limits.h>
#include <float.h>
int x=1;
int y=2;
int addtwonum();
int main()
{
    //  printf("memory of int : %lu \n", sizeof(int));
    printf("float 存储最大字节数 : %lu \n", sizeof(float));
    printf("float 最小值: %E\n", FLT_MIN);
    printf("float 最大值: %E\n", FLT_MAX);
    printf("精度值: %d\n", FLT_DIG);
    printf("%d \n",addtwonum());
    getchar();
    return 0;
}