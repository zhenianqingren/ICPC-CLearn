#include <iostream>
#include <string>
using namespace std;
// �����ַ����Ĵ�����������Ǿ������������⡣���������ַ������Կո񡢻س���
// �Ʊ����Ϊ�������ģ������ñ�׼�������������(cin/cout)��

int main()
{
    string str;
    cin >> str;
    cout << str << endl;
    char ch[20];
    cin >> ch;
    cout << ch << endl;
    // ���ϣ��������ַ��������ո���ַ��������ʹ������Ĵ���ʽ��
    getchar();
    getline(cin, str);
    cout << str << endl;
    //     �ر���Ҫע����ǵ�����һ���������͵�����������Ҫ�� getline �����ַ����������
    // ʹ�� cin.ignore()�����������еĻس���
    cin.ignore();
    int testcase;
    cin >> testcase;
    cin.ignore();
    getline(cin, str);
    system("pause");
    return 0;
}