#include <stdio.h>
// ��ȡ�ַ���ʱ��ֻҪ����һ���ո�scanf() �ͻ�ֹͣ��ȡ������ "this is test" �� scanf() ��˵�������ַ���
int main()
{
    int testInteger = 5;
    printf("Number = %d\n", testInteger); //%d ��ʽ���������:

    float f;
    printf("Enter a number: ");
    // %f ƥ�両�������� %c -> char %s -> string
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