#include <stdio.h>
#define message_for(a, b) \
    printf(#a " and " #b ": !\n")
#define tokenpaster(n) printf("token" #n " = %d", token##n)
#if !defined (MESSAGE)
   #define MESSAGE "You wish!"
#endif
#define MAX(x,y) ((x) > (y) ? (x) : (y))
int main()
{
    printf("File :%s\n", __FILE__);
    printf("Date :%s\n", __DATE__);
    printf("Time :%s\n", __TIME__);
    printf("Line :%d\n", __LINE__);
    printf("ANSI :%d\n", __STDC__);

    message_for("Hello", "World");

    int token34 = 40;
    tokenpaster(34);

    printf("Here is the message: %s\n", MESSAGE);

    printf("Max between 20 and 10 is %d\n", MAX(10, 20));

    getchar();
    return 0;
}