#include <stdio.h>
// 读取字符串时，只要遇到一个空格，scanf() 就会停止读取，所以 "this is test" 对 scanf() 来说是三个字符串
int main()
{
    int testInteger = 5;
    printf("Number = %d\n", testInteger); //%d 格式化输出整数:

    float f;
    printf("Enter a number: ");
    // %f 匹配浮点型数据 %c -> char %s -> string
    scanf("%f", &f);
    printf("Value = %f\n", f);

    int c;
    printf("Enter a value :");
    getchar(); //catch existed char from memory
               //when scanf() exists above, two getchar() are needed
    c = getchar();

    printf("\nYou entered : ");
    putchar(c);
    printf("\n");

    char*str;
    printf("Enter a value :");
    getchar();
    gets(str);

    printf("\nYou entered: ");
    puts(str);


    getchar();
    return 0;
}