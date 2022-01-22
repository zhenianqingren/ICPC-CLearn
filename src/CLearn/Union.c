#include <stdio.h>
#include <string.h>

union Data
{
    int i;
    float f;
    char str[20];
};
// 共用体是一种特殊的数据类型，允许您在相同的内存位置存储不同的数据类型。您可以定义一个带有多成员的共用体，但是任何时候只能有一个成员带有值。共用体提供了一种使用相同的内存位置的有效方式。
// 所有的成员都能完好输出，因为同一时间只用到一个成员。
// 共用体的 i 和 f 成员的值有损坏，因为最后赋给变量的值占用了内存位置，这也是 str 成员能够完好输出的原因。
// 共用体占用的内存应足够存储共用体中最大的成员

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