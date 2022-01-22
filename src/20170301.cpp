#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int *cake = new int[n];
    for (int i = 0; i < n; i++)
        cin >> cake[i];
    int j;
    int cur = 0;
    int p = 0;
    for (j = 0; j < n; j++)
    {
        cur += cake[j];
        if (cur >= k)
        {
            cur = 0;
            p++;
        }
    }
    if (cur != 0)
        p++;
    cout << (p > n ? n : p);
    return 0;
}