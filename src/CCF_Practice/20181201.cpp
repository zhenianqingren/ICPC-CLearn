#include<iostream>
using namespace std;
int main()
{
    int r,y,g;
    cin>>r>>y>>g;
    int n;
    cin>>n;
    int time=0;
    int k,t;
    while(n>0)
    {
        cin>>k>>t;
        if(k==0||k==1)
            time+=t;
        else if(k==2)
            time+=(t+r);
        else if(k==3)
            ;
        n--;
    }
    cout<<time;
    system("pause");
    return 0;
}