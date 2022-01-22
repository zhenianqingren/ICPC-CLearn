#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void allocate(char *p)
{
    char *temp = (char *)malloc(sizeof(char) * 16);
    strcpy(temp, "Hello World");
    p = temp;
}

void re_allocate(char **ptr)
{
    char *temp = (char *)malloc(sizeof(char) * 16);
    strcpy(temp, "Hello World");
    *ptr = temp;
}

void init()
{
    char *p = NULL;
    allocate(p);
    printf("%s\n", p);
}

void revise()
{
    char *p = NULL;
    re_allocate(&p);
    printf("%s\n", p);
}

int main(int argc, char const *argv[])
{
    init();
    revise();
    getchar();
    return 0;
}
