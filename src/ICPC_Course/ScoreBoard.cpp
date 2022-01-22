#include <iostream>
#include <string>
#include <vector>
using namespace std;

string a, b;

int Compare(string a, string b, size_t pos);
void find(string a, string b, size_t pos, vector<size_t> &v);

int main()
{

    cin >> a >> b;
    int res = Compare(a, b, 0);
    if (res <= 0)
        cout << -1;
    else
        cout << res;
    cout << endl;
    system("pause");
    return 0;
}

int Compare(string a, string b, size_t pos)
{
    if (pos >= a.size() || pos >= b.size())
        return -2147483648;
    if (a[pos] < b[pos])
        return 0;
    if (a[pos] == b[pos])
        return Compare(a, b, pos + 1);
    vector<size_t> v;
    find(a, b, pos, v);
    if (v.size() == 0)
        return -2147483648;
    bool sameExisted;
    int temp;
    int min = 2147483647;
    string s;
    for (size_t i = 0; i < v.size(); i++)
    {
        sameExisted = false;
        if (i == 0 && a[v[i]] < b[pos])
            return v[i] - pos;
        if (a[v[i]] < b[pos])
            temp = v[i] - pos;
        if (a[v[i]] == b[pos] && !sameExisted)
        {
            s = a;
            s.erase(v[i], 1);
            s.insert(pos, a.substr(v[i], 1));
            temp = Compare(s, b, pos + 1) + v[i] - pos;
            sameExisted = true;
        }
        if (temp < min)
            min = temp;
    }

    return min;
}

void find(string a, string b, size_t pos, vector<size_t> &v)
{
    for (size_t i = pos + 1; i < a.size(); i++)
        if (a[i] <= b[pos])
        {
            v.push_back(i);
            if (a[i] < b[pos])
                break;
        }
}