#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ��������������ַ������䷴�������������������һ�����������ַ�������
// ����Ȼ�����ַ���

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