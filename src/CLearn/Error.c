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
        fprintf(stderr, "�����: %d\n", errno);
        perror("ͨ�� perror �������");
        fprintf(stderr, "���ļ�����: %s\n", strerror(errnum));
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
        fprintf(stderr, "����Ϊ 0 �˳�����...\n");
        getchar();
        exit(-1);//EXIT_FAILURE
    }
    quotient = dividend / divisor;
    fprintf(stderr, "quotient ������ֵΪ : %d\n", quotient);
    exit(0);//EXIT_SUCCESS

    getchar();
    return 0;
}