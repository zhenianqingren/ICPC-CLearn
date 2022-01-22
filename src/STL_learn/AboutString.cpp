#include <iostream>
#include <string>
using namespace std;
// 关于字符串的处理，输入输出是经常碰到的问题。如果输入的字符串是以空格、回车、
// 制表符作为结束符的，可以用标准输入输出流处理(cin/cout)。

int main()
{
    string str;
    cin >> str;
    cout << str << endl;
    char ch[20];
    cin >> ch;
    cout << ch << endl;
    // 如果希望输入的字符串包含空格等字符，则必须使用另外的处理方式。
    getchar();
    getline(cin, str);
    cout << str << endl;
    //     特别需要注意的是当输入一个其他类型的数如整数后要用 getline 输入字符串，则必须
    // 使用 cin.ignore()；来忽略流中的回车符
    cin.ignore();
    int testcase;
    cin >> testcase;
    cin.ignore();
    getline(cin, str);
    system("pause");
    return 0;
}