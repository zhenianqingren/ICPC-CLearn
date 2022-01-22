#include <iostream>
#include <vector>
#include "travel.h"
using namespace std;
int main()
{
    //init
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> v2;
    for (int i = 0; i < 10; i++)
        v2.push_back(rand());
    vector<int> v3(10);
    vector<int> v4(10, 99);
    vector<int> v5(v4);
    vector<int> v6(v2.begin() + 1, v2.end() - 1);
    trav(v1);
    trav(v2);
    trav(v3);
    trav(v4);
    trav(v5);
    trav(v6);

    //common methods
    // assign(begin,end)
    // assign(n,elem)
    // empty()
    // capacity()
    // size()
    // resize(int len)
    // resize(int len , elem)
    // push_back(elem)
    // pop_back()
    // insert(const_iterator pos,elem)
    // insert(const_iterator pos, int n,elem)
    // erase(const_iterator pos)
    // erase(const_iterator start, const_iterator end)
    // clear()
    vector<int> v7(10000);
    cout << v7.capacity() << "   " << v7.size() << endl;
    v7.resize(5);
    cout << v7.capacity() << "   " << v7.size() << endl;
    // use swap() reasonably to reduce space
    vector<int>(v7).swap(v7);
    cout << v7.capacity() << "   " << v7.size() << endl;
    cout << "\n \n \n";
    // reserve(int len)
    // reduce the expansion times of vector when dynamically expanding capacity
    vector<int> v8;
    int num = 0;
    int *p = nullptr;
    for (int i = 0; i < 100000; i++)
    {
        v8.push_back(i);
        if (p != &v8[0])
        {
            num++;
            p = &v8[0];
        }
    }
    cout << num << endl;
    v8.clear();
    num = 0;
    p = nullptr;
    v8.reserve(100000);
    for (int i = 0; i < 100000; i++)
    {
        v8.push_back(i);
        if (p != &v8[0])
        {
            num++;
            p = &v8[0];
        }
    }
    cout << num << endl;
    getchar();
    return 0;
}