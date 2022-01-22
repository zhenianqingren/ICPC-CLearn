#include<iostream>
#include<string>
using namespace std;
template<class T,class U>
struct Pair
{
    typedef T first_type;
    typedef U second_type;
    T first;
    T second;
    Pair();
    Pair(const T&x,const U&y)
    {
        this->first=x;
        this->second=y;
    }
    template<class V,class W>
        Pair(const Pair<V,W>&pr)
        {
            this->first=pr->first;
            this->second=pr->second;
        }
};

int main()
{
    int key=1;
    char value='a';
    Pair<int,char>*mypair=new Pair<int,char>(key,value);
    cout<<mypair->first<<endl;
    cout<<mypair->second<<endl;



    getchar();
    return 0;
}
