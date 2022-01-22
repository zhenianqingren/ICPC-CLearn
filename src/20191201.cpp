#include <iostream>
using namespace std;
bool IsSkip(int e)
{
    if (e % 7 == 0)
        return true;
    while (e != 0)
    {
        if (e % 10 == 7)
            return true;
        e = e / 10;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int people[4] = {0, 0, 0, 0};
    int order;
    for (int i = 1; n != 0; i++)
    {
        if (IsSkip(i))
        {
            order = ((i % 4) - 1 >= 0 ? (i % 4) - 1 : 3);
            people[order]++;
        }
        else
            n--;
    }
    cout<<people[0]<<'\n'<<people[1]<<'\n'<<people[2]<<'\n'<<people[3];
    system("pause");
    return 0;
}