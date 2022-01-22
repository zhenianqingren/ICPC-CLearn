#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *data = new int[n];
    for (int i = 0; i < n; i++)
        cin >> data[i];
    int Max, Min;
    bool isfloat = true;
    float mid;
    if (n % 2 == 0)
    {
        if ((data[n / 2] + data[n / 2 - 1]) % 2 == 0)
            isfloat = false;
        mid = (data[n / 2] + data[n / 2 - 1]) / 2.0;
    }
    else
    {
        mid = data[n / 2];
        isfloat = false;
    }
    if (data[1] - data[0] >= 0)
    {
        Max = data[n - 1];
        Min = data[0];
    }
    else
    {
        Max = data[0];
        Min = data[n - 1];
    }
    if (isfloat)
        cout << Max << " " << setiosflags(ios::fixed) << setprecision(1) << mid << " " << Min;
    else
        cout << Max << " " << setiosflags(ios::fixed) << setprecision(0) << mid << " " << Min;//attention
    system("pause");
    return 0;
}