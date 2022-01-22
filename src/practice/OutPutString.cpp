#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 对于输入给定的字符串将其反序输出。输入是先输入一个整数代表字符串的行
// 数，然后是字符串

void Reverse(string s)
{
    int lo = 0;
    int hi = s.size() - 1;
    static char temp = '0';
    while (lo < hi)
    {
        temp = s[lo];
        s[lo] = s[hi];
        s[hi] = temp;
        lo++;
        hi--;
    }
    cout << s << endl;
}

int main()
{
    int line;
    cin >> line;
    string str;
    cin.ignore();
    for (int i = 0; i < line; i++)
    {
        getline(cin,str);
        Reverse(str);
    }

    system("pause");
    return 0;
}