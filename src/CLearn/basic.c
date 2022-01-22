#include <stdio.h>
#define LENGTH 10
#define WIDTH 5
#define NEWLINE '\n'

enum DAY
{
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};

int main()
{

    int area;
    area = LENGTH * WIDTH;
    printf("value of area : %d", area);
    printf("%c", NEWLINE);

    auto Month = 8;
    register int miles;
    static int thing;
    extern int data;

    int *ptr = &area;
    printf("%d \n", *ptr);
    printf("%d \n", ptr);

    for (int day= MON; day <= SUN; day++)
        printf("%d  ", day);
    printf("\n");




    
    getchar();
    return 0;
}