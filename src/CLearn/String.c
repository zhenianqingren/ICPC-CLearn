#include <stdio.h>
#include<string.h>
int end;
int main()
{
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("Greeting message: %s\n", greeting);
    char another_greeting[] = "Hello";
    printf("Greeting message: %s\n", another_greeting);

    char str1[12] = "Hello";
    char str2[12] = "World";
    char str3[12];
    int len;

    /* ���� str1 �� str3 */
    strcpy(str3, str1);
    printf("strcpy( str3, str1) :  %s\n", str3);

    /* ���� str1 �� str2 */
    strcat(str1, str2);
    printf("strcat( str1, str2):   %s\n", str1);

    /* ���Ӻ�str1 ���ܳ��� */
    len = strlen(str1);
    printf("strlen(str1) :  %d\n", len);
    printf("sizeof(str1) : %d\n",(int)sizeof(str1));

    scanf("%d", &end);
    return 0;
}