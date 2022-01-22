#include <iostream>
#include <vector>
#include <algorithm>
#include"travel.h"
using namespace std;
class MyCompare
{
public:
    bool operator()(int a,int b)
    {
        return a>b;
    }
};

int main()
{
    vector<int>v;
    for(int i=0;i<15;i++)
        v.push_back(rand());
    sort(v.begin(),v.end());
    trav(v);
    sort(v.begin(),v.end(),MyCompare());
    trav(v);
    getchar();
    return 0;
}