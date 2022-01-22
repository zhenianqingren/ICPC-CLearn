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
    /* p 是函数指针 */
    int (*p)(int, int) = &max; // &可以省略
    int a, b, c, d;

    printf("请输入三个数字:");
    scanf("%d %d %d", &a, &b, &c);

    /* 与直接调用函数等价，d = max(max(a, b), c) */
    d = p(p(a, b), c);
    printf("最大的数字是: %d\n", d);



    scanf("%d",&d);
    return 0;
}