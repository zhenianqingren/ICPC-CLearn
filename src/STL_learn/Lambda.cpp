#include <iostream>
#include <vector>
#include <algorithm>
#include "travel.h"
using namespace std;

// [External variable access mode specifier](parameters)-> the value type of being returned
// {
//      block
// }
// -> can be omitted
// The external variable access method specifier can be = or &,
// indicating whether the variables used in {} and defined outside {} are allowed to be changed in {}
//  = indicates not allowed, while & indicates allowed.
//
//
//
//

int main()
{
    vector<int> v1;
    for (int i = 0; i < 15; i++)
        v1.push_back(rand());
    sort(v1.begin(), v1.end(), [&](int x, int y) -> bool
         { return x > y; });
    trav(v1);
    for_each(v1.begin(), v1.end(), [&](int e)
             { cout << e << " "; });
    cout<<endl;

    getchar();
    return 0;
}
