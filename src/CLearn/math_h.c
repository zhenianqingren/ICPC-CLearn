#include <stdio.h>
#include <math.h>
// double acos(double x) �����Ի��ȱ�ʾ�� x �ķ����ҡ�
// double asin(double x) �����Ի��ȱ�ʾ�� x �ķ����ҡ�
// double atan(double x) �����Ի��ȱ�ʾ�� x �ķ����С�
// double atan2(double y, double x) �����Ի��ȱ�ʾ�� y/x �ķ����С�y �� x ��ֵ�ķ��ž�������ȷ�����ޡ�
// double cos(double x) ���ػ��Ƚ� x �����ҡ�
// double cosh(double x) ���� x ��˫�����ҡ�
// double sin(double x) ���ػ��Ƚ� x �����ҡ�
// double sinh(double x) ���� x ��˫�����ҡ�
// double tanh(double x) ���� x ��˫�����С�
// double exp(double x) ���� e �� x ���ݵ�ֵ��
// double frexp(double x, int *exponent) �Ѹ����� x �ֽ��β����ָ��������ֵ��β��������ָ������ exponent �С����õ�ֵ�� x = mantissa * 2 ^ exponent��
// double ldexp(double x, int exponent) ���� x ���� 2 �� exponent ���ݡ�
// double log(double x) ���� x ����Ȼ����������Ϊ e �Ķ�������
// double log10(double x) ���� x �ĳ��ö���������Ϊ 10 �Ķ�������
// double modf(double x, double *integer) ����ֵΪС�����֣�С�����Ĳ��֣��������� integer Ϊ�������֡�
// double pow(double x, double y) ���� x �� y ���ݡ�
// double sqrt(double x) ���� x ��ƽ������
// double ceil(double x) ���ش��ڻ���� x ����С������ֵ��
// double fabs(double x) ���� x �ľ���ֵ��
// double floor(double x) ����С�ڻ���� x ����������ֵ��
// double fmod(double x, double y) ���� x ���� y ��������

int main()
{

    printf("%f\n",exp(5.0));
    printf("%f\n",pow(2,32));
    printf("%f\n",sqrt(10000));
    

    getchar();
    return 0;
}