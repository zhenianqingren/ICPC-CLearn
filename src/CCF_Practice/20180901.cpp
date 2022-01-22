#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *first_day = new int[n];
    int *next_day = new int[n];
    for (int i = 0; i < n; i++)
        cin >> first_day[i];
    for (int i = 0; i < n; i++)
        if (i == 0)
            next_day[i] = (first_day[i] + first_day[i + 1]) / 2;
        else if (i == n - 1)
            next_day[i] = (first_day[i - 1] + first_day[i]) / 2;
        else
            next_day[i] = (first_day[i - 1] + first_day[i] + first_day[i + 1]) / 3;
    for (int i = 0; i < n; i++)
        cout << next_day[i] << " ";
    system("pause");
    return 0;
}