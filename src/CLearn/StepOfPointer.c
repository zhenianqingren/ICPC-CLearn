#include <stdio.h>

void Test()
{
    char *p1 = NULL;

    printf("%d\n",p1);
    printf("%d\n",p1+1);

    long*p2=NULL;
    printf("%d\n",p2);
    printf("%d\n",p2+1);
    
}



int main(int argc, char const *argv[])
{
    Test();
    getchar();
    return 0;
}
