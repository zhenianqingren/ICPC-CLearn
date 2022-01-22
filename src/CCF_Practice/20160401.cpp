#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *amount = new int[n];
    int num = 0;
    for (int i = 0; i < n; i++)
        cin >> amount[i];
    if (n == 1)
        cout << num;
    else
    {
        int before = amount[1] - amount[0] > 0 ? 1 : 0;
        for (int i = 2; i < n; i++)
        {
            int now = amount[i] - amount[i - 1] > 0 ? 1 : 0;
            if (now != before)
            {
                before = now;
                num++;
            }
        }
        cout << num;
    }
    return 0;
}

// #include <stdio.h>
// int main()
// {
//     int n, d1, d2;
//     scanf("%d%d", &n, &d1);
//     int ans = 0;
//     int f1 = 0, f2 = 0;
//     for (int i = 1; i < n; i++)
//     {
//         scanf("%d", &d2);
//         f2 = d2 - d1 > 0 ? 1 : -1;
//         if (f1 * f2 < 0)
//             ans++;
//         f1 = f2;
//         d1 = d2;
//     }
//     printf("%d\n", ans);
//     return 0;
// }