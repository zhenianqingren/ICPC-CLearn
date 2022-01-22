#include <stdio.h>
#include <stdarg.h>

double average(int num, ...)
{

    va_list valist;
    double sum = 0.0;
    int i;

    /* Ϊ num ��������ʼ�� valist */
    va_start(valist, num);

    /* �������и��� valist �Ĳ��� */
    for (i = 0; i < num; i++)
        sum += va_arg(valist,int);

    /* ����Ϊ valist �������ڴ� */
    va_end(valist);

    return sum / num;
}

int main()
{
    printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2, 3, 4, 5));
    printf("Average of 5, 10, 15 = %f\n", average(3, 5, 10, 15));

    getchar();
    return 0;
}