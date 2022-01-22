#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
// defination:
// Function objects that return bool types are called predicates
// one parameter -> OnePredicate
// two parameter -> TwoPredicate
class MyCompare
{
public:
    bool operator()(int val)
    {
        return val>15;
    }
};
int main()
{
    vector<int>v;
    for(int i=0;i<20;i++)
        v.push_back(i);
    vector<int>::iterator ite=find_if(v.begin(),v.end(),MyCompare());
// find_if() return the first
    cout<<*ite;
    getchar();
    return 0;
}