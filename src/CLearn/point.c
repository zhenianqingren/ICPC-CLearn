#include <stdio.h>

int max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    int i = 1;
    int arr1[10];
    printf("%p \n", &i);
    printf("%p \n", arr1);

    // function pointer
    /* p �Ǻ���ָ�� */
    int (*p)(int, int) = &max; // &����ʡ��
    int a, b, c, d;

    printf("��������������:");
    scanf("%d %d %d", &a, &b, &c);

    /* ��ֱ�ӵ��ú����ȼۣ�d = max(max(a, b), c) */
    d = p(p(a, b), c);
    printf("����������: %d\n", d);



    scanf("%d",&d);
    return 0;
}