#include <iostream>
using namespace std;
int main()
{
    int score = 0;
    int pre=0;
    int cur;
    while(cin>>cur&&cur)
    {
        if(cur==1)
        {
            score+=1;
            pre=1 ;
        }
        else if(pre==1||pre==0)
        {
            score+=2;
            pre=2;
        }
        else
        {
            pre+=2;
            score+=pre;
        }
    }
    cout<<score;
    system("pause");
    return 0;
}