#include<stdio.h>
#include<stdlib.h>

// double atof(const char *str) �Ѳ��� str ��ָ����ַ���ת��Ϊһ��������������Ϊ double �ͣ���
// int atoi(const char *str) �Ѳ��� str ��ָ����ַ���ת��Ϊһ������������Ϊ int �ͣ���
// long int atol(const char *str) �Ѳ��� str ��ָ����ַ���ת��Ϊһ��������������Ϊ long int �ͣ���
// double strtod(const char str, char *endptr) �Ѳ��� str ��ָ����ַ���ת��Ϊһ��������������Ϊ double �ͣ���
// long int strtol(const char str, char *endptr, int base) �Ѳ��� str ��ָ����ַ���ת��Ϊһ��������������Ϊ long int �ͣ���
// unsigned long int strtoul(const char str, char *endptr, int base) �Ѳ��� str ��ָ����ַ���ת��Ϊһ���޷��ų�����������Ϊ unsigned long int �ͣ���
// void exit(int status) ʹ����������ֹ��
int main()
{
    char num[]="123456789";

    exit(0);

    printf("%f\n",atof(num));
    printf("%d\n",atoi(num));

    getchar();
    return 0;

}