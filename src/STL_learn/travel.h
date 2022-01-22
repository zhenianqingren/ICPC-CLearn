#include <iostream>
#include <vector>
#include <list>
using namespace std;
template <class T>
void trav(vector<T> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}