#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
// int isalnum(int c) �ú�������������ַ��Ƿ�����ĸ�����֡�
// int isalpha(int c) �ú�������������ַ��Ƿ�����ĸ��
// int iscntrl(int c) �ú�������������ַ��Ƿ��ǿ����ַ���
// int isdigit(int c) �ú�������������ַ��Ƿ���ʮ�������֡�
// int isgraph(int c) �ú�������������ַ��Ƿ���ͼ�α�ʾ����
// int islower(int c) �ú�������������ַ��Ƿ���Сд��ĸ��
// int isprint(int c) �ú�������������ַ��Ƿ��ǿɴ�ӡ�ġ�
// int ispunct(int c) �ú�������������ַ��Ƿ��Ǳ������ַ���
// int isspace(int c) �ú�������������ַ��Ƿ��ǿհ��ַ���
// int isupper(int c) �ú�������������ַ��Ƿ��Ǵ�д��ĸ��
// int isxdigit(int c) �ú�������������ַ��Ƿ���ʮ���������֡�
// int tolower(int c) �ú����Ѵ�д��ĸת��ΪСд��ĸ��
// int toupper(int c) �ú�����Сд��ĸת��Ϊ��д��ĸ��
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