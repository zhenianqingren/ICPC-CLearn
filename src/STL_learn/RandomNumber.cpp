#include<iostream>
using namespace std;

int main()
{
//  int rand() return an integer between 0 and 32767 according to seeds
//  The default seed is 1
    for(int i=0;i<20;i++)
        cout<<rand()<<" ";
    cout<<endl;
// void srand(unsigned int seed)
// set the seed of srand()
    srand(2);
    for(int i=0;i<20;i++)
        cout<<rand()<<" ";
    cout<<endl;
    system("pause");
    return 0;
}