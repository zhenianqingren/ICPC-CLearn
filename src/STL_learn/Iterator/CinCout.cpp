#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(int argc, char *argv[])
{
    //�����������������ͨ�������������д��"��"
    //���캯����һ������ΪҪ���Ŀ�ĵأ��ڶ�������Ϊ�����
    ostream_iterator<int> intwriter(cout, " ");

    *intwriter = 11;
    *intwriter = 22;
    *intwriter = 33;

    vector<int> col1;

    for (int i = 0; i < 10; i++)
        col1.push_back(i);
    cout << endl;
    copy(col1.begin(), col1.end(), intwriter);
    cout << endl;
    copy(col1.begin(), col1.end(), ostream_iterator<int>(cout, "|"));
    cout << endl;

    col1.clear();
    //������������������ͨ���������������ȡ"��"
    //���캯���еĲ���Ϊ��������Դ��Ĭ��Ϊ����������
    istream_iterator<int> intreader(cin);
    istream_iterator<int> eof;
    //���������Ϊ������Դ������col1��
    while (intreader != eof)
    {
        //ÿ��������ȡ
        advance(intreader, 2);
        if (intreader != eof)
        {
            col1.push_back(*intreader);
            ++intreader;
        }
    }
    cout << endl;
    copy(col1.begin(), col1.end(), ostream_iterator<int>(cout, "|"));
    cout << endl;
    system("PAUSE"); //press any key to continue......
    return 0;
}