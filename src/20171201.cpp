#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int min = 10000;
    vector<int> data(n);
    for (int i = 0; i < n; i++)
        cin >> data[i];
    sort(data.begin(), data.end());
    for (int i = 0; i < n - 1; i++)
    {
        int judge = fabs(data[i + 1] - data[i]);
        if (judge < min)
            min = judge;
    }
    cout << min;
    system("pause");
    return 0;
}