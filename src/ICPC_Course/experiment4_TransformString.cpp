#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> TransformString(string a, string b);
void Print(string a, string b);
int Tackle(int ins, int del, int rep, int cur);
void ChangeString(string &a, string b, int select, size_t &i, size_t &j);
// 1.insert 2.del 3.replace
int main()
{
    string a, b;
    cin >> a >> b;
    cout<<'\n'<<endl;
    Print(a, b);
    system("pause");
    return 0;
}

vector<vector<int>> TransformString(string a, string b)
{
    vector<vector<int>> dp(a.size(), vector<int>(b.size()));
    for (size_t i = 0; i < b.size(); i++)
        dp[0][i] = b.substr(0, i + 1).find(a[0]) == b.npos ? i + 1 : i;
    for (size_t i = 1; i < a.size(); i++)
        dp[i][0] = a.substr(0, i + 1).find(b[0]) == a.npos ? i + 1 : i;
    for (size_t i = 1; i < a.size(); i++)
        for (size_t j = 1; j < b.size(); j++)
            if (a[i] == b[j])
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1) < dp[i - 1][j - 1] ? min(dp[i - 1][j] + 1, dp[i][j - 1] + 1) : dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1) < dp[i - 1][j - 1] + 1 ? min(dp[i - 1][j] + 1, dp[i][j - 1] + 1) : dp[i - 1][j - 1] + 1;

    return dp;
}

void Print(string a, string b)
{
    vector<vector<int>> res = TransformString(a, b);
    size_t i = a.size() - 1, j = b.size() - 1;
    string temp_str = "";
    cout << a << endl;
    while (i != 0 && j != 0)
    {
        int select = Tackle(res[i][j - 1], res[i - 1][j], res[i - 1][j - 1], res[i][j]);
        ChangeString(a, b, select, i, j);
    }
    if (i == 0 && j == 0)
    {
        a[0] = b[0];
        cout << a << endl;
    }
    if (j > 0)
    {
        temp_str = b.substr(0, j + 1);
        size_t sameExisted = temp_str.find(a[0]);
        if (sameExisted != temp_str.npos)
        {
            for (size_t m = sameExisted - 1; m >= 0; m--)
            {
                a.insert(0, temp_str.substr(m, 1));
                cout << a << endl;
            }
            for (size_t n = sameExisted + 1; n <= j; n++)
            {
                a.insert(n, temp_str.substr(n, 1));
                cout << a << endl;
            }
        }
        else
        {
            a[0] = b[j];
            cout << a << endl;
            for (size_t k = j - 1; k >= 0; k--)
            {
                a.insert(0, temp_str.substr(k, 1));
                cout << a << endl;
            }
        }
    }
    if (i > 0)
    {
        temp_str = a.substr(0, i + 1);
        size_t sameExisted = temp_str.find(b[0]);
        if (sameExisted != temp_str.npos)
        {
            for (size_t m = 0; m < sameExisted; m++)
            {
                a.erase(0, 1);
                cout << a << endl;
            }
            for (size_t n = sameExisted + 1; n <= i; n++)
            {
                a.erase(sameExisted + 1, 1);
                cout << a << endl;
            }
        }
        else
        {
            a[i] = b[0];
            cout << a << endl;
            for (size_t k = i - 1; k >= 0; k--)
            {
                a.erase(0, 1);
                cout << a << endl;
            }
        }
    }
    cout << res[res.size() - 1][res[0].size() - 1];
    cout << '\n';
}

int Tackle(int ins, int del, int rep, int cur)
{
    if (cur - rep == 1)
        return 3;
    if (cur - del == 1)
        return 2;
    if (cur - ins == 1)
        return 1;
    if (cur == rep)
        return 3;

    return -1;
}

void ChangeString(string &a, string b, int select, size_t &i, size_t &j)
{
    switch (select)
    {
    case 1:
        a.insert(i + 1, b.substr(j, 1));
        j--;
        cout << a << endl;
        return;

    case 2:
        a.erase(i, 1);
        i--;
        cout << a << endl;
        return;
    case 3:
        a[i] = b[j];
        i--;
        j--;
        cout << a << endl;
        return;
    }
}
