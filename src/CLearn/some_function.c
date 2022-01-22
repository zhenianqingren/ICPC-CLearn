#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define M_PI
int main()
{

    char*str=(char*)malloc(sizeof(char)*64);
    sprintf(str,"PiµÄÖµÊÇ %020.15f",sin(5.0));

    puts(str);

    free(str);
    str=(char*)calloc(64,sizeof(char));
    strcpy(str,"This is string.h library function");
    memset(str,'#',4);
    puts(str);
    free(str);


    getchar();
    return 0;
}