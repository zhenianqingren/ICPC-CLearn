#include<iostream>
using namespace std;

// cin>>等价于cin.operator>>()，即调用成员函数operator>>()进行读取数据。
// 当cin>>从缓冲区中读取数据时，若缓冲区中第一个字符是空格、tab或换行这些分隔符时，cin>>会将其忽略并清除，继续读取下一个字符，若缓冲区为空，则继续等待。但是如果读取成功，字符后面的分隔符是残留在缓冲区的，cin>>不做处理。
// 不想略过空白字符，那就使用 noskipws 流控制。比如cin>>noskipws>>input;

// cin>>对缓冲区中的第一个换行符视而不见，
// 采取的措施是忽略清除，继续阻塞等待缓冲区有效数据的到来。
// 但是，getline()读取数据时，并非像cin>>那样忽略第一个换行符，
// getline()发现cin的缓冲区中有一个残留的换行符，不阻塞请求键盘输入，
// 直接读取，送入目标字符串后，再将换行符替换为空字符’\0’，因此程序中的test为空串

// cin.get()从输入缓冲区读取单个字符时不忽略分隔符，直接将其读取
// cin.get()的返回值是int类型，成功：读取字符的ASCII码值，遇到文件结束符时，返回EOF，即-1，Windows下标准输入输入文件结束符为Ctrl+z，
// Linux为Ctrl+d。cin.get(char var)如果成功返回的是cin对象，因此可以支持链式操作，如cin.get(b).get(c)

// 读取一行可以使用istream& get ( char* s, streamsize n )或者istream& get ( char* s, size_t n, streamsize delim )。
// 二者的区别是前者默认以换行符结束(换行符会留在缓冲区自动传给下一次读入)，后者可指定结束符。n表示目标空间的大小
int main(int argc,char*argv[])
{
    char a;
    char array[20]={NULL};
    cin.get(array,20);
    cin.get(a);
    cout<<array<<" "<<a<<endl;
    system("pause");
    return 0;
}