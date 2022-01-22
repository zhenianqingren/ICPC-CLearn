#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    N=N/10;
    cout<<(N+(N/5)*2+(N%5)/3);
    system("pause");
    return 0;
}