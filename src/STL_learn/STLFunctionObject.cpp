#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "travel.h"
using namespace std;

int main()
{
    //  arithmetic
    //plus<T> +
    //minus<T> -
    //multiplies<T> *
    //divides<T> /
    //modulus<T> mod
    //negate<T> opposite
    negate<int> n;
    cout << n(50) << endl;
    plus<int> p;
    cout << p(1, 1) << endl;

    //  relationship
    //bool equal_to<T> =
    //bool not_equal_to<T> !=
    //bool greater<T> >
    //bool greater_equal<T> >=
    //bool less<T> <
    //bool less_equal<T> <=

    vector<int> v;
    for (int i = 0; i < 15; i++)
        v.push_back(rand());
    sort(v.begin(), v.end());
    trav(v);
    sort(v.begin(), v.end(), greater<int>());
    trav(v);

    // logic
    //bool logical_and<T>  &&
    //bool logical_or<T>   ||
    //bool logical_not<T>  !
    vector<bool> v1;
    for (int i = 0; i < 10; i++)
        i % 2 == 0 ? v1.push_back(true) : v1.push_back(false);
    vector<bool> v2;
    v2.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
    trav(v1);
    trav(v2);
    getchar();
    return 0;
}