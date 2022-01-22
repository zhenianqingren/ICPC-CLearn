#include<stdio.h>
#include<stdlib.h>

// double atof(const char *str) 把参数 str 所指向的字符串转换为一个浮点数（类型为 double 型）。
// int atoi(const char *str) 把参数 str 所指向的字符串转换为一个整数（类型为 int 型）。
// long int atol(const char *str) 把参数 str 所指向的字符串转换为一个长整数（类型为 long int 型）。
// double strtod(const char str, char *endptr) 把参数 str 所指向的字符串转换为一个浮点数（类型为 double 型）。
// long int strtol(const char str, char *endptr, int base) 把参数 str 所指向的字符串转换为一个长整数（类型为 long int 型）。
// unsigned long int strtoul(const char str, char *endptr, int base) 把参数 str 所指向的字符串转换为一个无符号长整数（类型为 unsigned long int 型）。
// void exit(int status) 使程序正常终止。
int main()
{
    char num[]="123456789";

    exit(0);

    printf("%f\n",atof(num));
    printf("%d\n",atoi(num));

    getchar();
    return 0;

}