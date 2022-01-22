#include <stdio.h>
#include<stdlib.h>
int CalculateLen(int arr[])//array will be transformed into pointer when passed as a parameter
{
    return (int)sizeof(arr);
}

int main(void)
{
    //unsigned
    printf("%d\n", (int)sizeof(void *));

    int i = 0;
    printf("%d\n", (int)sizeof i);

    int arr[]={1,2,3,4,5};
    int*Arr=(int*)malloc((int)sizeof(int)*5);
    printf("%d\n",CalculateLen(arr));
    printf("%d\n",sizeof(arr));
    printf("%d\n",sizeof(Arr));
    free(Arr);
    getchar();
    return 0;
}