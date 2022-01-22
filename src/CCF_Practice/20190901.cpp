#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    int T = 0;
    int p = -1, k;
    int total=0;
    int *data = new int[M + 1];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M + 1; j++)
            cin >> data[j];
        T+=data[0];
        for (int j = 1; j < M + 1; j++)
            total += abs(data[j]);
        if (total > p)
        {
            p = total;
            k = i + 1;
        }
        T -= total;
        total=0;
    }
    cout << T << " " << k << " " << p;
    system("pause");
    return 0;
}