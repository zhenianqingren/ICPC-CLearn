#include <stdio.h>
#include <limits.h>
#include <float.h>
int x=1;
int y=2;
int addtwonum();
int main()
{
    //  printf("memory of int : %lu \n", sizeof(int));
    printf("float �洢����ֽ��� : %lu \n", sizeof(float));
    printf("float ��Сֵ: %E\n", FLT_MIN);
    printf("float ���ֵ: %E\n", FLT_MAX);
    printf("����ֵ: %d\n", FLT_DIG);
    printf("%d \n",addtwonum());
    getchar();
    return 0;
}