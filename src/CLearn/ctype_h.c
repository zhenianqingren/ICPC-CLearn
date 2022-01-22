#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
// int isalnum(int c) 该函数检查所传的字符是否是字母和数字。
// int isalpha(int c) 该函数检查所传的字符是否是字母。
// int iscntrl(int c) 该函数检查所传的字符是否是控制字符。
// int isdigit(int c) 该函数检查所传的字符是否是十进制数字。
// int isgraph(int c) 该函数检查所传的字符是否有图形表示法。
// int islower(int c) 该函数检查所传的字符是否是小写字母。
// int isprint(int c) 该函数检查所传的字符是否是可打印的。
// int ispunct(int c) 该函数检查所传的字符是否是标点符号字符。
// int isspace(int c) 该函数检查所传的字符是否是空白字符。
// int isupper(int c) 该函数检查所传的字符是否是大写字母。
// int isxdigit(int c) 该函数检查所传的字符是否是十六进制数字。
// int tolower(int c) 该函数把大写字母转换为小写字母。
// int toupper(int c) 该函数把小写字母转换为大写字母。
int main()
{
    int size = 10;
    char *c = (char *)malloc(size * sizeof(char));
    strcpy(c, "abcdefghij");

    for (int i = 0; i < size; i++)
        c[i]=toupper(c[i]);

    printf(c);
    free(c);
    getchar();
    return 0;
}