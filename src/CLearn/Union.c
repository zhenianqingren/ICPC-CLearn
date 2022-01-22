#include <stdio.h>
#include <string.h>

union Data
{
    int i;
    float f;
    char str[20];
};
// ��������һ��������������ͣ�����������ͬ���ڴ�λ�ô洢��ͬ���������͡������Զ���һ�����ж��Ա�Ĺ����壬�����κ�ʱ��ֻ����һ����Ա����ֵ���������ṩ��һ��ʹ����ͬ���ڴ�λ�õ���Ч��ʽ��
// ���еĳ�Ա��������������Ϊͬһʱ��ֻ�õ�һ����Ա��
// ������� i �� f ��Ա��ֵ���𻵣���Ϊ��󸳸�������ֵռ�����ڴ�λ�ã���Ҳ�� str ��Ա�ܹ���������ԭ��
// ������ռ�õ��ڴ�Ӧ�㹻�洢�����������ĳ�Ա

int main()
{
    union Data data;
    printf("Memory size occupied by data : %d\n", sizeof(data));

    data.i = 10;
    data.f = 220.5;
    strcpy(data.str, "C Programming");

    printf("data.i : %d\n", data.i);
    printf("data.f : %f\n", data.f);
    printf("data.str : %s\n", data.str);

    data.i = 10;
    printf("data.i : %d\n", data.i);

    data.f = 220.5;
    printf("data.f : %f\n", data.f);

    strcpy(data.str, "C Programming");
    printf("data.str : %s\n", data.str);

    getchar();
    return 0;
}