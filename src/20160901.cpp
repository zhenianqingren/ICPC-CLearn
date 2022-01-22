#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *price = new int[n];
    for (int i = 0; i < n; i++)
        cin >> price[i];

    int max = fabs(price[1] - price[0]);
    for (int i = 2; i < n; i++)
    {
        int cur = fabs(price[i] - price[i - 1]);
        if (cur > max)
            max = cur;
    }
    cout << max;
    return 0;
}