#include <iostream>
#include <map>
using namespace std;
// map �����������ڿ��ٴ洢�Ͷ�ȡ�ؼ��������ֵ���ڲ��Ǻ�����ṹ��map ������
// �ظ��ؼ��֣����һ���ؼ���ֻ���Զ�Ӧһ��ֵ����Ϊһ��һӳ�䡣

int main()
{
    typedef map<int, double, less<int>> mid;//�˴�ʹ��less�������󣬴ﵽ������map�а���key����洢
    mid pairs;
    pairs.insert(mid::value_type(15, 2.7));
    pairs.insert(mid::value_type(30, 111.11));
    pairs.insert(mid::value_type(15, 2.7));
    pairs.insert(mid::value_type(5, 1010.1));
    pairs.insert(mid::value_type(10, 22.22));
    pairs.insert(mid::value_type(25, 33.33));
    pairs.insert(mid::value_type(5, 77.22));
    pairs.insert(mid::value_type(20, 6.7));
    pairs.insert(mid::value_type(15, 2.7)); //ingore for key has exsit
    mid::iterator iter;
    for (iter = pairs.begin(); iter != pairs.end(); iter++)
        cout << iter->first << '\t' << iter->second << endl;
    pairs[25] = 9999.99;
    pairs[40] = 8765.43;
    cout << "\nAfter subscript operations, pairs contains: "
         << "\nkey\tvalue\n";
    for (iter = pairs.begin(); iter != pairs.end(); iter++)
        cout << iter->first << "\t" << iter->second << "\t" << endl;
    cout << endl;
    system("PAUSE");
    return 0;
}